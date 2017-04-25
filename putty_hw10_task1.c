/*
 * =====================================================================================
 *
 *       Filename:  housePrice.c
 *       	Usage:  ./housePrice.c
 *    Description:  Ask user to specify the address and price
 *    				of two house that are on sale
 *    				It prints out which of the two houses is cheaper
 *
 *        Version:  1.0
 *        Created:  03/06/2014 04:03:12 PM
 *       Compiler:  gcc
 *         Author:  Dr. Hugo Valle (), hugovalle1@weber.edu
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "putty_hw10_task1.h"

/* Function Prototypes */

/* Main Program */
int main(int argc, char* argv[])
{
    PrintHouse("first house:", firstH);
    printf("\n\n");
    PrintHouse("second house", secondH);
    printf("\n\n");

    return 0;
}

/* Function Defenitions */
// 1) Function for InputHouse
struct house InputHouse(void)
{
    struct house Dhouse;
    printf("Enter street num: ");
    scanf("%d", *&Dhouse.StreetNum);

    printf("Enter street name: ");
    scanf("%s", *&Dhouse.StreetName);

    printf("Enter price: ");
    scanf("%f", &Dhouse.Price);

<<<<<<< HEAD
	return 0;
=======
    return (Dhouse);
}
	//....
// 2) Function to PrintHouse info
void PrintHouse(char *name, struct house h)
{
    printf("first house at %d %s for %f", h.StreetNum, h.StreetName, h.Price);
    printf("second house at %d %s for %f", h.StreetNum, h.StreetName, h.Price);

return;
>>>>>>> 909cb4fb45d8b2cb13f044ab070c39becc9c3bb1
}

// 3) Function to Compare Prices//
int ComparePrices(struct firstH.Price, struct secondH.Price)
{
    int comparison = ComparePrices (firstH.Price,secondH.Price);

    switch (comparison)
    {
        case 1:
            if (firstH.Price < secondH.Price)
                printf("the first house is cheaper\n");
            break;

        case 2:
            if (firstH.Price == secondH.Price)
                printf("the two houses are equally expensive\n");
            break;

        case 3:
            if (firstH.Price > secondH.Price)
                printf("the second house is cheaper\n");
            break;

        default:
            printf("invalid comparison value %d, there must be a bug\n", comparison);
            break;
    }

    return comparison;
}


