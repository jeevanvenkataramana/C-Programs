#ifndef CONTROLLER_H
#define CONTROLLER_H
#include<iostream>
#include<string>
#include"Model.h"
#include"Ui.h"
#include"Bill.h"
#include"Order.h"
#include"Item.h"

using namespace std;

class Controller
{
	public:
	void Add(Ui &,Model &);
	void initiatePayment(Ui &,Model &);
	void initiateGenerateBill(Ui &,Model &);
	void initiateViewBill(Ui &,Model &);
	void initiateCancelBill(Ui &,Model &);
	void initiateCreatePayment(Ui &, Model &);
	void initiateViewPayment(Ui &,Model &);
	void initiateCancellation(Ui &,Model &);
	void initiateSalesHistory(Ui &,Model &);



};
#endif


