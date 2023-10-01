/*
contains a free function named testOrdersLists() that creates a list of orders and demonstrates that the OrdersList implemented
Here : remove, move of the orderlist will be tested, expected result shown commented

*/
#include "Orders.h"

using namespace std;

int main()
{
	cout << "test OrderDriver...\n" << endl;
	OrderList anOrderList;

	Deploy aDeploy;
	Advance anadvance;
	Bomb abomb;
	Blockade ablockade;
	Airlift anairlift;
	Negotiate anegotiate;

	anOrderList.add_order_list(&aDeploy);
	anOrderList.add_order_list(&anadvance);
	anOrderList.add_order_list(&abomb);
	anOrderList.add_order_list(&ablockade);
	anOrderList.add_order_list(&anairlift);
	anOrderList.add_order_list(&anegotiate);


	//print orderlist
	cout << "\n the orderlist contains: " << endl;
	for (int i = 0; i < anOrderList.get_order_list()->size(); i++) {
		cout << "  " << anOrderList.get_order_list()->at(i)->get_type() << endl;
	}

	//removing an order
	anOrderList.remove_order(&aDeploy);

	//check output
	cout << "\n the orderlist contains: " << endl;
	for (int i = 0; i < anOrderList.get_order_list()->size(); i++) {
		cout << "  " << anOrderList.get_order_list()->at(i)->get_type() << endl;
	}

	anOrderList.move(0, 4); //expected result= will move advance in the list

	anOrderList.move(0, 8);//expected result= result in error since there is not 8 position

	//check result
	cout << "\n the orderlist contains: " << endl;
	for (int i = 0; i < anOrderList.get_order_list()->size(); i++) {
		cout << "  " << anOrderList.get_order_list()->at(i)->get_type() << endl;
	}

}