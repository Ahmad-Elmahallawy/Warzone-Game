#ifndef ORDERS_H
#define ORDERS_H

#include <iostream>
#include <deque>
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
    //assignemnt operator
    order& operator =(const order& ord);
    Player* getOwner();
    string getType();

    void write(ostream &output) const;
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
    void write(std::ostream&);
    bool executed;
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

    void write(ostream &);
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

    void write(ostream &);
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

    void write(ostream &);
};

class orderlist {
private:
    // vector of orders pointers
    vector<order*> list;

public:
    // destructor
    ~orderlist();

    // assignment operator
    orderlist& operator=(const orderlist& list);

    // remove from a list given index
    void remove(int num);

    // move from one position to another
    void move(int position1, int position2);

    // default constructor
    orderlist();

    // copy constructor
    orderlist(const orderlist& ord);

    // add a new order into the list
    void addOrder(order* ord);

    // get the first order of the list
    order* getFirstOrder();

    vector<order*> getList();

    // insertion operator
    friend std::ostream& operator<<(std::ostream& output, const orderlist& orderslist); // Stream insertion operator overload

    // get size of the vector
    int getsize();

    // show execute and validate from all objects of the list
    void showmethods();

    // override stringToLog
    string stringToLog();

    void reset();

    order* getNextOrder(); // Get the next order on the list
};

#endif
