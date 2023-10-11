
/*
contains a free function named testOrdersLists() that creates a list of orders and demonstrates that the OrdersList implemented
Here : remove, move of the orderlist will be tested, expected result shown commented

*/

#include "Orders.h"


void testOrdersLists()
{
    std::cout << "test OrderDriver" << std::endl;

    Deploy deploy_test = Deploy();
    Advance advance_test = Advance();
    Bomb bomb_test = Bomb();
    Blockade blockade_test = Blockade();
    Airlift airlift_test = Airlift();
    Negotiate negotiate_test = Negotiate();



    // create an OrdersList object to hold the orders
    std::cout << "create an OrdersList :\n" << std::endl;
    OrdersList orderslist_test = OrdersList();

    std::cout << std::endl;

    // place pointers to all the action objects in the list
    orderslist_test.addOrder(&deploy_test);
    orderslist_test.addOrder(&advance_test);
    orderslist_test.addOrder(&bomb_test);
    orderslist_test.addOrder(&blockade_test);
    orderslist_test.addOrder(&airlift_test);
    orderslist_test.addOrder(&negotiate_test);



    // print out the contents of the orderlist
    std::cout << "\n the orderslist contains :\n" << std::endl;
    std::cout << orderslist_test << std::endl;

    // removing blockade
    std::cout << " -- removing blockade Order from the list :\n" << std::endl;
    orderslist_test.remove(4);
    std::cout << orderslist_test << std::endl;

    // swapping orders
    orderslist_test.move(3, 1);
    std::cout << orderslist_test << std::endl;

  //check result
    Order* nextOrder = orderslist_test.getNextOrder();
    nextOrder->execute();
    std::cout << std::endl << orderslist_test << std::endl;


}