#include "Orders.h"

//Order&Order ::operator = (const Order&O)
//{
//	
//}

Order::Order()
{
}

Order::Order(Order& order)
{
    this->action = order.action;
}

Order::~Order()
{
}
//Order::Order(const Order& O) 
//{
//	this->vec_type1 = *new vector<string>(O.vec_type1);
//	this->type_id = new string(*(O.type_id));
//}
bool Order::validate()
{
    cout << "validate if the order is valid" << endl;
    return true;
}

void Order::execute()
{
    if (this->validate() == true) {
        cout << "executes the action..." << endl;
    }
}

void Order::set_type_id(int num)
{
    type_id = num;
}

string Order::get_type()
{
    return vec_type1.at(type_id);
}





void OrderList::add_order_list(Order* an_order)
{
    vec_order_list.push_back(an_order); //add an order
}

vector<Order*>* OrderList::get_order_list()
{
    return &vec_order_list;
}

void OrderList::remove(Order* oneOrder)
{
    for (int i = 0; i < vec_order_list.size(); i++) {
        if (oneOrder->get_type() == vec_order_list.at(i)->get_type()) {
            cout << "  deleting the order: " << oneOrder->get_type() << endl;
            vec_order_list.erase(vec_order_list.begin() + i);

            return;
        }
    }
}

void OrderList::move(int position, int new_position)
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


//subclasses of order

Deploy::Deploy()
{
    cout << "deploy added" << endl;
    set_type_id(0);
}

Deploy::Deploy(Deploy& deploy)
{
    this->action = deploy.action;
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