#include "member_shopping.h"
#include"gtest/gtest.h"

//浮点数比较不要用EXPECT_EQ
//测试用例的文件名最好采用test_XXXX.cpp
//现实需求中，往往是商店里有上万种商品，而单个用户一次只会购买较少种类的商品。目前的实现会有啥问题？
//考虑到实际的收银过程，同一种类的商品有可能会分几次扫描、计价，目前的实现能否满足需求？
//例如：oneshopping.countNestCoffee(1); oneshopping.countNestCoffee(3); 最终结果应该给是48*3




//add or remove some goods
void firstShop(std::map<std::string, int> &shopList) {
	//std::map<std::string, int> shopList;
	shopList["NestCoffee"] = 0;
	shopList["CoffeeCups"] = 1;
	shopList["Chocolates"] = 3;
	shopList["FruitTea"] = 5;
	
}

//add or remove some goods
void secondShop(std::map<std::string, int>& shopList) {
	//std::map<std::string, int> shopList;
	shopList["NestCoffee"] = 4;
	shopList["CoffeeCups"] = 1;
	shopList["Chocolates"] = 0;
	shopList["FruitTea"] = 2;

}

//add or remove some goods
void thirdShop(std::map<std::string, int>& shopList) {
	//std::map<std::string, int> shopList;
	shopList["NestCoffee"] = -8;
	shopList["CoffeeCups"] = -1;
	shopList["Chocolates"] = -4;
	shopList["FruitTea"] = -5;

}
//once 
TEST(CMailTest, test_when_member_GOLD_buy_a_coffee) {
	Shop oneshopping;

	oneshopping.checkMemberRank('A');
	firstShop(oneshopping.shopList);
	EXPECT_FLOAT_EQ(716.76, oneshopping.selectGoods(oneshopping.shopList));
}

// add some goods
TEST(CMailTest, test_when_member_NON_buy_a_coffee) {
	Shop oneshopping;
	oneshopping.checkMemberRank('A');
	firstShop(oneshopping.shopList);
	oneshopping.selectGoods(oneshopping.shopList);
	secondShop(oneshopping.shopList);
	EXPECT_FLOAT_EQ(1175.16, oneshopping.selectGoods(oneshopping.shopList));
}

//remove some goods
TEST(CMailTest, test_when_member_NON_buy_a_coffee_and_5_chocolates) {
	Shop oneshopping;
	firstShop(oneshopping.shopList);
	oneshopping.selectGoods(oneshopping.shopList);
	secondShop(oneshopping.shopList);
	oneshopping.selectGoods(oneshopping.shopList);
	thirdShop(oneshopping.shopList);
	oneshopping.checkMemberRank('A');

	EXPECT_FLOAT_EQ(266.40, oneshopping.selectGoods(oneshopping.shopList));
}

//NO VIP
TEST(CMailTest, test_when_member_NON_buy_a_coffee_and_1_chocolate_and_1_tea_and_3_cups) {
	Shop oneshopping;
	firstShop(oneshopping.shopList);
	oneshopping.selectGoods(oneshopping.shopList);
	secondShop(oneshopping.shopList);
	oneshopping.selectGoods(oneshopping.shopList);
	thirdShop(oneshopping.shopList);
	EXPECT_FLOAT_EQ(296, oneshopping.selectGoods(oneshopping.shopList));
}

