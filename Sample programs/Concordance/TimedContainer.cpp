/*
 * TimedContainer.cpp
 *
 *  Created on: Apr 10, 2018
 *      Author: jeeva
 */




/***** Jeevan Venkataramana 011917477*****/

#include "TimedContainer.h"
#include "Word.h"

/***** Modify this file as needed. *****/

Word *TimedContainer::timed_insert(const string text)
{
    // Start the timer.
    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();

    // Do the insertion.
    Word *word = insert(text);

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
    increment_elapsed_time(std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count());

    return word;
}

Word *TimedContainer::timed_search(const string text)
{
    // Start the timer.
    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();

    // Do the search.
    Word *word = search(text);

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
    long elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    increment_elapsed_time(elapsed);

    return word;
}


long TimedContainer::get_elapsed_time() const
{
   return elapsed_time;
}

void TimedContainer::reset_elapsed_time()
{
   elapsed_time = 0;
}


void TimedContainer::increment_elapsed_time(long a)
{
   elapsed_time += a;
}
