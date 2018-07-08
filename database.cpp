#include "stdafx.h"
#include "stringcommand.h"
#include "datacommand.h"

int database()
{
	char *basefilepath = new char[7];
	bool *functionrun = new bool;
	strcpy(basefilepath, "\\home\\");
	printf("DATABASE SYSTEM \n\n");

	for (;;)
	{
		*functionrun = false;
		char_array database_string;
		char *p_inputstring;
		printf("~%s $ ", basefilepath);
		database_string.getinput(&p_inputstring);					//get input from user
	
		new_directory("mkdir", &p_inputstring, functionrun);
		new_file("new", &p_inputstring, functionrun);
		delete_file("del", &p_inputstring, functionrun);
		change_directory("cd", &p_inputstring, &basefilepath, functionrun);
		list("ls", &p_inputstring, &basefilepath, functionrun);

		if (strcmp(p_inputstring, "help") == 0)						//add documentation later
		{
			printf("\n");
			printf("mkdir			-Creates new directory\n");
			printf("new			-Creates new file\n");
			printf("del			-Delete file or directory\n");
			printf("cd			-Change directories\n");
			printf("ls			-List conents\n");
			printf("exit			-Exit database\n");

			*functionrun = true;
		}

		else if (strcmp(p_inputstring, "exit") == 0)
		{
			delete[] p_inputstring;
			break;
		}
		if (*functionrun == false)
		{
			printf("\nCommand '%s' unknown\n", p_inputstring);
		}
		printf("\n");
		delete[] p_inputstring;
	}

	delete[] basefilepath;
	delete functionrun;
	return 0;
}