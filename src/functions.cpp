//
//  functions.cpp
//  lab01-01
//
//  Author: Benjie
//  Date: 1/25/2022
//

#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "functions.h"
#include <iostream>
using namespace std;


int loadLanguages( const string& filename, string names[], int maxLanguages )
{
	int numNames = 0;
   
	ifstream input(filename);
	if( input.is_open() )
	{
		while( !input.eof() && numNames < maxLanguages )
		{
			getline( input, names[numNames] );
			numNames++;
		}
		input.close();
	}
	return numNames;
}


bool loadInfo( const string& filename, int infoArray[][INFO], int numLanguages )
{
	{
		int count = 0;
		string buffer;

		ifstream input(filename);
		if( input.is_open() )
		{
			while( !input.eof() && count < numLanguages )
			{
				try{
					getline(input,buffer);
					infoArray[count][0] = stoi(buffer.substr(0,buffer.find(" ")));
					infoArray[count][1] = stoi(buffer.substr(buffer.find(" "),buffer.length()));
					count++;
				}catch(...){
					return false;
				}
			}
			input.close();
		}
		return count==numLanguages;
	}
   
   return false;
}


string formatReportLine( int languageRank, int infoArray[][INFO], string names[] )
{
	stringstream buffer("");
	buffer << setw(15) << left << names[languageRank] << setw(10) << left << infoArray[languageRank][0] << infoArray[languageRank][1];
   return buffer.str();
}
