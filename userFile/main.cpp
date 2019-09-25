/*
	Daniel Dooley
	C++ 1st Semester 2019
	Due: Due Date 9/26/19
	Lab number 3 Daniel Dooley
	Compute and output the mean and standard deviation of a set of four integers that are inputted by a file.
*/

//Libraries used for this project
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>

using namespace std;

//Function prototype
int meanStd();

//strings used to describe the file path of the input and output files
string inputFile = "D:/coding/userFile/inMeanStd.dat";
string outputFile = "D:/coding/userFile/outMeanStd.dat";

//numbers that are inputted by the computer files
int num1;
int num2;
int num3;
int num4;

//values that store the diffrence between the mean and integers.
float diff1, diff2, diff3, diff4;

//value that stores standard deviation
float stdDev;

//stores the mean of computer inputted numbers
float mean;

int main() {
	//file streamers that ensure files load correctly
	ifstream inFile;
	ofstream outFile;

	//a process that runs that loads the computer files
	inFile.open(inputFile);
	outFile.open(outputFile);

	//loads the 4 integers into num1-4
	inFile >> num1 >> num2 >> num3 >> num4;
	
	//function call to calculate the mean and standard deviation
	meanStd();

	//floats that save the calculated mean and standard deviation because it will be overwritted in the second function call.
	float saveMean, saveStdDev;
	saveMean = mean;
	saveStdDev = stdDev;

	//Human interface outputs and inputs
	cout << "Insert an integer then press enter:";
	cin >> num1;
	cout << "Insert a second integer then press enter:";
	cin >> num2;
	cout <<"Insert a third integer then press enter:";
	cin >> num3;
	cout << "Insert a fourth integer then press enter:";
	cin >> num4;

	//second function call
	meanStd();

	//saves the computer/human entered mean/standard deviation to file
	outFile << "File's mean: " << saveMean << endl << "File's standard deviation: " << saveStdDev << endl << "Player inputted mean: " << mean << endl << "Player inputted standard deviation: " << stdDev;

	//closes the file stream
	inFile.close();
	outFile.close();
	return 0;
}
int meanStd() {
	//calculates the mean
	mean = (float(num1) + num2 + num3 + num4) / 4;

	//displays to console the mean
	cout << "The mean is: " << mean << endl;

	//calculates the difference between the mean and num1-4
	diff1 = mean - num1;
	diff2 = mean - num2;
	diff3 = mean - num3;
	diff4 = mean - num4;

	//calculates the standard deviation
	stdDev = sqrt((pow(diff1, 2) + pow(diff2, 2) + pow(diff3, 2) + pow(diff4, 2)) / 4);

	//displays the standard deviation
	cout << "Standard deviation is: " << stdDev << endl;
	return 1;
}