#include "stdafx.h"
#include "stringcommand.h"
#include "datacommand.h"

int database()
{
	for (;;)
	{
		char_array database_string;		//fix memory leak
		char *p_inputstring;
		database_string.getinput(&p_inputstring);					//get input from user

		newdir("mkdir", &p_inputstring);
		//newfile("newfile", &p_inputstring);
		if (strcmp(p_inputstring, "break") == 0)
		{
			break;
		}
		
		delete[] p_inputstring;
	}

	return 0;
}