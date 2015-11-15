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

typedef struct date{
	int month,day,year;
}date;
typedef struct node{

	 struct node *next, *prev;
	char name[16];
	int acc_no, age;
	char address[60];
	char citizenship[16];
	double phone;
	char acc_type[10];
	float amt;
	date dob;
	date deposit;
	date withdraw;
}node;
typedef struct list {
	node *head, *tail;
	int length;
}list;

int j, rate;
float t, amount;

void init(list *l);
void fordelay(int j);
void close();
float interest(float t,float amount,int rate);
int length(list *l);
void createaccount(list *l);
void viewcustomerlist(list *l);
int withdrawamt(list *l); 
int depositamt(list *l);
void accountdetails(list *l);
void deleteaccount(list *l);
void help(list *l); 
void modify(list *l);
void see(list *l);
void menuchoice(void);
 	
	
