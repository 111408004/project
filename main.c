/*****************************************************************************
 * Copyright (C) Neha Ambhore  ambhorend14.it@coep.ac.in
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"mini.h"
list p;
int printmenu() {
	
	int choice;
	printf("\n\n\n**************************");
	printf("CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
	printf("**************************\n");
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\t\t1.Open new account  \n"
		"\t\t2. List of customers  \n"
		"\t\t3. Withdraw Amount  \n"
		"\t\t4.Deposit Amount   \n"
		"\t\t5.Account details  \n"
		"\t\t6.Delete account  \n"
		"\t\t7.See  \n"
		"\t\t8.Modify  \n"
		"\t\t9.Exit \n");
	scanf("%d",&choice);
	return choice;
}
int main() {

	int choice;
	//list p;
	init(&p);
	int main_exit;
	char str[128], *s;
	
	char pass[10],password[10]="coep";
    	int i = 0;
	
    	printf("\n\n\t\tEnter the password to login: ");
    	scanf("%s",pass);
	if (strcmp(pass,password) == 0) {
        
		printf("\n\nPassword Match!LOADING....\n");
		
        	for(i = 0; i <= 6; i++) {
			fordelay(100000000);
                	printf(".");
		}
		//choice = printmenu();
		menuchoice();
               
        }
	else {
		printf("\n\nWrong password!!\a\a\a");
                login_try:
                printf("\nEnter 1 to try again and 0 to exit:");
                scanf("%d",&main_exit);
                if (main_exit == 1) {
                	
			main(); 
                }

       		else if (main_exit == 0) {
        		close();           
        	}
        	else {
                	printf("\nInvalid!");
                	fordelay(1000000000);
			main();
                }  

        }

	
	return 0;
}
void menuchoice() {
	int choice = printmenu();
	//list p;
	//init(&p);
	while(1) {
		
		switch(choice) {

		case 1://open new account
			createaccount(&p);
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
			deleteaccount(&p);
			break;

		case 7://help
			see(&p);
			break;

		case 8://modify
			modify(&p);
			break;

		case 9://exit 
			exit(0);
			break;
		}
	}
}

			
		
