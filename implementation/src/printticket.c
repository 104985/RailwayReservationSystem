#include "printticket.h"
#include "specifictrain.h"
void printticket(char name[],int num_of_seats,int train_num)
{
	printf("---------------------------------\n");
	printf("\tTICKET\n");
	printf("---------------------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
}
