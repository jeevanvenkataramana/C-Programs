/***** Jeevan Venkataramana 011917477*****/

#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

/***** Complete this file. *****/

using namespace std;

TimedContainer::TimedContainer()
{
	 elapsed_time=0;
}

TimedContainer::~TimedContainer()
{

}

WordVector::WordVector()
{

}

WordVector::~WordVector()
{

}

Word *WordVector::insert(const string text)
{
   if(data.size()==0)
   {
      Word first(text);
      data.push_back(first);
      return &data[0];
   }

   Word* a = search(text);

   if(a != nullptr)
   {
      a->inc_count();
      return a;
   }

   Word b(text);
   unsigned int i=0;

   for(i=0; i<data.size(); i++)
   {
      if(data[i].get_word() > text)
      {
         break;
      }
   }

   vector<Word>::iterator  it = data.begin();
   it += i;
   it = data.insert(it, b);
   return &data[i];
}





Word *WordVector::search(const string text)
{
// Do a binary search.
   int low = 0;
   int high = data.size();

   while (low <= high)
   {
      int mid = (low + high)/2;

      if (text == data[mid].get_word())
      {
         return &data[mid];
      }
      else if (text < data[mid].get_word())
      {
         high = mid - 1; // search lower half
      }
      else
      {
         low = mid + 1; // search upper half
      }
   }
   return nullptr; // not found
}


int WordVector::get_size()
{
   return data.size();
}


vector<Word> WordVector::get_data()
{
   return data;
}
