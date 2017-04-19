/*
 * =====================================================================================
 *
 *       Filename:  putty_hw10_task3.c
 *       	Usage:  ./putty_hw10_task3.c
 *    Description:  task 3
 *
 *        Version:  1.0
 *        Created:  04/13/2017 03:47:39 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Kyle Webb (), kylewebbear@weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>		/* Standard Library */
#include <string.h>     /* Strings Library */

#define FILESIZE 81
/* Function Prototypes */
void Usage(char **info);
void ReadFile(char *fName, unsigned int num[]);
void MPEGVersion(arry);
/* Main Program */
int main(int argc, char *argv[])
{
    char inF = (FILESIZE);
    unsigned int array[FILESIZE];
    char str[7] = "--help";

    if(argc != 2 || (strcmp(argv[1], str) == 0))
    {
        Usage(&argv[0]);
    }
    strcpy(inF, argv[1]);
    ReadFile();
    MPGVersion);

	return 0;
}
/* Function Defenition */
/*
 * ===  FUNCTIONNCTION  ======================================================================
 *         Name:  Usage
 *  Description:  The Error function
 * =====================================================================================
 */
void Usage ( char **info )
{
    printf("\nUsage %s <inputFile>\n", *info);
    exit (1);
    return;
}		/* -----  end of function Usage  ----- */
/*
 * ===  FUNCTION  ======================================================================
 *         Name:  ReadFile
 *  Description: Reads the file and copys the string
 * =====================================================================================
 */

void ReadFile ( char *fileName, unsigned int num[] )
{
    int i = 0;
    FILE *inFile;
    inFile = fopen(fileName, "r");
    if(inFile == NULL)
    {
        exit(1);
    }
    while(fscanf(inFile, "%X", &num[i])!= EOF)
    {
        fgetc(inFile);
        printf("%X", num[i]);
        i++;
    }
    return;
}		/* -----  end of function ReadFile  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  MPEGVersion
 *  Description: Testing for the  MPEG version
 * =====================================================================================
 */
void MPEGVersion ( unsigned int data )
{
    unsigned int speed, remander;
    remander = data & 0x00180000;
    remander >> 19;
    speed = remander;
    switch (remander)
    {
        case 1:
            printf("Your MPEG Version is: MPEG version 2.5\n");
            break;

        case 2:
            printf("Your MPEG Version is: resurved\n");
            break;

        case 3:
            printf("Your MPEG Version is: MPEG Version 2\n");
            break;

        default:
            printf("Your MPEG Version is: MPEG Version 1\n");
            break;
    }				/* -----  end switch  ----- */
    remander = data & 0x00060000;
    remander >> 19;
    switch (remander)
    {
        case 1:
            printf("Your Layer is: Reserved\n");
            break;

        case 2:
            printf("Your Layer is: Layer 3\n");
            break;

        case 3:
            printf("Your Layer is: Layer 2\n");
            break;

        default:
            printf("Your Layer is: Layer 1\n");
            break;
    }				/* -----  end switch  ----- */
    remander = data & 0x00000c00;
    remander >> 7;
    if(speed == 3)
            {

                switch (remander)
                {
                    case 1:
                        printf("Your sampling rate is: 44100 Hz\n");
                        break;

                    case 2:
                        printf("Your sampling rate is: 48000 Hz\n");
                        break;

                    case 3:
                        printf("Your sampling rate is: 32000 Hz\n");
                        break;

                    default:
                        printf("Your sampling rate is: reserv\n");
                        break;
                }				/* -----  end switch  ----- */
            }
    else if(speed == 2)
    {

        switch (remander)
        {
            case 1:
                        printf("Your sampling rate is: 22050 Hz\n");
                break;

            case 2:
                        printf("Your sampling rate is: 24000 Hz\n");
                break;

            case 3:
                        printf("Your sampling rate is: 16000 Hz\n");
                break;

            default:
                        printf("Your sampling rate is: reserv\n");
                break;
        }				/* -----  end switch  ----- */

    }
    else if(speed == 0)
    {

        switch (remander)
        {
            case 1:
                        printf("Your sampling rate is: 11025 Hz\n");
                break;

            case 2:
                        printf("Your sampling rate is: 12000 Hz\n");
                break;

            case 3:
                        printf("Your sampling rate is: 8000 Hz\n");
                break;

            default:
                        printf("Your sampling rate is: reserv\n");
                break;
        }				/* -----  end switch  ----- */
    }
    return;
}		/* -----  end of function MPEGVersion  ----- */


