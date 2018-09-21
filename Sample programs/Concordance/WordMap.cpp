
/***** Jeevan Venkataramana 011917477*****/

#include <iostream>
#include <map>
#include "WordMap.h"

/***** Complete this file. *****/

using namespace std;

WordMap::WordMap()
{
    /***** Complete this member function. *****/
}

WordMap::~WordMap()
{
    /***** Complete this member function. *****/
}


int WordMap::get_size()
{
   return data.size();
}


Word *WordMap::insert(const string text)
{
    /***** Complete this member function. *****/

   if(data[text].get_word() == text)
   {
      data[text].inc_count();
      return &data[text];
   }
   else
   {
      Word a(text);
      data[text] = a;
      return &data[text];
   }
}


Word *WordMap::search(const string text)
{
    /***** Complete this member function. *****/

// written all 3 possible way of search none looks more efficient than binary search of vector

/*
   if(data[text].get_word() == text)
   {
      return &data[text];
   }
   else
   {
     // data.erase(text);          //since an entry of key gets inserted if not present
      return nullptr;
   }
*/


   map<string, Word>::iterator it = data.find(text);

  if (it != data.end())
   {
      return &data[text];
   }
   else
   {
      return nullptr;
   }

  /* try
   {
      if(data.at(text).get_word() == text)
      return &data[text];
   }

   catch (const std::out_of_range& oor)
   {
      return nullptr;
   }
*/
}

map<string, Word>& WordMap::get_data()
{
   return data;
}
