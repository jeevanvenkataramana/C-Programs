#include"Bill.h"
Bill::Bill()
{
}
Bill::Bill(int billid,int rid,int paymentid,int status,Order order,string date,float stax,float vat,float hd,float tSum)
{
	cout<<"hi";
this->billid=billid;
this->rid=rid;
this->paymentid=paymentid;
this->status=status;
this->order=order;
this->date=date;
this->stax=stax;
this->vat=vat;
this->hd=hd;
this->tSum=tSum;
}
int Bill::getBillId()
{
return billid;
}
int Bill::getRestId()
{
return rid;
}
int Bill::getPaymentId()
{
return paymentid;
}
int Bill::getStatus()
{
return status;
}
Order Bill::getOrder()
{
return order;
}
string Bill::getDate()
{
return date;
}
float Bill::getStax()
{
return stax;
}
float Bill::getVat()
{
return vat;
}
float Bill::getTsum()
{
return tSum;
}
float Bill::getHd()
{
return hd;
}

