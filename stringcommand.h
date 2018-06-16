#pragma once
#ifndef STRINGCOMMAND_H
#define STRINGCOMMAND_H

//#include <stdio.h>
#include <cstring>
#include "stdafx.h"

class char_array
{
	private:
		char stringarray[64];			//initial input array
		char *p_inputstring;			//holds actual length data
		char **pp_database_string;		//allocate data database.cpp
		int stringsize;					//holds array size to allocate memory
	
	public:
		inline char_array();			//inline so other functions can call on it
		inline ~char_array();
		inline void getinput(char**);			//retrieves user input
		inline void grabline();			//retrieve line with whitespace included	NOT COMPLETE, may not need
		inline int arraysize();	//returns size of string array
		inline void printinput();		//print input string
};

inline char_array::char_array()			//constructor
{
	stringsize = 0;
	p_inputstring = new char[2];
}

inline char_array::~char_array()		//destructor
{
	delete[] pp_database_string;
	delete[] p_inputstring;
}

inline void char_array::getinput(char **pp_stringin)
{
	printf("Enter string: ");		//delete later
	stringsize = 0;
	scanf("%63s", stringarray);	//get input string

	while (stringarray[stringsize] != NULL)	//finding out the size of string array
	{
		stringsize++;
	}
	stringsize++;

	delete[] p_inputstring;		//deallocate memory block

	p_inputstring = new char[stringsize];	//reallocate memory block and set array inside
	for (int i = 0; i < stringsize; i++)
	{
		p_inputstring[i] = stringarray[i];
	}

	*pp_stringin = new char[stringsize];		//set pp_stringin
	for (int i = 0; i < stringsize; i++)
	{
		(*pp_stringin)[i] = p_inputstring[i] ;
	}
}

inline void char_array::grabline()
{
	printf("ERROR: 'GRABLINE' FUNCTION IN 'STRINGCOMMAND.H' CURRENTLY DOES NOT EXIST\n");		//delete later
}

inline int char_array::arraysize()
{
	if (stringsize != 0)
	{
		return stringsize;
	}
	else
	{
		printf("Array size is set at 0\n");
		return 0;
	}
}

inline void char_array::printinput()
{
	printf("%s", p_inputstring);
}

#endif