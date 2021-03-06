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

#define NROWS 3
#define NCOLS 4
#define FILESIZE 81
/* Function Prototypes */
void Usage(char **info);
void ReadFile(char *file1, unsigned int num[]);
void MPEGversion(unsigned int vers);
void DispLayer(unsigned int val1);
void SampleRate(unsigned int sam);

/* Main Program */
int main(int argc, char *argv[])
{
    unsigned int nums[FILESIZE];
    if(argc != 2 || (strcmp(*(argv+1), "--help") == 0))
    {
        Usage(argv);
    }
    ReadFile(argv[1], nums);
    for (int i = 0; i < NROWS; i++)
    {
    MPEGversion(nums[i]);
    DispLayer(nums[i]);
    SampleRate(nums[i]);
    }
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

void ReadFile ( char *file1, unsigned int num[] )
{
    int i = 0, j = 0;
    unsigned int first[FILESIZE], second[FILESIZE], third[FILESIZE];
    FILE *inFile = fopen(file1, "r");
    char str1[8], str2[8], str3[8];
    if(inFile == NULL)
    {
        printf("The file was not opened\n");
        exit(1);
    }
    while(i < NROWS)
    {
        j = 0;
        while(j < NCOLS)
        {
            switch (i)
            {
                case 0:
                    {
                        fscanf(inFile, "%x", &first[j]);
                        break;
                    }
                case 1:
                    {
                        fscanf(inFile, "%x", &second[j]);
                        break;
                    }
                case 2:
                    {
                        fscanf(inFile, "%x", &third[j]);
                        break;
                    }
            }
            fgetc(inFile);
            j++;
        }
        i++;
    }
    sprintf(str1, "%x%x%x%x", first[0], first[1], first[2], first[3]);
    sprintf(str2, "%x%x%x%x", second[0], second[1], second[2], second[3]);
    sprintf(str1, "%x%x%x%x", third[0], third[1], third[2], third[3]);
    num[0] = strtol(str1, NULL, 16);
    num[1] = strtol(str2, NULL, 16);
    num[3] = strtol(str3, NULL, 16);

    return;
}		/* -----  end of function ReadFile  ----- */
/*
 * ===  FUNCTION  ======================================================================
 *         Name:  MPEGVersion
 *  Description: Function tests for witch MPEG Version
 * =====================================================================================
 */
void MPEGversion ( unsigned int vers )
{
    vers = vers & 0x180000;
    vers = vers >> 19;
    printf("Your MPEG Version is:\n");

    switch (vers)
    {
        case 0:
            printf("MPEG Version 2.5\n");
            break;

        case 1:
            printf("MPEG Version reserved\n");
            break;

        case 2:
            printf("MPEG Version 2\n");
            break;

        default:
            printf("MPEG VErson 1\n");
            break;
    }				/* -----  end switch  ----- */
    return;
}		/* -----  end of function MPEGVersion  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  DispLayer
 *  Description: Tests for and displays what layer
 * =====================================================================================
 */
void DispLayer (unsigned int lay)
{
    lay = lay & 0x60000;
    lay = lay >> 17;
    printf("Your Layer is:\n");
    switch (lay)
    {
        case 0:
            printf("Reserved\n");
            break;

        case 1:
            printf("III\n");
            break;

        case 2:
            printf("II\n");
            break;

        default:
            printf("I\n");
            break;
    }				/* -----  end switch  ----- */
    return;
}		/* -----  end of function DispLayer  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  SampleRate
 *  Description:  Scans and tests for Hz
 * =====================================================================================
 */
void SampleRate (unsigned int sam)
{
    int mpeg = sam;

    sam = sam & 0x00000C00;
    sam = sam >> 10;

    mpeg = mpeg & 0x180000;
    mpeg = mpeg >> 19;

    printf("Your Sampling Rate is:\n");
    switch (sam)
    {
        case 0:
            {
                if (mpeg == 0)
                {
                    printf("11025 Hz\n");
                }
                else if (mpeg == 2)
                {
                    printf("22050 Hz\n");
                }
                else if (mpeg == 3)
                {
                    printf("44100 Hz\n");
                }
                break;
            }
        case 1:
            {
                if (mpeg == 0)
                {
                    printf("12000 Hz\n");
                }
                else if (mpeg == 2)
                {
                    printf("24000 Hz\n");
                }
                else if (mpeg == 3)
                {
                    printf("48000 Hz\n");
                }
                break;
            }
        case 2:
            {
                if (mpeg == 0)
                {
                    printf("8000 Hz\n");
                }
                else if (mpeg == 2)
                {
                    printf("16000 Hz\n");
                }
                else if (mpeg == 3)
                {
                    printf("32000 Hz\n");
                }
                break;
            }
        default:
            {
                printf("Reserved\n");
                break;
            }
    }				/* -----  end switch  ----- */
    printf("\n");
    return;
}		/* -----  end of function DispRate  ----- */

