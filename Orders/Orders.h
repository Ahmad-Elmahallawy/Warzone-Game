#ifndef ORDERS_H
#define ORDERS_H

#include <iostream>
#include <deque>
#include "../Players/Player.h"
#include "../Map/Map.h"


class Player;

class order {

protected:
    string type;
    Player* owner;
public:
    virtual bool validate();
    virtual void execute()=0;
    // clone method to create deep copy of order
    virtual order* clone();
    //defalt constructor
    order();
    //copy construcotr
    order(const order& ord);
    virtual ~order();
    //stream insertion operator
    friend ostream& operator<<(ostream& cout, order& ord);
    //method wil be inherited and used inside the srtream insertion operatio to print right object
    virtual void write(std::ostream&);
    //assignemnt operator
    order& operator =(const order& ord);
    Player* getOwner();
    string getType();
};
void testOrdersLists();
void testOrderExecution();
class deploy : public order {
private:
    int numbOfArmies;
    Territory* target;
public:
    //prarameterized constructer;
    deploy(int numbOfarmies, Territory& target, Player* P);
    //stream insertion operator
    friend ostream& operator<<(ostream& cout, deploy& d);
    //destrucotr
    ~deploy();
    //copy constructor
    deploy(deploy* dep);
    bool validate();
    void execute();
    //clone to create a deep copy
    deploy *clone();
    deploy();
    void write(std::ostream&);
    int getNumOfArmies() const;
    Territory* getTerrority();
    Player* getOwner();
    //assignemnt operator
    deploy& operator=(const deploy& d);
};
class advancee : public order {
private:
    int numbOfarmies; Territory* source; Territory* target;

public:
    bool validate();
    void execute();
    //assignment operator
    advancee& operator=(const advancee& adv);
    //copy consdtructor
    advancee(advancee* adv);
    //parameter constructor
    advancee(int numbOfarmies, Territory& source, Territory& to, Player* p);

    //destructor
    ~advancee();
    //default constructor
    advancee();
    Territory* getSourceTerrority();
    Territory* getTargetTerrority();
    void setSourceTerritory(Territory* sourceTerritory);
    void setTargetTerritory(Territory* targetTerritory);
    void setNumOfArmy(int n);
    //to create depp copy
    advancee* clone();
    void write(std::ostream&);
    //stream inseretion operator
    friend ostream& operator<<(ostream& cout, advancee& ss);
};
class bomb:public order {
private:
    Territory* target;
public:
    //assignment operator
    bomb& operator=(const bomb& bom);
    //defauly constructor
    bomb();
    //parameterized
    bomb(Territory& target, Player* p);
    //destructor
    ~bomb();
    //stream insertion operator
    friend ostream& operator<<(ostream& cout, bomb& b);
    //copy constructor
    bomb(bomb* bom);
    void execute();
    bool validate();
    //deep copy
    Territory* getTerritory();
    void setTargetTerritory(Territory* targetTerritory);
    bomb* clone();
    bool validateCard();
};


class blockade :public order {
private:
    Territory* target;
    Player* neutralPlayer;
public:
    //assighnment operator
    blockade& operator=(const blockade& block);
    void execute();
    bool validate();
    bool validateCard();
    //default constructor
    blockade();
    //clone for deep copy
    blockade* clone();
    //parameterized constructor
    blockade(Territory& target, Player* p, Player* neutralPlayer);
    //destructor
    ~blockade();
    //copy constructor
    blockade(blockade* bl);
    Territory* getTerritory();
    void setTargetTerritory(Territory* targetTerritory);
    //stream instertion operator
    friend ostream& operator<<(ostream& cout, blockade& b);

};
class negotiate : public order {

private:
    //private members of the class
    Player* TargetPlayer;
public:
    negotiate& operator=(const negotiate& n);
    //default constructor
    negotiate();
    //constructor with one parameters
    negotiate(Player* target, Player* source);
    //destructor
    ~negotiate();
    //overload stream insertion operaation to be able to print an object by cout
    friend ostream& operator<<(ostream& cout, negotiate& n);
    //copy constructor
    negotiate(negotiate * neg);
    //execute inherited from order
    void execute();
    Player* getTargetPlayer();
    void setTargetPlayer(Player* P);
    //validate inherited from order
    bool validate();
    bool validateCard();
    // clone method inherited form order to ba able to deep copy the object in orderlist vector
    negotiate* clone();
};
//airlift class subclass of order
class airlift : public order {

private:
    //private members of the class
    int numbOfarmies; Territory* source; Territory* target;
public:
    airlift& operator=(const airlift& air);
    //default constructor
    airlift();
    //constructor with three parameters
    airlift(int numbOfarmies, Territory& source, Territory& target, Player* p);
    //destructor
    ~airlift();
    //overload stream insertion operaation to be able to print an object by cout
    friend ostream& operator<<(ostream& cout, airlift& ai);
    //copy constructor
    airlift(airlift* air);
    //execute inherited from order
    void execute();
    Territory* getSourceTerritory();
    Territory* getTargetTerritory();

    void setTargetTerritory(Territory* targetTerritory);
    void setSourceTerritory(Territory* sourceTerritory);
    void setNumOfArmy(int n);
    //validate inherited from order
    bool validate();
    bool validateCard();
    // clone method inherited form order to ba able to deep copy the object in orderlist vector
    airlift* clone();
};

class orderlist {
private://vector of orders pointers
    vector <order*> list;
public:
    //destructor
    ~orderlist();
    //assignemnt operator
    orderlist& operator=(const orderlist& list);
    //remove from an list given index
    void remove(int num);
    // move from one postion to another
    void move(int position1, int position2);
    //default conmstructor
    orderlist();
    //copy constructor
    orderlist(const orderlist& ord);
    //add a new order in to the list
    void addOrder(order* ord);
    //get First order of list
    order* getFirstOrder();
    vector <order*> getList();
    //insetion operator
    friend ostream& operator<<(ostream& cout, const orderlist& l);
    //getsize of the vector
    int getsize();
    //show execut and validate from all object of the list
    void showmethods();
    //override stringToLog
    string stringToLog();
    void reset();
};
#endif
