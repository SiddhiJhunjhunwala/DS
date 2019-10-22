#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<ctype.h>
#include<dos.h>
#define ANSI_COLOR_GREEN "\x1b[32m"

#define ANSI_COLOR_YELLOW "\x1b[33m"

void viewMedicines(int);
int printMenu();
void addToCart();


char name[14][50] = {" First Aid Kit"," Ibuprofen"," Paracetamol"," Dexamethasone"," Loratadine"," Crocin"," Pyrantel"," Ampicillin"," Linezolid","Dapsone","Amphotericin B","Ribavirin","Quinine","Doxycilin"};
int pri[]={140,588,433,157,153,125,420,154, 147,953,458,125,153,412};

void ccolor(int color){
    HANDLE hConsole;
    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,color);
}

struct node{
	int price;
	int quantity;
	char medname[50];
	struct node *next;
}*top;


void pushMed(struct node *newnode);
void displayBill();

int printMenu(){

    int n;
    ccolor(10);
	printf("\n\n\n\t\t\t\t Get Well!!\n\n");
	ccolor(7);

   printf("\t\t\t1.View medicines\n");
   printf("\t\t\t2.Add to Cart\n");
   printf("\t\t\t3.View your cart\n");
   printf("\t\t\t4.Confirm and place order\n");
   printf("\t\t\t5.Print Main menu\n");
   printf("\t\t\t6.Exit\n");

   printf("\n\n");
    ccolor(10);
   printf("\t\t\tEnter your option:");
    ccolor(7);
   scanf("%d",&n);
   printf("\n\n\n\n");
    system("cls");
   return n;
}


void viewMedicines(int mysignal)
{
	int i,enter;
	ccolor(47);
	printf("\t\t\t\tSr.No   Products      Price\n\n");
	ccolor(7);
	for(i=0; i<14; i++)
	{
        Sleep(100);
		printf("\t\t\t\t%d.   %s - $%d \n ", i+1 ,name + i , pri[i]);
	}
	 printf("\n\n");

	 if(mysignal==99)
     {
         ccolor(10);
         printf("\t\t\t\tPress 0 to go back:");
         ccolor(7);
         scanf("%d",&enter);
         if(enter==0)
         {
             system("cls");
         }
     }

}


void addToCart()
{
	int medno, quantity ,i;
	struct node *newnode ;
	ccolor(10);
	printf("\n\t\tEnter the medicine number or -1 to go back to menu:   ");
	ccolor(7);
	scanf("%d",&medno);
	i=0;
	while(medno!=-1)
	{
	    ccolor(10);

		printf("\t\tEnter Quantity   ");
		ccolor(7);
		scanf("%d", &quantity);

		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->quantity =  quantity;
		newnode->price = pri[medno-1];

		strcpy(newnode->medname ,name + (medno - 1));

		pushMed(newnode);
        ccolor(10);
		printf("\n\t\tEnter the medicine number or -1 to to go back to menu:   ");
		ccolor(7);
		scanf("%d",&medno);

	}
    system("cls");
}


void pushMed(struct node *newnode)
{
	if(top==NULL)
	{
		top = newnode;
		newnode->next= NULL;
	}
	else{
		newnode->next = top;
		top = newnode;
	}
}


int displayCart(int signal)
{
	int counter=0 ,sum=0, myoption;
	struct node *temp;
	temp = top;
	ccolor(47);
	printf("\n\n\n\t\t\t\tNO.\tMedicine Name\tQuantity\tPrice\n");
	ccolor(7);
	while(temp!=NULL)
	{
	    Sleep(70);
		printf("\t\t\t\t%d\t%s \t %d \t\t %d \n", ++counter,temp->medname , temp->quantity , temp->price );
		sum+= (temp->quantity)* (temp->price);
		temp= temp->next;
	}

	if(signal==99)
    {
        return sum;
    }
    ccolor(10);
    printf("\n\t\t\t\tEnter 1 to edit Cart and 2 to go back to menu:");
    ccolor(7);
    scanf("%d",&myoption);
    if(myoption==1)
    {
        addToCart();
    }else{
        system("cls");
        return sum;
    }

}


void displayBill()
{
    system("cls");
	int sum;
	sum=displayCart(99);
	printf("\t\t\t\t----------------------------------------------\n");
	ccolor(47);
	printf("\t\t\t\tAmount----------------------------------%d",sum);
	ccolor(9);
	printf("\n\n\n\t\t\t\t**************************Thanks for visiting********************************\n");
	ccolor(7);
	exit(0);
}

void main()
{
    int choice;
    choice = printMenu();
    while(1){
          switch(choice)
            {
                case 1: viewMedicines(99);
                    break;
                case 2:
                    viewMedicines(0);
                    addToCart();
                    break;
                case 3: displayCart(0);
                    break;
                case 4 :displayBill();
                    break;
                case 5: printMenu();
                    break;
                case 6: printf("\n ********************Thanks for visiting!******************/n Press enter to exit");
                    break;
            }
            if(choice==6)
            {
                break;
            }

            choice=printMenu();
    }


	/*viewMedicines();
	addToCart();
	displayCart();
	displayBill();*/

	getch();

}
