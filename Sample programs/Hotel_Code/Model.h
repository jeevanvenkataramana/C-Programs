#ifndef MODEL_H
#define MODEL_H
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include"Item.h"
#include"Order.h"
#include"Bill.h"
using namespace std;
class Model
{
//vector<Item> itemlist;
vector<Order> orderlist;
vector<Bill> billlist;
vector<Bill> paymentList;
public:
void add();
Model();
void addOrderList(Order);
Order viewOrder(int);
void cancelOrder(int);
Order updateOrder(int,int,int,int);
int generateOrderId();
int generateBillId();
Bill generateBill(int,Order);
int checkOrderId(int);
int checkBillId(int);
void cancelBill(int);
Bill viewBill(int);
float getDailySales(int,int,int);
int checkMonth(int);
int checkRestaurantId(int);
};
#endif


