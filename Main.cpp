/*******
Cayden Mayfield
Computer Science
Due Date: 10/28/2025
Lab 4: Temperature Bar Chart
description: This program reads temperature data from a file and generates a bar chart
******************/

	
#include <iostream>
#include <fstream> 
#include <string>
#include <cmath> // For abs function
#include <iomanip> // For setw and setprecision


using namespace std;

// Constants  temperature range and temperature bar chart scale
const int MIN_TEMP = -30; // Min temperature
const int MAX_TEMP = 120; // Max temperature
const int DEG_PER_STAR = 3; // Each star represents 3 degrees Fahrenheit
const int MAX_STARS = (MAX_TEMP - MIN_TEMP) / DEG_PER_STAR; // Max number of stars

//Function to print the header of the temperature bar chart
void printHeader()
{
	cout << "Temperature Bar chart throughout 24-hour period\n"
		<< "Range: " << MIN_TEMP << " to " << MAX_TEMP << " degrees Fahrenheit | Scale : * = "
		<< DEG_PER_STAR << " degrees Fahrenheit   |   Max width: " << MAX_STARS << "stars\n\n" << endl;
}

//Function to print a single line of the temperature bar chart
void printTemperatureBarLine(int temp)
{
	int Stars = abs(temp) / 3; // Calculate number of stars for the temperature
	string starBar(Stars, '*');
	cout << setw(5) << fixed << setprecision(0) << temp << "  |  "
		<< starBar << '\n'; // Format temperature output
}

int main()
{
	// Open the file with temperature data
	::ifstream inFile;
	inFile.open("HourTemp.dat");

	// Check  the file opened successfully
	if (!inFile)
	{
		cout << "Error opening file HourTemp.dat" << endl;
		return 1; //Exit with error code
	}

	printHeader(); //Print header for the bar chart

	int temp;

	// Read temperatures from  file and print the corresponding bar chart lines
	while (inFile >> temp)
	{
		if (temp < -30 || temp > 120) // Check for any out of range temperatures
		{
			cout << "Temperature out of range. Please input temperatures between -30 and 120." << endl;
		}
		else
		{
			printTemperatureBarLine(temp); //print   bar line
		}
	}
	inFile.close();
	return 0;
}
