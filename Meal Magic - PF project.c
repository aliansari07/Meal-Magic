#include<stdio.h>		
#include<time.h> 			
#include<stdlib.h> 			
#include <ctype.h>			
#include <windows.h>
#include<string.h>			
 
typedef struct{ 			

	char id[15]; 
	char firstname[25];
	char lastname[15];
	char number[15];
	char email[35];
	char address[70];
	char gender[8];
	char reservation[100];

}customer;

	int i,x,again,total,quantity,loginv=0,b=0,l=0,d=0,sumtotal=0;	 
	char choice,id1;	
	int* lptr=&loginv;
	
void titlepage(void){		 				

	system("color 6"); 		
	printf("\t\t\t\t ********************************************************\n");
	printf("\t\t\t\t |\t\tWelcome to The Meal-Magic\t\t|\n");
	printf("\t\t\t\t |\tThe Ultimate Restaurant Management System\t|\n");
	printf("\t\t\t\t *********************************************************\n");
	printf("Programming Fundamentals-Project made by:\n\t Ayesha Hassan (22K-4326)\n\t Emanay Arshad (22K-4602)\n\t Muhammad Ali Ansari (22K-4135)\n\t Section: BSCS-1F\n\n"); 
	
	 
    time_t time1; 				
    char* date_time; 			 
    time(&time1); 				 
    date_time = ctime(&time1); 
    printf("Today's Date and Current Time: %s", date_time);
    
	printf("\nIn this program, Pressing the following keys will perform respective actions.\n");
	printf(" 0. To exit the program\n");
	printf(" 1. Register as a new costumer\n");
	printf(" 2. Login as a registered costumer\n");
	printf(" 3. Order Meal \n");
	printf(" 4. View Customer Details \n");}

int search(customer cust);						

void registration(customer cust){				
	system("CLS");								
	printf("\t\t\tWelcome to the Registration process of The Magic Meal Restaurant.\n ");
  	printf("\t\t\t***************************************************************\n");  
	
	int no;
	FILE* fptr;									
	FILE* No_cust;
	No_cust=fopen("customercount.txt","r");			 
	fscanf(No_cust,"%d",&no);
	fclose(No_cust);
	printf("\nEnter the following details for Customer number %d\n",no);
	fptr=fopen("textfile.txt","a");	
	if(fptr==NULL)
   {
      printf("Error in opening file!");		
      exit(1);							
   } 
	again999:
		printf("Enter ID (Preference: 13 Characters): ");
		scanf("%s",cust.id);
		if(strlen(cust.id)==13){
			if(search(cust)!=-1){
			printf("This ID has 13 digits but already exists in the database\nTry another one\n");
			goto again999;}
		else{
			goto next101;}}
			next101:	
			printf("This ID has %d characters and is successfully stored into the database",strlen(cust.id));

	printf("\nFirst name: ");
	fflush(stdin);
	scanf("%[^\n]%*c",&cust.firstname);
	printf("\nLast name: ");
	fflush(stdin);
	scanf("%[^\n]%*c",&cust.lastname);
	again1:
	printf("\nGender (type in small case): ");
	fflush(stdin);
	scanf("%[^\n]%*c",&cust.gender);
	if(strchr(cust.gender,109)==NULL || strchr(cust.gender,97)==NULL || strchr(cust.gender,108)==NULL || strchr(cust.gender,101)==NULL)
	{ 
		printf("\nGender invalid\n");
		goto again1;
	}
	printf("\nPermanent Address: ");
	fflush(stdin);
	scanf("%[^\n]%*c",&cust.address);
	again3:
	printf("\nActive email: ");
	fflush(stdin);
	scanf("%[^\n]%*c",&cust.email);
	if(strchr(cust.email,'@')==NULL || strchr(cust.email,'.')==NULL )
	{
		printf("\nEmail invalid\n");
		goto again3;
	}
	while(1)
    {
	printf("\nPhone number:");
	scanf("%[^\n]%*c",&cust.number);
	if (strlen(cust.number)==11)
		break;
	else
		printf("Incorrect Phone Number\nIt should be of 11 digits\n");
	}
	
	int tablesleft;
	printf("\nThe Reservation for dining on our tables has the maximum range of 99");
	while(1)
    {
	printf("\nEnter the number of tables to be reserved (for example 02 for two tables): ");
	scanf("%s",&cust.reservation);
	if (strlen(cust.reservation)==2){
		if(strchr(cust.reservation,45)==NULL)
		printf("\nRegistration successful...");
		int tables= atoi(cust.reservation);
		tablesleft=99-tables;
		printf("\nAfter %d registrations, available tables are = %d",no,tablesleft);
		break;}
	else
		printf("Invalid Reservation\n");}

	fputs(cust.id,fptr);
	fputs(" ",fptr);
	fputs(cust.firstname,fptr);
	fputs(" ",fptr);
	fputs(cust.lastname,fptr);
	fputs(" ",fptr);
	fputs(cust.gender,fptr);
	fputs(" ",fptr);
	fputs(cust.address,fptr);
	fputs(" ",fptr);
	fputs(cust.email,fptr);
	fputs(" ",fptr);
	fputs(cust.number,fptr);
	fputs(" ",fptr);
	fputs(cust.reservation,fptr);
	fputs("\n",fptr);
	fclose(fptr);
	no++;
	No_cust=fopen("customercount.txt","w");
	fprintf(No_cust, "%d", no);
	fclose(No_cust);
}

			
	customer login_customer(customer st){ 		
		system("cls");	
		system("color 6");
  		printf("\t\t\t\tWelcome to the login Portal of The Magic Meal Restaurant.\n ");
  		printf("\t\t\t\t*********************************************************\n");
  		if(*lptr!=0){
  			printf("You are already logged in!");}
		else{
		  	char id[10];
		printf("\n\nKindly enter your ID: ");
		scanf("%s",st.id);
		int index=search(st);   
		if (index != -1){
			*lptr=1;
			int i;
			FILE* fptr;
			fptr=fopen("textfile.txt","r");
			for(i=1;i<=index;i++){
				fscanf(fptr,"%s %s %s %s %s %s %s\n", st.id,st.firstname,st.lastname,st.gender ,st.address,st.email,st.number);
			}
			fclose(fptr);
			char title[5];
			if(strcmp(st.gender,"female")==0){
				strcpy(title,"Miss");
			}
			else{
				strcpy(title,"Mr.");
			}
     	 	printf("\nLogin Successfull\nWelcome %s %s to our Restaurant.",title,(st.firstname));}
		else{
			int attempts;
			printf("\nID is incorrect or ID is not registered in the database.\n");
				for(attempts=3;attempts>0;attempts--){
					printf("\nEnter ID again: ");
					fflush(stdin);
					scanf("%s",&st.id);
					int index=search(st);    
						if (index != -1){
							*lptr=1;
							int i;
							FILE* fptr;
							fptr=fopen("textfile.txt","r");
							for(i=1;i<=index;i++){
								fscanf(fptr,"%s %s %s %s %s %s %s", st.id,st.firstname,st.lastname,st.gender ,st.address,st.email,st.number);
							}
							fclose(fptr);
							char title[5];
							if(strcmp(st.gender,"female")==0){
								strcpy(title,"Miss");
							}
							else{
								strcpy(title,"Mr.");
							}
                         	printf("\nLogin Successfull\nWelcome %s %s to our Restaurant.",title,(st.firstname));
							break;}
                        else{
                        	printf("\nID is incorrect or ID is not registered in the database.\n");
                        	printf(" ");}}
						}
						return (st);
						}}

int search(customer cust){
	FILE* No_cust;
	No_cust=fopen("customercount.txt","r");
	int records,found=-1,i;
	fscanf(No_cust,"%d",&records);
	FILE* fptr;
	fptr=fopen("textfile.txt","r");
	if(fptr==NULL)
   {
      printf(" Error in opening file!");
      exit(1);
   }
	char id[10],firstname[10],lastname[10],number[11],email[35],address[70],gender[10];
	int read=records;
	for(i=1; i<=read ;i++)
	{
		fscanf(fptr,"%s %s %s %s %s %s %s\n", id,firstname,lastname,number,email,address,gender);
		if(strcmp(cust.id,id) == 0)
		{
			found=i;
			break;
		}
	}
	return found;
}

// Ordering phase starts here

typedef struct{
	char name[35];
	int price;
	int quantity;
}order;

	order *bp;
	order *lp;
	order *dp;
	void bfast();		
	void lunch();
	void dinner(); 
	void eexit();
	void ending();
	void m_m();
	void m_m(void){ 								
  	printf("\t\t\t\tWelcome to the Ordering Phase of The Magic Meal Restaurant.\n ");
  	printf("\t\t\t\t*****************************************************************\n");
  	printf("\n\nKindly enter the type of Meal you want:\n");
  	printf("\t\t\t[A] Breakfast\n");
  	printf("\t\t\t[B] Lunch\n");
  	printf("\t\t\t[C] Dinner\n");
  	printf("\t\t\t[D] Exit\n\n");
  	printf("Your Choice: ");
  	scanf("%c", &choice);						
  	system("cls");{
		if (toupper(choice) == 'A' ) 			 
		  	bfast();
		else if (toupper(choice) == 'B')
			lunch();
		else if (toupper(choice) == 'C')
			dinner();
		else if (toupper(choice) == 'D'){
			printf("\nThank you for exiting from Meal-Magic-Ordering Phase.\nWe Expect to see you again.");
			system("CLS");}	
		else if (toupper(choice) != 'A' , 'B' , 'C' , 'D'){ 
			m_m();}}}
						
void bfast(void){ 							 
  int choice = 0,quantity=0,again=0;	
  fflush(stdin);
  	printf("\t\t\t\tWelcome to Ordering Phase of The Magic Meal Restaurant.\n ");
  	printf("\t\t\t\t******************************************************\n\n");
  	printf("\t\t\t\t\t*Breakfast Menu*\n");
  	printf("\nKindly enter the Meal Number of Breakfast:\n");
  	printf("\t\t\t[1] Egg & Cheese McMuffin Meal - Rs 250\n");
  	printf("\t\t\t[2] Hashbrowns Wrap with Smoothie - Rs 400\n");
  	printf("\t\t\t[3] Big Breakfast Meal - Rs 1000\n\t\t    Meal 3 includes: Three fluffy scrambled eggs, savoury chicken sausage and a crispy golden hash brown\n");
  	printf("\n\t\t\t *Special 30 %% discount on Meal 3*\n\t\t\t *Discount valid only for today*\n");
	printf("Your Choice: ");
	b++;
	if(b==1){
		bp=(order*)malloc(b*sizeof(order));
	}
	else{
		(order*)realloc(bp,b*sizeof(order));
	}
  	scanf("%d", &choice);{
  		if (choice == 1) {
			printf("Enter quantity: ");
	  		scanf("%d", &quantity);
	  		total = 250 * quantity ;
	   		printf("Your total amount is Rs %d\n ", total); 
	   		strcpy((bp+(b-1))->name,"Egg & Cheese McMuffin Meal");
	   		(bp+(b-1))->price=total;
	   		(bp+(b-1))->quantity=quantity;
	   		sumtotal+=total;
	   		buy:
	   		printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); 
			scanf("%d", &again);
			system("cls");
		if (again == 1 )
			bfast();
		else if (again == 2 )
              	eexit();
		else if (again != 1 , 2){
			printf("\n\nSorry Invalid Decision Entered\n\n\n\n");
			goto buy;
			}}
		else if ( choice == 2){
		  	printf("Enter quantity: ");
		  	scanf("%d", &quantity);
		  	total = 400 * quantity ;
		  	printf("Your total amount is Rs %d\n\n ", total);
		  	strcpy((bp+(b-1))->name,"Hashbrowns Wrap with Smoothie");
	   		(bp+(b-1))->price=total;
	   		(bp+(b-1))->quantity=quantity;
	   		sumtotal+=total;
		    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); 
			scanf("%d", &again);
			system("cls");
		if (again == 1 )
			bfast();
		else if (again == 2 )	
			eexit();
		else if (again != 1 , 2){
			printf("\n\n\t\tSorry Invalid Decision Entered\n\n\n\n");
			goto buy;
			}}
		else if ( choice == 3 ){
			printf("Enter quantity: ");
			scanf("%d", &quantity);
			total = 700 * quantity ;
			printf("Your total amount is Rs %d\n\n ", total); 
			strcpy((bp+(b-1))->name,"Big Breakfast Meal");
	   		(bp+(b-1))->price=total;
	   		(bp+(b-1))->quantity=quantity;
	   		sumtotal+=total;
		    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); 
			scanf("%d", &again);
			system("cls");
		if (again == 1 ){
			bfast();}
		else if (again == 2 ){	
			eexit();
			}
		else if (again != 1 , 2){
			printf("\n\n\t\tSorry Invalid Decision Entered\n\n\n\n");
			goto buy;
			}}
		else if (choice != 1 , 2 , 3 ){
			system("CLS");
			bfast();}}}

void lunch(){ 								
    int choice = 0,quantity=0,again=0;	 					
	printf("\t\t\t\tWelcome to Ordering Phase of The Magic Meal Restaurant.\n ");
  	printf("\t\t\t\t******************************************************\n\n");
  	printf("\t\t\t\t*Lunch Menu*\n");
  	printf("\nKindly enter the Meal Number of Lunch:\n");
  	printf("\t\t\t[1] Fried Rice with Fish - Rs 400\n");
  	printf("\t\t\t[2] Crispy Chicken Bucket - Rs 1600\n");
  	printf("\t\t\t[3] Happy Meal - Rs 1000\n");
  	printf("\n\t\t\t *Special 50 %% discount on Meal 2*\n\t\t\t *Discount valid only for today*\n");
	printf("Your Choice: ");
	l++;
	if(l==1){
		lp=(order*)malloc(l*sizeof(order));
	}
	else{
		(order*)realloc(lp,l*sizeof(order));
	}
  	scanf("%d", &choice);{
  		if (choice == 1) {
	  		printf("Enter quantity: ");
	  		scanf("%d", &quantity);
	  		total = 400 * quantity ;
	  		printf("Your total amount is Rs %d \n ", total);
			strcpy((lp+(l-1))->name,"Fried Rice with Fish");
	   		(lp+(l-1))->price=total;
	   		(lp+(l-1))->quantity=quantity;
			sumtotal+=total;{
	  	    buyy:
			printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
			scanf("%d", &again);
			system("cls");
		if (again == 1 )
			lunch();
		else if (again == 2 )
			eexit();
		else if (again != 1 , 2){	
			printf("\n\n\t\tSorry Invalid Decision Entered\n\n\n\n");
			goto buyy;
			}}}
		else if ( choice == 2){
		  	printf("Enter quantity: ");
		  	scanf("%d", &quantity);
		  	total = 800 * quantity ;
		  	printf("Your total amount is Rs %d\n ", total);
			strcpy((lp+(l-1))->name,"Crispy Chicken Bucket");
	   		(lp+(l-1))->price=total;
	   		(lp+(l-1))->quantity=quantity;
			sumtotal+=total;{
			printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
			scanf("%d", &again);
			system("cls");
		if (again == 1 )
			lunch();
		else if (again == 2 )
				eexit();
		else if (again != 1 , 2){	
			 printf("\n\n\t\tSorry Invalid Decision Entered\n\n\n\n");
			 goto buyy;}}}
		else if ( choice == 3 ){
			printf("Enter quantity: ");
			scanf("%d", &quantity);
			total = 1000 * quantity ;
			printf("Your total amount is Rs %d \n\n ", total);
			strcpy((lp+(l-1))->name,"Happy Meal");
	   		(lp+(l-1))->price=total;
	   		(lp+(l-1))->quantity=quantity;
			sumtotal+=total;{
			printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
			scanf("%d", &again);
			system("cls");
		if (again == 1 )
			lunch();
		else if (again == 2 )
			eexit();
		else if (again != 1 , 2){	
			printf("\n\n\t\tSorry Invalid Decision Entered\n\n\n\n");
			goto buyy;
			}}}
		else if (choice != 1 , 2 , 3){
			fflush(stdin);
			system("cls");
			printf("\n\n\t\t Invalid Choice Entered\n\n");
			lunch();}}}
			
void dinner() {								
    int choice = 0,quantity=0,again=0;	 						
    printf("\t\t\t\tWelcome to Ordering Phase of The Magic Meal Restaurant.\n ");
  	printf("\t\t\t\t******************************************************\n\n");
  	printf("\t\t\t\t*Dinner Menu*\n");
  	printf("\nKindly enter the Meal type of Dinner:\n");
  	printf("\t\t\t[1] Beef Steak - Rs 1000\n");
  	printf("\t\t\t[2] Krunch Chicken Combo - Rs 550\n");
  	printf("\t\t\t[3] Rice N Spice - Rs 300\n");
  	printf("\n\t\t\t *Special 35 %% discount on Meal 1*\n\t\t\t *Discount valid only for today*\n");
  	printf("Your Choice: ");
d++;
  	if(d==1){
  		dp=(order*)malloc(d*sizeof(order));
	  }
	else{
		(order*)realloc(dp,d*sizeof(order));
	}
  	scanf("%d", &choice);{
  		if (choice == 1) {
	  		printf("Enter quantity: ");
	  		scanf("%d", &quantity);
	  		total = 650 * quantity ;
	  		printf("Your total amount is Rs %d\n ", total);
			strcpy((dp+(d-1))->name,"Beef Steak");
	   		(dp+(d-1))->price=total;
	   		(dp+(d-1))->quantity=quantity;
			sumtotal+=total;{
            buyyy:
			printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
			scanf("%d", &again);
			system("cls");
		if (again == 1 )
			dinner();
		else if (again == 2 )
			eexit();
		else if (again != 1 , 2){	
			printf("\n\n\t\tSorry Invalid Decision Entered\n\n\n\n");
			goto buyyy;}}}
			else if ( choice == 2){
		  	printf("Enter quantity: ");
		  	scanf("%d", &quantity);
		  	total = 550 * quantity ;
		  	printf("Your total amount is Rs %d\\n ", total);
			strcpy((dp+(d-1))->name,"Crunch Chicken Combo");
	   		(dp+(d-1))->price=total;
	   		(dp+(d-1))->quantity=quantity;
			sumtotal+=total;{
			printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
			scanf("%d", &again);
			system("cls");
		if (again == 1 )
			dinner();
		else if (again == 2 )
			eexit();
		else if (again != 1 , 2){	
			printf("\n\n\t\tSorry Invalid Decision Entered\n\n\n\n");
			goto buyyy;}}}
		else if ( choice == 3 ){
			printf("Enter quantity: ");
			scanf("%d", &quantity);
			total = 300 * quantity ;
			printf("Your total amount is Rs %d\n ", total);
			strcpy((dp+(d-1))->name,"Rice N Spice");
	   		(dp+(d-1))->price=total;
	   		(dp+(d-1))->quantity=quantity;
			sumtotal+=total;{
			printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
			scanf("%d", &again);
			system("cls");
		if (again == 1 )
			dinner();
		else if (again == 2 )
			eexit();
		else if (again != 1 , 2){	
			printf("\n\n\t\tSorry Invalid Decision Entered\n\n\n\n");
			goto buyyy;}
		else if (choice != 1 , 2 , 3){
			fflush(stdin);
			system("cls");
			printf("\n\n\t\tInvalid Choice Entered\n\n");
			dinner(); }}}
		}
}

void rating(void){
	system("CLS");
	printf("\t\t\t\tWelcome to Rating and Suggestion phase of The Magic Meal Restaurant\n ");
  	printf("\t\t\t\t*******************************************************************\n\n");
 	FILE *rates;
 	rates=fopen("ratings.txt","r");
	int rate=0,freq[10]={1,2,3,4,5,6,7,8,9,10},freqcount[10];
	char choice=0,suggestion[100];
	fscanf(rates,"%d %d %d %d %d %d %d %d %d %d\n",&freqcount[0],&freqcount[1],&freqcount[2],&freqcount[3],&freqcount[4],&freqcount[5],&freqcount[6],&freqcount[7],&freqcount[8],&freqcount[9]);
	fclose(rates);
	printf("\nKindly rate our program-service from 1 to 10: ");
	scanf("%d",&rate);
	while(rate<0 || rate>10){
		printf("\nInvalid rating");
		printf("\nKindly rate our program-service from 1 to 10: ");
		scanf("%d",&rate);
	}
	if(rate==freq[0]) freqcount[0]++;
	else if(rate==freq[1]) freqcount[1]++;
	else if(rate==freq[2]) freqcount[2]++;
	else if(rate==freq[3]) freqcount[3]++;
	else if(rate==freq[4]) freqcount[4]++;
	else if(rate==freq[5]) freqcount[5]++;
	else if(rate==freq[6]) freqcount[6]++;
	else if(rate==freq[7]) freqcount[7]++;
	else if(rate==freq[8]) freqcount[8]++;
	else if(rate==freq[9]) freqcount[9]++;
	rates=fopen("ratings.txt","w");
	fprintf(rates,"%d %d %d %d %d %d %d %d %d %d\n",freqcount[0],freqcount[1],freqcount[2],freqcount[3],freqcount[4],freqcount[5],freqcount[6],freqcount[7],freqcount[8],freqcount[9]);
	fclose(rates);
	suggest:
	printf("\nAny suggestions(Y/N): ");
	fflush(stdin);
	scanf("%c",&choice);
	if(choice=='Y'|| choice=='y'){
		printf("\nKindly enter your suggestion here: ");
		FILE* suggest;
		suggest=fopen("Suggestions.txt","a");
		fflush(stdin);
		gets(suggestion);
		fputs(suggestion,suggest);
		fputs("\n",suggest);
		fclose(suggest);
		printf("\nYour valuable suggestion has been successfully recorded");
		Sleep(2000);
		ending();
	}
	else if(choice=='N'|| choice=='n'){
	ending();
	} 
	else {
	printf("\nInvalid Choice\n");
	goto suggest; }
	}
	
 void hyperlink(void)
{
    char* internet = "START https://www.hbl.com/personal/digital-banking/hbl-internetbanking?gclid=CjwKCAiAjs2bBhACEiwALTBWZWO6ETOzYIHMkJcGeYa5FyAIxtkzLpvoWwRCmvRiUiuvtEaTmMlrCxoCvQ8QAvD_BwE"; //CharPointer or Char
    system (internet);
}
void billing_method(void){ 
	free(bp);
	free(lp);
	free(dp);
	int method;
	printf("\nSelect the billing method\n1.Online Payment\n2.Cash On Delivery\nYour Choice: ");
  	scanf("%d",&method);
  	switch(method){
  		case 1 :{
  			system("CLS");
  			printf("Redirecting you to the Online payment link...");
  			Sleep(2000);
  			hyperlink();
			break;
		  }
		  case 2:{
		   printf("\nThank you for choosing Cash on Delivery Method of payment\nOur Rider will be at your doorstep shortly...");
		  break;
		  }
		  default:{
		  	printf("\nInvalid Option Entered.\n");
		  	billing_method();
			}
	  }
}

void eexit()
{
    char billing_choice;
	system("CLS"); 
  printf("\t\t\t\tThank You for using ordering phase of The Meal Magic Restaurant\n ");
  printf("\t\t\t\t****************************************************************\n\n");
  printf("----------------------Order Summary----------------------\nName\t\t\t\tQuantity\tTotal Price\n");
  if(b>0){
  	for(int i=0;i<b;i++){
  	printf("%25s\t%d\t\t%d\n",(bp+i)->name,(bp+i)->quantity,(bp+i)->price);
  }
  }

  if(l>0){
  	for(int i=0;i<l;i++){
  	printf("%25s\t%d\t\t%d\n",(lp+i)->name,(lp+i)->quantity,(lp+i)->price);
  }
  }

  if(d>0){
  	for(int i=0;i<d;i++){
  	printf("%25s\t%d\t\t%d\n",(dp+i)->name,(dp+i)->quantity,(dp+i)->price);
  }
  }

  printf("----------------------------------------------------------\n%s\t\t\t\t\t\t%d\n----------------------------------------------------------\n\n","Total",sumtotal);
  option:
  printf("\nDo You want to proceed for Billing (Y/N): ");
  fflush(stdin);
  scanf("%c",&billing_choice);
  if(billing_choice=='y'|| billing_choice=='Y'){
  	billing_method();
  	printf("\nWhile the meal is on its way, do you wish to suggest something for our restaurant?\nChoose from (Y/N): ");
  	fflush(stdin);
	scanf("%c",&choice);
  	if(choice=='Y'||choice=='y'){
	  system("CLS");
	  printf("Proceeding to Suggestion Phase...");
	  Sleep(2000);
	  rating();}
	else if(choice=='N'||choice=='n'){
	  system("CLS");
	  ending();}}
 else  if(billing_choice=='n'|| billing_choice=='N'){
  		m_m(); }
  else {
  printf("\nInvalid Option Selected ");
  goto option;
  }
}

		
void viewall(customer st){
	system("cls");	
	printf("\t\t\t ********************************************************\n");
	printf("\t\t\t |\t\tWelcome to The Meal-Magic\t\t|\n");
	printf("\t\t\t |\tThe Ultimate Restaurant Management System\t|\n");
	printf("\t\t\t *********************************************************\n");
	int i=0;
	char title[5];
	if(strcmp(st.gender,"female")==0){
		strcpy(title,"Miss");
	}
	else{
		strcpy(title,"Mr.");
	}
		    	printf("\n\t\tDetails Of %s %s\n",title,st.firstname);
				printf("\n\t\t**********************");
   				fflush(stdin);
   				printf("\n\nID: %s",st.id);
   				printf("\nFirst Name: %s",st.firstname);
   				printf("\nLast Name: %s",st.lastname);
   				printf("\nContact Number: %s",st.number);
   				printf("\nEmail ID: %s",st.email);
	   			printf("\nAddress: %s",st.address);
   				printf("\nGender: %s",st.gender);
				printf("\n");}   

void hy_socialmedia(void){    
	char ch_social;
	printf("\nFor further updates visit our social media page ");
	againsocialmedia:
	printf("\nDo you want to visit our social media page(Y/N) ");
	fflush(stdin);
    scanf("%c",&ch_social);
	if(ch_social=='Y' || ch_social=='y'){
		char*internet;
	internet="START https://www.facebook.com/profile.php?id=100087781915508";
	system (internet);
	}
	if(ch_social=='N' || ch_social=='n'){
		m_m();
	}
	if(ch_social!='y'&& ch_social!='Y' &&ch_social!='n'&&ch_social!='N'){
		printf("\nEnter Valid Option: ");
		goto againsocialmedia;
	} 
}

void ending(){
			system("CLS");
	 	 	printf("\n\t\t\tThank You for using the ordering phase of Meal-Magic \n ");
  			printf("\t\t\t******************************************************\n");
			printf("\t\t\t******************************************************\n");
  			hy_socialmedia();
			printf(" ");
			Sleep(2000);
			system("CLS");}


int main(){
	customer st;
	titlepage();
	int yourchoice;
	char confirm;
	do{
		printf("Enter your choice(0-4): ");
		scanf("%d",&yourchoice);
		if (yourchoice==0) {
 	 		printf("\n\t\t\tThank You for using this program\n ");
  			printf("\t\t\t*********************************\n");
  			printf("\t\t\tTeam Meal-Magic expects to see you again in the near future.\n");
			printf("\t\t\t*************************************************************\n");
			break;}
customer cust;
switch(yourchoice){
	case 1:registration(st);break;
	case 2: cust=login_customer(st);break;
	case 3:m_m();break;
	case 4:viewall(cust);break;
	default:
	printf("\nInvalid Input\n");    
}
again99:
printf("\nPress y or Y to continue: ");
fflush(stdin);
scanf("%c",&confirm);
if(confirm=='y'||confirm=='Y'){
system("CLS");
	printf("\nIn this program, Pressing the following keys will perform respective actions.\n");
	printf(" 0. To exit the program\n");
	printf(" 1. Register as a new costumer\n");
	printf(" 2. Login as a registered costumer\n");
	printf(" 3. Order Meal \n");
	printf(" 4. View Customer Details \n");}
else{
	goto again99;}}
while(confirm=='y'||confirm=='Y');
return EXIT_SUCCESS;
}