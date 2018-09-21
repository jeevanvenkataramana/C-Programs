#ifndef BILL_H
#define BILL_H
#include<iostream>
#include<string>
#include"Order.h"
#include"Item.h"
using namespace std;
class Bill
{
int billid;
int rid;
int paymentid;
int status;
Order order;
string date;
float stax;
float vat;
float hd;
float tSum;
public:
Bill();
Bill(int,int,int,int,Order,string,float,float,float,float);
//Bill(int,int,Order,string,float,float,float,float);
int getBillId();
int getRestId();
int getPaymentId();
int getStatus();
Order getOrder();
string getDate();
float getStax();
float getVat();
float getHd();
float getTsum();
};
#endif

