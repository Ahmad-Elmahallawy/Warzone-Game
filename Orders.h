/*
Part 3: Orders List
Orders are created by the player during their turn and placed into the player’s list of orders. By default, each order is placed
in the list sequentially. After orders are put in the list, the player can move them around in the list (using the
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
	void validate();
	//execute method 
	void execute();

	//set type of the subclass
	void set_type_id(int num);
	string get_type();

private:
	bool valid;
	vector<string> vec_type1 = { "deploy", "advance", "bomb", "blockade", "airlift", "negotiate" };
	int type_id;
};

class Deploy : public Order
{

public:
	Deploy();
	~Deploy();
	string* get_type();
private:
	string type1 = { "deploy" };
};

class Advance : public Order {
public:
	Advance();
	~Advance();

private:
};

class Bomb : public Order
{
public:
	Bomb();
	~Bomb();

private:
};

class Blockade : public Order
{
public:
	Blockade();
	~Blockade();
private:
};

class Airlift : public Order
{
public:
	Airlift();
	~Airlift();
private:
};

class Negotiate : public Order
{
public:
	Negotiate();
	~Negotiate();

private:
};

class OrderList
{
public:
	void add_order_list(Order* an_order);

	vector<Order*>* get_order_list();
	
	void remove_order(Order* oneOrder); //delete an order
	
	void move(int position, int new_position); //move

private:
	vector<Order*> vec_order_list; //store the orders in the list
};