#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


struct dry
{ char notes[1000];
};
struct add
{ 
char name[50], address[100];
long long int phno;
}ad;


char dt[50],name1[50];
time_t t; 
char date[10],cmp1date[11],cmp2date[11],cmpchar;
int first,last;
FILE *p,*a;

struct dry d;

void password(long int*);
void diary();
void address();
void display();
void appending();
void passChange();

int main()
{
	
	int option,demo=0;
	long int pass,*p1,userPass;
	
	printf("WELCOME TO DIARY MANAGEMENT SYSTEM");
	
	c:	
	p1=&pass;
	
	password(p1);
    
	printf("\n\nENTER THE PIN\n");
	scanf("%d",&userPass);
	
	if(userPass == (*p1))
    {  
	   
	     printf("\n\t\tACCESS GRANTED\n");
	     
	     b:
	     	
	     	
	     	printf("\n\nSELECT AN OPTION : \n\n");
	     	
         printf("1. FOR ENTERING NOTES INTO DIARY\t\t2. FOR ENTERING PHONE NUMBERS AND ADRESSES\n");
         printf("3. CHANGE PIN\t\t\t\t\t4. READ THE DIARY \n5. DISPLAY IMPORTANT PHONE NUMBERS AND ADRESSES\t");
         printf("6. EXIT\n\n");
		 scanf("%d",&option);        

	    
	       time(&t);
         strcpy(dt,ctime(&t));
         printf("%s",dt);
        
         
           date[0]=dt[8];
	       date[1]=dt[9];
           date[2]='/';
         
	    if(dt[4]=='J' && dt[5]=='a')
	    {  date[3]='0';
	       date[4]='1';
		}
	    else if(dt[4]=='F')
	     {  date[3]='0';
	       date[4]='2';
		}
	    else if(dt[4]=='M' && dt[6]=='r')
	     {  date[3]='0';
	       date[4]='3';
		}
	    else if(dt[4]=='A' && dt[5]=='p')
	     {  date[3]='0';
	       date[4]='4';
		}
	    else if(dt[4]=='M' && dt[6]=='y')
	     { date[3]='0';
	       date[4]='5';
		}
	    else if(dt[4]=='J' && dt[6]=='n')
	     {  date[3]='0';
	       date[4]='6';
		}
	    else if(dt[4]=='J' && dt[6]=='l')
	     {  date[3]='0';
	       date[4]='7';
		}
	    else if(dt[4]=='A' && dt[5]=='u')
	     {  date[3]='0';
	       date[4]='8';
		}
	    else if(dt[4]=='S')
	     {  date[3]='0';
	      date[4]='9';
		}
	    else if(dt[4]=='O')
	     {  date[3]='1';
	       date[4]='0';
		}
	    else if(dt[4]=='N')
	     {  date[3]='1';
	       date[4]='1';
		}
	    else if(dt[4]=='D')
	     { date[3]='1';
	       date[4]='2';
		}
		  date[5]='/';
		 date[6]=dt[20];
		  date[7]=dt[21];
		 date[8]=dt[22];
		  date[9]=dt[23];
		  
//	printf("%s",date);
		
		
	    
	   switch(option)
	   {
	   	case 1:diary();
	   		goto b;
	     break;
	     
	     
	   	case 2:	
	   	address();
	   	   goto b;
	   	break;
	   	
	   	
	   	case 3:
		   passChange();
		   goto c; 	
	   	break;
	   	
	   	
	   	case 4:
		   display();
	   	   goto b;	
	   	   break;
	   	   
	   	   
	   	   
	    case 5:
	    
	    	a=fopen("address.txt","r");
	    	printf("ENTER NAME \n");
	    	fflush(stdin);
	    	gets(name1);
	    	
	    	rewind(p);
	    
	    	while(!feof(a))
	    	{
	    		
				fread(&ad,sizeof(ad),1,a);
				
			
	    	if((strcmp(name1,ad.name))==0)
	    	{
	    	printf(" NAME = %s \n ADDRESS = %s\n PHONE NUMBER = %lld \n\n ",ad.name,ad.address,ad.phno);

		  demo=1;
		  goto b;
		  break;
			
			}
			}
			
		 if(demo==0)
			printf("PLEASE ENTER CORRECT NAME \n");			     	
	
	    
	    goto b;
	    
	    
	   
	break;
	
	case 6: exit(1);
	break;
	
	
	default:
		printf("ENTER A VALID OPTION\n");
	    goto b;
	    break;
    }
    
    }
	else
	printf("ACESS DETAINED\n");
	goto c;
	
	
}

void password(long int *p1)
{
	FILE *p;
	p=fopen("password.txt","r");
	
	
	if(p==NULL)
	printf("exit");

     *p1=getw(p);
        
	
}

void diary()
{
	FILE *p;
	p=fopen("info.txt","r+");
  int i;
  char info[5000];
  int j=0;
  printf("ENTER '$' TO EXIT FROM THE DIARY WRITING\n");
   	rewind(p);
   	strcpy(cmp1date,date);
	
	while(!feof(p))
	{
	     fgets(cmp2date,11,p);
     	if((strcmp(cmp2date,cmp1date))==0)
          j=1;
		  				
	}
	
   
   if(j==1)
   {
       appending();
   }
   else
    {

     fseek(p,0,SEEK_END);
    
    fprintf(p,"\n%s\t",date);
    
    char c,d;
    c=' ';
    d='^';
  for(i=0;i<200;i++)
  {
  	  gets(info);
  	
  	  // fprintf(p,"%s",info);
  	   fputs(info,p);
  	   fprintf(p," %c",d);
  	    fprintf(p,"\n",c);
  	    
  	    if(info[0]=='$' && info[1]=='\0')
  	     break;
		          
  }
  fclose(p);
   }
}
	
void address()
{

char name[50];
int i;
a=fopen("address.txt","r+");

printf("ENTER NAME\n");
fflush(stdin);
gets(ad.name);


printf("ENTER  PHONE NUMBER \n");
scanf("%lld",&ad.phno);

printf("ENTER ADDRESS\n");
fflush(stdin);
gets(ad.address);


fseek(a,0,SEEK_END);

fwrite(&ad,sizeof(ad),1,a);

fseek(a,-sizeof(ad),SEEK_END);

fread(&ad,sizeof(ad),1,a);
printf(" NAME = %s \n ADDRESS = %s\n PHONE NUMBER = %lld \n\n ",ad.name,ad.address,ad.phno);	

fclose(a);	
	
}

void display()
{
	int flag;
	p=fopen("info.txt","r");
	
	printf("ENTER DATE IN THE FORMAT DD/MM/YYYY\n");
	scanf("%s",&cmp1date);
	rewind(p);
	
	while(!feof(p))
	{
		fgets(cmp2date,11,p);
	

     	if((strcmp(cmp2date,cmp1date))==0)
         {
		        flag=1;
			  	 break;	
			  	
				   }	
			
	   		
	}
	if(flag!=1)
	printf("RECORD NOT FOUND\n");
	
if(flag==1)
 {
 int k=0;
    while(!feof(p))
    {
    	 k++;
    	
        fscanf(p,"%s",&cmp2date);
       
        
          if(cmp2date[0]=='^')
           printf("\n");
          else 
         {
		  if(cmp2date[0]=='$')
		   break; 
		   
          printf("%s ",cmp2date);
          }
	   
	}}
	fclose(p);
}	
	
void appending()
{
   	FILE *p;
	p=fopen("info.txt","r+");
	fseek(p,-5,SEEK_END);
    int i;
    char c,d,info[5000];
    c=' ';
    d='^';
	
	printf("\nAPPENDING THE INFO TO THE DIARY YOU PREVIOUSLY WRITTEN\n");

	
   for(i=0;i<200;i++)
  {
  	  gets(info);
  	   fputs(info,p);
  	   fprintf(p," %c",d);
  	    fprintf(p,"\n",c);
  	    
  	    if(info[0]=='$' && info[1]=='\0')
  	      break;

  }
  fclose(p);
   	
}
	
void passChange()	
{
	FILE *p;
	long int n;
	
	p=fopen("password.txt","w");
	if(p==NULL)
	{
		printf("exiting");
		exit(1);
	}
   
	printf("ENTER NEW PIN\n");
	scanf("%d",&n);
	putw(n,p);
    printf("PASSWORD HAS BEEN CHANGED\n");
   
	fclose(p);

}
