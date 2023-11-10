#include "../Map/Map.h"
#include "../Orders/Orders.h"
#include "../Players/Player.h"
#include <iostream>
#include <string>
//order
//validate from order class
bool order::validate()
{
    cout << "validate from super class";
    return true;
}

order* order::clone()
{
    return this;
}
order::order()
{
    //default constructor
}
//copy constructor
order::order(const order& ord)
{
    this->type = ord.type;
}
//assignemnt operator
order& order::operator=(const order& ord)
{
    this->type = ord.type;
    return *this;//return ponter to object
}
Player* order::getOwner()
{
    return owner;
}
string order::getType()
{
    return type;
}
ostream& operator<<(ostream& cout, order& b)
{
    b.write(cout);
    return cout;
}
order::~order() {}
//deploy
deploy::deploy(int numbOfarmies, Territory& target, Player* p) : numbOfArmies(numbOfarmies)
{
    this->numbOfArmies = numbOfarmies;
    this->target = &target;
    this->type = "deploy";
    this->owner = p;
}
//destructor
deploy::~deploy()
{
    target = nullptr;
}
//validate method
bool deploy::validate()
{
    Player *p = getOwner();
    Territory *target = getTerrority();
    for (int i = 0; i < p->getterriortiesOwned().size(); i++) {
        if (p->getterriortiesOwned()[i] == target)
        {
            return true;
        }
    }
    return false;
}
//return a ostream cout for printing the objecr
ostream& operator<<(ostream& cout, deploy& d)
{
    //use write from subclass by polymorphism
    d.write(cout);
    return cout;
}
//copy constructor
deploy::deploy(deploy* dep) {
    this->numbOfArmies = dep->numbOfArmies;
    this->target = dep->target;
    this->type = dep->type;
}
//execute method
void deploy::execute()
{
    Territory *target = getTerrority();
    if (validate()) {//first check if the terrority belongs to the player or not
        target->setNumOfArmies(target->getNumOfArmies() + numbOfArmies);// if it does, then it add numbofarmies to the target
        cout << "The deploy order is executed" << endl;
        cout << "The number of armies are moved to the " << target->getName() << " and now the number of this territory is " << target->getNumOfArmies() <<" armies." << endl;
    }
    else
    {
        cout << "Can't execute order since the territory doesn't belong to the player";
    }

}
//default constructor
deploy::deploy()
{
    this->numbOfArmies = 0;
    this->target = nullptr;
    this->type = "deploy";
}
//write method same as before
void deploy::write(std::ostream&)
{
    cout << "put " << this->numbOfArmies << " on a target territory\n";
}
int deploy::getNumOfArmies() const
{
    return numbOfArmies;
}
Territory* deploy::getTerrority()// returns the target terrority
{
    return target;
}

Player* deploy::getOwner()// returns the player issuing the order
{
    return owner;
}
//assignemnt operator
deploy& deploy::operator=(const deploy& d)
{
    order ::operator =(d);
    this->numbOfArmies = d.numbOfArmies;
    this->target = d.target;
    return *this;

}
//advance
//parameterized constructor
advancee::advancee(int numbOfarmies, Territory& source, Territory& to, Player* p)
{
    this->type = "advance";
    this->source = &source;
    this->target = &to;
    this->numbOfarmies = numbOfarmies;
    this->owner = p;
}
//destructor
advancee::~advancee()
{
    target = nullptr;
    source = nullptr;
}
//default constructor
advancee::advancee()
{
    this->source = nullptr;
    this->target = nullptr;
    this->numbOfarmies = 0;
    this->type = "advancee";
}

Territory* advancee::getSourceTerrority()
{
    return source;
}

Territory* advancee::getTargetTerrority()
{
    return target;
}

void advancee::setSourceTerritory(Territory* sourceTerritory) {
    this->source = sourceTerritory;
}

void advancee::setTargetTerritory(Territory* targetTerritory) {
    this->target = targetTerritory;
}

void advancee::setNumOfArmy(int n) {
    this->numbOfarmies = n;
}
// clone method same as other subclasses
advancee* advancee::clone()
{
    return new advancee(this);
}
//write method
void advancee::write(std::ostream&)
{
    cout << " move " << this->numbOfarmies << " from  a source territory to a target territory\n";
}
//validate method to check tthe order is valid
bool advancee::validate()
{
    if (owner != source->getOwner()) {
        return false;
    }

    // If the target territory is not adjacent to the source territory, the order is invalid
    if (!source->isAdjacent(*target)) {
        return false;
    }

    return true;
}

void advancee::execute() {
    if (!validate()) {
        // Output error message or handle invalid order
        cout << "Invalid advance order." << endl;
        return;
    }

    // If the source and target territory both belong to the player, move armies
    if (owner == target->getOwner()) {
        source->setNumOfArmies(source->getNumOfArmies() - numbOfarmies);
        target->setNumOfArmies(target->getNumOfArmies() + numbOfarmies);
    } else {
        // Simulate an attack
        int attackingArmies = numbOfarmies;
        int defendingArmies = target->getNumOfArmies();

        // Simulate battle
        for (int i = 0; i < attackingArmies; ++i) {
            if (rand() % 100 < 60) {
                // Attacking army kills defending army
                defendingArmies--;
            }
        }

        for (int i = 0; i < defendingArmies; ++i) {
            if (rand() % 100 < 70) {
                // Defending army kills attacking army
                attackingArmies--;
            }
        }

        // If all defender's armies are eliminated, attacker captures the territory
        if (defendingArmies == 0) {
            target->setOwner(owner);
            target->setNumOfArmies(attackingArmies);
        } else {
            // Set remaining armies after battle
            source->setNumOfArmies(source->getNumOfArmies() - (numbOfarmies - attackingArmies));
            target->setNumOfArmies(defendingArmies);
        }

        // Check if the player successfully conquered at least one territory to receive a card
        if (defendingArmies == 0) {
            owner->getCard(); // Assuming there's a method in the Player class to add a card
        }
    }
}

//assignemnt operator
advancee& advancee::operator=(const advancee& adv)
{
    order :: operator=(adv);
    this->source = adv.source;
    this->target = adv.target;
    this->numbOfarmies = adv.numbOfarmies;
    return *this;//return pointetr to the object
}
ostream& operator<<(ostream& cout, advancee& ss)
{
    ss.write(cout);
    return cout;
}
advancee::advancee(advancee* adv) {
    this->source = adv->source;
    this->target = adv->target;
    this->type = adv->type;
    this->numbOfarmies = adv->numbOfarmies;

}
/////the comments are exactly the same as the other subclasses
//blockade
blockade* blockade::clone()
{
    return new blockade(this);
}
blockade::blockade(Territory& target, Player* p, Player* neutralPlayer)
{
    this->type = "blockade";
    this->target = &target;
    this->owner = p;
    this->neutralPlayer = neutralPlayer;
}

blockade::~blockade()
{
    this->target = NULL;
}

blockade& blockade::operator=(const blockade& block)
{
    order :: operator =(block);
    this->target = block.target;
    return *this;
}

void blockade::execute()
{
    Territory *t = getTerritory();
    if (validateCard()) {// checks if the player has blockade card in hands or not
        if (validate()) {// checks if the territory belongs to the player or not
            t->setNumOfArmies(t->getNumOfArmies() * 2);

            for (int x = 0; x < target->getOwner()->getterriortiesOwned().size(); x++) {
                if (target->getOwner()->getterriortiesOwned()[x] == t) {
                    this->target->getOwner()->removeTerritory(x);
                    cout << "removing territory " << t->getName();
                    break;
                }
            }
            cout << "Blockade order is executed " << endl;
            cout << "Now the territory has " << t->getNumOfArmies() << " armies and the ownership of "<< t->getName() <<  " is transfered to this player " << t->getOwner()->getName() << endl;
        }
        else {
            cout << "Can't Execute from blockade order";
        }
    }
    else {
        cout << "The player doesn't own have the blockade card in hand";
    }
}
bool blockade::validate()
{
    Territory* target = getTerritory();
    Player* p = getOwner();
    for (int i = 0; i < p->getterriortiesOwned().size(); i++) {
        if (p->getterriortiesOwned()[i] == target)
        {
            return true;
        }
    }
    return false;
}

blockade::blockade()
{
    this->target = NULL;
    this->type = "blockade";

}
ostream& operator<<(ostream& cout, blockade& b)
{
    b.write(cout);
    return cout;
}

blockade::blockade(blockade* vl) {
    this->target = vl->target;
    this->type = vl->type;
}
Territory* blockade::getTerritory()// returns the territory
{
    return target;
}

void blockade::setTargetTerritory(Territory* targetTerritory) {
    this->target = targetTerritory;
}
bool blockade::validateCard()
{
    Player* p = getOwner();
    for (int i = 0; i < p->getHand()->getCard().size(); i++)
    {
        if (p->getHand()->getCard()[i]->getCard() == Card::Blockade) {
            return true;
        }
    }
    return false;
}
/////the comments are exactly the same as the other subclasses
//negotiate
negotiate& negotiate::operator=(const negotiate& n)
{
    order:: operator=(n);
    this->TargetPlayer = n.TargetPlayer;
    return *this;
}
negotiate::negotiate()
{
    this->TargetPlayer = NULL;
    this->type = "negotiate";
}

negotiate::negotiate(Player* target, Player* source) : TargetPlayer(target)
{
    this->type = "negotiate";
    this->owner = source;
}

negotiate::~negotiate()
{
    this->TargetPlayer = NULL;
}
ostream& operator<<(ostream& cout, negotiate& n)
{
    n.write(cout);
    return cout;
}
negotiate::negotiate(negotiate* neg) {
    this->type = neg->type;
    this->TargetPlayer = neg->TargetPlayer;
}
void negotiate::execute()
{
    if (validateCard()) {// checks if the player has dipolamcy card in their hands or not
        if (validate()) {// check if both players are the same or not
            // negotiatiolist will contain all players that the player issuing order has
            // and we will change the advancee order and bomb order so that of the player
            // that advance  and bomb( attacking orders )is issued on is in the negotiation list the order will be invalid
            getOwner()->addnegotiationlist(TargetPlayer);
            cout <<getOwner()->getnegotiateList().size();
            this->getTargetPlayer()->getnegotiateList().push_back(this->getOwner());
            cout << "Players had negotiatied and they will not attack each other for this turn"<<endl;
        }
        else
        {
            cout << "Can't execute negotiate order!\n";
        }
    }
    else
        cout << "The player doesn't own have the negotiate card in hand";

}
Player* negotiate::getTargetPlayer()// returns the target player
{
    return TargetPlayer;
}
void negotiate::setTargetPlayer(Player* P) {
    this->TargetPlayer = P;
}
bool negotiate::validate()
{
    Player *p = getTargetPlayer();
    Player* s = getOwner();
    int pID = p->getPlayerID();
    int sID = s->getPlayerID();
    if (sID == pID) {
        return false;
    }
    return true;
}
bool negotiate::validateCard()
{
    Player* p = getOwner();
    vector <Card*> card = p->getHand()->getCard();
    for (int i = 0; i < card.size(); i++)
    {
        if (card[i]->getCard() == Card::Diplomacy) {
            return true;
        }
    }
    return false;
}
negotiate* negotiate::clone()
{
    return new negotiate(this);
}
/////the comments are exactly the same as the other subclasses
//airlift
airlift& airlift::operator=(const airlift& air)
{
    order :: operator=(air);
    this->source = air.source;
    this->target = air.target;
    this->numbOfarmies = air.numbOfarmies;
    return *this;
}
airlift::airlift()
{
    this->source = NULL;
    this->target = NULL;
    this->type = "airlift";
    this->numbOfarmies = 0;
}

airlift::airlift(int numbOfarmies, Territory& source, Territory& to, Player* p) : numbOfarmies(numbOfarmies)
        , source(&source), target(&to)
{
    this->type = "airlift";
    this->owner = p;
}

airlift::~airlift()
{
    source = NULL;
    target = NULL;

}

airlift::airlift(airlift* air)
{

    this->numbOfarmies = air->numbOfarmies;
    this->source = air->source;
    this->target = air->source;
    this->type = air->type;
}
void airlift::setSourceTerritory(Territory* sourceTerritory) {
    this->source = sourceTerritory;
}

void airlift::setTargetTerritory(Territory* targetTerritory) {
    this->target = targetTerritory;
}

void airlift::execute()
{
    Territory* source = getSourceTerritory();
    Territory* target = getTargetTerritory();
    int olds = source->getNumOfArmies();
    int oldt = target->getNumOfArmies();
    if (validateCard()) {// checks if the player has airlift card in their hands
        if (validate()) {// if the source or target territory does not belong to the player it will not go inside the if statmnemnt

            if (this->numbOfarmies > source->getNumOfArmies()) {
                cout << source->getOwner()->getName() << " airlift armies greater than the number of armies in the source territory\n";
                cout << "Nothing chamges and the order was not executed \n";
                return;
            }
            source->setNumOfArmies(source->getNumOfArmies() - numbOfarmies);
            target->setNumOfArmies(numbOfarmies+target->getNumOfArmies());// moving the armies from source to target
            cout << "The airlift is executed" << endl;
            cout << "Now the source territory had " << olds << " armies but now it has " << source->getNumOfArmies() <<
                 " armies. The target territory had " << oldt << " armies and after airlift order execute, now it has "
                 << target->getNumOfArmies() << " armies." << endl;
        }
        else {
            cout << "Cant execute order airlift because either target or source doesnt belong to the player";
        }
    }
    else
        cout << "The player doesn't have airlift card in hand";


}
Territory* airlift::getSourceTerritory()// returns the source territory
{
    return source;
}

Territory* airlift::getTargetTerritory()// returns the target territory
{
    return target;
}

void airlift::setNumOfArmy(int n) {
    this->numbOfarmies = n;
}

bool airlift::validate()
{
    Territory* s = getSourceTerritory();
    Territory* t = getTargetTerritory();
    Player *p = getOwner();
    bool founds = false;
    bool foundt = false;
    for (auto ter : p->getterriortiesOwned()) {
        if (ter == s) {
            founds = true;
        }
        if (ter == t) {
            foundt = true;
        }
    }
    if ((founds == true) && (foundt == false)) {
        return false;
    }
    if ((founds == false) && (foundt == true)) {
        return false;
    }
    // if neither source nor target terriorty belongs to the player it is invalid
    if ((founds == true) && (foundt == true)) {
        return true;
    }
    return false;
}

bool airlift::validateCard()
{
    Player* p = getOwner();
    vector <Card*> card = p->getHand()->getCard();
    for (int i = 0; i < card.size(); i++)
    {
        if (card[i]->getCard() == Card::Airlift) {
            return true;
        }
    }
    return false;
}

airlift* airlift::clone()
{
    return new airlift(this);
}
ostream& operator<<(ostream& cout, airlift& ai)
{
    ai.write(cout);
    return cout;
}
/////the comments are exactly the same as the other subclasses
//bomb
bomb& bomb::operator=(const bomb& bom)
{
    order :: operator =(bom);
    this->target = bom.target;
    return *this;
}

bomb::bomb()
{
    this->target = NULL;
    this->type = "bomb";
}

bomb::bomb(Territory& target, Player* p)
{
    this->type = "bomb";
    this->target = &target;
    this->owner = p;
}

bomb::~bomb()
{
    target = NULL;
}

void bomb::execute() {
    if (this->validate()) {
        std::cout << "Executing Bomb Order" << std::endl;
        // Remove half of the army units from the target territory
        int currentArmies = target->getNumOfArmies();
        int halfArmies = currentArmies / 2;
        target->setNumOfArmies(halfArmies);

        std::cout << "Half of the army units removed from " << target->getTerritoryName() << std::endl;

        this->executed = true;
    }
}

bool bomb::validate() {
    if (!target || target->getOwner() == this->getOwner() || !this->getTerritory()->isAdjacent(*target)) {
        std::cout << "Bomb order is invalid" << std::endl;
        return false;
    }
    return true;
}
Territory* bomb::getTerritory()
{
    return target;
}

void bomb::setTargetTerritory(Territory* targetTerritory) {
    this->target = targetTerritory;
}

bomb* bomb::clone()
{
    return new bomb(this);
}
bool bomb::validateCard()
{
    Player* p = getOwner();
    vector <Card*> card = p->getHand()->getCard();
    for (int i = 0; i < card.size(); i++)
    {
        if (card[i]->getCard() == Card::Bomb) {
            return true;
        }
    }
    return false;
}

bomb::bomb(bomb* bom) {
    this->target = bom->target;
    this->type = bom->type;

}
ostream& operator<<(ostream& cout, bomb& b)
{
    b.write(cout);
    return cout;
}
//destructor destroys all the objects inside the list
orderlist::~orderlist()
{

    for (int x = 0; x < list.size(); x++) {
        delete this->list[x];
    }
    this->list.clear();

}
//default constructor
orderlist::orderlist()
{
    std::cout << "OrdersList created " << std::endl;
}

// copy constructor
orderlist::orderlist(const orderlist& ordersList)
{
    this->list = ordersList.list;
}

// add an order to the list
void orderlist::addOrder(order* order)
{
    this->list.push_back(order);
}

// get next order on the list
order* orderlist::getFirstOrder()
{
    return list.back();
    }

// remove an order from the list [takes an int, which is a menu number]
void orderlist::remove(int num)
{
    delete list[num];  // delete the order from heap when removed
    this->list.erase(this->list.begin() + num);

    std::cout << "an order was removed\n" << std::endl;
}

// swap two orders in the list [takes two ints, which are menu numbers]
void orderlist::move(int a, int b)
{
    // index is one less than menu numbering
    a--;
    b--;

    order* temp = this->list[a];

    this->list[a] = this->list[b];
    this->list[b] = temp;

    std::cout << "orders were swapped\n" << std::endl;
}

// assignment operator
orderlist& orderlist::operator=(const orderlist& orderslist)
{
    this->list = orderslist.list;

    return *this;
}

// stream insertion operator overload
ostream& operator<<(ostream& cout, const orderlist& l)
{
    for (int x = 0; x < l.list.size(); x++) {

        cout << *(l.list[x]);
    }
    return cout;
}