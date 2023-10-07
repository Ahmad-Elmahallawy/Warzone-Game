/*
Part 3: Orders List
Orders are created by the Players during their turn and placed into the Players’s list of orders. By default, each order is placed
in the list sequentially. After orders are put in the list, the Players can move them around in the list (using the
move() method) or delete them (using the remove() method). The different kinds of orders are: deploy, advance,
bomb, blockade, airlift, and negotiate. All orders must have a validate() method that verifies if the order is valid.
*/

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Order
{
public:
    Order();
    ~Order();
    Order(Order& order);//copy constructor

    //check of the order is valid
    bool validate();
    //execute method
    void execute();

    //set type of the subclass
    void set_type_id(int num);
    string get_type();

private:
    std::string action = "String describing the order"; 
    bool valid;
    vector<string> vec_type1 = { "deploy", "advance", "bomb", "blockade", "airlift", "negotiate" }; //store the subclasses of order in a vecotr
    int type_id;
};

class Deploy : public Order
{

public:
    Deploy();
    Deploy(Deploy& Deploy);//copy constructor
    ~Deploy();
    string* get_type();
    void execute();
    bool validate();
private:
    std::string action = "effect in Deploy order class"; //describes the effect of each order subtype
    string type1 = { "deploy" };
};

class Advance : public Order {
public:
    Advance();
    Advance(Advance& Advance);//copy constructor
    ~Advance();
    void execute();
    bool validate();

private:
    std::string action = "effect in Advance order class";
};

class Bomb : public Order
{
public:
    Bomb();
    Bomb(Bomb& Bomb);//copy constructor
    ~Bomb();
    void execute();
    bool validate();

private:
    std::string action = "effect in Bomb order class";
};

class Blockade : public Order
{
public:
    Blockade();
    Blockade(Blockade& Blockade);//copy constructor
    ~Blockade();
    void execute();
    bool validate();
private:
    std::string action = "effect in Blockade order class";
};

class Airlift : public Order
{
public:
    Airlift();
    Airlift(Airlift& Airlift);//copy constructor
    ~Airlift();
    void execute();
    bool validate();
private:
    std::string action = "effect in airlift order class";
};

class Negotiate : public Order
{
public:
    Negotiate();
    Negotiate(Negotiate& Negotiate);//copy constructor
    ~Negotiate();
    void execute();
    bool validate();

private:
    std::string action = "effect in negotiate order class";
};

//OrderList class

class OrderList
{
public:
    void add_order_list(Order* an_order); //adding a specific order to the list

    vector<Order*>* get_order_list(); //returning Orderlist

    void remove(Order* oneOrder); //delete an order

    void move(int position, int new_position); //move

private:
    vector<Order*> vec_order_list; //store the orders in the list
};

void testOrdersLists();//free function to test