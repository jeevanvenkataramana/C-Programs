#ifndef ORDER_H
#define ORDER_H
#include<iostream>
#include<string>
#include"Item.h"
using namespace std;
class Order
{
int orderid;
int rid;
vector<Item> itemlist;
int option;
public:
Order();
Order(int,int,vector<Item>,int);
//Order(int,int,vector<Item>,int,string,int,string);
int getOrderId();
int getRestId();
vector<Item> getItem();
int getOption();
//string getName();
//int getPhone();
//string getAddress();
};
#endif

