/**********************************************PREPROCESSORS**********************************************************/
//Railway Reservation System
//including all libraries
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

/*******************************************GLOBAL VARIABLES**********************************************************/
//ALl the global variables and the composite data types will be declared here
typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;
}pd;




/*******************************************FUNCTION PROTOTYPE**********************************************************/
//function prototypes used
void reservation(void);							//main reservation function
void viewdetails(void);							//view details of all the trains
void printticket(char name[],int,int,float);	//print ticket
void specifictrain(int);						//print data related to specific train
float charge(int,int);							//charge automatically w.r.t number of seats and train
void login();                                   //login form
void registration();                            //registration page


/******************************************FUNCTION DECLARATION**********************************************************/

/*********************************************MAIN()*************************************************/

int main()

{
		
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|         RAILWAY TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");


	printf(" \n Press any key to continue:");

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

/*********************************************VIEWDETAILS()*************************************************/


void viewdetails(void)
{
	printf("----------------------------------------------------------------------------------------------------------------");
	printf("\nTr.No\tName\t\t\tOrigin - Destination\tSeats Available\tCharges\tStart Time\tReach Time\n");
	printf("----------------------------------------------------------------------------------------------------------------");
	printf("\n12001\t Rajdhani Express\tBangalore to Delhi\t\t 12\tRs.5000\t 09:00 am\t 06:35 pm");
        printf("\n12002\t Rajdhani Express\tDelhi to Bangalore\t\t 07\tRs.5000\t 11:00 pm\t 08:35 am");
	printf("\n12003\tBangalore Express\tTrivandrum to Bangalore\t\t 22\tRs.4500\t 08:00 am\t 12:00 am");
	printf("\n12004\tBangalore Express\tBangalore to Trivandrum\t\t 15\tRs.4500\t 07:00 pm\t 11:00 am");
	printf("\n12005\tKacheguda Express\tBangalore to Kacheguda\t\t 16\tRs.4000\t 06:00 am\t 05:20 pm");
	printf("\n12006\tKacheguda Express\tKacheguda to Bangalore\t\t 20\tRs.4000\t 08:30 pm\t 07:50 am");
        printf("\n12007\tChennai Express\t\tBangalore to Chennai\t\t 19\tRs.3500\t 01:00 pm\t 06:30 pm");
        printf("\n12008\tChennai Express\t\tChennai to Bangalore \t\t 12\tRs.3500\t 11:40 am\t 05:40 pm");
        printf("\n12009\tShatabdi Express\tChennai to Mysore\t\t 03\tRs.6000\t 03.35 pm\t 10:35 pm");
        printf("\n12010\tShatabdi Express\tMysore to Chennai\t\t 10\tRs.6000\t 04.15 am\t 11:15 am");

}

/*********************************************RESERVATION()*************************************************/

void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=12001 && passdetails.train_num<=12010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

/*********************************************CHARGE()*************************************************/

float charge(int train_num,int num_of_seats)
{
		if (train_num==12001)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==12002)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==12003)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==12004)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==12005)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==12006)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==12007)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==12008)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==12009)
	{
		return(6000.0*num_of_seats);
	}
	if (train_num==12010)
	{
		return(6000.0*num_of_seats);
	}
}


/*********************************************PRINTTICKET()*************************************************/

void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charges);
}

/*********************************************SPECIFICTRAIN()*************************************************/

void specifictrain(int train_num)
{

	if (train_num==12001)
	{
		printf("\nTrain:\t\t\tRajdhani Express");
		printf("\nDestination:\t\tBangalore to Delhi");
		printf("\nDeparture:\t\t 09:00 am");
		printf("\nArrival at Destination: 06:35 pm");
	}
	if (train_num==12002)
	{
        printf("\nTrain:\t\t\tRajdhani Express");
		printf("\nDestination:\t\tDelhi to Bangalore");
		printf("\nDeparture:\t\t 11:00 pm");
		printf("\nArrival at Destination: 08:35 am");
	}
	if (train_num==12003)
	{
		printf("\nTrain:\t\t\tBangalore Express");
		printf("\nDestination:\t\tTrivandrum to Bangalore");
		printf("\nDeparture:\t\t 08:00 am");
		printf("\nArrival at Destination: 12:00 am");
	}
	if (train_num==12004)
	{
		printf("\nTrain:\t\t\tBangalore Express");
		printf("\nDestination:\t\tBangalore to Trivandrum");
		printf("\nDeparture:\t\t 07:00 pm");
		printf("\nArrival at Destination: 11:00 am");
	}
	if (train_num==12005)
	{
		printf("\nTrain:\t\t\tKacheguda Express");
		printf("\nDestination:\t\tKacheguda to Bangalore");
		printf("\nDeparture:\t\t 06:00 am");
		printf("\nArrival at Destination: 05:20 pm");
	}
	if (train_num==12006)
	{
		printf("\nTrain:\t\t\tKacheguda Express");
		printf("\nDestination:\t\tBangalore to Kacheguda");
		printf("\nDeparture:\t\t 08:30 pm");
		printf("\nArrival at Destination: 07:50 am");
	}
	if (train_num==12007)
	{
		printf("\nTrain:\t\t\tChennai Express");
		printf("\nDestination:\t\tBangalore to Chennai");
		printf("\nDeparture:\t\t 01:00 am");
		printf("\nArrival at Destination: 06:30 pm");
	}
	if (train_num==12008)
	{
		printf("\nTrain:\t\t\tChennai Express");
		printf("\nDestination:\t\tChennai to Bangalore");
		printf("\nDeparture:\t\t 11:40 am");
		printf("\nArrival at Destination: 05:40 pm");
	}
	if (train_num==12009)
	{
		printf("\nTrain:\t\t\tShatabdi Express");
		printf("\nDestination:\t\tChennai to Mysore");
		printf("\nDeparture:\t\t 03:35 pm");
		printf("\nArrival at Destination: 10:35 pm");
	}
	if (train_num==12010)
	{
		printf("\nTrain:\t\t\tShatabdi Express");
		printf("\nDestination:\t\tMysore to Chennai");
		printf("\nDeparture:\t\t 04:15 am");
		printf("\nArrival at Destination: 11:15 am");
	}
}

/*********************************************REGISTRATION()*************************************************/
void registration()
{
    char user[10];
    char mail[30];
    char location[40];
    printf(" \n                    Enter NAME:-  ");
    scanf("%s",&user);
    printf(" \n                    Enter MailID:-  ");
    scanf("%s",&mail);
    printf("\n                     Enter Location:- ");
    scanf("%s",&location);
    printf("\n=======================REGISTERED SUCCESSFULLY...!=============================\n");
    printf("  \n\n            Dear Passenger your login credentials are\n   ");
    printf("\n               USERNAME:user \t PASSWORD:pass\n ");

}

/*********************************************LOGIN()*************************************************/
void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
}







