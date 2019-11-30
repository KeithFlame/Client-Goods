#pragma once
#include<iostream>
#include<map>
#include<string>
//不要在头文件里using namespace或者using std::map
//想想为啥    ---因为头文件被打开的次数较多，会导致多次加载。


//为啥取名叫CMail，含义?     ----拼错了  -_-||
class Shop {
public:
	Shop() {
		calcArrange();
		initCart();
	};

	void checkMemberRank(char memberrank = 0);
	//随着产品种类的增加，这个类的接口会不会爆炸？               ----会
	//void countNestCoffee(double coffee = 0);
	//void countCoffeeCups(double cups = 0);
	//void countChocolates(double chocolates = 0);
	//void countFruitTea(double tea = 0);

	double selectGoods(std::map<std::string, int> &shopList);

	std::map<std::string, int> shopList;
private:

	double calcCost();
	void calcArrange();
	void initCart();
	double m_memberDiscount = 1.0;
	//typedef std::map<double, int> m_goods;
	std::map<std::string, double> m_price;
	std::map<std::string, int> countAllCost;

};
