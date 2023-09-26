#pragma once

//part 3: Orders List
/*Orders are created by the player during their turn and placed into the player’s list of orders. By default, each order is placed
in the list sequentially. After orders are put in the list, the player can move them around in the list (using the
move() method) or delete them (using the remove() method). The different kinds of orders are: deploy, advance,
bomb, blockade, airlift, and negotiate. All orders must have a validate() method that verifies if the order is valid.

*/
using namespace std;
#include <queue>

class Order {

    private:

        std::string effect = "String describing the order";

    public:

	    Order();//default constructor

        Order(Order& order);//copy constructor

	    //to be implemented in subclasses

	    bool validate(); //see if the order is valid

	    void execute();//some game action being implemented

};

class OrdersList {

    private:

        std::queue<Order*>ordersList;//list of pointers to Orders objects

    public:

       OrdersList();// default constructor
       
       OrdersList(OrdersList& ordersList);// copy constructor
       
       void addOrder(Order* order);// add an order to the list of orders
       
       Order* getNextOrder();// get next order on the list of orders
       
       void remove();// delete an order from the list of orders
      
       void move(); // move around an order from the list of orders

};

//Different Order types/ actions not implemented yet

class Deploy : public Order
{
    private:
        
        std::string effect = "effect in Deploy order class";

    public:

        Deploy();
        Deploy(Deploy& Deploy);

        void execute();
        bool validate();
};



class Advance : public Order
{

    private:
    
        std::string effect = "effect in Advance order class";

    public:
       
        Advance();
        Advance(Advance& Advance);

        void execute();
        bool validate();
};



class Bomb : public Order
{
    private:
        
        std::string effect = "effect in Bomb order class";

    public:
        
        Bomb();
        Bomb(Bomb& Bomb);

        void execute();
        bool validate();
};



class Blockade : public Order
{
    private:
       
        std::string effect = "effect in Blockade order class";

    public:
      
        Blockade();
        Blockade(Blockade& Blockade);

        void execute();
        bool validate();
};



class Airlift : public Order
{
    private:
        
        std::string effect = "effect in Airlift order class";

    public:
        
        Airlift();
        Airlift(Airlift& Airlift);

        void execute();
        bool validate();
};



class Negotiate : public Order
{
    private:
  
        std::string effect = "effect in Negotiate order class";

    public:
        
        Negotiate();
        Negotiate(Negotiate& Negotiate);

        void execute();
        bool validate();
};