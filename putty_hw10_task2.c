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
struct tsunami
{
	int mo, da, yr, fatalities;
	double max_height;
	char location[20];
};
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
	int i;
	int x = 1;
	double height = 0;
	double all = 0;
	double avg;
	struct tsunami height[SIZE];
	infile = fopen(file1, "r");
	if(infile == NULL)
	{
		printf("The file was not successfully read\n"); 
		exit(1);
	}
		printf("The txt file %s was successfully read. \n", file1);
	while(fscanf(infile, "%d %d %d %d %lf %s", &surf[i].mo, &surf[i].da, &surf[i].yr, &surf[i].fatalities, &surf[i].max_height, &surf[i].location) != EOF)
	{
		all = all + surf[i].max_height;
		if(surf[i].max_height > height)
		{
			height = surf[i].max_height;
			i++;
		}	
	}
	x = 1;
	avg = all/x;
	printf("Max height in feet is: %.2f\n", height*3.28);	//why *3.28?
	printf("The average height in feet is: %.2f\n", average*3.28);
	printf("List of tsunamis with a height greater than average: \n");
	
	for(i = 0; i < j; i++)
	{
		if(wave[i].maxheight > avg)
		{
			printf("%s \n", surf[i].location);
		}
	}
	fclose(infile);
	return;
}


