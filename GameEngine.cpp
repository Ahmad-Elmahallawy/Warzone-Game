
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "GameEngine.h"
#include "Command/CommandProcessor.h"
#include "Players/Player.h"
#include "Map/Map.h"
#include "Cards/Cards.h"


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


GameEngine::GameEngine():currentState(START), commandProcessor(new CommandProcessor()) {
    srand(time(nullptr));

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


void GameEngine::gameStart() {
    if (AddedPlayerList.size() < 2) {

        cout << "Cannot start the game with less than 2 players" << endl;
        return;
    }

    cout << "Part a: Distributing territories " << endl;

    // Allocates one territory to each player. Each territory allocated are equidistant from each other
    int numTerritories = ml->getNumberOfTerritories();
    int gap = numTerritories / (int)AddedPlayerList.size();
    int playersIndex = 0;

    for(int i = 0; i < numTerritories ; i++)
    {
        Territory t = ml->gameMap->listOfTerritories[i];
        AddedPlayerList[playersIndex % AddedPlayerList.size()]->setTerritories(t);

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
        }
    }


    cout << "\nDrew two cards from the deck for each player..." << endl;
}

// transition to the next state if the command is valid
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

                return currentState;  // Return the new state
            }
        }
    }

    std::cout << "Invalid transition from state: " << stateToString(currentState)
              << " with command: " << commandToString(command) << std::endl;

    // Return the current state if no valid transition is found
    Notify(this);
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
                gameStart();
                currentState = transition(CMD_GAME_START);
                break;
            default:
                std::cout << "Invalid command. Try again." << std::endl;
                break;
        }
        delete command;
    }


    std::cout << "Game has ended." << std::endl;
}

// returns the current state of the game
GameEngine::State GameEngine::getCurrentState() {
    return currentState;
}

// display the valid commands user can enter
//void GameEngine::printValidCommands() {
  //  std::cout << "Valid commands for state " << stateToString(currentState) << ":" << std::endl;
    //for (const auto &transition : stateTransitions[currentState]) {
      //  std::cout << commandToString(transition.command) << std::endl;
 //   }
//}

// returns true if the state is equal to end
bool GameEngine::isGameComplete() {
    return currentState == END;
}

GameEngine::~GameEngine() {
    delete commandProcessor;
    delete ml;

    for (int i = 0; i < AddedPlayerList.size(); i++) {
        delete AddedPlayerList[i];
        AddedPlayerList[i] = NULL;
    }


    AddedPlayerList.clear();

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
        case CMD_GAME_START: return "gamestart";
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
    return CMD_UNDEFINED;
}

string GameEngine::stringToLog() {
    return "Game Engine: new state is " + stateToString(this->getCurrentState());
}

CommandProcessor* GameEngine::getCommandProcessor() {
    return this->commandProcessor;
}