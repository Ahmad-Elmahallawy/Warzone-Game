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

// validate method
bool Order::validate() { return true; }

// execute method
void Order::execute() { this->executed = true; }

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
Deploy::Deploy()
{
    std::cout << "Deploy is added\n" << std::endl;
}

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

//   ---   Advance class   ---

// default constructor
Advance::Advance()
{
    std::cout << "Advance is added\n" << std::endl;
}

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
//get how many orders are in orderslist
int OrdersList::getOrdersListSize() {
    return ordersList.size();
}

Order* OrdersList::getOrder(int index) {
    if (index < getOrdersListSize() && index >= 0) {
        return ordersList[index];
    }
    return nullptr;
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