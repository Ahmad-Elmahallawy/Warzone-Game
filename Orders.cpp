#include "Orders.h"
#include <math.h>

#include <iostream>
#include <queue>
using namespace std;

//for order class
Order::Order() {}
Order::Order(Order& order) 
{
	this->action = order.action;
}

bool Order::validate() {}
void Order::execute() {}


//different kinds of orders are: deploy, advance,bomb, blockade, airlift, and negotiate

//for deploy subclass
Deploy::Deploy() {}
Deploy::Deploy(Deploy& deploy) 
{
	this->action = deploy.action;
}

bool Deploy :: validate()
{
	cout << "deploy class is valid"<< endl;
}

void Deploy::execute()
{
	if (this->validate() == true)
	{
		cout << "executing Order deploy" << endl;
	}
}

//for advance subclass
Advance::Advance() {}
Advance::Advance(Advance& advance) 
{
	this->action = advance.action;
}

bool Advance::validate()
{
	cout << "Advance class is valid" << endl;
}

void Advance::execute()
{
	if (this->validate() == true)
	{
		cout << "executing Order Advance" << endl;
	}
}

//for bomb subclass
Bomb::Bomb() {}
Bomb::Bomb(Bomb& bomb)
{
	this->action = bomb.action;
}

bool Bomb::validate()
{
	cout << "Bomb class is valid" << endl;
}

void Bomb::execute()
{
	if (this->validate() == true)
	{
		cout << "executing Bomb deploy" << endl;
	}
}

//for blockade subclass
Blockade::Blockade() {}
Blockade::Blockade(Blockade& blockade) 
{
	this->action = blockade.action;
}

bool Blockade::validate()
{
	cout << "Blockade class is valid" << endl;
}

void Blockade::execute()
{
	if (this->validate() == true)
	{
		cout << "executing Order Blockade" << endl;
	}
}

//for airlift subclass
Airlift::Airlift() {}
Airlift::Airlift(Airlift& airlift)
{
	this->action = airlift.action;
}

bool Airlift::validate()
{
	cout << "Airlift class is valid" << endl;
}

void Airlift::execute()
{
	if (this->validate() == true)
	{
		cout << "executing Order Airlift" << endl;
	}
}


//for negotiate subclass
Negotiate::Negotiate() {}
Negotiate::Negotiate(Negotiate& negotiate)
{
	this->action = negotiate.action;
}

bool Negotiate::validate()
{
	cout << "Negotiate class is valid" << endl;
}

void Negotiate::execute()
{
	if (this->validate() == true)
	{
		cout << "executing Order Negotiate" << endl;
	}
}


//orders list class

OrdersList::OrdersList() {}
OrdersList::OrdersList(OrdersList& ordersList)
{
	this->ordersList = ordersList.ordersList;
}

//add an order to OrdesList
void OrdersList::addOrder(Order* order)
{
	ordersList.push(order);
}

// get next order on the list
Order* OrdersList::getNextOrder()
{
	// if list not empty, pop and return next order
	if (!ordersList.empty())
	{
		Order* nextOrderPtr = ordersList.front();
		ordersList.pop();
		return nextOrderPtr;
	}
	else
	{   // if list is empty, print a message
		std::cout << " nothing to get: Order list is empty !";
		return nullptr;
	}
}

