#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Patron { char name[100]; 
char pass[30];
char email[50]; int is_staff; };

// function prototypes int save_patron(struct Patron patron); void add_patron(); 
int menu(); void execute_action(int action); void view_patrons();

int main() { while(1) { printf("COUNTY LIBRARY SYSTEM!\n"); 
printf("Welcome Mary Njeri!\n"); execute_action(menu());
printf("Press any key to continue"); getch(); system("cls"); }
return 0;
}

int save_patron(struct Patron patron){ FILE *fp; fp = fopen("patrons","ab");
fwrite(&patron,sizeof(struct Patron),1,fp);
fclose(fp); 
return 1; }

void add_patron() { struct Patron patron; 
printf("Enter name:"); 
getchar();
gets(patron.name);
printf("Enter Email:");
gets(patron.email); printf("Initial Password: ");
gets(patron.pass); 
printf("Enter 1 if staff 0 otherwise: ");
scanf("%d",&patron.is_staff);
if(save_patron(patron)) printf("Patron %s successfully added\n",patron.name);
else printf("Unsuccessful\n"); }

int menu() { int action;
printf("Select an action:\n");
printf("1. Add new patron\n"); printf("2. View Patrons\n");
printf("3. View Books\n");
printf("4. Add New Book\n");
printf("Your Action: ");
scanf("%d",&action); 
if(action < 1 || action > 4) { printf("Invalid action. Try again\n"); }
return action; }

void execute_action(int action) { switch(action) { case 1: add_patron();
break; case 2: view_patrons(); 
break; case 3: printf("Here is a list of all books"); 
break; case 4: printf("adding a new Book\n");
break; default: printf("Invalid action.\n"); } }

void view_patrons() { FILE *fp; struct Patron patron; if((fp = fopen("patrons","rb")) == NULL) { printf("Unable to open file.\n");
return; }
