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

//for advance subclass
Advance::Advance() {}
Advance::Advance(Advance& advance) 
{
	this->action = advance.action;
}

//for bomb subclass
Bomb::Bomb() {}
Bomb::Bomb(Bomb& bomb)
{
	this->action = bomb.action;
}

//for blockade subclass
Blockade::Blockade() {}
Blockade::Blockade(Blockade& blockade) 
{
	this->action = blockade.action;
}

//for airlift subclass
Airlift::Airlift() {}
Airlift::Airlift(Airlift& airlift)
{
	this->action = airlift.action;
}


//for negotiate subclass
Negotiate::Negotiate() {}
Negotiate::Negotiate(Negotiate& negotiate)
{
	this->action = negotiate.action;
}



