/*
 * =====================================================================================
 *
 *       Filename:  putty_hw10_task2.c
 *       	Usage:  ./putty_hw10_task2.c
 *    Description:  task2
 *
 *        Version:  1.0
 *        Created:  04/13/2017 03:47:28 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Kyle Webb (), kylewebbear@weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>		/* Standard Library */
#include <string.h>

/* Function Prototypes */
void Usage(char** info);
/* Main Program */
int main(int argc, char *argv[])
{
	if(argc != 2 || strcmp((argv[1]), "--help")==0)
	{
		Usage(argv);
	}

	return 0;
}


/* Function Defenitions */
void Usage(char** info)
{
	printf("Error opening data file.\n");
	printf("Usage: ./<file name>\n");
	exit(1);
	return;
}


