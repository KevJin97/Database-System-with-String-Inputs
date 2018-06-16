#pragma once

#ifndef DATACOMMAND_H
#define DATACOMMAND_H

#include "stringcommand.h"

struct data
{
	char *title;
};

inline void newdir(const char commandkey[], char **pp_inputstring)
{
	if (strcmp(commandkey, *pp_inputstring) == 0)
	{
		char_array data_command;
		data_command.getinput(pp_inputstring);

		char basefilepath[] = "c:\\DATABASE\\directory\\";
		char *filepath = new char[( sizeof(basefilepath) + 4 + data_command.arraysize() )];
		strcpy(filepath, basefilepath);
		strcat(filepath, *pp_inputstring);
		strcat(filepath, ".txt");	//change to .bin or other
		
		FILE *directory = fopen(filepath, "w");
		fclose(directory);
		printf("Directory '%s' was created successfully\n", *pp_inputstring);
		
		delete[] filepath;
	}
}

void newfile(const char commandkey[], char **pp_inputstring)
{
	if (strcmp(commandkey, *pp_inputstring) == 0)
	{
		char_array data_command;
		data_command.getinput(pp_inputstring);

		char basefilepath[] = "c:\\DATABASE\\datafiles\\";
		char *filepath = new char[(sizeof(basefilepath) + 4 + data_command.arraysize())];
		strcpy(filepath, basefilepath);
		strcat(filepath, *pp_inputstring);
		strcat(filepath, ".txt");	//change to .bin or other

		FILE *directory = fopen(filepath, "w");
		fclose(directory);
		printf("File '%s' was created successfully\n", *pp_inputstring);

		delete[] filepath;
	}
}

void del(const char)
{

}

void cd(const char)
{
	
}

#endif
