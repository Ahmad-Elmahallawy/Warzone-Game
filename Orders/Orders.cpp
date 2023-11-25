#include "Orders.h"
#include <iostream>
#include <string>
//   ---   Order class   ---


/**
 *  The labels of the orders, which are constant and static.
 */
const std::string Deploy::label = "deploy";
const std::string Advance::label = "advance";
const std::string Bomb::label = "bomb";
const std::string Blockade::label = "blockade";
const std::string Airlift::label = "airlift";
const std::string Negotiate::label = "negotiate";


// Default constructor
Order::Order() : executed(false), player(nullptr), targetTerritory(nullptr), armiesToDeploy(0) {}

// Parameter constructor
Order::Order(Player* player, Territory* targetTerritory, int armiesToDeploy)
        : player(player), targetTerritory(targetTerritory), armiesToDeploy(armiesToDeploy) {
}

// Copy constructor
Order::Order(const Order& order)
        : action(order.action), executed(order.executed), player(order.player), targetTerritory(order.targetTerritory), armiesToDeploy(order.armiesToDeploy) {}

// Destructor
Order::~Order() {
    delete sourceTerritory;
}

// Validate method
bool Order::validate() { return true; }

string Order::getAction() {
    return this->action;
}

// Execute method
void Order::execute() { this->executed = true; }

// Set the player associated with the order
void Order::setPlayer(Player* player) { this->player = player; }

// Get the player associated with the order
Player* Order::getPlayer() const { return player; }

// Assignment operator
Order& Order::operator=(const Order& order) {
    if (this != &order) {
        this->action = order.action;
        this->executed = order.executed;
        this->player = order.player;
        this->targetTerritory = order.targetTerritory;
        this->armiesToDeploy = order.armiesToDeploy;
    }
    return *this;
}


// Getter and Setter for targetTerritory
Territory* Order::getTargetTerritory() const {
    return targetTerritory;
}
void Order::setTargetTerritory(Territory* territory) {
    targetTerritory = territory;
}

// Getter and Setter for sourceTerritory
Territory* Order::getSourceTerritory() const {
    return sourceTerritory;
}
void Order::setSourceTerritory(Territory* territory) {
    sourceTerritory = territory;
}

// Getter and Setter for armiesToDeploy
int Order::getArmiesToDeploy() const {
    return armiesToDeploy;
}
void Order::setArmiesToDeploy(int armies) {
    armiesToDeploy = armies;
}

// Print helper method for stream insertion operator overload
void Order::print(std::ostream& output) const {
    output << "Order" << std::endl;
}

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& output, const Order& order) {
    order.print(output);
    if (order.executed) {
        output << order.action << std::endl;
    }
    return output;
}

/*
Subclasses of order
The different kinds of orders are: deploy, advance,
bomb, blockade, airlift, and negotiate. All orders must have a validate() method that verifies if the order is valid.
All orders must have an execute() method that will result in some game action being implemented (see the
project description document).
*/


//   ---   Deploy class   ---

// default constructor

// Default constructor for Deploy class
Deploy::Deploy() : Order() {
    this->action = "deploy order";
}

// Parameter constructor for Deploy class
Deploy::Deploy(Player* target, Player* player, int armyCount, Territory* targetLocation, Territory* fromLocation) {
    this->target = target;
    this->player = player;
    this->armiesToDeploy = armyCount;
    this->targetTerritory = targetLocation;
    this->sourceTerritory = fromLocation;
    this->action = "Deploy order";
}

// Copy constructor for Deploy class
Deploy::Deploy(const Deploy& deploy) : Order(deploy) {}

// Destructor for Deploy class
Deploy::~Deploy() {}

// execute method override
void Deploy::execute() {
    if (this->validate()) {
        // Deploy the specified number of army units to the target territory
        targetTerritory->addArmies(armiesToDeploy);

        // subtract from the reinforcement pool
        this->player->setReinforcementPool(-this->armiesToDeploy);

        // setting the action string
        this->action = this->player->getPlayerName() + " deployed " + to_string(this->armiesToDeploy) + " to " + this->targetTerritory->getTerritoryName();
        // Set the order as executed
        this->executed = true;

        std::cout << "Deploy order executed successfully." << std::endl;
        std::cout << this->action << endl;
    }
    Notify(this);
}

// validate method override
bool Deploy::validate() {
    // Check if the target territory exists
    if (!targetTerritory) {
        std::cout << "Player " << player->getPlayerName() << " has invalid Deploy order: Target territory does not exist." << std::endl;
        return false;
    }

    // Check if the target territory belongs to the player issuing the order
    if (targetTerritory->getOwner() != this->getPlayer()) {
        std::cout << "Player " << player->getPlayerName() << " has invalid Deploy order: Target territory does not belong to the player issuing the order." << std::endl;
        return false;
    }

    // if the number of armies to deploy is greater than the reinforcement pool
    if (this->armiesToDeploy > this->getPlayer()->getReinforcementPool()) {
        std::cout << "Player " << player->getPlayerName() << " has invalid Deploy  order: Can not deploy more army than what is in the pool";
        return false;
    }

    // The order is valid
    return true;
}

// Assignment operator override for Deploy class
Deploy& Deploy::operator=(const Deploy& deploy) {
    if (this != &deploy) {
        Order::operator=(deploy);
        // additional assignments specific to Deploy class, if any
    }
    return *this;
}

// Print helper method for stream insertion overload for Deploy class
void Deploy::print(std::ostream& output) const {
    output << "Deploy" << std::endl;
}

// Stream insertion operator overload for Deploy class
std::ostream& operator<<(std::ostream& output, const Deploy& deploy) {
    deploy.print(output);
    if (deploy.executed) {
        output << deploy.action << std::endl;
    }
    return output;
}
//   ---   Advance class   ---

// Default constructor for Advance class
Advance::Advance() : Order() {
    this -> sourceTerritory = nullptr;
    this->action = "Advance order";
}

// Parameter constructor for Advance class
Advance::Advance(Player* target, Player* player, int armyCount, Territory* targetLocation, Territory* fromLocation) {
    this->target = target;
    this->player = player;
    this->armiesToDeploy = armyCount;
    this->targetTerritory = targetLocation;
    this->sourceTerritory = fromLocation;
    this->action = "Advance";

}
// Copy constructor for Advance class
Advance::Advance(const Advance& existingAdvance) : Order(existingAdvance) {
    this->sourceTerritory = existingAdvance.sourceTerritory;
    this->action = existingAdvance.action;
    std::cout << "Advance is added" << std::endl;
}

// Destructor for Advance class
Advance::~Advance() {}

// Advance order execute method
void Advance::execute() {
    if (this->validate()) {
        bool conqueredTerritory = false;
        // Simulate battle
        int attackerUnits = armiesToDeploy;
        int defenderUnits = targetTerritory->getNumberOfArmies();
        const int ATTACK_SUCCESS_RATE = 6; // 60%
        const int DEFENSE_SUCCESS_RATE = 7; // 70%
        // Check if the target territory belongs to another player
        if (targetTerritory->getOwner() != this->getPlayer()) {

            // Simulate battle
            while (attackerUnits > 0 && defenderUnits > 0) {
                // Attacker's success rate: 60%
                if ((rand() % 10) < 6) {
                    if(defenderUnits == 0)
                    {
                        break;
                    }
                    defenderUnits--;
                }

                // Check if defender is still present after the attacker's attack
                if (defenderUnits > 0) {
                    // Defender's success rate: 70%
                    if ((rand() % 10) < 7) {
                        attackerUnits--;
                    }
                }
            }
            // If all defenders are eliminated, the attacker captures the territory
            if (defenderUnits <= 0 && attackerUnits > 0) {
                std::cout << "Attack successful! " << this->getPlayer()->getPlayerName()
                          << " captured " << targetTerritory->getTerritoryName() << std::endl;

                // Move remaining attacker units to the conquered territory
                targetTerritory->setOwner(this->getPlayer());
                target->removeOwnedTerritory(targetTerritory->getTerritoryName());
                player->setTerritories(targetTerritory);
                targetTerritory->addArmies(attackerUnits - targetTerritory->getNumberOfArmies());
                sourceTerritory->addArmies(-attackerUnits);
                action = this->getPlayer()->getPlayerName() + " captured " + this->targetTerritory->getTerritoryName();
                // Set conqueredTerritory to true
                conqueredTerritory = true;
                this->getPlayer()->setCapturedTerritoryThisTurn(conqueredTerritory);

            } else {
                this-> action = "Attack failed! " + targetTerritory->getTerritoryName() + " defended successfully.";
            }
        } else {
            // Move army units from source to target territory
            sourceTerritory->removeArmies(armiesToDeploy);
            targetTerritory->addArmies(armiesToDeploy);
            this->action = this->player->getPlayerName() + " advanced " + std::to_string(this->armiesToDeploy) + " units from " + this->sourceTerritory->getTerritoryName() + " to " + this->targetTerritory->getTerritoryName();

        }

        // Set the order as executed
        this->executed = true;
        // Check if a territory is conquered during the turn to determine card eligibility
        if (conqueredTerritory) {
            Deck deck{};
            Card* c1 = deck.draw();
            // Award a card to the player at the end of their turn
            this->getPlayer()->getHand()->returnCard(*c1);
        }

        std::cout << "Advance order executed successfully." << std::endl;
        cout << action << endl;
    }
    Notify(this);
}

// Advance order validate method
bool Advance::validate() {
    // Check if the source territory exists
    if (!sourceTerritory) {
        std::cout << "Player " << player->getPlayerName() << " has invalid Advance order: Source territory does not exist." << std::endl;
        return false;
    }

    // Check if the source territory belongs to the player issuing the order
    if (sourceTerritory->getOwner() != this->getPlayer()) {
        std::cout << "Player " << player->getPlayerName() << " has invalid Advance order: Source territory does not belong to the player issuing the order." << std::endl;
        return false;
    }

    // Check if the target territory exists
    if (!targetTerritory) {
        std::cout << "Player " << player->getPlayerName() << " has invalid Advance order: Target territory does not exist." << std::endl;
        return false;
    }


    // Check if the target territory is adjacent to the source territory
    bool adjacent = false;
    for(int i = 0;i<sourceTerritory->adjacentTerritories.size();i++){
        if((targetTerritory->getTerritoryName() == sourceTerritory->adjacentTerritories[i].getTerritoryName())){
            adjacent = true;
        }
    }
    if (!adjacent) {
        std::cout << "Player " << player->getPlayerName() << " has invalid Advance order: Source and target territories are not adjacent." << std::endl;
        return false;
    }

    if (this->armiesToDeploy > this->getPlayer()->getReinforcementPool())
    {
        std::cout << "Player " << player->getPlayerName() << " has invalid Advance  order: Can not advance more army than what is in the pool";
    }

    for (Player* p : player->negociatedPlayers) {
        if (p == targetTerritory->getOwner()) {
            cout << "\nFAILED: The target territory owner currently has a negociated contract and cannot be attacked.";
            return false;
        }
    }

    // The order is valid
    return true;
}



// assignment operator override
Advance& Advance::operator=(const Advance& advance) {
    if (this != &advance) {
        Order::operator=(advance);
        this->sourceTerritory = advance.sourceTerritory;
    }
    return *this;
}

// print helper method for stream insertion overload
void Advance::print(std::ostream& output) const {
    output << "Advance" << std::endl;
}

// stream insertion operator overload
std::ostream& operator<<(std::ostream& output, const Advance& advance) {
    advance.print(output);
    if (advance.executed) {
        output << advance.action << std::endl;
    }
    return output;
}

//   ---   Bomb class   ---

// default constructor
Bomb::Bomb()
{
    this->action = "Bomb order";
}

// Parameterized constructor for Bomb
Bomb::Bomb(Player* target, Player* player, int armyCount, Territory* targetLocation, Territory* fromLocation) {
    this->target = target;
    this->player = player;
    this->armiesToDeploy = armyCount;
    this->targetTerritory = targetLocation;
    this->sourceTerritory = fromLocation;
    this->action = "Bomb order";
}

// copy constructor
Bomb::Bomb(const Bomb& existingBomb)
{
    this->action = "Bomb order";
}

// destructor
Bomb::~Bomb() {
}

// validate method override
bool Bomb::validate() {
    // Check if the target territory exists
    if (!targetTerritory) {
        std::cout << "Player " << player->getPlayerName() << " has invalid Bomb order: Target territory does not exist." << std::endl;
        return false;
    }

    // Check if the target territory belongs to the player issuing the order
    if (targetTerritory->getOwner()->getPlayerName() == sourceTerritory->getOwner()->getPlayerName()) {
        std::cout << "Player " << player->getPlayerName() << " has invalid Bomb order: Target territory belongs to the player issuing the order." << std::endl;
        return false;
    }

    // Check if the target territory is adjacent to one of the player's territories
    bool isAdjacent = false;
    for(int i = 0;i<sourceTerritory->adjacentTerritories.size();i++){
        if((targetTerritory->getTerritoryName() == sourceTerritory->adjacentTerritories[i].getTerritoryName())){
            isAdjacent = true;
        }
    }

    if (!isAdjacent) {
        std::cout << "Player " << player->getPlayerName() << " has invalid Bomb order: Target territory is not adjacent to any of the player's territories." << std::endl;
        return false;
    }

    for (Player* p : player->negociatedPlayers) {
        if (p == targetTerritory->getOwner()) {
            cout << "\nFAILED: The target territory owner currently has a negotiated contract and cannot be attacked.";
            return false;
        }
    }

    // The order is valid
    return true;
}

// execute method override
void Bomb::execute() {
    if (this->validate()) {
        // Remove half of the army units from the target territory
        int remainingArmies = targetTerritory->getNumberOfArmies() / 2;
        targetTerritory->removeArmies(remainingArmies);

        // Set the order as executed
        this->executed = true;

        std::cout << "Bomb order executed successfully. Half of the army units removed from "
                  << targetTerritory->getTerritoryName() << "." << std::endl;
    }
    Notify(this);

}

// assignment operator
Bomb& Bomb::operator=(const Bomb& bomb)
{
    this->action = bomb.action;
    this->executed = bomb.executed;

    return *this;
}

// print helper method for stream insertion overload
void Bomb::print(std::ostream& output) const
{
    output << "Bomb" << std::endl;
}

// stream insertion operator overload
std::ostream& operator<<(std::ostream& output, const Bomb& bomb)
{
    bomb.print(output);
    if (bomb.executed)
    {
        output << bomb.action << std::endl;
    }
    return output;
}

//   ---   Blockade class   ---

// default constructor
Blockade::Blockade()
{
    this->action = "Blockade order";
}

// Parameterized constructor for Blockade
Blockade::Blockade(Player* target, Player* player, int armyCount, Territory* targetLocation, Territory* fromLocation) {
    this->target = target;
    this->player = player;
    this->armiesToDeploy = armyCount;
    this->targetTerritory = targetLocation;
    this->sourceTerritory = fromLocation;
    this->action = "Blockade";
}

// copy constructor
Blockade::Blockade(const Blockade& blockade)
{
    this->action = "Blockade order";
}

// destructor
Blockade::~Blockade() {}

// execute method override
void Blockade::execute() {
    if (this->validate()) {

        // Double the number of army units on the target territory
        int currentArmies = targetTerritory->getNumberOfArmies();
        targetTerritory->addArmies(currentArmies);

        // Transfer the ownership of the territory to the Neutral player
        targetTerritory->setOwner(target);

        // Set the order as executed
        this->executed = true;

        std::cout << "Blockade order executed successfully." << std::endl;
    }
    Notify(this);

}

// --- Blockade class validate method ---

// validate method override
bool Blockade::validate() {
    // Check if the target territory exists
    if (!targetTerritory) {
        std::cout << "Invalid Blockade order: Target territory does not exist." << std::endl;
        return false;
    }

    // Check if the target territory belongs to the player issuing the order
    if (targetTerritory->getOwner() != this->getPlayer()) {
        std::cout << "Invalid Blockade order: Target territory does not belong to the player issuing the order." << std::endl;
        return false;
    }

    // Check if the target territory belongs to the neutral player
    if (targetTerritory->getOwner() == target) {
        std::cout << "Invalid Blockade order: Target territory already belongs to the Neutral player." << std::endl;
        return false;
    }

    // The order is valid
    return true;
}




// assignment operator
Blockade& Blockade::operator=(const Blockade& blockade)
{
    this->action = blockade.action;
    this->executed = blockade.executed;

    return *this;
}

// print helper method for stream insertion overload
void Blockade::print(std::ostream& output) const
{
    output << "Blockade" << std::endl;
}

// stream insertion operator overload
std::ostream& operator<<(std::ostream& output, const Blockade& blockade)
{
    blockade.print(output);
    if (blockade.executed)
    {
        output << blockade.action << std::endl;
    }
    return output;
}

//   ---   Airlift class   ---

// default constructor
Airlift::Airlift()
{
    this->action = "Airlift order";
}

Airlift::Airlift(Player* target, Player* player, int armyCount, Territory* targetLocation, Territory* fromLocation) {
    this->target = target;
    this->player = player;
    this->armiesToDeploy = armyCount;
    this->targetTerritory = targetLocation;
    this->sourceTerritory = fromLocation;
    this->action = "Airlift order";

}

// copy constructor
Airlift::Airlift(const Airlift& existingAirlift)
{
    this->action = "Airlift order";
}

// destructor
Airlift::~Airlift() {}

// validate method override
bool Airlift::validate() {
    // Check if the source territory exists
    if (!sourceTerritory) {
        cout <<  "Player " << player->getPlayerName() << " has invalid Airlift order: Source territory does not exist.";
        return false;
    }


    // Check if the target territory exists
    if (!targetTerritory) {
        cout << "Player " << player->getPlayerName() + " has invalid Airlift order: Target territory does not exist.";
        return false;
    }

    // Check if the source territory belongs to the player issuing the order
    if (sourceTerritory->getOwner() != this->getPlayer()) {
       cout << "Player " << player->getPlayerName() << " has invalid Airlift order: Source territory does not belong to the player issuing the order.";
        return false;
    }

    if(armiesToDeploy > sourceTerritory->getNumberOfArmies())
    {
       cout << "Player " << player->getPlayerName() << " has invalid Airlift order: Source territory has less army than what is in the order.";
        return false;
    }

    // Check if the target territory belongs to the player issuing the order
    if (targetTerritory->getOwner() != this->getPlayer()) {
       cout << "Player " << player->getPlayerName() << " has invalid Airlift order: Target territory does not belong to the player issuing the order.";
        return false;
    }

    // The order is valid
    return true;
}

// execute method override
void Airlift::execute() {
    if (this->validate()) {
        // Move army units from source to target territory
        sourceTerritory->removeArmies(armiesToDeploy);
        targetTerritory->addArmies(armiesToDeploy);

        // Set the order as executed
        this->executed = true;
        action = this->getPlayer()->getPlayerName() + " has ordered an Airlist, army units will move from " + sourceTerritory->getTerritoryName() + " to " + targetTerritory->getTerritoryName()
                 + ". The number of units moved: " + to_string(armiesToDeploy);

        std::cout << "Airlift order executed successfully." << std::endl;
        cout << action << endl;
    }
    Notify(this);

}

// assignment operator
Airlift& Airlift::operator=(const Airlift& airlift)
{
    this->action = airlift.action;
    this->executed = airlift.executed;

    return *this;
}

// print helper method for stream insertion overload
void Airlift::print(std::ostream& output) const
{
    output << "Airlift" << std::endl;
}

// stream insertion operator overload
std::ostream& operator<<(std::ostream& output, const Airlift& airlift)
{
    airlift.print(output);
    if (airlift.executed)
    {
        output << airlift.action << std::endl;
    }
    return output;
}

//   ---   Negotiate class   ---

// default constructor
Negotiate::Negotiate()
{
    this->action = "Negotiate order";
}
Negotiate::Negotiate(Player* target, Player* player, int armyCount, Territory* targetLocation, Territory* fromLocation) {
    this->target = target;
    this->player = player;
    this->armiesToDeploy = armyCount;
    this->targetTerritory = targetLocation;
    this->sourceTerritory = fromLocation;
    this->action = "Negotiate order";
}


// copy constructor
Negotiate::Negotiate(const Negotiate& existingNegotiate)
{
    this->action = "Negotiate order";
}


// destructor
Negotiate::~Negotiate() {}

// validate method override
bool Negotiate::validate()
{
    if (targetTerritory->getOwner() == this->getPlayer()) {
        std::cout << "Player " << player->getPlayerName() << " has invalid target territory belongs to the same player issuing negotiate " << std::endl;
        return false;
    }
    else{
        std::cout << "success: negotiate order validated " << std::endl;
        return true;
    }
}

// execute method override
void Negotiate::execute()
{
    if (this->validate())
    {
        player->addPlayerToNegociatedList(targetTerritory->getOwner());
    }
    Notify(this);
}

// assignment operator
Negotiate& Negotiate::operator=(const Negotiate& negotiate)
{
    this->action = negotiate.action;
    this->executed = negotiate.executed;

    return *this;
}

// print helper method for stream insertion overload
void Negotiate::print(std::ostream& output) const
{
    output << "Negotiate" << std::endl;
}

// stream insertion operator overload
std::ostream& operator<<(std::ostream& output, const Negotiate& negotiate)
{
    negotiate.print(output);
    if (negotiate.executed)
    {
        output << negotiate.action << std::endl;
    }
    return output;
}



// default constructor
OrdersList::OrdersList()
{
    std::cout << "OrdersList created " << std::endl;
}

// copy constructor
OrdersList::OrdersList(const OrdersList& ordersList)
{
    this->ordersList = ordersList.ordersList;
}

OrdersList::~OrdersList()
{
    // change all the pointers to nullptr
    for (Order* order : ordersList)
    {
        delete order;
    }
    ordersList.clear();
}

// add an order to the list
void OrdersList::addOrder(Order* order)
{
    this->ordersList.push_back(order);
    Notify(this);
}

// get next order on the list
Order* OrdersList::getNextOrder()
{
    std::cout << "getNextOrder() was called\n" << std::endl;

    // if list not empty, pop and return next order
    if (!ordersList.empty())
    {
        Order* nextOrderPtr = ordersList.front();
        ordersList.pop_front();
        return nextOrderPtr;
    }
    else
    {   // if list is empty, print a message
        std::cout << " -- Order list is empty !" << std::endl;
        return nullptr;
    }
}
//get order in orderlist by index
Order* OrdersList::getOrder(int index) {
    if (index < getOrdersListSize() && index >= 0) {
        return ordersList[index];
    }
    return nullptr;
}

// remove an order from the list [takes an int, which is a menu number]
void OrdersList::remove(int num)
{
    // index is one less than menu numbering
    num--;

    this->ordersList.erase(this->ordersList.begin() + num);

    std::cout << "an order was removed\n" << std::endl;
}
//getting number of orders in size
int OrdersList::getOrdersListSize()
{
    return ordersList.size();
}

// swap two orders in the list [takes two ints, which are menu numbers]
void OrdersList::move(int a, int b)
{
    // index is one less than menu numbering
    a--;
    b--;

    Order* temp = this->ordersList[a];

    this->ordersList[a] = this->ordersList[b];
    this->ordersList[b] = temp;

    std::cout << "orders were swapped\n" << std::endl;
}

// assignment operator
OrdersList& OrdersList::operator=(const OrdersList& orderslist)
{
    this->ordersList = orderslist.ordersList;

    return *this;
}

int OrdersList::getSize() {
    return ordersList.size();
}

deque<Order *> OrdersList::getOrderList() {
    return ordersList;
}

//return the order's names
//string OrdersList::getList() {
//
//    string t1;
//    if(ordersList.empty())
//       return " Orderlist is empty.";
//    else {
//        t1 += " Orderlist contains: { ";
//        for (const auto &order: this->ordersList) {
//            t1 +=  order->getAction() + ", ";
//        }
//        t1 += "}.";
//        return t1;
//    }
//    return " ";
//}

string OrdersList::getList() {
    string t1;
    if (ordersList.empty())
        return " Orderlist is empty.";
    else {
        t1 += " Orderlist contains: { ";
        for (const auto &order : this->ordersList) {
            if (order) {
                t1 += order->getAction() + ", ";
            } else {
                return " nullpoointer or invalid object";
            }
        }
        t1 += "}.";
        return t1;
    }
}

void OrdersList::restart() {
    for (auto & i : ordersList) {
        delete i;
    }
    ordersList.clear();
}

string OrdersList::stringToLog() {
    Order* o1 = ordersList.back();
    string s1 = "Order Issue: player added " + o1->getAction() +" to their order list. The updated list contains: ";

    for(int i = 0; i < ordersList.size(); i++) {
        s1 += this->ordersList.at(i)->getAction();
        if(i != this->getSize() - 1)
            s1 += ", ";
    }
    s1 += ".";
    return s1;
}

// stream insertion operator overload
std::ostream& operator<<(std::ostream& output, const OrdersList& orderslist)
{
    // creates a temporary copy of orderlist and traverse it to print it out
    std::deque<Order*> temp = orderslist.ordersList;
    int i = 1;
    while (!temp.empty())
    {
        Order* tempObj = temp.front();
        std::cout << std::to_string(i) + ": ";
        std::cout << *tempObj << std::endl;
        temp.pop_front();
        i++;
    }

    return output;
}

/**
 * Returns the label of the order.
 * @return
 */
std::string Deploy::getLabel() const
{
    return label;
}

/**
 * Returns the label of the order.
 * @return
 */
std::string Advance::getLabel() const
{
    return label;
}

/**
 * Returns the label of the order.
 * @return
 */
std::string Bomb::getLabel() const
{
    return label;
}

/**
 * Returns the label of the order.
 * @return
 */
std::string Blockade::getLabel() const
{
    return label;
}

/**
 * Returns the label of the order.
 * @return
 */
std::string Airlift::getLabel() const
{
    return label;
}

/**
 * Returns the label of the order.
 * @return
 */
std::string Negotiate::getLabel() const
{
    return label;
}

string Deploy::stringToLog() {
    string order;

    if(validate()) {
        order = "Order Executed: Deploy!";
    }
    else
        order = "Invalid deploy execution! Territory doesn't belong to the player.";
    return order;
}

string Advance::stringToLog() {
    string order;

    if(validate()) {
        order = "Order Executed: Advance!";
    }
    else
        order = "Invalid advance execution! Source territory doesn't belong to the player that issued the order or target territory is not adjacent to the source territory, .";
    return order;
}

string Bomb::stringToLog() {
    string order;

    if(validate()) {
        order = "Order Executed: Bomb!";
    }
    else
        order = "Invalid bomb execution! Target territory belongs to the player that issuing the order or target territory is not adjacent to one of the territory owned by the player issuing the order";
    return order;
}

string Blockade::stringToLog() {
    string order;

    if(validate()) {
        order = "Order Executed: Blockade!";
    }
    else
        order = "Invalid blockade execution! Target territory belongs to an enemy player";
    return order;
}

string Airlift::stringToLog() {
    string order;

    if(validate()) {
        order = "Order Executed: Airlift!";
    }
    else
        order = "Invalid airlift execution! Source or target territory does not belong to the player that issued the order!";
    return order;
}

string Negotiate::stringToLog() {
    string order;

    if(validate()) {
        order = "Order Executed: Negotiate!";
    }
    else
        order = "Invalid negotiate execution! Target is the player issuing the order!";
    return order;
}


