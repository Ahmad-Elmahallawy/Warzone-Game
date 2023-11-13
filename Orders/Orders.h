
/*
Part 3: Orders List
Orders are created by the Players during their turn and placed into the Players’s list of orders. By default, each order is placed
in the list sequentially. After orders are put in the list, the Players can move them around in the list (using the
move() method) or delete them (using the remove() method). The different kinds of orders are: deploy, advance,
bomb, blockade, airlift, and negotiate. All orders must have a validate() method that verifies if the order is valid.
*/

#ifndef ORDERS_H
#define ORDERS_H

#include <iostream>
#include <deque>
#include "../Players/Player.h"
#include "../GameLog/LoggingObserver.h"




// Forward declaration for circular dependency
class Territory;

//   ---   Order class    ---   [each ORDER type (below) inherits from this class and overrides execute() and validate()]

class Order : public ILoggable, public Subject
{
protected:
    // action of the Order
    std::string action = "String describing the order";

    // boolean set true if action object has been executed
    bool executed = false;
    Player* player = nullptr;
    Player* target = nullptr;
    Territory* targetTerritory;
    Territory* sourceTerritory;
    int armiesToDeploy;

public:
    // default constructor
    Order();



    Order(Player* player, Territory* targetTerritory, int armiesToDeploy);

    // copy constructor
    Order(const Order& order);

    // virtual destructor
    virtual ~Order();

    // virtual method to execute order (implemented in subclasses)
    virtual void execute();

    // virtual method to validate order (implemented in subclasses)
    virtual bool validate();

    // Getter and Setter for player
    Player* getPlayer() const;
    void setPlayer(Player* player);

    // Getter and Setter for targetTerritory
    Territory* getTargetTerritory() const;
    void setTargetTerritory(Territory* territory);

    // Getter and Setter for sourceTerritory
    Territory* getSourceTerritory() const;
    void setSourceTerritory(Territory* territory);

    // Getter and Setter for armiesToDeploy
    int getArmiesToDeploy() const;
    void setArmiesToDeploy(int armies);
    // assignment operator
    Order& operator=(const Order& order);

    string getAction();

    // print helper method for stream insertion overload
    virtual void print(std::ostream& output) const;

    // stream insertion operator
    friend std::ostream& operator<<(std::ostream& output, const Order& order);

    virtual std::string getLabel() const = 0;

};

// order types:

//   ---   Deploy class   ---

class Deploy : public Order
{

private:
    const static std::string label;

public:
    // default constructor
    Deploy();

    // parameter constructor
    Deploy(Player* target, Player* from, int armyCount, Territory* targetLocation, Territory* fromLocation);

    // copy constructor
    Deploy(const Deploy& deploy);

    // default destructor
    ~Deploy();

    // execute method override
    void execute() override;

    // validate method override
    bool validate() override;

    // assignment operator
    Deploy& operator=(const Deploy& deploy);

    // print helper method for stream insertion overload
    void print(std::ostream& output) const override;

    // stream insertion operator
    friend std::ostream& operator<<(std::ostream& output, const Deploy& deploy);

    string stringToLog();

    std::string getLabel() const override;
};

//   ---   Advance class   ---

class Advance : public Order
{
private:
    const static std::string label;
public:
    // default constructor
    Advance();

    // parameter constructor
    Advance(Player* target, Player* player, int armyCount, Territory* targetLocation, Territory* fromLocation);

    ~Advance() override;

    // copy constructor
    Advance(const Advance& advance);

    string stringToLog();

    // execute method override
    void execute() override;

    // validate method override
    bool validate() override;

    // assignment operator
    Advance& operator=(const Advance& advance);

    // print helper method for stream insertion overload
    void print(std::ostream& output) const override;

    // stream insertion operator
    friend std::ostream& operator<<(std::ostream& output, const Advance& advance);

    std::string getLabel() const override;

};

//   ---   Bomb class   ---

class Bomb : public Order
{
private:
    // action of Bomb
    std::string action = "effect in Bomb Order class";

    // boolean set true if action object has been executed
    bool executed = false;

    const static std::string label;

public:
    // default constructor
    Bomb();

    Bomb(Player* target, Player* player, int armyCount, Territory* targetLocation, Territory* fromLocation);

    // copy constructor
    Bomb(const Bomb& bomb);

    // default destructor
    ~Bomb();

    // execute method override
    void execute() override;

    // validate method override
    bool validate() override;

    string stringToLog();

    // assignment operator
    Bomb& operator=(const Bomb& bomb);

    // print helper method for stream insertion overload
    void print(std::ostream& output) const override;

    // stream insertion operator
    friend std::ostream& operator<<(std::ostream& output, const Bomb& bomb);

    std::string getLabel() const override;

};

//   ---   Blockade class   ---

class Blockade : public Order
{
private:
    // action of Blockade
    std::string action = "effect in Blockade Order class";


    // boolean set true if action object has been executed
    bool executed = false;

    const static std::string label;

public:
    // default constructor
    Blockade();

    Blockade(Player* target, Player* player, int armyCount, Territory* targetLocation, Territory* fromLocation);
    // copy constructor
    Blockade(const Blockade& blockade);

    // default destructor
    ~Blockade();

    // execute method override
    virtual void execute() override;

    // validate method override
    virtual bool validate() override;

    // assignment operator
    Blockade& operator=(const Blockade& blockade);

    // print helper method for stream insertion overload
    void print(std::ostream& output) const override;

    string stringToLog();

    // stream insertion operator
    friend std::ostream& operator<<(std::ostream& output, const Blockade& blockade);

    std::string getLabel() const override;
};

//   ---   Airlift class  ---

class Airlift : public Order
{
private:
    // action of Airlift
    std::string action = "effect in Airlift Order class";

    // boolean set true if action object has been executed
    bool executed = false;


    const static std::string label;

public:
    // default constructor
    Airlift();

    Airlift(Player* target, Player* player, int armyCount, Territory* targetLocation, Territory* fromLocation);

    // copy constructor
    Airlift(const Airlift& airlift);


    // default destructor
    ~Airlift();

    // execute method override
    void execute() override;

    // validate method override
    bool validate() override;

    // assignment operator
    Airlift& operator=(const Airlift& airlift);

    // print helper method for stream insertion overload
    void print(std::ostream& output) const override;

    // stream insertion operator
    friend std::ostream& operator<<(std::ostream& output, const Airlift& airlift);
    string stringToLog();
    std::string getLabel() const override;
};

//   ---   Negotiate class  ---

class Negotiate : public Order
{
private:
    /// action of Negotiate
    std::string action = "effect in Negotiate Order class";

    // boolean set true if action object has been executed
    bool executed = false;

    const static std::string label;

public:
    // default constructor
    Negotiate();

    Negotiate(Player* target, Player* player, int armyCount, Territory* targetLocation, Territory* fromLocation);


    // copy constructor
    Negotiate(const Negotiate& negotiate);

    // default destructor
    ~Negotiate();

    // execute method override
    void execute() override;

    // validate method override
    bool validate() override;

    // assignment operator
    Negotiate& operator=(const Negotiate& negotiate);

    // print helper method for stream insertion overload
    void print(std::ostream& output) const override;

    // stream insertion operator
    friend std::ostream& operator<<(std::ostream& output, const Negotiate& negotiate);
    string stringToLog();
    std::string getLabel() const override;
};

// end of order types!


//   ---   OrdersList class   ---   [a class to create and manage a list of orders]

class OrdersList : public ILoggable, public Subject
{
private:

    // a list of pointers to Order objects
    std::deque<Order*> ordersList;

public:

    // default constructor
    OrdersList();

    // copy constructor
    OrdersList(const OrdersList& ordersList);

    // destructor
    ~OrdersList();

    // add an order to the list
    void addOrder(Order* order);

    // get next order on the list
    Order* getNextOrder();

    //get order according to index
    Order* getOrder(int index);

    // delete an order from the list (use menu number)
    void remove(int num);

    // move around an order in the list (use menu numbers)
    void move(int a, int b);

    //get the number of orders in orderslist
    int getOrdersListSize();

    // assignment operator
    OrdersList& operator=(const OrdersList& ordersList);

    string stringToLog();

    int getSize();

    //stream insertion operator
    friend std::ostream& operator<<(std::ostream& output, const OrdersList& ordersList);


};
//free function to test OrdersList methods
void testOrderExecution();

#endif