/*************************************************
			02 Temperature converter
	- This program for : Temperature convert.
	- Author : Ibrahim Mohamed Abdul-Meged.
			 : facebook.com/Ibrahiim.Pasha
			 : github.com/Ibrahiim-Pasha
	- Date : 23/9/2016 - 9:04 PM

*************************************************/

#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

// Creating functions
void start();
void toFK();
void toCK();
void toCF();
void again(string repeatProcess);
void wrongChoice();
void exit();

const char DEGREE = 248; // Temperature marker -> 248(Ascii Table)

int main()
{
	start();

	system("PAUSE");
	return 0;
}

void start() // Start of the program
{
	int operationNumber;
	cout << "\t\t\t\twhat do you want to do ?" << endl << endl
		<< "\t\t1- To convert from Celsius to Fahrenheit and Kelvin press 1." << endl
		<< "\t\t2- To convert from Fahrenheit to Celsius and Kelvin press 2." << endl
		<< "\t\t3- To convert from Kelvin to Celsius and Fahrenheit press 3." << endl
		<< "\t\t4- Press 4 to exit." << endl << endl;
	cin >> operationNumber;

	switch (operationNumber)
	{
		case 1 :
			toFK();
			break;
		case 2 :
			toCK();
			break;
		case 3 :
			toCF();
			break;
		case 4 :
			exit();
			break;
		default:
			wrongChoice();
			start();
			break;
	}
}

void toFK() // To convert from Celsius to Fahrenheit(F) and Kelvin(K).
{
	float celsius, f, k; // F -> Fahrenheit , K -> Kelvin
	system("CLS");
	cout << "\nEnter the degree Celsius : ";
	cin >> celsius;

	f = (1.8 * celsius) + 32;
	k = celsius + 273.15;

	cout << "\n\nFahrenheit = " << f << DEGREE << "F" << endl
		 << "Kelvin = " << k << DEGREE << "K" << endl << endl;

	again("FK");

}

void toCK() // To convert from Fahrenheit to Celsius(C) and Kelvin(K).
{
	float fahrenheit, c, k; // C -> Celsius , K -> Kelvin
	system("CLS");
	cout << "\nEnter the degree fahrenheit : ";
	cin >> fahrenheit;

	c = (fahrenheit - 32) / 1.8;
	k = ((fahrenheit - 32) / 1.8) + 273.15;

	cout << "\n\nCelsius = " << c << DEGREE << "C" << endl
		 << "Kelvin = " << k << DEGREE << "K" << endl << endl;

	again("CK");

}

void toCF() // To convert from Kelvin to Celsius(C) and Fahrenheit(F).
{
	float kelvin, c, f; // C -> Celsius , F -> Fahrenheit
	system("CLS");
	cout << "\nEnter the degree kelvin : ";
	cin >> kelvin;

	c = kelvin - 273.15;
	f = ((kelvin - 273.15) * 1.8) + 32;

	cout << "\n\nCelsius = " << c << DEGREE << "C" << endl
	 	 << "Fahrenheit = " << f << DEGREE << "F" << endl << endl;

	again("CF");

}

void again(string repeatProcess) // Conversion again , repeatProcess(Conversion type)
{
	char againAnswer;
	cout << "Again[Y/N]? : ";
	cin >> againAnswer;
	if (againAnswer == 'Y' || againAnswer == 'y')
	{
		
		if (repeatProcess == "FK") // To convert from Celsius to Fahrenheit(F) and Kelvin(K).
		{
			toFK();
		}
		else if (repeatProcess == "CK") // To convert from Fahrenheit to Celsius(C) and Kelvin(K).
		{
			toCK();
		}
		else if (repeatProcess == "CF") // To convert from Kelvin to Celsius(C) and Fahrenheit(F).
		{
			toCF();
		}
	}
	else if (againAnswer == 'N' || againAnswer == 'n')
	{
		system("CLS"); // For clear console screen -optional-
		start();
	}
	else
	{
		wrongChoice();
		start();
	}
}

void wrongChoice()
{
	cout << "\nWrong choice! ..";
	Sleep(2000);
	system("CLS");
}

void exit()
{
	cout << endl << "Goodbye! .. " << endl;
	Sleep(2000);
	exit(0);
}