#pragma once
#include <string>
#include <vector>
#include <stack>
#include <queue>


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
	int m_position;

public:
	PanelSlot();
	~PanelSlot();

public:
	void setPosition(int position);
	int getPosition();
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
public:
	std::string getName() const;
	int getPrice() const;
	int getCalories() const;
};

using Slot = std::stack<Snack>; // sloth
class VendingMachine
{
private:
	PanelSlot m_panel;
	CashSlot m_cash;
	std::vector<Slot> m_container;
	std::queue<Snack> m_dispenser;
	const int m_slots;
	const int m_accessCode;
	int m_revenue;
	int m_slotsTaken = 0;
public:
	VendingMachine();
	VendingMachine(int slots);
	VendingMachine(int slots, int accessCode);
	~VendingMachine();
public:
	Slot insertSlot(Slot slot);
	Slot extractSlot(int slotPosition, int accessCode);
	void deposit(int money);
	int checkout();
	bool purchase();
	Snack grabPurchasedItem();
	void selectSlot(int position);
};
