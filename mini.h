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
void init(list *l);
int length(list *l,char *str);
void createaccount(list *l,int pos);
void viewcustomerlist(list *l);
int withdrawamt(list *l); 
int depositamt(list *l);
void accountdetails(list *l);
void deleteaccount();
void help(); 
void modify();
 	
	
