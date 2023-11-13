
#include <iostream>
#include <string>
#include <utility>
#include "Orders.h"
#include "../Players/Player.h"

//   ---   Order class   ---

// default constructor
Order::Order()
{

}

// destructor
Order::~Order() {}

// copy constructor
Order::Order(const Order& order)
{
    this->action = order.action;
}

Order::Order(std::string orderName) : action(std::move(orderName)), executed(false) {
    // Additional initialization if needed
}

// validate method
bool Order::validate() { return true; }

// execute method
void Order::execute() { this->executed = true;}

// assignment operator
Order& Order::operator=(const Order& order)
{
    this->action = order.action;
    this->executed = order.executed;

    return *this;
}

// print helper method for stream insertion operator overload
void Order::print(std::ostream& output) const
{
    output << "Order" << std::endl;
}

// stream insertion operator overload
std::ostream& operator<<(std::ostream& output, const Order& order)
{
    order.print(output);
    if (order.executed)
    {
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
Deploy::Deploy() : Order("Deploy Order") {}

// copy constructor
Deploy::Deploy(const Deploy& deploy)
{
    this->action = deploy.action;
}

// destructor
Deploy::~Deploy() {}

// validate method override
bool Deploy::validate()
{
    std::cout << "deploy class is valid" << std::endl;
    return true;
}

// execute method override
void Deploy::execute()
{
    if (this->validate())
    {
        std::cout << "executing Order Deploy" << std::endl;
        this->executed = true;
        Notify(this);
    }
}

// assignment operator
Deploy& Deploy::operator=(const Deploy& deploy)
{
    this->action = deploy.action;
    this->executed = deploy.executed;

    return *this;
}

// print helper method for stream insertion overload
void Deploy::print(std::ostream& output) const
{
    output << "Deploy" << std::endl;
}

// stream insertion operator overload
std::ostream& operator<<(std::ostream& output, const Deploy& deploy)
{
    deploy.print(output);
    if (deploy.executed)
    {
        output << deploy.action << std::endl;
    }
    return output;
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

//   ---   Advance class   ---

// default constructor
Advance::Advance() : Order("Advance Order") {}

// copy constructor
Advance::Advance(const Advance& existingAdvance)
{
    this->action = existingAdvance.action;
    std::cout << "Advance is added" << std::endl;
}

// destructor
Advance::~Advance() {}

// validate method override
bool Advance::validate()
{
    std::cout << "Advance class is valid" << std::endl;
    return true;
}

// execute method override
void Advance::execute()
{
    if (this->validate())
    {
        std::cout << "executing Order advance" << std::endl;
        this->executed = true;
    }
    Notify(this);
}

// assignment operator
Advance& Advance::operator=(const Advance& advance)
{
    this->action = advance.action;
    this->executed = advance.executed;

    return *this;
}

// print helper method for stream insertion overload
void Advance::print(std::ostream& output) const
{
    output << "Advance" << std::endl;
}

// stream insertion operator overload
std::ostream& operator<<(std::ostream& output, const Advance& advance)
{
    advance.print(output);
    if (advance.executed)
    {
        output << advance.action << std::endl;
    }
    return output;
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

//   ---   Bomb class   ---

// default constructor
Bomb::Bomb() : Order("Bomb Order") {}

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

string Bomb::stringToLog() {
    string order;

    if(validate()) {
        order = "Order Executed: Bomb!";
    }
    else
        order = "Invalid bomb execution! Target territory belongs to the player that issuing the order or target territory is not adjacent to one of the territory owned by the player issuing the order";
    return order;
}

//   ---   Blockade class   ---

// default constructor
Blockade::Blockade() : Order("Blockade Order") {}

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
    Notify(this);
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

string Blockade::stringToLog() {
    string order;

    if(validate()) {
        order = "Order Executed: Blockade!";
    }
    else
        order = "Invalid blockade execution! Target territory belongs to an enemy player";
    return order;
}

//   ---   Airlift class   ---

// default constructor
Airlift::Airlift() : Order("Airlift Order") {}

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

string Airlift::stringToLog() {
    string order;

    if(validate()) {
        order = "Order Executed: Airlift!";
    }
    else
        order = "Invalid airlift execution! Source or target territory does not belong to the player that issued the order!";
    return order;
}

//   ---   Negotiate class   ---

// default constructor
Negotiate::Negotiate() : Order("Negotiate Order") {}

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

string Negotiate::stringToLog() {
    string order;

    if(validate()) {
        order = "Order Executed: Negotiate!";
    }
    else
        order = "Invalid negotiate execution! Target is the player issuing the order!";
    return order;
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

int OrdersList::getSize() {
    return ordersList.size();
}

string Order::getAction() {
    return this->action;
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