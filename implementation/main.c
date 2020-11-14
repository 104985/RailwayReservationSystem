#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "login.h"
#include "register.h"
#include "reservation.h"
#include "viewdetails.h"
#include "printticket.h"
#include "charge.h"
#include "specifictrain.h"

int main()

{
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|         RAILWAY TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");


	printf(" \n Press any key to continue:\n");

	getch();
    int ch;
    printf("Enter 1 to LOGIN\n");
    printf("Enter 0 to REGISTER\n");
    scanf("%d",&ch);
    do
    {
    switch(ch)
    {
        case 0:registration();
                break;
        case 1:login();
                break;
        default:printf("INVALID CHOICE");
    }
    ch++;
    }while(ch==1);

	int menu_choice,choice_return;
	start:
	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Trains");
	printf("\n------------------------");
	printf("\n3>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}
