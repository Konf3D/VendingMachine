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
	:m_position(0)
{
}

PanelSlot::~PanelSlot()
{
}

int PanelSlot::getPosition()
{
	return m_position;
}

void PanelSlot::setPosition(int position)
{
	m_position = position;
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

std::string Snack::getName() const
{
	return m_name;
}

int Snack::getPrice() const
{
	return m_price;
}

int Snack::getCalories() const
{
	return m_calories;
}

VendingMachine::VendingMachine()
	:m_cash(),m_panel(),m_slots(25),m_accessCode(0),m_revenue(0)
{

}
VendingMachine::VendingMachine(int slots)
	: m_cash(), m_panel(), m_slots(slots), m_accessCode(0),m_revenue(0)
{

}
VendingMachine::VendingMachine(int slots, int accessCode)
	: m_cash(), m_panel(), m_slots(25), m_accessCode(accessCode),m_revenue(0)
{

}
VendingMachine::~VendingMachine()
{

}

void VendingMachine::deposit(int money)
{
	m_revenue += money;
}

int VendingMachine::checkout()
{
	const int change = m_revenue;
	m_revenue = 0;
	return change;
}

bool VendingMachine::purchase()
{
	const int snackPosition = m_panel.getPosition();

	if (snackPosition < 1)
		return false;

	if (m_container.at(snackPosition).empty())
		return false;

	Snack purchased = m_container.at(snackPosition).top();
	if (purchased.getPrice() > m_revenue)
		return false;

	m_container.at(snackPosition).pop();

	m_cash.deposit(purchased.getPrice());
	m_revenue -= purchased.getPrice();

	m_dispenser.emplace(std::move(purchased));
	return true;
}

Slot VendingMachine::insertSlot(Slot slot,int position)
{
	if (!m_container.at(position).empty() || position > m_container.size() || position < 1)
		return slot;
	++m_slotsTaken;
	std::swap(slot, m_container.at(++position));
	return slot;
}

Slot VendingMachine::extractSlot(int position, int accessCode = 0)
{
	auto temp = Slot();
	if (accessCode != m_accessCode || position > m_container.size() || position < 1)
		return temp;

	const Slot slot = m_container.at(position);
	std::swap(temp, m_container.at(position));

	return slot;
}