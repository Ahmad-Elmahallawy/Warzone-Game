
#include "../Map/Map.h"
#include "../Orders/Orders.h"
#include "../Players/Player.h"
#include <iostream>
#include <string>
#include <algorithm>

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
//ostream& operator<<(ostream& cout, const order& d)
//{
//    d.write(cout);
//    return cout;
//}
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
bool deploy::validate() {
    Player *p = getOwner();
    Territory *target = getTerrority();

    if (!p || !target) {
        std::cout << "Deploy order validation failed: Owner or target is null." << std::endl;
        return false;
    }

    const auto& territoriesOwned = p->getterriortiesOwned();  // Use the correct method name here
    if (std::find(territoriesOwned.begin(), territoriesOwned.end(), target) == territoriesOwned.end()) {
        std::cout << "Deploy order validation failed: Territory does not belong to the player." << std::endl;
        return false;
    }

    return true;
}

//return a ostream cout for printing the objecr
ostream& operator<<(std::ostream& out, deploy& d)
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
// In deploy::execute()
void deploy::execute() {
    Territory *target = getTerrority();
    if (validate()) {
        int currentArmies = target->getNumOfArmies();
        target->setNumOfArmies(currentArmies + numbOfArmies);
        std::cout << "The deploy order is executed" << std::endl;
        std::cout << "The number of armies are moved to " << target->getName()
                  << " and now the number of this territory is " << target->getNumOfArmies() << " armies." << std::endl;
    } else {
        std::cout << "Can't execute order since the territory doesn't belong to the player" << std::endl;
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
void deploy::write(std::ostream& out) {
    out << "Deploy Order: Number of Armies = " << numbOfArmies
        << ", Target Territory = " << (target ? target->getName() : "null")
        << ", Issued by Player = " << (owner ? owner->getName() : "null");
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
deploy* deploy::clone()
{
    return new deploy(this);
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
    if (!owner || !source || !target) {
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

void blockade::execute() {
    // ... existing validation checks ...

    Territory* t = getTerritory();
    Player* originalOwner = t->getOwner();

    // Double the number of armies in the target territory
    t->setNumOfArmies(t->getNumOfArmies() * 2);

    // Transfer ownership to the neutral player
    t->setOwner(neutralPlayer);

    // Find the index of the territory in the original owner's list
    vector<Territory *> terriortiesOwned = originalOwner->getterriortiesOwned();
    auto it = std::find(terriortiesOwned.begin(), terriortiesOwned.end(), t);
    if (it != terriortiesOwned.end()) {
        int index = std::distance(terriortiesOwned.begin(), it);
        originalOwner->removeTerritory(index);
    }

    // Add the territory to the neutral player's list
    neutralPlayer->addTerriorty(t);

    cout << "Blockade order is executed." << endl;
    cout << "Now the territory '" << t->getName() << "' has " << t->getNumOfArmies()
         << " armies and the ownership is transferred to the neutral player." << endl;
}


bool blockade::validate() {
    Territory* target = getTerritory();
    Player* p = getOwner();
    if (!p || !target) return false;
    if (target->getOwner() != p) return false;
    return true;
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
void blockade::write(std::ostream& out) {
    out << "Blockade Order: Territory = " << (target ? target->getName() : "null")
        << ", Owner = " << (owner ? owner->getName() : "null");
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
void negotiate::execute() {
    if (!validateCard()) {
        cout << "Cannot execute negotiate order: player does not have the diplomacy card." << endl;
        return;
    }

    if (!validate()) {
        cout << "Cannot execute negotiate order: target player is the same as the issuing player." << endl;
        return;
    }

    // Add negotiation status between the players
    getOwner()->addnegotiationlist(TargetPlayer);
    TargetPlayer->addnegotiationlist(getOwner());

    cout << "Negotiate order executed: " << getOwner()->getName() << " and "
         << TargetPlayer->getName() << " cannot attack each other for this turn." << endl;
}

Player* negotiate::getTargetPlayer()// returns the target player
{
    return TargetPlayer;
}
void negotiate::setTargetPlayer(Player* P) {
    this->TargetPlayer = P;
}
bool negotiate::validate() {
    if (!TargetPlayer || !getOwner())
        return false;
    return TargetPlayer != getOwner();
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
void negotiate::write(std::ostream&)
{
    cout << "prevent attacks between the current player and another target player until the end of the turn.\n";
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

airlift::airlift(airlift* air) {
    this->numbOfarmies = air->numbOfarmies;
    this->source = air->source;
    this->target = air->target; // Corrected to copy the target territory
    this->type = air->type;
}

void airlift::setSourceTerritory(Territory* sourceTerritory) {
    this->source = sourceTerritory;
}

void airlift::setTargetTerritory(Territory* targetTerritory) {
    this->target = targetTerritory;
}

void airlift::execute() {
    // Check if the player has the airlift card
    if (!validateCard()) {
        cout << "Cannot execute airlift order: player does not have an airlift card." << endl;
        return;
    }

    // Check if both territories belong to the player and are valid
    if (!validate()) {
        cout << "Cannot execute airlift order: one or both territories do not belong to the player." << endl;
        return;
    }

    // Check if there are sufficient armies in the source territory
    if (this->numbOfarmies > source->getNumOfArmies()) {
        cout << "Cannot execute airlift order: insufficient armies in the source territory." << endl;
        return;
    }

    // Perform the airlift operation
    source->setNumOfArmies(source->getNumOfArmies() - numbOfarmies);
    target->setNumOfArmies(target->getNumOfArmies() + numbOfarmies);

    // Log the results
    cout << "The airlift order is executed." << endl;
    cout << "The source territory '" << source->getName() << "' had " << source->getNumOfArmies() + numbOfarmies
         << " armies, now has " << source->getNumOfArmies() << " armies." << endl;
    cout << "The target territory '" << target->getName() << "' had " << target->getNumOfArmies() - numbOfarmies
         << " armies, now has " << target->getNumOfArmies() << " armies." << endl;
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
    Player* p = getOwner();

    // Check if the source and target territories belong to the player
    bool foundSource = (std::find(p->getterriortiesOwned().begin(), p->getterriortiesOwned().end(), s) != p->getterriortiesOwned().end());
    bool foundTarget = (std::find(p->getterriortiesOwned().begin(), p->getterriortiesOwned().end(), t) != p->getterriortiesOwned().end());

    // If both source and target territories belong to the player, the order is valid
    if (foundSource && foundTarget) {
        return true;
    }

    // If either source or target territory does not belong to the player, the order is invalid
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
void airlift::write(std::ostream& out) {
    out << "Airlift Order: Moving " << this->numbOfarmies
        << " armies from " << (source ? source->getName() : "unknown")
        << " to " << (target ? target->getName() : "unknown");
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
    // Check if the player has the bomb card
// if (!validateCard()) {
//        std::cout << "Cannot execute bomb order: player does not have a bomb card." << std::endl;
//        return;  // Ensure this return statement properly exits the method
//    }

    // Validate if the target territory belongs to another player and is adjacent
    if (!validate()) {
        std::cout << "Bomb order is invalid: target territory is either owned by the player or not adjacent." << std::endl;
        return;
    }

    // Execute the bomb order by removing half of the army units from the target territory
    int currentArmies = target->getNumOfArmies();
    int halfArmies = currentArmies / 2;
    target->setNumOfArmies(halfArmies);

    std::cout << "Half of the army units removed from " << target->getTerritoryName() << std::endl;
}


bool bomb::validate() {
    // Check if the target territory is null
    if (!target) {
        std::cout << "Bomb order validation failed: Target territory is null." << std::endl;
        return false;
    }

    // Check if the target territory is owned by the player issuing the order
    if (target->getOwner() == this->getOwner()) {
        std::cout << "Bomb order validation failed: Target territory is owned by the player." << std::endl;
        return false;
    }

    // Check if the target territory is adjacent to any of the player's territories
    bool isAdjacentToAny = false;
    const auto& territoriesOwned = this->getOwner()->getterriortiesOwned();
    for (const auto& territory : territoriesOwned) {
        if (territory->isAdjacent(*target)) {
            isAdjacentToAny = true;
            break;
        }
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
//bool bomb::validateCard() {
//    Player* p = getOwner();
//    vector <Card*> card = p->getHand()->getCard();
//    std::cout << "Checking player's hand for a bomb card...\n";
//    for (int i = 0; i < card.size(); i++) {
//        std::cout << "Card " << i << ": " << card[i]->getCard() << std::endl;
//        if (card[i]->getCard() == Card::Bomb) {
//            std::cout << "Bomb card found.\n";
//            return true;
//        }
//    }
//    std::cout << "No bomb card in hand.\n";
//    return false;
//}


bomb::bomb(bomb* bom) {
    this->target = bom->target;
    this->type = bom->type;

}
void bomb::write(std::ostream& out) {
    out << "Bomb Order: Target Territory = " << (target ? target->getName() : "unknown");
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

void orderlist::remove(int num) {
    if (num < 0 || num >= list.size()) {
        std::cerr << "Invalid index for removal." << std::endl;
        return;
    }

    delete list[num];  // delete the order from heap when removed
    list.erase(list.begin() + num);
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
/*ostream& operator<<(ostream& cout, const orderlist& b)
{
    for (int x = 0; x < b.list.size(); x++) {

        cout << *(b.list[x]);
    }
    return cout;
}*/