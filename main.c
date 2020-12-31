#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define MAX 50

void enc(char user[])
{
	int flag;
	char fname[20],fname1[20], ch;
    FILE *fps, *fpt;
    strcpy(fname,user);
    strcpy(fname1,user);
    fps = fopen(fname, "r");
    if(fps == NULL)
        exit(0);
        
    strcat(fname1,"_enc.txt");
    fpt = fopen(fname1, "w");
    if(fpt == NULL)
        exit(0);
    ch = fgetc(fps);
    while(ch != EOF)
    {
        ch = ch+100;
        fputc(ch, fpt);
        ch = fgetc(fps);
    }
    fclose(fps);
    fclose(fpt);
    fps = fopen(fname, "w");
    if(fps == NULL)
        exit(0);
    fpt = fopen(fname1, "r");
    if(fpt == NULL)
        exit(0);
    ch = fgetc(fpt);
    while(ch != EOF)
    {
        ch = fputc(ch, fps);
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);
    printf("\n  File %s Encrypted Successfully!", fname);
    getch();
//    flag=strcmp(fname,"signup.txt");
//    if(flag!=0)
//    exit(0);
}


void dec(char user[])
{
  char fname[20],fname1[20], ch;
    FILE *fps, *fpt;
    strcpy(fname,user);
    strcpy(fname1,user);
    fps = fopen(fname, "w");
    if(fps == NULL)
        return 0;
    strcat(fname1,"_enc.txt");
    fpt = fopen(fname1, "r");
    if(fpt == NULL)
        return 0;
    ch = fgetc(fpt);
    while(ch != EOF)
    {
        ch = ch-100;
        fputc(ch, fps);
        ch = fgetc(fpt);
    }
    fflush(fps);
    fflush(fpt);
    fclose(fps);
    fclose(fpt);
    printf("\n  File %s Decrypted Successfully!", fname);
    getch();
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void header()
{
printf("  =================== WELCOME TO PASSAFE ===================\n");
printf("  =================== a password manager ===================\n");
}

void signup(char name1[],char pass[])
{
	FILE *fp;
	int i;
	
	printf("\n  FIRST MONTH FREE. YOU WILL BE CHARGED RS.200 / MONTH FROM NEXT THE MONTH - PRESS ENTER \n  you can cancel the subscription anytime;\n");
	getch();
	fp=fopen("signup.txt","a");
	if (fp == NULL)
	printf("  Error");
	else
	{
	fprintf(fp,"\n%s",name1);
	fprintf(fp," %s",pass);
	printf("\n  SIGN UP SUCCESSFULL\n");
	fflush(fp);
	printf("  PRESS ENTER TO CONTINUE");
	}
	
	fclose(fp);
	
}

int login(char name[],char pass[])
{
	FILE *fp;
	fp=fopen("signup.txt","r");
	
	int i;
	char singleline1[150],singleline2[150];
	int flag1,flag2,correct=-1;
	
	if (fp == NULL)
	{
	printf("\a\n  Please signup first\n  ");
	correct=1;
	}
	else if(strcmp("admin",name)==0 && strcmp("admin",pass)==0)
	correct=10;
	else
	{
	while(!feof(fp))
	{
	fscanf(fp, "%s %s", singleline1, singleline2);
	flag1=strcmp(name,singleline1);
	flag2=strcmp(pass,singleline2);
	if(flag1==0 && flag2==0)
	{
	correct=0;
	break;
    }
	}
	}
	
	
   fflush(fp);
   fclose(fp);

	
	return correct;
}

void NewEntry(char user[])
{
	FILE *fp;
	struct userdata
	{
	char pass[10],username[20],cat[15],name1[20];
	}userx;
	int i;
	fp=fopen(user,"a");
	printf("  Enter Name: ");
	scanf("%s",userx.name1);
	printf("  Enter Username: ");
	scanf("%s",userx.username);
	printf("  Enter password: ");
	scanf("%s",userx.pass);
	printf("  Enter it's category: ");
	scanf("%s",userx.cat);
	fprintf(fp,"\n%s",userx.name1);
	fprintf(fp,"\n%s",userx.username);
	fprintf(fp," %s",userx.pass);
	fprintf(fp," %s",userx.cat);
	fflush(fp);
	printf(" --- Entry sucessfull ---");
	fclose(fp);
}

void DisplayPass(char user[])
{
	FILE *fp;
	fp=fopen(user,"r");
	if (fp == NULL || feof(fp))
	printf(" \a Empty\n");
	else
	{
	int i;
	char singleline1[150],singleline2[150],singleline3[150],singleline4[150];
	header();
	printf("  Names      ||   Usernames     ||   Passwords    ||  Categories  \n\n");
	while(!feof(fp))
	{
	fscanf(fp, "%s %s %s %s", singleline1, singleline2,singleline3, singleline4);
	printf("  NAME; %s - USERNAME; %s - PASSWORD; %s - CATEGORY; %s\n",singleline1,singleline2,singleline3,singleline4);
	printf("\n");
	}
	
	}
	
	fclose(fp);
}

int DispUsers()
{
	int ctr;
	FILE *fp;
	fp=fopen("signup.txt","r");
	if (fp == NULL || feof(fp))
	printf(" \a Empty\n");
	else
	{
	int i;
	char singleline1[150],singleline2[150];
	while(!feof(fp))
	{
	fscanf(fp, "%s %s", singleline1, singleline2);
	printf("  USERNAME; %s\n",singleline1);
	ctr++;
	printf("\n");
	}
	
	}
	
	fclose(fp);
	return ctr;
}

void SearchPass(char user[])
{
	FILE *fp;
	fp=fopen(user,"r");
	int i,count=0;
	char singleline1[150],singleline2[150],singleline3[150],singleline4[150],search[50];
	int flag1,flag2,flag3,flag4;
	if (fp == NULL)
	printf("\a  Empty\n");
	else
	{
		header();
	printf("  Search: ");
	scanf("%s",search);
	printf("\n");
	while(!feof(fp))
	{
	fscanf(fp, "%s %s %s %s", singleline1, singleline2, singleline3, singleline4);
	flag1=strcmp(search,singleline1);
	flag2=strcmp(search,singleline2);
	flag3=strcmp(search,singleline3);
	flag4=strcmp(search,singleline4);
	if(flag1==0 || flag2==0 || flag3==0 || flag4==0)
	{
	printf("  NAME; %s - USERNAME; %s - PASSWORD; %s - CATEGORY; %s\n",singleline1,singleline2,singleline3,singleline4);
	printf("\n");
	count++;
    }
	}
	if(count==0)
	printf("\a\n  === Nothing Found ===\n");
		
	}
	
	fclose(fp);
}

void randpass(char user[])
{
	 srand((unsigned int)(time(NULL)));
	 
	header();
	printf("\n\n");
	
    int i;
    char pass[12];
    char randpswd[12];
    
    FILE *fp;
    
	struct userdata
	{
	char username1[20],cat[15],name1[20];
	}userx;
	
	fp=fopen(user,"a");
	printf("  Enter name: ");
	scanf("%s",userx.name1);
	printf("  Enter Username: ");
	scanf("%s",userx.username1);
	printf("  Enter it's category: ");
	scanf("%s",userx.cat);
	fprintf(fp,"\n%s",userx.name1);
	fprintf(fp," %s ",userx.username1);
	
    printf("  Press ENTER to get a twelve-character password\n");
    getch();
    printf("  ");
    for (i = 0; i < 4; i++) 
	{
        pass[i] = rand() % 9;
        char capLetter = 'A' + (rand() % 26);
        pass[i + 2] = capLetter;
        char letter = 'a' + (rand() % 26);
        pass[i + 3] = letter;
        printf("%d%c%c", pass[i], pass[i + 2], pass[i + 3]);
        fprintf(fp,"%d%c%c", pass[i], pass[i + 2], pass[i + 3]);
    }
    
    fprintf(fp," %s",userx.cat);
    fflush(fp);
    printf("\n\n");
    fclose(fp);
}

void delrec(char user[])
{
	int yes=-1;
        char ch;
        char singleline1[150],singleline2[150],singleline3[150],singleline4[150],lno[150];
        FILE *fptr1, *fptr2;
		char fname[MAX];
        char str[MAX], temp[] = "temp.txt";
        strcpy(fname,user);
        fptr1 = fopen(fname, "r");
        if (!fptr1) 
		{
                printf(" File not found or unable to open the input file!!\n");
        }
        fptr2 = fopen(temp, "w"); // open the temporary file in write mode 
        if (!fptr2) 
		{
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
        }
        DisplayPass(user);
        printf("  Input the name of record you want to remove : ");
        scanf("%s",lno);
        // copy all contents to the temporary file except the specific line
        while(!feof(fptr1))
			{
			fscanf(fptr1, "%s %s %s %s", singleline1, singleline2,singleline3, singleline4);
			yes=strcmp(lno,singleline1);
			if(yes!=0)
			{
				fprintf(fptr2,"\n%s %s %s %s", singleline1, singleline2,singleline3, singleline4);
			}
			
			}
			
        fflush(fptr1);
        fflush(fptr2);
        fclose(fptr1);
        fclose(fptr2);
//        remove(user);  		// remove the original file 
//        rename(temp, user); 	// rename the temporary file to original name
       // printf("  Record deleted successfully\n");
}

void delrecsignup(char user[])
{
	int yes=-1;
        char ch;
        char singleline1[150],singleline2[150],d[20],lno[150];
        FILE *fptr1, *fptr2;
		char fname[MAX];
        char str[MAX], temp[] = "temp.txt";
        strcpy(fname,user);
        fptr1 = fopen(fname, "r");
        if (!fptr1) 
		{
                printf(" File not found or unable to open the input file!!\n");
        }
        fptr2 = fopen(temp, "w"); // open the temporary file in write mode 
        if (!fptr2) 
		{
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
        }
        DispUsers();
        printf("  Input the name of record you want to remove : ");
        scanf("%s",lno);
        // copy all contents to the temporary file except the specific line
        while(!feof(fptr1))
			{
			fscanf(fptr1, "%s %s", singleline1, singleline2);
			yes=strcmp(lno,singleline1);
			if(yes!=0)
			{
				fprintf(fptr2,"\n%s %s", singleline1, singleline2);
			}
			
			}
			strcpy(d,lno);
			strcat(d,"_enc.txt");
        fflush(fptr1);
        fflush(fptr2);
        fclose(fptr1);
        fclose(fptr2);
        remove(lno);
        remove(d);
        remove(user);  		// remove the original file 
        rename(temp, user); 	// rename the temporary file to original name
       // printf("  Record deleted successfully\n");
}


int main(int argc, char *argv[]) {
int a=-1,choice,i,k;
char pass[10],name1[20];

dec("signup.txt");
start:
system("cls");
header();
printf("\n\n");
printf("\n  Press 1 for Sign Up\n  Press 2 for Login\n  Press 0  to Exit\n\n");
printf("  ==========================================================");
scanf("%d",&choice);

if(choice == 1 || choice ==2)
{
	printf("  Enter Username: ");
	scanf("%s",name1);
	printf("  Enter your password: ");
	for(i=0;i<=12;i++)
	{
		if(i==12)
		pass[i]='\0';
		else
		{
		pass[i]=getch();
		if(pass[i] == '\r')
		{
			pass[i]='\0';
			goto next;
		}
		printf("*");
		//Beep(600,200);
		}
	}
	
}
next:
if(choice==0)
{
	goto end;
}

	switch(choice)
{
	case 1:
	{
	signup(name1,pass);
	getch();
	system("cls");
	goto here;
	break;
	}
	
	case 2:
	{
	a=login(name1,pass);
	if(a==0)
	{
	printf("\n\n  login successfull");
	Beep(350,200);
	printf("\n  Press ENTER to proceed");
	getch();
	choice=0;
	system("cls");
	}
	else if(a==-1)
	{
		while(a!=0)
		{
		 printf("\a\n\n  Username or Password incorrect\n  Retry!\n  Press K to go back menu\n\n");
		 printf("  Enter Username: ");
		 scanf("%s",name1);
		 k=strcmp(name1,"k");
		 if(k==0)
		 goto start;
		 printf("  Enter your password: ");
		 for(i=0;i<=12;i++)
		 {
		if(i==12)
		pass[i]='\0';
		else
		{
		pass[i]=getch();
		if(pass[i] == '\r')
		{
			pass[i]='\0';
			break;
		}
		printf("*");
		//Beep(600,200);
		}
		}
		 
		 a=login(name1,pass);
		}
	printf("\n  Press ENTER to proceed");
	Beep(350,200);
	getch();
	system("cls");
	}
	break;
	}
		
}


if(a==0)
{
	
	int flag=-1;
	header();
	dec(name1);
	here:
	printf("\n");
	do
	{
	printf("\n");
	printf("  ------------------- YOUR DATABASE -------------------\n\n");
	printf("  Press 1 to Enter new data\n  Press 2 to display all data\n  Press 3 for search\n  Press 4 for random password generator\n  Press 5 to delete a record\n  Press 0 to open menu    ");
	scanf("%d",&choice);
	printf("  --------------------------------------------------------\n\n");
	system("cls");
	
	if(choice==1)
	NewEntry(name1);
	else if(choice==2)
	DisplayPass(name1);
	else if(choice==3)
	SearchPass(name1);
	else if(choice==4)
	randpass(name1);
	else if(choice==5)
	{
	delrec(name1);
	int e,d;
	e=remove(name1);  		// remove the original file 
    d=rename("temp.txt", name1); 	// rename the temporary file to original name
    printf("  %d%d",e,d);
	}
	printf("\n\n  Do you want to go back to your database? \n  Press 1 to return or 0 to exit\n  Press -1 to logout ");
	scanf("%d",&flag);
	if(flag==-1)
	{
		enc(name1);
		goto start;
	}
	system("cls");
	}
	while(flag!=0);

}
else if(a==1)
{
	getch();
	goto start;
}
else if(a==10)
{
	int rev=0;
	admin:
	printf("\n\n  ------------- Welcome Admin --------------- \n");
	printf("  Press 1 to Display the revenue\n  Press 2 to Display Users that use the tool\n  Press 3 to remove users\n  Press 0 to exit\n  Press -1 to logout\n  ");
	scanf("%d",&choice);
	if(choice==1)
	{
		rev=DispUsers();
		printf("  Monthly revenue being generated by the tool is Rs.%d\n",rev*200);
		printf("  Press ENTER");
		getch();
		system("cls");
		goto admin;
	}
	else if(choice==2)
	{
		DispUsers();
		printf("  Press ENTER");
		getch();
		system("cls");
		goto admin;
	}
	else if(choice==3)
	{
	delrecsignup("signup.txt");
	printf("  Press ENTER");
	getch();
	system("cls");
	goto admin;	
	}
	else if(choice==0)
	goto end;
	else if(choice==-1)
	goto start;
	
}
end:
	system("cls");
	printf("\n --- THANK YOU FOR USING PASSAFE ---");
	enc("signup.txt");
	enc(name1);
	
	
	
	return 0;
}
