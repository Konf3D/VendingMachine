#include <iostream>
#include "vending.h"
int main()
{
	VendingMachine vm;
	Slot slot;
	Snack* snickers = new Snack("Snickers",30,120);
	Snack* twix = new Snack("twix", 40, 110);
	Snack* mars = new Snack("Mars", 45, 115);

	slot.push(*snickers);
	slot.push(*twix);
	slot.push(*mars);

	vm.insertSlot(slot);

	vm.deposit(100);
	vm.selectSlot(0);

	vm.purchase();

	auto hand1 = vm.grabPurchasedItem();

	system("pause");

}