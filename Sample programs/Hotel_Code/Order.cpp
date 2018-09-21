#include"Order.h"
#include"Item.h"
Order::Order()
{
}
Order::Order(int orderid,int rid,vector<Item> itemlist,int option)
{
this->orderid=orderid;
this->rid=rid;
this->itemlist=itemlist;
this->option=option;
}
int Order::getOrderId()
{
return orderid;
}
int Order::getRestId()
{
return rid;
}
vector<Item> Order::getItem()
{
return itemlist;
}
int Order::getOption()
{
return option;
}

