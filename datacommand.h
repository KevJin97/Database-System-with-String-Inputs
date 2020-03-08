#pragma once

#ifndef DATACOMMAND_H
#define DATACOMMAND_H

#include "stringcommand.h"

struct info	//change later
{
	char *filetype;	//directory or data type
	char *subdir;	//under which directory
	char *filepath;	//file path of info
	char *title;	//name of file
	char *content;	//actual content
};

//turn pp_inputstring into char *&ref_inputstring and in main, push through direct pointer

inline void new_directory(const char commandkey[], char **pp_inputstring, bool *functionrun)	//fix to create directory in database filepath (not system) later
{
	if (strcmp(commandkey, *pp_inputstring) == 0)
	{
		char_array data_command;
		delete[] *pp_inputstring;
		data_command.getinput(pp_inputstring);

		if (strcmp(*pp_inputstring, "?") == 0)		//enter help text later
		{
			printf("\nType in directory name after '%s' to create new directory\n", commandkey);
		}
		else
		{
			char systemfilepath[] = "c:\\DATABASE\\directory\\";
			char *filepath = new char[(sizeof(systemfilepath) + 3 + data_command.arraysize())];
			strcpy(filepath, systemfilepath);
			strcat(filepath, *pp_inputstring);
			strcat(filepath, ".txt");	//change to .bin or other

			FILE *directory = fopen(filepath, "w");
			fclose(directory);
			printf("Directory '%s' was created successfully\n", *pp_inputstring);

			delete[] filepath;
		}
		*functionrun = true;
	}
}

inline void new_file(const char commandkey[], char **pp_inputstring, bool *functionrun)	//fix to incorporate database file path
{
	if (strcmp(commandkey, *pp_inputstring) == 0)
	{
		char_array data_command;
		delete[] *pp_inputstring;
		data_command.getinput(pp_inputstring);

		if (strcmp(*pp_inputstring, "?") == 0)	//enter help later
		{
			printf("\nType in file name after '%s' to create new file\n", commandkey);
		}
		else
		{
			char systemfilepath[] = "c:\\DATABASE\\datafiles\\";
			char *filepath = new char[(sizeof(systemfilepath) + 3 + data_command.arraysize())];
			strcpy(filepath, systemfilepath);
			strcat(filepath, *pp_inputstring);
			strcat(filepath, ".txt");	//change to .bin or other

			FILE *directory = fopen(filepath, "w");
			fclose(directory);
			printf("File '%s' was created successfully\n", *pp_inputstring);
	
			delete[] filepath;
		}
		*functionrun = true;
	}
}

inline void delete_file(const char commandkey[], char **pp_inputstring, bool *functionrun)		//fix to incorporate database filepath
{
	if (strcmp(commandkey, *pp_inputstring) == 0)
	{
		char_array data_command;
		delete[] *pp_inputstring;
		data_command.getinput(pp_inputstring);

		if (strcmp(*pp_inputstring, "?") == 0)	//help function here later
		{
			printf("\nType in 'dir' or 'file' after %s to delete\n", commandkey);
			printf("'dir'				delete directory\n");
			printf("'file'				delete file\n");
		}
		else if (strcmp(*pp_inputstring, "file") == 0)	//check for existence first later
		{
			delete[] *pp_inputstring;
			data_command.getinput(pp_inputstring);
			char basefilepath[] = "c:\\DATABASE\\datafiles\\";
			char *filepath = new char[(sizeof(basefilepath) + 4 + data_command.arraysize())];
			strcpy(filepath, basefilepath);
			strcat(filepath, *pp_inputstring);
			strcat(filepath, ".txt");	//change to .bin or other
			remove(filepath);
			printf("File deleted successfully\n");

			delete[] filepath;
		}
		else if (strcmp(*pp_inputstring, "dir") == 0)		//make sure to erase all files within directory later
		{
			delete[] *pp_inputstring;
			data_command.getinput(pp_inputstring);
			char basefilepath[] = "c:\\DATABASE\\directory\\";
			char *filepath = new char[(sizeof(basefilepath) + 4 + data_command.arraysize())];
			strcpy(filepath, basefilepath);
			strcat(filepath, *pp_inputstring);
			strcat(filepath, ".txt");	//change to .bin or other
			remove(filepath);
			printf("Directory deleted successfully\n");

			delete[] filepath;
		}
		else    //add function to delete whatever file without specifying later
		{
			printf("\nCommand unknown. For help, add '?' after command to see options\n");
		}
		*functionrun = true;
	}
}

inline void change_directory(const char commandkey[], char **pp_inputstring, char **pp_basefilepath, bool *functionrun)
{
	if (strcmp(commandkey, *pp_inputstring) == 0)
	{
		char_array data_command;
		delete[] *pp_inputstring;
		data_command.getinput(pp_inputstring);

		if (strcmp(*pp_inputstring, "?") == 0)
		{
			printf("\nType in directory name after '%s' to go into directory\n", commandkey);
			printf("Type '.' after '%s' to go to previous directory\n", commandkey);
			printf("Type '..' after '%s' to go to original directory\n", commandkey);
		}

		else if (strcmp(*pp_inputstring, ".") == 0)
		{
			int filecount = 6;
			while ((*pp_basefilepath)[filecount] != NULL)
			{
				filecount++;
			}
			if (filecount > 6)
			{
				filecount -= 2;
				while ((*pp_basefilepath)[filecount] != '\\')
				{
					filecount--;
				}
				filecount+= 2;

				char *holder = new char[filecount];
				for (int count = 0; count < (filecount - 1); count++)
				{
					holder[count] = (*pp_basefilepath)[count];
				}
				holder[filecount - 1] = NULL;
				delete *pp_basefilepath;
				*pp_basefilepath = new char[filecount];
				strcpy(*pp_basefilepath, holder);
				delete holder;
			}

		}

		else if (strcmp(*pp_inputstring, "..") == 0)
		{
			delete[] *pp_basefilepath;
			*pp_basefilepath = new char[7];
			strcpy(*pp_basefilepath, "\\home\\");
		}

		else    //add 'if not found in directory give error message later'
		{
			int inputcount = 0;
			int filepathcount = 6;
			while ((*pp_inputstring)[inputcount] != NULL)
			{
				inputcount++;
			}
			while ((*pp_basefilepath)[filepathcount] != NULL)
			{
				filepathcount++;
			}
			filepathcount++;
			inputcount++;
			char *holder = new char[filepathcount + inputcount];
			strcpy(holder, *pp_basefilepath);
			strcat(holder, *pp_inputstring);
			strcat(holder, "\\");
			delete[] *pp_basefilepath;
			*pp_basefilepath = new char[filepathcount + inputcount];
			strcpy(*pp_basefilepath, holder);
			delete[] holder;
		}
		*functionrun = true;
	}
}

inline void list(const char commandkey[], char **pp_inputstring, char **pp_basefilepath, bool *functionrun)
{
	if (strcmp(commandkey, *pp_inputstring) == 0)
	{
		char_array data_command;
		data_command.getinput(pp_inputstring);

		*functionrun = true;
	}
}

inline void open(const char commandkey[], char **pp_inputstring, bool *functionrun)		//have only input be filename and use NULL comparison to run program
{
	if (strcmp(*pp_inputstring, commandkey) == 0)
	{
		/*
		if (strcmp(*pp_inputstring, "?") == 0)	//help here later
		{

		}
		else if (strcmp(commandkey, *pp_inputstring) == 0)
		{
			char_array data_command;
			data_command.getinput(pp_inputstring);
			FILE *ToOpen;

			//struct data whatever "name" filepath

			ToOpen = fopen(filepath, "r");		//filepath is a const char array variable. should be component of struct

			if (ToOpen == NULL)
			{
				printf("Error Opening File\n");
				fclose(ToOpen);
			}
			else
			{
				info data;	//change variable name later
				//example code
				while (fread(&data, sizeof(info), 1, ToOpen));
				{
					//printf() components of info
				}
				fclose(ToOpen);
			}
		}
		*/
		*functionrun = true;
	}
}

#endif
