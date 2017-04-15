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

#define SIZE 81
/* Function Prototypes */
void Usage(char** info);
void ReadFile(char *file1, float data[]);
/* Main Program */
int main(int argc, char *argv[])
{
	float data[SIZE];

	if(argc != 2 || strcmp((argv[1]), "--help")==0)
	{
		Usage(argv);
	}

	else
	{
		ReadFile(argv[1], data);

	}
	return 0;
}


/* Function Defenitions */
void Usage(char** info)
{
	printf("Error opening data file.\n");
	printf("Usage: ./<waves.txt>\n");
	exit(1);
	return;
}
void ReadFile(char *file1, float data[])
{
	FILE *infile;
	infile = fopen(file1, "r");
	if(infile == NULL)
	{
		printf("The file was not successfully read\n"); 
		exit(1);
	}
		printf("The txt file %s was successfully read. \n", file1);
	while(fscanf(infile, "%f", data) != EOF)
	{
		data++;
	}
	fclose(infile);
	return;
}


