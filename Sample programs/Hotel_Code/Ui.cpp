#include"ui.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<sstream>
#include"Bill.h"
#include"Order.h"
#include"Item.h"
using namespace std;
void Ui::displayTitle()
{
cout<<"\n\t\t\tFine Dine Restaurant Payment Management\n\n\n\n";
}
void Ui::displayString(string s)
{
	cout<<"\n\n\t\t\t"<<s<<"\n\n"<<endl;
}
int Ui::displayMainMenu()
{
system("clear");
displayTitle();
cout<<"\n\t\t\t1.Generate Bill:\n\n\t\t\t2.View Bill:\n\n\t\t\t3.Cancel Bill:\n\n\t\t\t4.Create Payment:\n\n\t\t\t5.View Payment:\n\n\t\t\t6.Cancel Payment:\n\n\t\t\t7.Generate Sales History:\n\n\t\t\t8.Exit:\n\n\n\n\n\t\tEnter your choice:";
do
{
	int ch;string s;stringstream ss;
	cin>>s;
	if (s.find_first_not_of("12345678") != std::string::npos)
		{

			cout<<"\n\n\t\t\t\t\tPlease enter a valid choice:\t";
		}
	else
		{
			ss<<s;
			ss>>ch;
			return ch;
		}
}while(1);

}


int Ui::displayConfirmation()
{
int temp;
cout<<"\n\t\t\t1. YES\n\t\t\t2. NO\n\tEnter Choice:";
cin>>temp;
return temp;
}



int Ui::enterOrderId()
{
displayTitle();
system("clear");
cout<<"\n\n\t\t\tEnter Order Id:\t";
do
{
        int ch;string s;stringstream ss;
        cin>>s;
        if (s.find_first_not_of("1234567890") != std::string::npos)
                {

                        cout<<"\n\n\t\t\tPlease enter a valid order id:\t";
                }
        else
                {
                        ss<<s;
                        ss>>ch;
                        return ch;
                }
}while(1);
}
int Ui::enterBillId()
{
displayTitle();
cout<<"\n\n\t\t\tEnter Bill Id:\t";
do
{
        int ch;string s;stringstream ss;
        cin>>s;
        if (s.find_first_not_of("1234567890") != std::string::npos)
                {

                        cout<<"\n\n\t\t\tPlease enter a valid bill id:\t";
                }
        else
                {
                        ss<<s;
                        ss>>ch;
                        return ch;
                }
}while(1);
}
void Ui::displayBill(Bill b)
{

	float price;
	displayTitle();
	cout<<"\n\n";
	cout<<"\n\t\tBil id        :\t"<<b.getBillId();
	cout<<"\n\t\tRestaurant id :\t"<<b.getRestId();
	Order o=b.getOrder();
	vector<Item> items=o.getItem();
	displayItem(items);
	cout<<"\n";
	cout<<"\n\t\tservice tax   :"<<b.getStax();
	cout<<"\n\t\tvat           :"<<b.getVat();
	cout<<"\n\t\thome delivary :"<<b.getHd();
	cout<<"\n\t\tSUM TOTAL     :"<<b.getTsum();
	int j=o.getOption();
//	if(j==2)
 //       {
 //       	cout<<"\n\t\tName     :"<<o.getName();
 //       	cout<<"\n\t\tPhone    :"<<o.getPhone();
 //       	cout<<"\n\t\tAddress  :"<<o.getAddress();
//	}
}

void Ui::displayItem(vector<Item> items)
{
	float sum=0;
	cout<<"\n\tno\tname\tqty\tprice\ttotal\n\n";
	for(int i=0;i<items.size();i++)
	{
		cout<<"\t"<<i+1<<"\t"<<items[i].getDishName()<<"\t"<<items[i].getQty()<<" \t"<<items[i].getIprice();
		float price=(items[i].getQty())*(items[i].getIprice());

		cout<<"\t"<<price<<"\n";
		sum=sum+price;
		}
		cout<<"\n\t\t\tSum:"<<sum;
}

void Ui::displayMonthlySalesHistory()
{
cout<<"\n******************************************************************************************************\n";
cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tMONTHLY SALES HISTORY\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<endl;
cout<<"********************************************************************************************************\n";
}

int Ui::getRestaurantId()
{
int Rid;
cout<<"\t\t\t\t\t\t\tEnter the restaurant Id:"<<endl;
cin>>Rid;
cout<<"\t\t\t\t\t\t\t\t\t\t"<<Rid<<endl;
return Rid;
}


int Ui::displayConfirmation1()
{
 cout<<"\t\t\t\t1.Yes \n\v\v\t\t\t\t\2.No\v\v"<<endl;
 cout<<"Enter your choice:\t";
 do
	{
		int ch;string s;stringstream ss;
		cin>>s;
		if (s.find_first_not_of("12") != std::string::npos)
		{
			//system("clear");
			//displayTitle();
			cout<<"\n\n\t\t\t\t\tPlease enter a valid choice:\t";
		}
		else
		{
			ss<<s;
			ss>>ch;
			return ch;
		}
	}while(1);

}
int Ui::getMonth()
{
  int Month;
  cout<<"\t\t\t\t\t\tEnter the month:\t\t\t\t\t\t"<<endl;
  cin>>Month;
  cout<<"\t\t\t\t\t\t\t"<<Month<<endl;
  return Month;
}

void Ui::displayDailySales(int Rid,int date,float dsum)
{

cout<<"\t\t\t\t\t\t\t\tRestaurant Id:"<<Rid<<endl;
//cout<<"\t\t\t\t\t\t\t\tMonth:"<<Month<<endl;

cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tDATE\t\t\t\t\t\t\t\t\tAMOUNT\t\t\t\t\t\t\t\t\n";
cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<date<<"\t\t\t\t\t\t\t\t\t\t\t\t\t"<<dsum<<endl;
}
void Ui::displayTotalSum(float msum)
{

cout<<"\t\t\t\t\tThe total sales of the month is:"<<msum<<endl;
}
