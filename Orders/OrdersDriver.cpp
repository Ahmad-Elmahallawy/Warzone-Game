
/*
contains a free function named testOrdersLists() that creates a list of orders and demonstrates that the OrdersList implemented
Here : remove, move of the orderlist will be tested, expected result shown commented

*/
#include "../Map/Map.h"
#include "../Orders/Orders.h"
#include "../Players/Player.h"
#include "Orders.h"
#include <iostream>

// OrdersDriver.cpp

#include "Orders.h"

void testOrdersLists() {
    //create objects of order and its subclasses

    bomb* b1 = new bomb();
    deploy * d1 = new deploy();
    airlift *a1 = new airlift();
    negotiate *n = new negotiate();
    blockade* bk = new blockade();
    advancee* adv = new advancee();
    //create order list
    orderlist list;
    //use push method
    list.addOrder(a1);
    list.addOrder(b1);
    list.addOrder(d1);
    list.addOrder(n);
    list.addOrder(bk);
    list.addOrder(adv);
    cout << "--use stream insertion operator of list--\n";
    cout << list;
    cout << "-------------------\n";
    cout << "use validate and execut with all objects";
    list.showmethods();
    cout << "-------------------\n";

    list.move(4, 1);
    cout << "--move position 4 to 1--\n";

    cout << list;
    cout << "-------------------\n";
    cout << "--remove--order in position 4\n";
    list.remove(4);
    cout << list;
    cout << "-------------------\n";

    orderlist list2 = list;
    cout << "---using copy constructor---\n";

    cout << list2;
    cout << "-------------------\n";
    orderlist list3;
    list3 = list2;
    cout << "---using assignement operator---\n";
    cout << list2;
}
