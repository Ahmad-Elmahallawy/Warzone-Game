// GameEngine.cpp
#include "GameEngine.h"
#include "Command/CommandProcessing.h"
#include <iostream>
#include <vector>
#include <algorithm> // include for case-insensitive string comparison

using namespace std;

#include "gameengine.h"

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
                               {CMD_ASSIGN_COUNTRIES, State::ASSIGN_REINFORCEMENTS}
                       }},
        {State::ASSIGN_REINFORCEMENTS, {
                               {CMD_ISSUE_ORDER, State::ISSUE_ORDERS}
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


GameEngine::GameEngine():currentState(START), commandProcessor(new CommandProcessing()), currentMap(nullptr) {

}





// transition to the next state if the command is valid

void GameEngine::transition(Commands command) {
    auto transitionIterator = stateTransitions.find(currentState);

    if (transitionIterator != stateTransitions.end()) {
        for (const auto &transition : transitionIterator->second) {
            std::cout << "Checking transition: " << stateToString(currentState)
                      << " -> " << stateToString(transition.nextState)
                      << " with command: " << commandToString(transition.command) << std::endl;
            if (transition.command == command) {
                currentState = transition.nextState;
                std::cout << "Transitioning to state: " << stateToString(currentState) << std::endl;
                return;
            }
        }
    }

    std::cout << "Invalid transition from state: " << stateToString(currentState)
              << " with command: " << commandToString(command) << std::endl;
}




// command to enter players in the game
void GameEngine::addPlayer(string playerName)
{

    // check if a playername is empty
    if(playerName.empty())
    {
        commandProcessor->getCommand()->saveEffect("Your name cannot be empty");
        cout << commandProcessor->getCommand()->getEffect() << endl;
        return;
    }

    // check if there are more than 6 players
    if(AddedPlayerList.size() > 6)
    {
        commandProcessor->getCommand()->saveEffect("Number of players can not exceed 6. You can not add more players");
        cout << commandProcessor->getCommand()->getEffect() << endl;
        return;
    }

    for (Player* p : AddedPlayerList) {
        if (p->getPlayerName() == playerName) { //check if 2 names are the same

            commandProcessor->getCommand()->saveEffect("The player's name is already taken");
            cout << commandProcessor->getCommand()->getEffect() << endl;
            return;
        }
    }

    // creating a player and adding it to the list of players
    Player* player = new Player(playerName);
    AddedPlayerList.push_back(player);

}


void GameEngine::gameStart() {
    if (AddedPlayerList.size() < 2) {
        commandProcessor->getCommand()->saveEffect("Cannot start the game with less than 2 players");
        cout << commandProcessor->getCommand()->getEffect() << endl;
        return;
    }

    cout << "Part a: Distributing territories " << endl;

    // Allocates one territory to each player. Each territory allocated are equidistant from each other
    int numTerritories = (int)this->currentMap->listOfTerritories.size();
    int gap = numTerritories / (int)AddedPlayerList.size();
    int playersIndex = 0;

    for(int i = 0; i < numTerritories ; i++)
    {
        Territory* t = &(currentMap->listOfTerritories[i]);
        AddedPlayerList[playersIndex % AddedPlayerList.size()]->setTerritories(t);
        playersIndex++;
    }

    // Randomizes the order of players
    vector<Player*> orderedPlayers;
    while(AddedPlayerList.size() != 0) {
        int index = rand() % AddedPlayerList.size();
        orderedPlayers.push_back(AddedPlayerList[index]);
        AddedPlayerList.erase(AddedPlayerList.begin() + index);
    }

    this->AddedPlayerList = orderedPlayers;

    cout << "Determined the order of play is shown below: " << endl;
    for(int i = 0; i < orderedPlayers.size() ; i++) {
        cout << "Player #: " << i + 1 << " with name " << orderedPlayers[i]->getPlayerName();
    }

    // add 50 armies to each player's reinforcement pool
    for (int i = 0; i < orderedPlayers.size(); i++)
    {
        orderedPlayers[i]->setReinforcementPool(50);
    }

    cout << "\nAdded 50 armies to each player's reinforcement pool..." << endl;

    // Draws two cards from the deck for each player
    Deck* deck = new Deck();

    Card* card1, *card2;
    for(int i = 0; i < orderedPlayers.size() ; i++)
    {
        card1 = deck->draw();
        card2 = deck->draw();
        orderedPlayers[i]->getHand()->returnCard(*card1);
        orderedPlayers[i]->getHand()->returnCard(*card2);
    }
    delete deck;
    deck = nullptr;
    delete card1;
    card1 = nullptr;
    delete card2;
    card2 = nullptr;

    cout << "\nDrew two cards from the deck for each player..." << endl;
}


// Implementation of GameEngine class
void GameEngine::startupPhase() {

    while (currentState != ASSIGN_REINFORCEMENTS) {
        Command* command = commandProcessor->getCommand();

        if (command == NULL) {
            cout << "No command was input." << endl;
            exit(0);
        }


        // Validate the command
        if (!commandProcessor->validate(command,this->currentState)) {
            std::cout << "Invalid command. Try again." << std::endl;
            continue;
        }
        currentState = stringToState(command->getCommand());
        cout << "Current state: " << command->getCommand() << std::endl;

        int numberOfVertices = testLoadMaps(command->secondParameter);
        MapLoader ml(numberOfVertices, command->secondParameter);
        // Process the command and change game state accordingly
        if (command->getCommand().compare("loadmap")) {
            // Load the map
            ml.firstRun();
        } else if (command->getCommand().compare("validatemap")) {
            // Validate the map
            ml.secondRun();
        } else if (command->getCommand().compare("addplayer")) {
            addPlayer(command->secondParameter);
        } else if (command->getCommand().compare("gamestart")) {
            gameStart();
        } else {
            std::cout << "Invalid command. Try again." << std::endl;
        }

        transition(commandToEnum(command->getCommand()));

    }

    std::cout << "Game has ended." << std::endl;
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

GameEngine::~GameEngine() {
    delete commandProcessor;
    delete currentMap;

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
        default: return "UNKNOWN_STATE";
    }
}

// converts command to string
std::string commandToString(Commands command) {
    switch (command) {
        case CMD_START: return "start";
        case CMD_LOAD_MAP: return "loadmap";
        case CMD_VALIDATE_MAP: return "validatemap";
        case CMD_ADD_PLAYER: return "addplayer";
        case CMD_ASSIGN_COUNTRIES: return "assigncountries";
        case CMD_ISSUE_ORDER: return "issueorder";
        case CMD_END_ISSUE_ORDER: return "endissueorder";
        case CMD_EXECUTE_ORDERS: return "executeorders";
        case CMD_END_EXEC_ORDERS: return "endexecorders";
        case CMD_WIN: return "win";
        case CMD_END: return "end";
        case CMD_PLAY: return "play";
        case CMD_EXEC_ORDER: return "execorder";
        default: return "UNKNOWN_COMMAND";
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
    } else if (commandStr == "assigncountries") {
        return CMD_ASSIGN_COUNTRIES;
    } else if (commandStr == "issueorder") {
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

