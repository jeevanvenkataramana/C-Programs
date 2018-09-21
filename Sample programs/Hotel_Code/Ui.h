#ifndef BOOKING_H
#define BOOKING_H
#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include"Order.h"
#include"Bill.h"
#include"Item.h"
using namespace std;

class Ui
{
	public:
	int displayMainMenu();
	void displayTitle();
	int enterOrderId();
	int enterBillId();
	void displayBill(Bill);
	void displayItem(vector<Item>);
	void displayString(string);
	int displayConfirmation();
	void displayMonthlySalesHistory();
	int getRestaurantId();
	int displayConfirmation1();
	int getMonth();
	void displayDailySales(int,int,float);
	void displayTotalSum(float);
};
#endif
