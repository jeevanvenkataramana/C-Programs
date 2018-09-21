#include"Bill.h"
#include"Order.h"
#include"Model.h"
#include"Item.h"
Model::Model()
{
}
void Model::add()
{
	Item i1(1, "breakfast", 20, "dosa", 3, 25);
	Item i2(1, "breakfast", 20, "dosa", 3, 25);
	vector<Item>itemList1;
	itemList1.push_back(i1);
	itemList1.push_back(i2);
	Order o1(101,201,itemList1,0);
	addOrderList(o1);

	Item i3(1, "lunch", 20, "meals", 3, 70);
	Item i4(1, "dinner", 20, "meals", 3, 70);
	vector<Item>itemList2;
	itemList2.push_back(i3);
	itemList2.push_back(i4);
	Order o(102,201,itemList2,0);
	addOrderList(o);

}



int Model::generateOrderId()
{
	int a=0;
	a++;
	return a;
}

int Model::generateBillId()
{

	static int b=0;
	b++;
	return b;
}
void Model::addOrderList(Order a)
{
	orderlist.push_back(a);

}
Order Model::viewOrder(int orderid)
{
	for(int i=0;i<orderlist.size();i++)
	{
		if(orderlist[i].getOrderId()==orderid)
		{
			return orderlist[i];
		}
	}
}


void Model::cancelOrder(int orderid)
{
	for(int i=0;i<orderlist.size();i++)
	{
		if(orderlist[i].getOrderId()==orderid)
		{
			orderlist.erase(orderlist.begin()+i);
			return;
		}
	}
}


int Model::checkOrderId(int orderid)
{


	for(int i=0;i<orderlist.size();i++)
	{
		if(orderlist[i].getOrderId()==orderid)
		{
		return 1;
		}
	}
return 0;
}
int Model::checkBillId(int billid)
{
	for(int i=0;i<billlist.size();i++)
	{
		if(billlist[i].getBillId()==billid)
		{
			return 1;

		}
	}
return 0;
}




Bill Model::generateBill(int bid,Order a)
{

	int id,rid,option,phone,qty,paymentid=0,pstatus=0;
	string name,address,date="27/01/2016";
	vector<Item> items;
	float stax,vat,tsum,sum,price,hd=0;
	id=a.getOrderId();
	rid=a.getRestId();
	items=a.getItem();

	for(int i=0;i<items.size();i++)
	{
		qty=items[i].getQty();
		price=items[i].getIprice();
		sum=sum+(qty*price);
	}

	stax=sum*0.05;
	vat=sum*0.122;
	sum=sum+stax+vat;
	option=a.getOption();

	if(option==2)
	{
		hd=sum*0.04;
	}
	sum=sum+hd;
	Bill b(bid,rid,paymentid,pstatus,a,date,stax,vat,hd,sum);

	billlist.push_back(b);
	paymentList.push_back(b);
	return b;
}




Bill Model::viewBill(int billid)
{
	for(int i=0;i<billlist.size();i++)
	{
		if(billlist[i].getBillId()==billid)
		{
		return billlist[i];
		}
	}
}


void Model::cancelBill(int billid)
{
	for(int i=0;i<billlist.size();i++)
	{
		if(billlist[i].getBillId()==billid)
		{
			billlist.erase(billlist.begin()+i);
			return;
		}
	}
}


int Model::checkRestaurantId(int Rid)
{
  for(int i=0;i<paymentList.size();i++)
  {
     if(paymentList[i].getRestId()==Rid)
     {
       return 1;
     }
  }
   return 0;
}

int Model::checkMonth(int Month)
{
int ch;string s;stringstream ss;

for(int i=0;i<paymentList.size();i++)
{
string a=paymentList[i].getDate();
std::string b=a.substr(3,2);
ss<<b;
ss>>ch;

if(Month==ch)
{
 return 1;
}
}
return 0;
}

float Model::getDailySales(int Rid,int Day,int Month)
{
int ch;string s;stringstream ss;

float sum=0;
for(int i=0;i<paymentList.size();i++)
{
if(paymentList[i].getRestId()==Rid)
{
string c=paymentList[i].getDate();
std::string d=c.substr(3,2);
ss<<d;
ss>>ch;

if(Month==ch)
{

int ch2;
std::string e=c.substr(0,2);
ss<<e;
ss>>ch2;


if(ch2==Day)
{
sum=sum+paymentList[i].getTsum();
}
}
}

return sum;

}

}
