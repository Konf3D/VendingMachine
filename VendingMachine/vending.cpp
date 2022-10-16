#include "vending.h"

CashSlot::CashSlot()
	:m_money(0)
{

}

CashSlot::~CashSlot()
{
}

CashSlot::CashSlot(int money)
	:m_money(money)
{
}

void CashSlot::deposit(int money)
{
	m_money += money;
}

int CashSlot::checkout()
{
	return m_money;
}

PanelSlot::PanelSlot()
	:m_row(0),m_column(0)
{
}

PanelSlot::~PanelSlot()
{
}

void PanelSlot::chooseSnack(int row, int column)
{
	m_row = row;
	m_column = column;
}

Snack* PanelSlot::purchaseSnack(VendingMachine* vm)
{
	return nullptr;
}

Snack::Snack()
	:m_name("unnamed"),m_price(50),m_calories(100)
{
}

Snack::Snack(std::string name)
	: m_name(name), m_price(50), m_calories(100)
{
}

Snack::Snack(std::string name, int price, int calories)
	: m_name(name), m_price(price), m_calories(calories)
{
}

Snack::Snack(std::string name, int price)
	: m_name(name), m_price(price), m_calories(100)
{
}

Snack::~Snack()
{
}
