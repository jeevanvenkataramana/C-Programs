/***** Jeevan Venkataramana 011917477*****/

#include <string>
#include "Word.h"
using namespace std;

/***** Modify this file as needed. *****/

Word::Word() : text(""), count(0) {}
Word::Word(string text) : text(text), count(1) {}

Word::~Word() { }


void Word::inc_count()
{
   count++;
}

string Word::get_word() const
{
   return text;
}

int Word::get_count() const
{
   return count;
}



bool operator!=(Word a, Word b)
{
   return((a.get_word() != b.get_word()) || (a.get_count() != b.get_count()));
}
