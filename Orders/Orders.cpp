#include "Orders.h"
#include <iostream>
#include <string>
//   ---   Order class   ---

// Default constructor
Order::Order() : executed(false), player(nullptr), targetTerritory(nullptr), armiesToDeploy(0) {}

// Parameter constructor
Order::Order(Player* player, Territory* targetTerritory, int armiesToDeploy)
        : action("String describing the order"), executed(false), player(player), targetTerritory(targetTerritory), armiesToDeploy(armiesToDeploy) {}

// Copy constructor
Order::Order(const Order& order)
        : action(order.action), executed(order.executed), player(order.player), targetTerritory(order.targetTerritory), armiesToDeploy(order.armiesToDeploy) {}

// Destructor
Order::~Order() {}

// Validate method
bool Order::validate() { return true; }

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
Deploy::Deploy() : Order() {}

// Parameter constructor for Deploy class
Deploy::Deploy(Player* player, Territory* targetTerritory, int armiesToDeploy)
        : Order(player, targetTerritory, armiesToDeploy) {
    this->action = "effect in Deploy Order class";
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

        // Set the order as executed
        this->executed = true;

        std::cout << "Deploy order executed successfully." << std::endl;
    }
}

// validate method override
bool Deploy::validate() {
    // Check if the target territory exists
    if (!targetTerritory) {
        std::cout << "Invalid Deploy order: Target territory does not exist." << std::endl;
        return false;
    }

    // Check if the target territory belongs to the player issuing the order
    if (targetTerritory->getOwner() != this->getPlayer()) {
        std::cout << "Invalid Deploy order: Target territory does not belong to the player issuing the order." << std::endl;
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
    std::cout << "Advance is added\n" << std::endl;
}

// Parameter constructor for Advance class
Advance::Advance(Player* player, Territory* sourceTerritory, Territory* targetTerritory, int armiesToAdvance)
        : Order(player, targetTerritory, armiesToAdvance) {
    this->sourceTerritory = sourceTerritory;
    this->action = "effect in Advance Order class";
    std::cout << "Advance is added" << std::endl;
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
        // Check if the target territory belongs to another player
        if (targetTerritory->getOwner() != this->getPlayer()) {
            // Simulate battle
            int attackerUnits = armiesToDeploy;
            int defenderUnits = targetTerritory->getNumberOfArmies();

            while (attackerUnits > 0 && defenderUnits > 0) {
                // Simulate each round of battle
                if (rand() % 100 < 60) {
                    // Attacker kills one defender
                    defenderUnits--;
                }

                if (rand() % 100 < 70) {
                    // Defender kills one attacker
                    attackerUnits--;
                }
            }

            // If all defenders are eliminated, the attacker captures the territory
            if (defenderUnits == 0) {
                std::cout << "Attack successful! " << this->getPlayer()->getPlayerName()
                          << " captured " << targetTerritory->getTerritoryName() << std::endl;

                // Move remaining attacker units to the conquered territory
                targetTerritory->setOwner(this->getPlayer());
                targetTerritory->addArmies(attackerUnits);
            } else {
                std::cout << "Attack failed! " << targetTerritory->getTerritoryName() << " defended successfully." << std::endl;
            }
        } else {
            // Move army units from source to target territory
            sourceTerritory->removeArmies(armiesToDeploy);
            targetTerritory->addArmies(armiesToDeploy);
        }

        // Set the order as executed
        this->executed = true;

        std::cout << "Advance order executed successfully." << std::endl;
    }
}

// Advance order validate method
bool Advance::validate() {
    // Check if the source territory exists
    if (!sourceTerritory) {
        std::cout << "Invalid Advance order: Source territory does not exist." << std::endl;
        return false;
    }

    // Check if the source territory belongs to the player issuing the order
    if (sourceTerritory->getOwner() != this->getPlayer()) {
        std::cout << "Invalid Advance order: Source territory does not belong to the player issuing the order." << std::endl;
        return false;
    }

    // Check if the target territory exists
    if (!targetTerritory) {
        std::cout << "Invalid Advance order: Target territory does not exist." << std::endl;
        return false;
    }

    // Check if the target territory is adjacent to the source territory
    if (!sourceTerritory->isAdjacent(targetTerritory)) {
        std::cout << "Invalid Advance order: Source and target territories are not adjacent." << std::endl;
        return false;
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
    std::cout << "Bomb is added\n" << std::endl;
}

// copy constructor
Bomb::Bomb(const Bomb& existingBomb)
{
    this->action = existingBomb.action;
}

// destructor
Bomb::~Bomb() {}

// validate method override
bool Bomb::validate()
{
    std::cout << "Bomb class is valid\n" << std::endl;
    return true;
}

// execute method override
void Bomb::execute()
{
    if (this->validate())
    {
        std::cout << "executing Order Bomb" << std::endl;
        this->executed = true;
    }
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
    std::cout << "Blockade is added\n" << std::endl;
}

// copy constructor
Blockade::Blockade(const Blockade& blockade)
{
    this->action = blockade.action;
}

// destructor
Blockade::~Blockade() {}

// validate method override
bool Blockade::validate()
{
    std::cout << "Blockade class is valid" << std::endl;
    return true;
}

// execute method override
void Blockade::execute()
{
    if (this->validate())
    {
        std::cout << "executing Order Blockade" << std::endl;
        this->executed = true;
    }
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
    std::cout << "Airlift is added\n" << std::endl;
}

// copy constructor
Airlift::Airlift(const Airlift& existingAirlift)
{
    this->action = existingAirlift.action;
}

// destructor
Airlift::~Airlift() {}

// validate method override
bool Airlift::validate()
{
    std::cout << "validate() called in an Airlift object" << std::endl;
    return true;
}

// execute method override
void Airlift::execute()
{
    if (this->validate())
    {
        std::cout << "execute() called in an Airlift object" << std::endl;
        this->executed = true;
    }
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
    std::cout << "Negotiate is added\n" << std::endl;
}

// copy constructor
Negotiate::Negotiate(const Negotiate& existingNegotiate)
{
    this->action = existingNegotiate.action;
}

// destructor
Negotiate::~Negotiate() {}

// validate method override
bool Negotiate::validate()
{
    std::cout << "Negotiate class is valid" << std::endl;
    return true;
}

// execute method override
void Negotiate::execute()
{
    if (this->validate())
    {
        this->executed = true;
    }
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
        order = nullptr;
    }
}

// add an order to the list
void OrdersList::addOrder(Order* order)
{
    this->ordersList.push_back(order);
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

// remove an order from the list [takes an int, which is a menu number]
void OrdersList::remove(int num)
{
    // index is one less than menu numbering
    num--;

    this->ordersList.erase(this->ordersList.begin() + num);

    std::cout << "an order was removed\n" << std::endl;
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