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
#include"mini.h"

void init(list *l) {

	l->head = l->tail = NULL;
	l->length = 0;
}
void fordelay(int j) {
 
	int i,k;
        for(i=0;i<j;i++)
        k=i;
}
int length(list *l) {
	return l->length;	
}
void close() {
	printf("\n\n\n\nThe System is closed.....!\n\n");
	exit(0);
}
float interest(float t,float amount,int rate)
{
	float SI;
        SI=(rate*t*amount)/100.0;
        return (SI);

}

void createaccount(list *l) {

	int choice, acc;
	node *add, *check, *p;
	int i, main_exit;
	add = (node *)malloc(sizeof(node));
	
	
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ADD RECORD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("Enter today's date(dd/mm/yyyy):\n");
	scanf("%d/%d/%d",&add->deposit.day,&add->deposit.month,&add->deposit.year);
	printf(" Enter the account number:\n");
	scanf("%d", &acc);
	check = l->head;
	if(l->tail == NULL) {
		check = NULL;
	}
	while(check != NULL) {
		if (acc == check->acc_no) {
        		printf("Account no. already in use!\n");
        		fordelay(1000000000);
                	createaccount(l);
			break;
		}
		
		check = check->next;
	}
	add->acc_no = acc;
	printf("Enter account holder name:\n");
	scanf("%s",add->name);
	printf("Enter the age of account holder\n");
	scanf("%d",&add->age);
	printf("Enter the address\n");
	scanf("%s",add->address);
	printf("Enter date of birth\n");
	scanf("%d/%d/%d",&add->dob.day,&add->dob.month,&add->dob.year);
	printf("Enter the citizenship\n");
	scanf("%s", add->citizenship);
	printf("Enter phone no\n");
	scanf("%lf", &add->phone);
	printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
	scanf("%s",add->acc_type);
	printf("Enter the amount\n");
	scanf("%f",&add->amt);
	
	if(l->head) {
		add->next = NULL;
		add->prev = l->tail;
		l->tail->next = add;
		printf("***************");
	} 
	else {
		add->next = add->prev = NULL; 
		l->head	= add;
		
	}
	l->tail = add;	
	l->length++;
	if(l->length == 1)
		p = l->head = add; 
	
	printf("Account created successfully\n\n\n");
	
	printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        if (main_exit == 1) {
        	
		menuchoice();
	}
        else if(main_exit == 0) {
        	close();
	}
	else {
        	printf("\nInvalid!\a");
        }
	
}

void viewcustomerlist(list *l) {
	node *add;
	add = l->head;
	int i = 0, main_exit;
	//node *add, *check;
	if (add == NULL) {
        
            printf("\nNO RECORDS!!\n");
	}
	else {
		printf("\nACC. NO.\tNAME\t\t\tACC. TYPE\t\t\tAMOUNT\n");
		add = l->head;
		while(i < l->length) {
			
			printf("\n%d\t%s\t\t%s\t\t%f\n",add->acc_no,add->name,add->acc_type,add->amt);
			add = add->next;
			i++;
		}
	}
	printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
       
        if (main_exit == 1) {
        	menuchoice();
	}
        else if(main_exit == 0) {
        	close();
	}
        else {
        	printf("\nInvalid!\a");
		exit(0);
        }
}

int withdrawamt(list *l) {

	int choice, i;
	float cash;
	int acc;
	int main_exit, test = 0;
	node *p, *check;
	p = (node *)malloc(sizeof(node));
	check = l->head;
	printf("Enter account number\n");
	scanf("%d",&acc);
	while(check != NULL) {
		if (acc == check->acc_no) {
			printf("**********Account Status**************\n");
			printf("Account number = %d\n",check->acc_no);
			printf("Account holder = %s\n",check->name);
			printf("Type of account = %s\n",check->acc_type);
			printf("Balance amount = %f\n\n\n",check->amt);
			printf("Enter amount you have to withdraw\n");
			scanf("%f",&cash);
			if(cash > check->amt) {
				printf("Insufficient balance\n");
			}
			else {
				check->amt = check->amt - cash;
				printf("Balance left :%f\n",check->amt);
			}
			printf("Record Updated\n");
			test++; 
			break;
		}
		check = check->next;
	}
		
	if(test == 0) {
        
        	printf("\nRecord not found!!\a\a\a");
        	printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
                scanf("%d",&main_exit);

                if (main_exit == 1) {
                	menuchoice();
		}
                else if (main_exit == 2) {
                	close();
		}
                else if(main_exit == 0) {
                     withdrawamt(l);
		}
                else {
                	printf("\nInvalid!\a");
                }
        }
        else {
        
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
	        scanf("%d",&main_exit);
        }
        if (main_exit == 1) {
        	menuchoice();
	}
        else {
            close();
        }
	
	
}

int depositamt(list *l) {

	int choice, i;
	float cash;
	int acc;
	int main_exit, test;
	node *p, *check;
	p = (node *)malloc(sizeof(node));
	check = l->head;
	printf("Enter account number\n");
	scanf("%d", &acc);
		
	while(check != NULL) {
		if (acc == check->acc_no) {
			printf("**********Account Status**************\n");
			printf("Account number = %d\n",check->acc_no);
			printf("Account holder = %s\n",check->name);
			printf("Type of account = %s\n",check->acc_type);
			printf("Balance amount = %f\n\n\n",check->amt);
			
			printf("Enter amount you have to deposit\n");
			scanf("%f",&cash);
			check->amt = check->amt + cash;
			printf("Balance left = %f\n",check->amt);
		
			printf("Record Updated\n");
			test++;
			break;
		}
		check = check->next;
	}
		
	if(test == 0) {
        
        	printf("\nRecord not found!!\a\a\a");
        	printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
                scanf("%d",&main_exit);

                if (main_exit == 1) {
                	menuchoice();
		}
                else if (main_exit == 2) {
                	close();
		}
                else if(main_exit == 0) {
                    depositamt(l);
		}
                else {
                	printf("\nInvalid!\a");
                }
        }
        else {
        
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
	        scanf("%d",&main_exit);
        }
        if (main_exit == 1) {
        	menuchoice();
	}
        else {
            close();
        }
		
	
	
}


void accountdetails(list *l) {

	int i, test = 0;
	node *p, *check;
	int main_exit;
	int acc;
	check = l -> head;
	p = (node *)malloc(sizeof(node));
	printf("Enter account number\n");
	scanf("%d", &acc);
	while(check != NULL) {
		if (acc == check->acc_no) {
			printf("**********Account Details**************\n");
		printf("Account number = %d\n",check->acc_no);
		printf("Account holder = %s\n",check->name);
		printf("Type of account = %s\n",check->acc_type);
		printf("Balance amount = %f\n",check->amt);
		printf("Age of account holder = %d\n",check->age);
		printf("Address = %s\n",check->address);
		printf("Citizenship = %s\n",check->citizenship);
		printf("Phone number = %lf\n\n",check->phone);
		test++;	
		}
		check = check->next;
	}
	if(test == 0) {
        
        	printf("\nRecord not found!!\a\a\a");
        	printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
                scanf("%d",&main_exit);

                if (main_exit == 1) {
                	menuchoice();
		}
                else if (main_exit == 2) {
                	close();
		}
                else if(main_exit == 0) {
                    accountdetails(l);
		}
                else {
                	printf("\nInvalid!\a");
                }
        }
        else {
        
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
	        scanf("%d",&main_exit);
        }
        if (main_exit == 1) {
        	menuchoice();
	}
        else {
            close();
        }
}

void modify(list *l) {

	int i, test = 0, acc;
	int choice, main_exit;
	node *p;
	p = (node *)malloc(sizeof(node));
	node *add, *upd, *check;
	check = l->head;
	printf("\nEnter the account no. of the customer whose info you want to change:");
	scanf("%d",&acc);
		
	while(check != NULL) {
		if (acc == check->acc_no) {
			printf("**********Account Status**************\n");
			printf("Account number = %d\n",check->acc_no);
			printf("Account holder = %s\n",check->name);
			printf("Type of account = %s\n",check->acc_type);
			printf("Balance amount = %f\n\n\n",check->amt);
			test = 1;
                	printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
                	scanf("%d",&choice);
                	if(choice == 1) {
                		printf("Enter the new address:");
                		scanf("%s",check -> address);
				printf("Changes saved!");
                	}
			else if(choice == 2) {
                		printf("Enter the new phone number:");
                		scanf("%lf",&check -> phone);
				printf("Changes saved!");
                	}

			break;
		}
		check = check->next;
	}
	if(test != 1) {
           
        	printf("\nRecord not found!!\a\a\a");
                printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
                scanf("%d",&main_exit);
                
                if (main_exit==1) {
			printmenu();
		}
                else if (main_exit==2) {
                	close();
		}
                else if(main_exit==0) {
                	modify(l);
		}
                else {
                	printf("\nInvalid!\a");
                }
        }
	else {
        	printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        	scanf("%d",&main_exit);
        	if (main_exit == 1) {
            		menuchoice();
		}
        	else {
       			close();
		}
        }
	
}

void deleteaccount(list *l) {
	
	int i, test = 0, acc;
	int choice, main_exit;
	node *check, *p;
	node *q;
	p = check = l->head;
	//p = (node *)malloc(sizeof(node));
	
	printf("Enter account number\n");
	scanf("%d",&acc);
		
	while(check != NULL) {
		if (acc == check->acc_no) {
			printf("**********Account Status**************\n");
			printf("Account number = %d\n",check->acc_no);
			printf("Account holder = %s\n",check->name);
			printf("Type of account = %s\n",check->acc_type);
			printf("Balance amount = %f\n\n\n",check->amt);
			printf("Are you sure do you want to delete account\n");
			printf("1.YES\n");
			printf("2.NO\n");
			scanf("%d",&choice);
			if(choice == 1) {
				if(l->length == 1) {
					l->head = l->tail = NULL;
					free(check);
					l->length--;
					//return tmp;
				}
				else if(l->length == 2) {
					if(check->next == NULL) {
						l->tail = l->head;
						l->head = NULL;
						check->prev = NULL;
						free(check);
						l->length--;
					}
					else{
						l->head = l->tail;
						l->tail->prev = NULL;
						check->next = NULL;
						free(check);
						l->length--;
					}
				}
				else {
					if(check->next == NULL) {
						l->tail = l->tail->prev;
						l->tail->next = NULL;
						check->prev = NULL;
						free(check);
					}
					else if(check->prev == NULL) {
						l->head = l->head->next;
						l->head->prev = NULL;
						check->next = NULL;
						free(check);
					}
					else {
						p = check->prev;
						q = check->next;
						p->next = q;
						q->prev = p;
						check->next = NULL;
						check->prev = NULL;
						free(check); 
					
					}
					
				}
				

				printf("Account deleted successfully\n");
				//return;
			}
			else
				exit(0);
			test++;
			break;
		}
		check = check->next;
	}
		
	if(test == 0) {
        
        	printf("\nRecord not found!!\a\a\a");
        	printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
                scanf("%d",&main_exit);

                if (main_exit == 1) {
                	menuchoice();
		}
                else if (main_exit == 2) {
                	close();
		}
                else if(main_exit == 0) {
                    deleteaccount(l);
		}
                else {
                	printf("\nInvalid!\a");
                }
        }
        else {
        
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
	        scanf("%d",&main_exit);
        }
        if (main_exit == 1) {
        	menuchoice();
	}
        else {
            close();
        }
}

void help(list *l) {
	node *p;
	printf("Enter account number\n");
	scanf("%d",&p->acc_no);
	
	
}

void see(list *l) {

    	int main_exit;
	int test = 0,rate;
    	int choice, acc;
    	float time;
    	float intrst;
	node *add, *check, *p;
	check = l->head;
	char str[16];
    
    	printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    	scanf("%d",&choice);
    	if (choice == 1) {
        	printf("Enter the account number:");
        	scanf("%d",&acc);
		while(check != NULL) {
				if (acc == check->acc_no) {
				printf("Account number = %d\n",check->acc_no);
				printf("Account holder = %s\n",check->name);
				printf("Type of account = %s\n",check->acc_type);
				printf("Balance amount = %f\n",check->amt);
				printf("Age of account holder = %d\n",check->age);
				printf("Address = %s\n",check->address);
				printf("Citizenship = %s\n",check->citizenship);
				printf("Phone number = %lf\n\n",check->phone);
				test = 1;	
				if(strcmp(check->acc_type,"fixed1")==0) {
                    
                        		time=1.0;
                        		rate=9;
                        		intrst=interest(time,check->amt,rate);
                                	printf("\n\nYou will get $%.2f as interest on %d/%d/%d",intrst,check->deposit.month,check->deposit.day,check->deposit.year+1);
                        	}
                		else if(strcmp(check->acc_type,"fixed2") == 0) {
                    
                        		time=2.0;
                        		rate=11;
                        		intrst=interest(time,check->amt,rate);
                        		printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,check->deposit.month,check->deposit.day,check->deposit.year+2);
				}
                		else if(strcmp(check->acc_type,"fixed3") == 0) {
                    
                        	time=3.0;
                        	rate=13;
                        	intrst=interest(time,check->amt,rate);
                        	printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,check->deposit.month,check->deposit.day,check->deposit.year+3);

                        	}
                 		else if(strcmp(check->acc_type,"saving") == 0) {
                    
                        		time=(1.0/12.0);
                        		rate=8;
                        		intrst=interest(time,check->amt,rate);
                        		printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,check->deposit.day);

                        	}
                 		else if(strcmp(check->acc_type,"current")==0) {
                        		printf("\n\nYou will get no interest\a\a");
				}

			}
			check = check->next;
		}
	}
       
else if (choice == 2) {
      
	printf("Enter the name:");
        scanf("%s",str);
	while(check != NULL) {
			if(strcmp(check->name,str) == 0) {
				printf("Account number = %d\n",check->acc_no);
				printf("Account holder = %s\n",check->name);
				printf("Type of account = %s\n",check->acc_type);
				printf("Balance amount = %f\n",check->amt);
				printf("Age of account holder = %d\n",check->age);
				printf("Address = %s\n",check->address);
				printf("Citizenship = %s\n",check->citizenship);
				printf("Phone number = %lf\n\n",check->phone);
				test = 1;	
    				if(strcmp(check->acc_type,"fixed1")==0) {
                    
                        		time=1.0;
                        		rate=9;
                        		intrst=interest(time,check->amt,rate);
                                	printf("\n\nYou will get $%.2f as interest on %d/%d/%d",intrst,check->deposit.month,check->deposit.day,check->deposit.year+1);
                        	}
                		else if(strcmp(check->acc_type,"fixed2") == 0) {
                    
                        		time=2.0;
                        		rate=11;
                        		intrst=interest(time,check->amt,rate);
                        		printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,check->deposit.month,check->deposit.day,check->deposit.year+2);
				}
                		else if(strcmp(check->acc_type,"fixed3") == 0) {
                    
                        	time=3.0;
                        	rate=13;
                        	intrst=interest(time,check->amt,rate);
                        	printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,check->deposit.month,check->deposit.day,check->deposit.year+3);

                        	}
                 		else if(strcmp(check->acc_type,"saving") == 0) {
                    
                        		time=(1.0/12.0);
                        		rate=8;
                        		intrst=interest(time,check->amt,rate);
                        		printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,check->deposit.day);

                        	}
                 		else if(strcmp(check->acc_type,"current")==0) {
                        		printf("\n\nYou will get no interest\a\a");
				}
				
			}
			check = check->next;
		}
	}
	if(test != 1) {
        	printf("\nRecord not found!!\a\a\a");
           	printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              	scanf("%d",&main_exit);
              
                if (main_exit == 1)
                    menuchoice();
                else if (main_exit == 2)
                    close();
                else if(main_exit==0)
                    see(l);
                else {
                 	printf("\nInvalid!\a");
                }
        }
    	else {
  		printf("\nEnter 1 to go to the main menu and 0 to exit:");
        	scanf("%d",&main_exit);
	}
        	if (main_exit==1)
       			menuchoice();
        
	else {
     		close();
        }
}


