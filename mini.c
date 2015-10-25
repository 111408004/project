#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mini.h"

void init(list *l) {

	l->head = l->tail = NULL;
	l->length = 0;
}

void createaccount(list *l,int pos) {

	int choice;
	node *p, *tmp;
	int i;
	tmp = (node *) malloc(sizeof(node));
	
	if(l-> head == NULL) {
		tmp -> next = tmp ->prev =NULL;
		l->head = l->tail = tmp;
		l->length = 1;
		//return;
	}

	if(pos == l->length) {
		l->tail->next = tmp;
		tmp->prev = l->tail;
		l->tail = tmp;
		tmp->next = NULL;
		(l->length)++;
		//return;
	}
	
	printf("Enter today's date(mm/dd/yyyy):\n");
	scanf("%d/%d/%d",&tmp->deposit.month,&tmp->deposit.day,&tmp->deposit.year);
	printf(" Enter the account number:\n");
	scanf("%d",&tmp->acc_no);
	printf("Enter account holder name:\n");
	scanf("%s",tmp->name);
	printf("Enter the age of account holder\n");
	scanf("%d",&tmp->age);
	printf("Enter the address\n");
	scanf("%s",tmp->address);
	printf("Enter date of birth\n");
	scanf("%d/%d/%d",&tmp->dob.day,&tmp->dob.month,&tmp->dob.year);
	printf("Enter the citizenship\n");
	scanf("%s",tmp->citizenship);
	printf("Enter phone no\n");
	scanf("%lf",&tmp->phone);
	printf("Enter account type(C/S)\n");
	scanf("%s",tmp->acc_type);
	printf("Enter the amount:(for C = 1000 and S = 500)\n");
	scanf("%f",&tmp->amt);
	printf("Account created successfully\n\n\n");
}

void viewcustomerlist(list *l) {

	node *p;
	p = l -> head;
	int i;
	printf("\tAccno\tName\tType\tBalance\n");
	for(i = 0;i < l->length;i++) {
		printf("\t%d\t%s\t%s\t%f\n",p->acc_no,p->name,p->acc_type,p->amt);
		p = p -> next;
	}
	p -> next = NULL;
	return;
}

int withdrawamt(list *l) {

	int choice, i;
	float cash;
	node *p;
	p = l->head;
	printf("Enter account number\n");
	scanf("%d",&p->acc_no);
		
	for(i = 0;i < p->acc_no;i++)
		p = p->next;
		
	printf("**********Account Status**************\n");
	printf("Account number = %d\n",p->acc_no);
	printf("Account holder = %s\n",p->name);
	printf("Type of account = %s\n",p->acc_type);
	printf("Balance amount = %f\n\n\n",p->amt);

	printf("Enter amount you have to withdraw\n");
	scanf("%f",&cash);
	if(cash > p->amt)
		printf("Insufficient balance\n");
	else {
		p->amt = p->amt - cash;
		printf("%f\n",p->amt);
	}
	printf("Record Updated\n"); 
}

int depositamt(list *l) {
	int choice, i;
	float cash;
	node *p;
	p = l->head;
	printf("Enter account number\n");
	scanf("%d",&p->acc_no);
		
	for(i = 0;i < p->acc_no;i++)
		p = p->next;
		
	printf("**********Account Status**************\n");
	printf("Account number = %d\n",p->acc_no);
	printf("Account holder = %s\n",p->name);
	printf("Type of account = %s\n",p->acc_type);
	printf("Balance amount = %f\n\n\n",p->amt);
		
	printf("Enter amount you have to deposit\n");
	scanf("%f",&cash);
	p->amt = p->amt + cash;
	printf("Balance left = %f\n",p->amt);
		
	printf("Record Updated\n");
}


void accountdetails(list *l) {

	int i;
	node *p;
	p = l->head;
	printf("Enter account number\n");
		scanf("%d",&p->acc_no);
		
		for(i = 0;i < p->acc_no;i++)
			p = p->next;
		
		printf("**********Account Details**************\n");
		printf("Account number = %d\n",p->acc_no);
		printf("Account holder = %s\n",p->name);
		printf("Type of account = %s\n",p->acc_type);
		printf("Balance amount = %f\n",p->amt);
		printf("Age of account holder = %d\n",p->age);
		printf("Address = %s\n",p->address);
		printf("Citizenship = %s\n",p->citizenship);
		printf("Phone number = %lf\n\n",p->phone);
}

void modify(list *l) {

	int i;
	node *p;
	p = l->head;
	printf("Enter account number\n");
	scanf("%d",&p->acc_no);
		
	for(i = 0;i < p->acc_no;i++)
		p = p->next;
	
	printf("**********Current Account Status**************\n");
	printf("Account number = %d\n",p->acc_no);
	printf("Account holder = %s\n",p->name);
	printf("Type of account = %s\n",p->acc_type);
	printf("Balance amount = %f\n\n\n",p->amt);
		
}

void deleteaccount(list *l) {
	
	int i;
	node *p;
	p = l->head;
	printf("Enter account number\n");
		scanf("%d",&p->acc_no);
		
	for(i = 0;i < p->acc_no;i++)
	p = p->next;
	printf("**********Account Status**************\n");
	printf("Account number = %d\n",p->acc_no);
	printf("Account holder = %s\n",p->name);
	printf("Type of account = %s\n",p->acc_type);
	printf("Balance amount = %f\n\n\n",p->amt);
	
	
	
	
}

void help() {
}


