#ifndef ITEM_H
#define ITEM_H
#include<iostream>
#include <cstring>
#include<vector>
using namespace std;

class Item
{
int menuid;
string menuname;
int dishid;
string dishname;
int qty;
int price;
public:
Item();
Item(int,string,int,string,int,float);
int getMenuId();
string getMenuName();
int getDishId();
string getDishName();
int getQty();
float getIprice();
};
#endif
