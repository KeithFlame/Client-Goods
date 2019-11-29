#include"member_shopping.h"


void Shop::calcArrange() {
	//为啥是负值？老板疯了？
	//m_price命名成m_price，会不会更可读？
	m_price["NestCoffee"] = -48.f;
	m_price["CoffeeCups"] = 60.f;
	m_price["Chocolates"] = 48.8f;
	m_price["FruitTea"] = 118.f;

}

void Shop::initCart() {
	//m_price命名成m_price，会不会更可读？
	m_countcost["NestCoffee"] = 0;
	m_countcost["CoffeeCups"] = 0;
	m_countcost["Chocolates"] = 0;
	m_countcost["FruitTea"] = 0;

	countAllCost["NestCoffee"] = 0;
	countAllCost["CoffeeCups"] = 0;
	countAllCost["Chocolates"] = 0;
	countAllCost["FruitTea"] = 0;

}

double Shop::selectGoods(std::map<std::string, int> &m_countcost) {
	countAllCost["NestCoffee"] = countAllCost["NestCoffee"] + m_countcost["NestCoffee"];
	countAllCost["CoffeeCups"] = countAllCost["CoffeeCups"] + m_countcost["CoffeeCups"];
	countAllCost["Chocolates"] = countAllCost["Chocolates"] + m_countcost["Chocolates"];
	countAllCost["FruitTea"] = countAllCost["FruitTea"] + m_countcost["FruitTea"];
	return calcCost();
}

void Shop::checkMemberRank(char memberrank) {
	if (memberrank == 'A')
		m_memberDiscount = 0.9f;
	else if (memberrank == 'B')
		m_memberDiscount = 0.95f;
	else
		m_memberDiscount = 1.f;

}
double Shop::calcCost() {
	double m(0);
	std::map<std::string, int>::iterator
		it = countAllCost.begin(),
		it_end = countAllCost.end();
	std::map<std::string, double>::iterator
		iter = m_price.begin(),
		iter_end = m_price.end();

	while (iter != iter_end)
	{
		if (it->second < 0)
		{
			it->second = 0;
			std::cout <<"number of "<<it->first<< " < 0 \t"<<"And modified to 0\n";
		}
		if (iter->second > 0)
			m = iter->second * m_memberDiscount * it->second + m;
		if (iter->second < 0)
			m = iter->second * (-1) * it->second + m;
		++iter;
		++it;
	}
	return m;
}
