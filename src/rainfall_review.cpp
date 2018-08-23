/*
Programmer		:	Seth Dara
Program No.		:	1
Date Written	:	09/07/04
Date Revised	:	09/07/04
Program	Title	:	Rainfall Review
Description		:

  This program will ask the user for the total rainfall (in inches)
  for each month, January through December. It will gather the input
  and store it in an array (MonthlyRain), and display the total rainfall,
  average rainfall, highest rainfall, and lowest rainfall.

  This program will utilize 2 array, one being two-dimensional. The first array,
  called MonthlyRain, will store the inputs the user enters representing the monthly
  rainfall totals. It will then be used in calculating the total, average, lowest and 
  highes values later. The second array, called Months, will be a two-dimensional array.
  It will store 12 elements, representing the months of a year, and each element will be up
  to 10 characters long (the second dimension).

  Input Validation: Do not allow negative numbers for rainfall totals to be entered.
*/


// This program gets 12 months of MonthlyRain data from the user
// and displays the total, average, highest, and lowest amounts.

//Include common libraries for use within this program
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
float sumMonthlyRain(float array[], int size);
float getHighestRain(float array[], int);
float getLowestRain(float array[], int);
void inputMonthlyRain(float array[], int numMonths);
void OutputData(float total, float average, float highest, float lowest);

//Global Variables (Used Throughout Program's Function)
int HighestMonthNum=0, LowestMonthNum=0;
	char Months[12][10] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

void main(void)
{
	const int numMonths = 12;	// Number of days
	float MonthlyRain[numMonths],	// To hold MonthlyRain amounts
		  total = 0,		// Accumulator
		  average,			// To hold the average
		  highest,			// To hold the highest MonthlyRain
		  lowest;			// To hold the lowest MonthlyRain

	// Get the MonthlyRain data.
	inputMonthlyRain(MonthlyRain, numMonths);

	// Get the total MonthlyRain.
	total = sumMonthlyRain(MonthlyRain, numMonths);

	// Get the average.
	average = total / numMonths;

	// Find the highest MonthlyRain amount.
	highest = getHighestRain(MonthlyRain, numMonths);

	// Find the lowest MonthlyRain amount.
	lowest = getLowestRain(MonthlyRain, numMonths);

	// Display the results.
	OutputData(total,  average,  highest,  lowest);
	
}

//***************************************************
// Definition of sumMonthlyRain                     *
// This function accepts a float array and its size *
// as arguments. The sum of the array's elements    *
// is returned as an float.                         *
//***************************************************

float sumMonthlyRain(float array[], int size)
{
	float total = 0;	// Accumulator

	for (int count = 0; count < size; count++)
		total += array[count];
	return total;
}

//****************************************************
// Definition of getHighestRain                      *
// This function accepts a float array and its size  *
// as arguments. The highest value in the array is   *
// returned as an float.                             *
//****************************************************

float getHighestRain(float array[], int size)
{
	float highest;

	highest = array[0];
	for (int count = 1; count < size; count++)
	{
		if (array[count] > highest)
		{
			highest = array[count];
			HighestMonthNum=count;
		}

	}
	return highest;
}

//****************************************************
// Definition of getLowestRain                       *
// This function accepts a float array and its size  *
// as arguments. The lowest value in the array is    *
// returned as an float.                             *
//****************************************************

float getLowestRain(float array[], int size)
{
	float lowest;

	lowest = array[0];
	for (int count = 1; count < size; count++)
	{
		if (array[count] < lowest)
		{
			lowest = array[count];
			LowestMonthNum=count;
		}
	}
	return lowest;
}


//****************************************************
// Definition of inputMonthlyRain                    *
// This function asks the user to input data         *
// (rainfall amounts) for each of the 12 months - it *
// also has input validation with a warning if the   *
// entered value is less than 0.                     *
//****************************************************

void inputMonthlyRain(float array[], int numMonths)
{

	cout << "This program will gather the Rainfall amounts for 12 months and give you the \ntotal, average, highest amount, and lowest amount.\n\n## Please enter the Monthly Rainfall the year (each month) ##\n";
	for (int count = 0; count < numMonths; count++)
	{
		
		do
		{
			cout << "\nEnter the rainfall amount for the month of " << Months[count] << " (Value must be >= 0):"<<endl;
			cin >> array[count];
			if(array[count] < 0)
				cout << "\n *** Please enter a value greater than or equal to zero ***\n\n";

		}while (array[count] < 0);
	}
}

//****************************************************
// Definition of OutputData                          *
// This function display all of the gathered data to *
// the screen.                                       *
//****************************************************

void OutputData(float total, float average, float highest, float lowest)
{
	cout << fixed << showpoint << setprecision(2);
	cout << "\n======================================================================\nOUTPUT\n======================================================================\n\nThe total Rainfall for 12 months is    : " << total << " inches" << endl;
	cout << "The average Monthly Rainfall amount is : " << average << " inches" << endl;
	cout << "The highest Monthly Rainfall amount is : " << highest << " inches (" << Months[HighestMonthNum] << ")" << endl;
	cout << "The lowest Monthly Rainfall amount is  : " << lowest << " inches (" << Months[LowestMonthNum] << ")" << "\n\n======================================================================\n\nThank you for using the program!\n" <<endl;
}
