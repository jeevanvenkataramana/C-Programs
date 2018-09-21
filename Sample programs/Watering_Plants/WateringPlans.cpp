/*
 * WateringPlans.cpp
 *
 *  Created on: Mar 21, 2018
 *      Author: jeeva
 */

/* Jeevan Venkataramana SID :011917477*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
/*** Complete this program. ***/

int main()

{


    const string INPUT_FILE_NAME = "counts.txt";
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

	// Loop once for each number of plants read from the input file.
	// Stop when the number of plants is 0 or less.
	// During each loop,
	//simulate Plan Near and Plan Far.

    int plant_count;
    do
    {
	input >> plant_count;
	if(plant_count==0)
	{
		break;
	}


	        // Plan Near

	cout << endl;
	cout << "==========================" << endl;
	cout << " Plan Near with " << plant_count << " plants" << endl;
	cout << "==========================" << endl;
	cout << endl;
	cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
	cout << "---------  ----------  ----------  ---------------" << endl;

        	/*** Complete the code for Plan Near. ***/

	int step_tofaucet = 0, watered = 0, water_amt, step_units = 0, steps = 0, plant_count1 = 0, step_difference;

	while(plant_count1!=plant_count)
	{
		step_tofaucet=watered;						/*steps from tap to last watered plant*/
		water_amt=3;							/*fill at the start and after empty*/
		step_units=step_units+(watered*3);				/*step units from tap to last watered plant*/
		steps=steps+watered;

		while((water_amt>0)&&(plant_count1!=plant_count))
		{
			steps++;
			step_units=water_amt+step_units;
			plant_count1++;
			step_tofaucet++;
			cout<<"Plant   "<<plant_count1<<"       "<<steps<<"          "<<water_amt<<"           "<<step_units<< endl;
			watered++;
			water_amt--;
		}

		steps=steps+watered;

		if((water_amt==0)&&(plant_count1!=plant_count))
		{
			cout<<"FAUCET          "<<steps<<"          "<<water_amt<<"           "<<step_units<< endl;
		}

		if(plant_count1==plant_count)
		{
			step_units=step_tofaucet*water_amt+step_units;					/*step units to return to tap after watering*/
			cout<<"FAUCET          "<<steps<<"          "<<water_amt<<"          "<<step_units<< endl<<endl;
			cout<<"Plan Near: Total steps = "<<steps<<", total step-units = "<<step_units<< endl;
			break;
		}
	}


		// Plan Far



	cout << endl;
	cout << "=========================" << endl;
	cout << " Plan Far with " << plant_count << " plants" << endl;
	cout << "=========================" << endl;
	cout << endl;
	cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
	cout << "---------  ----------  ----------  ---------------" << endl;

        	/*** Complete the code for Plan Far. ***/

	        // Which plan is better? Better means fewer step-units.

	int unwatered = plant_count, plant_count2 = plant_count, step_units2 = 0;
	step_tofaucet=0;
	unwatered = plant_count;
	water_amt=3;
	int steps2 = plant_count;

	while(plant_count2!=0)
	{
		water_amt=3;
		step_tofaucet=unwatered;
		while((water_amt!=0)&&(plant_count2!=0))
		{
			if(water_amt==3)
			{
				step_units2=unwatered*water_amt+step_units2;		/*step units to far unwatered plant*/
			}
			else
			{
				step_units2=water_amt+step_units2;
				step_tofaucet--;
				steps2++;
			}
			cout<<"Plant   "<<plant_count2<<"       "<<steps2<<"          "<<water_amt<<"           "<<step_units2<< endl;
			unwatered--;
			water_amt--;
			plant_count2--;
		}

		steps2=steps2+step_tofaucet;

		if((water_amt==0)&&(plant_count2!=0))
		{
			cout<<"FAUCET          "<<steps2<<"          "<<water_amt<<"           "<<step_units2<< endl;
			steps2=steps2+unwatered;					/*steps to fill water from tap*/
		}

		if(plant_count2==0)
		{
			step_units2=step_tofaucet*water_amt+step_units2;
			cout<<"FAUCET          "<<steps2<<"          "<<water_amt<<"          "<<step_units2<< endl<<endl;
			cout<<"Plan Far:  Total steps = "<<steps2<<", total step-units = "<<step_units2<< endl;
			break;
		}
	}


	cout << endl;
	cout << "*** With " << plant_count << " plants, ";


		/*** Complete the code to determine the better plan. ***/

	if(step_units<step_units2)
	{
		step_difference = step_units2-step_units;
		cout<<"Plan Near is better with "<<step_difference<<" fewer step-units."<< endl;
	}
	else
	{
		step_difference=step_units-step_units2;
		cout<<"Plan Far is better with "<<step_difference<<" fewer step-units."<< endl;
	}


    }while (plant_count > 0);

    return 0;

}
