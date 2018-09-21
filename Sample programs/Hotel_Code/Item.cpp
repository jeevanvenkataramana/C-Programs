#include"Item.h"
Item::Item()
{
}
Item::Item(int menuid,string menuname,int dishid,string dishname,int qty,float price)
{
this->menuid=menuid;
this->menuname=menuname;
this->dishid=dishid;
this->dishname=dishname;
this->qty=qty;
this->price=price;
}
int Item::getMenuId()
{
return menuid;
}
string Item::getMenuName()
{
return menuname;
}
int Item::getDishId()
{
return dishid;
}
string Item::getDishName()
{
return dishname;
}
int Item::getQty()
{
return qty;
}
float Item::getIprice()
{
return price;
}

