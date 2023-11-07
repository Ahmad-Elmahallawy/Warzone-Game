// GameEngine.cpp
#include "GameEngine.h"
#include "players\player.h"
#include "Map\Map.h"
#include "Cards\Cards.h"

GameEngine::GameEngine() {
    // current state when the game runs
    currentState = START;

    // Initialize the state transition map
    stateTransitions[START] = {{CMD_START, MAP_LOADED}};
    stateTransitions[MAP_LOADED] = {{CMD_LOAD_MAP, MAP_LOADED}, {CMD_VALIDATE_MAP, MAP_VALIDATED}};
    stateTransitions[MAP_VALIDATED] = {{CMD_ADD_PLAYER, PLAYERS_ADDED}};
    stateTransitions[PLAYERS_ADDED] = {{CMD_ADD_PLAYER, PLAYERS_ADDED}, {CMD_ASSIGN_COUNTRIES, ASSIGN_REINFORCEMENTS}};
    stateTransitions[ASSIGN_REINFORCEMENTS] = {{CMD_ISSUE_ORDER, ISSUE_ORDERS}};
    stateTransitions[ISSUE_ORDERS] = {{CMD_ISSUE_ORDER, ISSUE_ORDERS}, {CMD_END_ISSUE_ORDER, EXECUTE_ORDERS}};
    stateTransitions[EXECUTE_ORDERS] = {{CMD_EXEC_ORDER, EXECUTE_ORDERS}, {CMD_END_EXEC_ORDERS, ASSIGN_REINFORCEMENTS}, {CMD_WIN, WIN}};
    stateTransitions[WIN] = {{CMD_PLAY, START}, {CMD_END, END}};
}

// function definition to check if the command is valid to transition to the next state
bool GameEngine::isValidTransition(Command command) {
    for (const auto &transition : stateTransitions[currentState]) {
        if (transition.command == command) {
            return true;
        }
    }
    return false;
}


// transition to the next state if the command is valid
void GameEngine::transition(Command command) {
    if (isValidTransition(command)) {
        for (const auto &transition : stateTransitions[currentState]) {
            if (transition.command == command) {
                currentState = transition.nextState;
                break;
            }
        }
    } else {
        std::cout << "Invalid state transition." << std::endl;
    }
}

// returns the current state of the game
State GameEngine::getCurrentState() {
    return currentState;
}

// display the valid commands user can enter
void GameEngine::printValidCommands() {
    std::cout << "Valid commands for state " << stateToString(currentState) << ":" << std::endl;
    for (const auto &transition : stateTransitions[currentState]) {
        std::cout << commandToString(transition.command) << std::endl;
    }
}

// returns true if the state is equal to end
bool GameEngine::isGameComplete() {
    return currentState == END;
}

// converts state enum value to string
std::string stateToString(State state) {
    switch (state) {
        case START: return "start";
        case MAP_LOADED: return "map loaded";
        case MAP_VALIDATED: return "map validated";
        case PLAYERS_ADDED: return "players added";
        case ASSIGN_REINFORCEMENTS: return "assign reinforcement";
        case ISSUE_ORDERS: return "issue orders";
        case EXECUTE_ORDERS: return "execute orders";
        case WIN: return "win";
        case END: return "end";
        default: return "UNKNOWN_STATE";
    }
}

// converts command to string
std::string commandToString(Command command) {
    switch (command) {
        case CMD_START:
            return "start";
        case CMD_LOAD_MAP:
            return "loadmap";
        case CMD_VALIDATE_MAP:
            return "validatemap";
        case CMD_ADD_PLAYER:
            return "addplayer";
        case CMD_ASSIGN_COUNTRIES:
            return "assigncountries";
        case CMD_ISSUE_ORDER:
            return "issueorder";
        case CMD_END_ISSUE_ORDER:
            return "endissueorder";
        case CMD_EXECUTE_ORDERS:
            return "executeorders";
        case CMD_END_EXEC_ORDERS:
            return "endexecorders";
        case CMD_WIN:
            return "win";
        case CMD_END:
            return "end";
        case CMD_PLAY:
            return "play";
        case CMD_EXEC_ORDER:
            return "execorder";
        default:
            return "UNKNOWN_COMMAND";
    }
}



//void GameEngine::getMaps()
//{
//    for (int j = 0; j < Map.size(); j++)
//    {
//        int mapNb = j + 1;
//        cout << mapNb << ": " << mapList[j] << endl;
//    }
//}

void GameEngine::mainGameLoop() {
    //test local variables will change;
    int numPlayers = 2;

    players[numPlayers];
    Player *players[5] = {};
    bool firstRound = true;


    //the loop continues until one person owns all territories on map
    while (numPlayers != 1) {
        //If a players territoryList size is 0, he/she is removed from the game because he/she no longer controls at least 1 territory
        //Iterating through GameEngine's list of players
        for (int i = 0; i < PLAYERS_ADDED; i++) {
            if (players[i]->getTerritories().empty()) {
                std::cout << " Sorry you have lost all your territories and is therefore eliminated\n" << std::endl;
            }
        }

        if (!firstRound)// reinforcement phase is skipped during the first round
        {
            // Reinforcement Phase
            reinforcementPhase();
        }

        // Issuing Orders Phase
        issueOrdersPhase();

        // Orders Execution Phase
        ordersExecutionPhase();

        firstRound = false;

    }
}


void GameEngine:: reinforcementPhase() {
    /*Players are given a number of army units that depends on the number of
    territories they own, (# of territories owned divided by 3, rounded down). If the player owns all the
    territories of an entire continent, the player is given a number of army units corresponding to the
    continent’s control bonus value. In any case, the minimal number of reinforcement army units per turn for
    any player is 3. These army units are placed in the player’s reinforcement pool. This must be
    implemented in a function/method named reinforcementPhase() in the game engine.
     */

    for (int i = 0; i < players.size(); i++) {
        players[i]->setPhase("Reinforcement");
        cout << "Player: " << players[i]->getPlayerId() << "'s old Reinforcement Pool: "
             << players[i]->getReinforcementPool();
        // if (number of territories owned) / 3 is less than 3, assigns 3 to the player reinforcement pool
        if (((players[i]->getTerritories().size()) / 3) < 3) // removed round
        {
            cout << "| Player: " << players[i]->getPlayerId() << "'s updated Reinforcement Pool: ";
            players[i]->setReinforcementPool(players[i]->getReinforcementPool() + 3);
            cout << players[i]->getReinforcementPool() << endl;
        }

            //check if players owned number of territories matches a continent that hold n amount of territories in order to gain control bonus
        else if (players[i]->ownAllTerritoryInContinent()) {
            cout << "| Player: " << players[i]->getPlayerId() << "'s updated Reinforcement Pool: ";
            players[i]->setReinforcementPool(players[i]->getReinforcementPool() + 10);
            cout << players[i]->getReinforcementPool() << endl;
        } else {
            cout << "| Player: " << players[i]->getPlayerId() << "'s updated Reinforcement Pool: ";
            players[i]->setReinforcementPool(players[i]->getReinforcementPool() +
                                             ((players[i]->getTerritories().size()) / 3)); // removed round
            cout << players[i]->getReinforcementPool() << endl;
        }

    }
}

void GameEngineissueOrdersPhase() {
    /*deploy -> put armies in a territory
    advance -> moves a specified number of armies between adjacent territories, if its a player territory, armies get transferred
    to that territory, if its an enemy territory, an attack happens between the 2 territories
    bomb -> destroy half of the armies located on an opponent's territory that is adjacent to one of player's territory
    blockade -> triple number of armies on one of player's current territory and make it a neutral territory (cannot be attacked?)
    airlift ->
    negotiate -> prevent attacks between current and another player until end of turn

     */

    int numPlayers = 2;


    Player *players[5] = {};
    bool firstRound = true;

    for (int i = 0; i < players.size(); i++)
    {
        players[i]->setPhase("Issue Orders");

        int pID = players[i]->getPlayerId();
        vector<Card *> currentPlayerHandCards = players[i]->getHand()->vectorHand;
        string type;
        string answer;

        while (answer != "n")
        {
            cout << "Player " << pID << ", it is your turn to make a move! Make an order of your choice!\n" << endl;
            cout << "Input your desired order here: ";
            cin >> type;

            // If input is advance or deploy it calls issueOrder
            if (type == "advance" || type == "deploy")
            {
                players[i]->issueOrder(type);
            }

                // If input is any of these it will loop through player's hands to see if card exists and play it as well as add it
                // to orders list
            else if(type == "bomb" || type == "blockade" || type == "airlift" || type == "negotiate")
            {
                cout << currentPlayerHandCards.size() << endl;

                // If hand is empty output error message
                if(currentPlayerHandCards.size() == 0)
                {
                    cout << "Invalid order! Your hand is empty!!" << endl;
                }

                // looping through player's hand to find appropriate card
                for (int j = 0; j < currentPlayerHandCards.size(); j++)
                {
                    if (currentPlayerHandCards[j]->getCard() == type)
                    {
                        players[i]->play(deck, currentPlayerHandCards[j]);
                    }

                    else
                    {
                        cout << "Such a card does not exist in your deck!" << endl;
                    }
                }
            }

            else
            {
                cout << "Invalid order!" << endl;
            }

            // asks user if he/she desires to issue a new order, if no, his or her turn ends and goes to next player in queue
            cout << "Would you like to issue another order? Type y for YES or n for NO" << endl;
            cin >> answer;
            if(answer == "no")
            {
                break;
            }
            cout << "\n" << endl;
        }
    }

}

void GameEngine::ordersExecutionPhase() {
    int beforeTerritoryListSize;
    int afterTerritoryListSize;
    // 1:deploy NEED TO CHECK IF REINFORCEMENT POOL IS EMPTY OTHERWISE CANNOT EXECUTE OTHER ORDERS
    for (int i = 0; i < players.size(); i++)
    {
        players[i]->setPhase("Execute Orders DEPLOY (1st priority)");

        beforeTerritoryListSize = players[i]->getTerritoryList()->size();
        OrdersList currentPlayerOrdersList = players[i]->getOrdersList();

        // If player's order list is empty do not display
        if(players[i]->getOrdersList().getOrdersListSize() != 0)
        {
            players[i]->setPhase("Execute Orders DEPLOY (1st priority)");

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
        afterTerritoryListSize = players[i]->getTerritoryList()->size();
        if(afterTerritoryListSize - beforeTerritoryListSize){ // if the player conquered at least one territory, they can draw a card
            deck->draw();
        }
    }

    // 2: airlift
    for (int i = 0; i < players.size(); i++)
    {
        if(players[i]->getOrdersList().getOrdersListSize() != 0)
        {
            players[i]->setPhase("Execute Orders: AIRLIFT (2nd priority)");

        }

        OrdersList currentPlayerOrdersList = players[i]->getOrdersList();

        for (int j = 0; j < currentPlayerOrdersList.getOrdersListSize(); j++)
        {
            if (currentPlayerOrdersList.getNextOrder()->getLabel() == "airlift")
            {
                //execute airlift actions here
                currentPlayerOrdersList.getNextOrder()->execute();
            }
        }
    }

    // 3: blockade
    for (int i = 0; i < players.size(); i++)
    {
        if(players[i]->getOrdersList().getOrdersListSize() != 0)
        {
            players[i]->setPhase("Execute Orders: BLOCKADE (3rd priority)");

        }

        OrdersList currentPlayerOrdersList = players[i]->getOrdersList();

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
    for (int i = 0; i < players.size(); i++)
    {
        if(players[i]->getOrdersList().getOrdersListSize() != 0)
        {
            players[i]->setPhase("Execute Orders: executing the rest according to their order in the list");

        }

        OrdersList currentPlayerOrdersList = players[i]->getOrdersList();

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









