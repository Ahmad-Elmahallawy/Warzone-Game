// GameEngine.cpp
#include "GameEngine.h"
#include "Command/CommandProcessing.h"
#include <iostream>
#include <vector>
#include <algorithm> // include for case-insensitive string comparison
#include <random>

using namespace std;

#include "GameEngine.h"
// converts state enum value to string
std::string stateToString(GameEngine::State state) {
    switch (state) {
        case GameEngine::State::START: return "start";
        case GameEngine::State::MAP_LOADED: return "map loaded";
        case GameEngine::State::MAP_VALIDATED: return "map validated";
        case GameEngine::State::PLAYERS_ADDED: return "players added";
        case GameEngine::State::ASSIGN_REINFORCEMENTS: return "assign reinforcement";
        case GameEngine::State::ISSUE_ORDERS: return "issue orders";
        case GameEngine::State::EXECUTE_ORDERS: return "execute orders";
        case GameEngine::State::WIN: return "win";
        case GameEngine::State::END: return "end";
    }
}

// converts command to string
std::string commandToString(Commands command) {
    switch (command) {
        case CMD_START: return "start";
        case CMD_LOAD_MAP: return "loadmap";
        case CMD_VALIDATE_MAP: return "validatemap";
        case CMD_ADD_PLAYER: return "addplayer";
        case CMD_GAME_START: return "gamestart";
        case CMD_ISSUE_ORDER: return "issueorder";
        case CMD_END_ISSUE_ORDER: return "endissueorder";
        case CMD_EXECUTE_ORDERS: return "executeorders";
        case CMD_END_EXEC_ORDERS: return "endexecorders";
        case CMD_WIN: return "win";
        case CMD_END: return "end";
        case CMD_PLAY: return "play";
        case CMD_EXEC_ORDER: return "execorder";
    }
}

// converts command string to enum
Commands commandToEnum(const std::string commandStr) {
    if (commandStr == "start") {
        return CMD_START;
    } else if (commandStr == "loadmap") {
        return CMD_LOAD_MAP;
    } else if (commandStr == "validatemap") {
        return CMD_VALIDATE_MAP;
    } else if (commandStr == "addplayer") {
        return CMD_ADD_PLAYER;
    }
    else if (commandStr == "gamestart")
    {
        return CMD_GAME_START;
    }
    else if (commandStr == "issueorder") {
        return CMD_ISSUE_ORDER;
    } else if (commandStr == "endissueorder") {
        return CMD_END_ISSUE_ORDER;
    } else if (commandStr == "executeorders") {
        return CMD_EXECUTE_ORDERS;
    } else if (commandStr == "endexecorders") {
        return CMD_END_EXEC_ORDERS;
    } else if (commandStr == "win") {
        return CMD_WIN;
    } else if (commandStr == "end") {
        return CMD_END;
    } else if (commandStr == "play") {
        return CMD_PLAY;
    } else if (commandStr == "execorder") {
        return CMD_EXEC_ORDER;
    }
}

// Definition and initialization of the static member
std::map<GameEngine::State, std::vector<GameEngine::Transition>> GameEngine::stateTransitions = {
        {State::START, {
                               {CMD_LOAD_MAP, State::MAP_LOADED}
                       }},
        {State::MAP_LOADED, {
                               {CMD_LOAD_MAP, State::MAP_LOADED},
                               {CMD_VALIDATE_MAP, State::MAP_VALIDATED}
                       }},
        {State::MAP_VALIDATED, {
                               {CMD_ADD_PLAYER, State::PLAYERS_ADDED}
                       }},
        {State::PLAYERS_ADDED, {
                               {CMD_ADD_PLAYER, State::PLAYERS_ADDED},
                               {CMD_GAME_START, State::ASSIGN_REINFORCEMENTS}
                       }},
        {State::ASSIGN_REINFORCEMENTS, {
                               {CMD_ISSUE_ORDER, State::ISSUE_ORDERS},
                       }},
        {State::ISSUE_ORDERS, {
                               {CMD_ISSUE_ORDER, State::ISSUE_ORDERS},
                               {CMD_END_ISSUE_ORDER, State::EXECUTE_ORDERS}
                       }},
        {State::EXECUTE_ORDERS, {
                               {CMD_EXEC_ORDER, State::EXECUTE_ORDERS},
                               {CMD_END_EXEC_ORDERS, State::ASSIGN_REINFORCEMENTS},
                               {CMD_WIN, State::WIN}
                       }},
        {State::WIN, {
                               {CMD_PLAY, State::START},
                               {CMD_END, State::END}
                       }},
};


GameEngine::GameEngine():currentState(START), commandProcessor(new CommandProcessing()) {

}

GameEngine::~GameEngine() {
    if (ml != nullptr) {
        delete ml;
        ml = nullptr;
    }

}




// command to enter players in the game
bool GameEngine::addPlayer(string playerName)
{

    // check if a playername is empty
    if(playerName.empty())
    {
        cout << "Your name cannot be empty" << endl;
        return false;
    }

    // check if there are more than 6 players
    if(AddedPlayerList.size() == 6)
    {
        cout << "Number of players can not exceed 6. You can not add more players" << endl;
        return false;
    }

    for (Player* p : AddedPlayerList) {
        if (p->getPlayerName() == playerName) { //check if 2 names are the same


            cout << "The player's name is already taken" << endl;
            return false;
        }
    }

    // creating a player and adding it to the list of players
    Player* player = new Player(playerName);
    AddedPlayerList.push_back(player);
    cout << AddedPlayerList.at(AddedPlayerList.size() - 1)->getPlayerName() << " has been added." << endl;
    cout << "Current players: " << endl;
    for(int i = 0; i < AddedPlayerList.size() ; i++)
    {
        cout << "Player #" << i+1 << ": " << AddedPlayerList.at(i)->getPlayerName() << endl;
    }

    return true;

}


bool GameEngine::gameStart() {
    if (AddedPlayerList.size() < 2) {

        cout << "Cannot start the game with less than 2 players" << endl;
        return false;
    }

    cout << "Part a: Distributing territories " << endl;

    // Allocates one territory to each player. Each territory allocated are equidistant from each other
    int numTerritories = ml->getNumberOfTerritories();
    int gap = numTerritories / (int)AddedPlayerList.size();
    int playersIndex = 0;

    for(int i = 0; i < numTerritories ; i++)
    {
        Territory t = ml->gameMap->listOfTerritories[i];
        AddedPlayerList[playersIndex % AddedPlayerList.size()]->setTerritories(&t);

        playersIndex++;
    }

    // Randomizes the order of players
    for (int i = AddedPlayerList.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(AddedPlayerList[i], AddedPlayerList[j]);
    }


    cout << "Determined the order of play is shown below: " << endl;
    for(int i = 0; i < AddedPlayerList.size() ; i++) {
        cout << "Player #: " << i + 1 << " with name " << AddedPlayerList[i]->getPlayerName() << endl;
    }

    // add 50 armies to each player's reinforcement pool
    for (int i = 0; i < AddedPlayerList.size(); i++)
    {
        AddedPlayerList[i]->setReinforcementPool(50);
        cout << AddedPlayerList[i]->getPlayerName() << " has " << AddedPlayerList[i]->getReinforcementPool() << " in the reinforcement pool" << endl;
    }

    cout << "\nAdded 50 armies to each player's reinforcement pool..." << endl;

    // Draws two cards from the deck for each player
    Deck deck{};


    for(int i = 0; i < AddedPlayerList.size() ; i++)
    {
        Card* card1 = deck.draw();
        Card* card2 = deck.draw();
        if (card1 && card2) {
                AddedPlayerList[i]->getHand()->returnCard(*card1);
                AddedPlayerList[i]->getHand()->returnCard(*card2);

        } else {
            std::cout << "Error: Unable to draw cards from the deck." << std::endl;
            return false;
        }

    }

    cout << "\nDrew two cards from the deck for each player..." << endl;
    return true;
}

// transition to the next state if the command is valid
GameEngine::State GameEngine::transition(Commands command) {
    auto transitionIterator = stateTransitions.find(currentState);

    if (transitionIterator != stateTransitions.end()) {
        for (const auto &transition : transitionIterator->second) {
            if (transition.command == command) {
                std::cout << "Checking transition: " << stateToString(currentState)
                          << " -> " << stateToString(transition.nextState)
                          << " with command: " << commandToString(transition.command) << std::endl;

                currentState = transition.nextState;  // Update the current state
                std::cout << "Transitioning to state: " << stateToString(currentState) << std::endl;
                Notify(this);

                return currentState;  // Return the new state
            }
        }
    }

    std::cout << "Invalid transition from state: " << stateToString(currentState)
              << " with command: " << commandToString(command) << std::endl;

    Notify(this);

    // Return the current state if no valid transition is found
    return currentState;
}


// Implementation of GameEngine class
void GameEngine::startupPhase() {
    while (currentState != ASSIGN_REINFORCEMENTS) {
        Command *command = commandProcessor->getCommand();

        if (command == nullptr) {
            cout << "No command was input." << endl;
            continue;
        }

        // Validate the command
        if (!commandProcessor->validate(command, this->currentState)) {
            std::cout << "Invalid command. Try again." << std::endl;
            continue;
        }

        cout << "Current command: " << command->getCommand() << std::endl;

        // Process the command and change game state accordingly
        switch (commandToEnum(command->getCommand())) {
            case CMD_LOAD_MAP: {
                int numberOfVertices = testLoadMaps(command->secondParameter);
                ml = new MapLoader(numberOfVertices,command->secondParameter);
                // Load the map
                if (!ml->firstRun()) {
                    continue;
                }
                cout << "map loaded successfully" << endl;
                currentState = transition(CMD_LOAD_MAP);
                break;
            }
            case CMD_VALIDATE_MAP: {
                // Validate the map
                if (!ml->secondRun()) {
                    continue;
                }
                currentState = transition(CMD_VALIDATE_MAP);
                break;
            }
            case CMD_ADD_PLAYER:
                if(!addPlayer(command->secondParameter)) {
                    continue;
                }
                currentState = transition(CMD_ADD_PLAYER);
                break;
            case CMD_GAME_START:
                if(!gameStart())
                {
                    continue;
                }
                currentState = transition(CMD_GAME_START);
                break;
            default:
                std::cout << "Invalid command. Try again." << std::endl;
                break;
        }
        delete command;
    }


}

// returns the current state of the game
GameEngine::State GameEngine::getCurrentState() {
    return currentState;
}

// display the valid commands user can enter
//void GameEngine::printValidCommands() {
//    std::cout << "Valid commands for state " << stateToString(currentState) << ":" << std::endl;
//    for (const auto &transition : stateTransitions[currentState]) {
//        std::cout << commandToString(transition.command) << std::endl;
//    }
//}

// returns true if the state is equal to end
bool GameEngine::isGameComplete() {
    return currentState == END;
}


GameEngine::State GameEngine::stringToState(string stateStr) {
    if (stateStr == "start") {
        return GameEngine::State::START;
    } else if (stateStr == "map loaded") {
        return GameEngine::State::MAP_LOADED;
    } else if (stateStr == "map validated") {
        return GameEngine::State::MAP_VALIDATED;
    } else if (stateStr == "players added") {
        return GameEngine::State::PLAYERS_ADDED;
    } else if (stateStr == "assign reinforcement") {
        return GameEngine::State::ASSIGN_REINFORCEMENTS;
    } else if (stateStr == "issue orders") {
        return GameEngine::State::ISSUE_ORDERS;
    } else if (stateStr == "execute orders") {
        return GameEngine::State::EXECUTE_ORDERS;
    } else if (stateStr == "win") {
        return GameEngine::State::WIN;
    } else if (stateStr == "end") {
        return GameEngine::State::END;
    }
}

//////////////////////////////Main Game Loop Part 3////////////////////////////////////

//reinforcement phase

void GameEngine:: reinforcementPhase() {
    /*Players are given a number of army units that depends on the number of
    territories they own, (# of territories owned divided by 3, rounded down). If the player owns all the
    territories of an entire continent, the player is given a number of army units corresponding to the
    continent’s control bonus value. In any case, the minimal number of reinforcement army units per turn for
    any player is 3. These army units are placed in the player’s reinforcement pool. This must be
    implemented in a function/method named reinforcementPhase() in the game engine.
     */

    for (int i = 0; i < AddedPlayerList.size(); i++) {
        AddedPlayerList[i]->setPhase("Reinforcement");
        cout << "Player: " << AddedPlayerList[i]->getPlayerName() << "'s old Reinforcement Pool: "
             << AddedPlayerList[i]->getReinforcementPool();
        // if (number of territories owned) / 3 is less than 3, assigns 3 to the player reinforcement pool
        if (((AddedPlayerList[i]->getTerritories().size()) / 3) < 3) // removed round
        {
            cout << "| Player: " << AddedPlayerList[i]->getPlayerName() << "'s updated Reinforcement Pool: ";
            AddedPlayerList[i]->setReinforcementPool(AddedPlayerList[i]->getReinforcementPool() + 3);
            cout << AddedPlayerList[i]->getReinforcementPool() << endl;
        }

            //check if players owned all territories in continent
        else if (AddedPlayerList[i]->ownAllTerritoryInContinent()) {
            cout << "| Player: " << AddedPlayerList[i]->getPlayerName() << "'s updated Reinforcement Pool: ";
            AddedPlayerList[i]->setReinforcementPool(AddedPlayerList[i]->getReinforcementPool() + 10);
            cout << AddedPlayerList[i]->getReinforcementPool() << endl;
        } else {
            cout << "| Player: " << AddedPlayerList[i]->getPlayerName() << "'s updated Reinforcement Pool: ";
            AddedPlayerList[i]->setReinforcementPool(AddedPlayerList[i]->getReinforcementPool() +
                                             ((AddedPlayerList[i]->getTerritories().size()) / 3)); // removed round
            cout << AddedPlayerList[i]->getReinforcementPool() << endl;
        }

    }
}

void GameEngine::issuingOrdersPhase() {
    /*deploy -> put armies in a territory
    advance -> moves a specified number of armies between adjacent territories, if its a player territory, armies get transferred
    to that territory, if its an enemy territory, an attack happens between the 2 territories
    bomb -> destroy half of the armies located on an opponent's territory that is adjacent to one of player's territory
    blockade -> triple number of armies on one of player's current territory and make it a neutral territory (cannot be attacked?)
    airlift ->
    negotiate -> prevent attacks between current and another player until end of turn

     */


    for (int i = 0; i < AddedPlayerList.size(); i++) {
        AddedPlayerList[i]->setPhase("Issue Orders");

        string playerName = AddedPlayerList[i]->getPlayerName();
        vector<Card *> currentPlayerHandCards = AddedPlayerList[i]->getHand()->vectorHand;
        string type;
        string answer;


        while (answer != "n")
        {
            cout << "Player " << playerName << ", it is your turn\n" << endl;
            cout << "type : advance|| deploy|| bomb || blockade || airlift||  ";
            cout << "Input your desired order here: ";
            cin >> type;
    }

        ////////////////////////////////////////////////////old code

        while (answer != "n")
        {
            cout << "Player " << playerName << ", it is your turn\n" << endl;
            cout << "type : advance|| deploy|| bomb || blockade || airlift||  ";
            cout << "Input your desired order here: ";
            cin >> type;

            // If input is advance or deploy it calls issueOrder
            if (type == "advance" || type == "deploy")
            {
                AddedPlayerList[i]->issueOrder(type);
            }

                // If input is any of these it will loop through player's hands to see if card exists and play it as well as add it
                // to orders list
            else if(type == "bomb" || type == "blockade" || type == "airlift" || type == "negotiate")
            {
                cout << currentPlayerHandCards.size() << endl;
                AddedPlayerList[i]->issueOrder(type);

                // If hand is empty output error message
                if(currentPlayerHandCards.empty())
                {
                    cout << "Invalid order! Your hand is empty!!" << endl;
                }
            }

            else
            {
                cout << "Invalid order!" << endl;
            }

            // asks user if he/she desires to issue a new order, if no, his or her turn ends and goes to next player in queue
            cout << "Would you like to issue another order? (yes or no)" << endl;
            cin >> answer;
            if(answer == "no")
            {
                break;
            }
            cout << "\n" << endl;
        }
    }

}

//orders executionPhase

void GameEngine::ordersExecutionPhase() {
    Deck *deck = new Deck();
    int beforeTerritoryListSize; //how many territories owned before
    int afterTerritoryListSize;  //how many territories owned after

     //1:deploy NEED TO CHECK IF REINFORCEMENT POOL IS EMPTY OTHERWISE CANNOT EXECUTE OTHER ORDERS
    for (int i = 0; i < AddedPlayerList.size(); i++)
    {
        AddedPlayerList[i]->setPhase("Execute Orders DEPLOY (1st priority)");

        beforeTerritoryListSize = AddedPlayerList[i]->getTerritories().size();
        OrdersList currentPlayerOrdersList = AddedPlayerList[i]->getOrdersList();

        // If player's order list is empty do not display
        if(AddedPlayerList[i]->getOrdersList().getOrdersListSize() != 0)
        {
            AddedPlayerList[i]->setPhase("Execute Orders DEPLOY (1st priority)");

        }

        // looping through player's order list
        for (int j = 0; j < currentPlayerOrdersList.getOrdersListSize(); j++)
        {
            if (currentPlayerOrdersList.getOrder(j)->getLabel() == "deploy")
            {
                //execute deploy actions here
                currentPlayerOrdersList.getNextOrder()->execute();
            }
        }
        afterTerritoryListSize = AddedPlayerList[i]->getTerritories().size();
        if(afterTerritoryListSize - beforeTerritoryListSize){ // player receives card at end of turn if they conquer at least one territory during thier turn
            deck->draw();
        }
    }

    // 2: airlift
    for (int i = 0; i < AddedPlayerList.size(); i++)
    {
        if(AddedPlayerList[i]->getOrdersList().getOrdersListSize() != 0)
        {
            AddedPlayerList[i]->setPhase("Execute Orders: AIRLIFT(2)");

        }

        OrdersList currentPlayerOrdersList = AddedPlayerList[i]->getOrdersList();

        for (int j = 0; j < currentPlayerOrdersList.getOrdersListSize(); j++)
        {
            if (currentPlayerOrdersList.getNextOrder()->getLabel() == "airlift")
            {
                //execute airlift actions here
                currentPlayerOrdersList.getNextOrder()->execute();
            }
        }
    }

    // 3: blockade and the others
    for (int i = 0; i < AddedPlayerList.size(); i++)
    {
        if(AddedPlayerList[i]->getOrdersList().getOrdersListSize() != 0)
        {
            AddedPlayerList[i]->setPhase("Execute Orders: BLOCKADE (3rd)");

        }

        OrdersList currentPlayerOrdersList = AddedPlayerList[i]->getOrdersList();

        for (int j = 0; j < currentPlayerOrdersList.getOrdersListSize(); j++)
        {
            if (currentPlayerOrdersList.getOrder(j)->getLabel() == "blockade")
            {
                //execute blockade actions here
                currentPlayerOrdersList.getOrder(j)->execute();
            }
        }
    }

    // 4: rest of the orders executed in this block
    for (int i = 0; i < AddedPlayerList.size(); i++)
    {
        if(AddedPlayerList[i]->getOrdersList().getOrdersListSize() != 0)
        {
            AddedPlayerList[i]->setPhase("Execute Orders: executing the rest according to their order in the list");

        }

        OrdersList currentPlayerOrdersList = AddedPlayerList[i]->getOrdersList();

        for (int j = 0; j < currentPlayerOrdersList.getOrdersListSize(); j++)
        {
            if (currentPlayerOrdersList.getOrder(j)->getLabel() == "advance")
            {
                //execute advance actions here
                currentPlayerOrdersList.getOrder(j)->execute();
            }

            if (currentPlayerOrdersList.getOrder(j)->getLabel() == "bomb")
            {
                //execute bomb actions here
                currentPlayerOrdersList.getOrder(j)->execute();
            }

            if (currentPlayerOrdersList.getOrder(j)->getLabel() == "negotiate")
            {
                //execute negotiate actions here
                currentPlayerOrdersList.getOrder(j)->execute();
            }
        }
    }

}
string GameEngine::stringToLog() {
    return "Game Engine: new state is " + stateToString(this->getCurrentState());
}

CommandProcessing* GameEngine::getCommandProcessor() {
    return this->commandProcessor;
}

void GameEngine::mainGameLoop() {
    //test local variables will change;
    int numPlayers = AddedPlayerList.size();

    //indicates its first round
    bool firstRound = true;

    //the loop continues until one person owns all territories on map
    while (numPlayers != 1) {
        //If a players territoryList size is 0, he/she is removed from the game because he/she no longer controls at least 1 territory
        //Iterating through GameEngine's list of players
        for (int i = 0; i < AddedPlayerList.size(); i++) {
            if (AddedPlayerList[i]->getTerritories().empty()) {
                delete AddedPlayerList[i];
                AddedPlayerList[i]= nullptr;
                std::cout << " you have lost all your territories and have been eliminated\n" << std::endl;
            }
        }

        if (!firstRound)// reinforcement phase is skipped during the first round
        {
            // Reinforcement Phase
            reinforcementPhase();
        }

        // Issuing Orders Phase
        issuingOrdersPhase();

        // Orders Execution Phase
        ordersExecutionPhase();
        //not first round anymore after orders execution phase
        firstRound = false;


    }
}