#include<iostream>
#include<vector>
#include"Controller.h"
#include"Bill.h"
#include<cstdlib>
using namespace std;

void Controller::Add(Ui &ui,Model &m)
{

m.add();

}
void Controller::initiatePayment(Ui &ui,Model &m)
{
	int ch=ui.displayMainMenu();

		switch(ch)
		{
			case 1:
				initiateGenerateBill(ui,m);
				break;
			case 2:
				initiateViewBill(ui,m);
				break;
			case 3:
				initiateCancelBill(ui,m);
				break;
			case 4:
				//initiateCreatePayment(ui,m);
				break;
			case 5:
				//initiateViewPayment(ui,m);
				break;
			case 6:
				//initiateViewCancellation(ui,m);
				break;
			case 7:
				initiateSalesHistory(ui,m);
                                break;
			case 8:
				exit(0);
				break;
		}

}
void Controller::initiateGenerateBill(Ui &ui,Model &m)
{
int oid=ui.enterOrderId();
int j=m.checkOrderId(oid);
	if(j==0)
	{
		ui.displayString("\n\torder id does not exist");
		ui.displayString("\n\tDo you want to enter Order ID again?");
		int temp=ui.displayConfirmation();
		if(temp==1)
		{
			system("clear");
			initiateGenerateBill(ui,m);
		}
		else
		{
			system("clear");
			initiatePayment(ui,m);
		}
	}

int bid=m.generateBillId();
Order o=m.viewOrder(oid);
//ui.displayOrder(Order);
Bill bb=m.generateBill(bid,o);

ui.displayBill(bb);
ui.displayString("\n\tTo generate another bill\n");
int temp2=ui.displayConfirmation();
		if(temp2==1)
		{
			system("clear");
			initiateGenerateBill(ui,m);
		}
		else
		{
			system("clear");
			initiatePayment(ui,m);
		}





}





void Controller::initiateViewBill(Ui &ui,Model &m)
{
int bid=ui.enterBillId();
int j=m.checkBillId(bid);
        if(j==0)
        {
                ui.displayString("\n\t Bill id does not exist\n");
                ui.displayString("\n\tDo you want to enter bill ID again?");
                int temp=ui.displayConfirmation();
                if(temp==1)
                {
                        system("clear");
                        initiateViewBill(ui,m);
                }
                else
                {
                        system("clear");
                        initiatePayment(ui,m);
                }
        }

Bill b=m.viewBill(bid);
ui.displayBill(b);

ui.displayString("\n\tTo view another bill\n");
int temp2=ui.displayConfirmation();
		if(temp2==1)
		{
			system("clear");
			initiateViewBill(ui,m);
		}
		else
		{
			system("clear");
			initiatePayment(ui,m);
		}


}


void Controller::initiateCancelBill(Ui &ui,Model &m)
{
int bid=ui.enterBillId();
int j=m.checkBillId(bid);
        if(j==0)
        {
                ui.displayString("\n\tInvalid Bill Id");
                ui.displayString("Do you want to enter bill ID again?");
                int temp=ui.displayConfirmation();
                if(temp==1)
                {
                        system("clear");
                        initiateViewBill(ui,m);
                }
                else
                {
                        system("clear");
                        initiatePayment(ui,m);
                }
        }

Bill b=m.viewBill(bid);
ui.displayBill(b);
int temp1;
ui.displayString("\nAre you sure do you want to delete?");
temp1=ui.displayConfirmation();

		if(temp1==1)
		{
			m.cancelBill(bid);
			ui.displayString("\n\tBill cancelled successfully");
			system("read");
			initiatePayment(ui,m);

		}
		else
		{
			system("clear");
			initiatePayment(ui,m);
		}

}


void Controller::initiateSalesHistory(Ui &ui,Model &m)
{
	ui.displayMonthlySalesHistory();
 	int Rid=ui.getRestaurantId();
 	int i=m.checkRestaurantId(Rid);
 	if(i==0)
	{
 		system("clear");
 		ui.displayMonthlySalesHistory();

 		ui.displayString("Restaurant Id doesnot exist");
		ui.displayString("Do you want to enter Restaurant Id again?");
		int ch=ui.displayConfirmation1();
		if(ch==1)
		{
    			system("clear");
    			initiateSalesHistory(ui,m);
		}
		else if(ch==2)
		{
    			system("clear");
    			initiatePayment(ui,m);
		}
	}

 	system("clear");
 	ui.displayMonthlySalesHistory();
 	int Month=ui.getMonth();
 	int j=m.checkMonth(Month);
	if(j==0)
	{
 		system("clear");
 		ui.displayMonthlySalesHistory();

 		ui.displayString("No sales in this month");
 		initiatePayment(ui,m);
	}




	if(Month==1||Month==3||Month==5||Month==7||Month==8||Month==10||Month==12)
	{
		float msum1=0;
		for(int Day=1;Day<31;Day++)
		{
 			float dsum=m.getDailySales(Rid,Day,Month);

			 msum1=msum1+dsum;
 			ui.displayDailySales(Rid,Day,dsum);

		}
		ui.displayTotalSum(msum1);
	}


	else if(Month==4||Month==6||Month==9||Month==11)
	{
		float msum2=0;
		for(int Day=1;Day<30;Day++)
		{

 			float dsum=m.getDailySales(Rid,Day,Month);

 			msum2=msum2+dsum;
 			ui.displayDailySales(Rid,Day,dsum);

		}
		ui.displayTotalSum(msum2);
	}


	else if(Month==2)
	{
		float msum3=0;
		for(int Day=1;Day<28;Day++)
		{

			 float dsum=m.getDailySales(Rid,Day,Month);

 			msum3=msum3+dsum;

			 ui.displayDailySales(Rid,Day,dsum);

		}
		ui.displayTotalSum(msum3);
	}


}
