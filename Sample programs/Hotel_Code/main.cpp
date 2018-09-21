#include <iostream>
#include<string>
#include"Controller.h"
#include"Ui.h"
#include"Model.h"


using namespace std;

int main()
{
	Ui ui;
	Model m;
	Controller c;
	c.Add(ui,m);
	c.initiatePayment(ui,m);
	return 0;
}


