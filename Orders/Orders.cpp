#include "Orders.h"


Order::Order() //constructor
{
}

Order::Order(Order& order) //copy constructor
{
    this->action = order.action;
}

Order::~Order()
{
}

bool Order::validate()  //validate method, condition to be implemented after
{
    cout << "validate if the order is valid" << endl;
    return true;
}

void Order::execute()  //execute method, to be overriden by the subclasses
{
    if (this->validate() == true) {
        cout << "executes the action..." << endl;
    }
}

void Order::set_type_id(int num) //setting the type to the order 
{
    type_id = num;
}

string Order::get_type() //returning the type id of the order
{
    return vec_type1.at(type_id);
}





void OrderList::add_order_list(Order* an_order)
{
    vec_order_list.push_back(an_order); //add an order to the list
}

vector<Order*>* OrderList::get_order_list() //returning the ordered list
{
    return &vec_order_list;
}

void OrderList::remove(Order* oneOrder) //removing an order based on its type
{
    for (int i = 0; i < vec_order_list.size(); i++) {
        if (oneOrder->get_type() == vec_order_list.at(i)->get_type()) {
            cout << "  deleting the order: " << oneOrder->get_type() << endl;
            vec_order_list.erase(vec_order_list.begin() + i);

            return;
        }
    }
}

void OrderList::move(int position, int new_position) //moving an order from old to new position
{
    if (position >= 0 && position < vec_order_list.size() && new_position >= 0 && new_position < vec_order_list.size())
    {
        vec_order_list.insert(vec_order_list.begin() + new_position, vec_order_list.at(position));
        vec_order_list.erase(vec_order_list.begin() + position);
    }
    else if (new_position == vec_order_list.size())
    {
        vec_order_list.push_back(vec_order_list.at(position));
        vec_order_list.erase(vec_order_list.begin() + position);
    }
    else {
        cout << "\n error, not valid position" << endl;
    }
}


/*
Subclasses of order
The different kinds of orders are: deploy, advance,
bomb, blockade, airlift, and negotiate. All orders must have a validate() method that verifies if the order is valid.
All orders must have an execute() method that will result in some game action being implemented (see the
project description document).

*/

Deploy::Deploy()
{
    cout << "deploy added" << endl;
    set_type_id(0);
}

Deploy::Deploy(Deploy& deploy)   
{
    this->action = deploy.action; //refers to the private action string declared in the header file (Orders.h)
}

Deploy::~Deploy()
{
}

bool Deploy::validate()
{
    cout << "deploy class is valid" << endl;
    return true;
}

void Deploy::execute()
{
    if (this->validate() == true)
    {
        cout << "executing Order deploy" << endl;
        cout << "order: " + this->action;
    }
}

string* Deploy::get_type()
{
    return &type1;
}


Advance::Advance()
{
    cout << "advance is added" << endl;
    set_type_id(1);
}

Advance::Advance(Advance& advance)
{
    this->action = advance.action;
}

Advance::~Advance()
{
}

bool Advance::validate()
{
    cout << "Advance class is valid" << endl;
    return true;
}

void Advance::execute()
{
    if (this->validate() == true)
    {
        cout << "executing Order Advance" << endl;
        cout << "order: " + this->action;
    }
}

Bomb::Bomb()
{
    cout << "bomb is added" << endl;
    set_type_id(2);
}

Bomb::Bomb(Bomb& bomb)
{
    this->action = bomb.action;
}

Bomb::~Bomb()
{
}

bool Bomb::validate()
{
    cout << "Bomb class is valid" << endl;
    return true;
}

void Bomb::execute()
{
    if (this->validate() == true)
    {
        cout << "executing Bomb deploy" << endl;
        cout << "order: " + this->action;
    }
}

Blockade::Blockade()
{
    cout << "blockade is added" << endl;
    set_type_id(3);
}

Blockade::Blockade(Blockade& blockade)
{
    this->action = blockade.action;
}

Blockade::~Blockade()
{
}

bool Blockade::validate()
{
    cout << "Blockade class is valid" << endl;
    return true;
}

void Blockade::execute()
{
    if (this->validate() == true)
    {
        cout << "executing Order Blockade" << endl;
        cout << "order: " + this->action;
    }
}

Airlift::Airlift()
{
    cout << "airlift is added" << endl;
    set_type_id(4);
}

Airlift::Airlift(Airlift& airlift)
{
    this->action = airlift.action;
}

Airlift::~Airlift()
{
}

bool Airlift::validate()
{
    cout << "Airlift class is valid" << endl;
    return true;
}

void Airlift::execute()
{
    if (this->validate() == true)
    {
        cout << "executing Order Airlift" << endl;
        cout << "order: " + this->action;
    }
}

Negotiate::Negotiate()
{
    cout << "negotiate is added" << endl;
    set_type_id(5);
}

Negotiate::~Negotiate()
{
}

bool Negotiate::validate()
{
    cout << "Negotiate class is valid" << endl;
    return true;
}

void Negotiate::execute()
{
    if (this->validate() == true)
    {
        cout << "executing Order Negotiate" << endl;
        cout << "order: " + this->action;
    }
}