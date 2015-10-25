#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"mini.h"
int printmenu(){
	int choice;
	printf("**************************");
	printf("WELCOME TO NATIONAL BANK");
	printf("**************************\n");
	printf("\t\t1.Open new account  \n"
		"\t\t2. List of customers  \n"
		"\t\t3. Withdraw Amount  \n"
		"\t\t4.Deposit Amount   \n"
		"\t\t5.Account details  \n"
		"\t\t6.Delete account  \n"
		"\t\t7.Help  \n"
		"\t\t8.Modify  \n"
		"\t\t9.Exit \n");
	scanf("%d",&choice);
	return choice;
}
int main() {
	int choice;
	int pos;
	char str[128], *s;
	list p;
	init(&p);
	while(1) {
		choice = printmenu();
		switch(choice) {
		case 1://open new account
			printf("Enter the account number\n");
			scanf("%d",&pos);
			createaccount(&p,pos);
			break;
		case 2://list of account
			viewcustomerlist(&p);
			break;
		case 3://withdraw amount
			withdrawamt(&p);
			break;
		case 4://deposit amount
			depositamt(&p);
			break;
		case 5://account details
			accountdetails(&p);
			break;
		case 6://  delete account 
			break;
		case 7://help
			break;
		case 8://modify
			break;
		case 9://exit 
			exit(0);
			break;
		}
	}
	return 0;
}

			
		
