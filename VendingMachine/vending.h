#pragma once
#include <string>
#include <vector>
#include <stack>
#include <deque>

class CashSlot
{
private:
	int m_money;

public:
	CashSlot();
	~CashSlot();
	CashSlot(int money);

public:
	void deposit(int money);
	int checkout();
};

class PanelSlot
{
private:
	int m_row;
	int m_column;

public:
	PanelSlot();
	~PanelSlot();

public:
	void chooseSnack(int row, int column);
	Snack* purchaseSnack(VendingMachine* vm);
};

class Snack
{
private:
	const std::string m_name;
	const int m_price = 50;
	const int m_calories = 50;

public:
	Snack();
	Snack(std::string name);
	Snack(std::string name, int price);
	Snack(std::string name, int price, int calories);

	~Snack();
};

class VendingMachine
{
private:
	const PanelSlot m_panel;
	const CashSlot m_cash;
	std::vector<std::stack<Snack>> m_container;
	const int slots;
	const int accessCode;
	int revenue = 0;
public:
	VendingMachine();
	VendingMachine(int slots);
	VendingMachine(int slots, int accessCode);
	~VendingMachine();
public:

};
