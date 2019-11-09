/*
Name: Student Information System
Copyright: http://bestengineeringprojects.com
Author: BEP
Date: 24/1/15 23:39
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
/* function deslaration start*/
	void add();
	void display();					
	void search_modify();
	void delete();
	void input();
	void output();
	void division1();
	void division2();
	void division3();
	void division4();
	/*Function declaration End*/
FILE *BEX,*BCT,*CIVIL;					 //file pointer
typedef struct		
{
	char f_name[25],l_name[25],address[100],phone_no[15],bloodgroup[5],section;
	char roll[15];
	float marks[6],obt_marks,avg_marks,total_marks[6],percent;
}student;
student st;							//global declaration of structure

int main()							//main function start
{
	int c=1;
	char password[10];
	char pass[]={"123"};
	printf("\t\t\twww.bestengineeringprojects.com");
	printf("\n\n\t\tplease enter the password:>  ");
	gets(password);
	if(strcmp(password,pass)==0)  /*Password Compare*/
 {
	
	start: system("cls");
	int no;
	do
	{
		system("cls");
 
     height: printf("\t\t====== STUDENT INFORMATION SYSTEM ======"); /*Menu*/
      printf("\n\n                                          ");
      printf( "\n\n");
      printf( "\n \t\t\t 1. Add    Records");
   	  printf( "\n \t\t\t 2. List   Records");
      printf( "\n \t\t\t 3. Search and Modify Records");
      printf( "\n \t\t\t 4. Delete Records");
      printf( "\n \t\t\t 5. Exit   Program");
      printf( "\n\n");
      printf("\t\t\t Select Your Choice(1,2,3,4 or 5) :=> ");
     target : scanf("%d",&no);
      switch(no)
      {
      	case 1:
      		add(); /* Add Function Calling*/
      		break;
      	case 2:
      		display(); /*Display Function Calling*/
      		break;
      	case 3:
      		search_modify(); /*Search_ modify Function Calling*/
      		break;
      	case 4:
      		delete(); /*Delete Function Calling*/
      		break;
      	case 5: /*Program exit with leaving this message*/
      		     printf( "\n\n");
             printf("\t\t     THANK YOU FOR USING THIS SOFTWARE");
           printf( "\n\n");
           getch();
              exit(0); "\n\n";
             break;
             default :
             	printf("\n\t\tInvalid choice--please enter the valid choice again:");
             	goto target;
             	break;
    	
             
     }
	}while(no!=5);
}
	else
	{
		while(1) /*Second time password comparing*/
		{
				if(c==1)
				printf("\n\t\tincorrect password??? last 2 try left");
				printf("\n\t\tenter the correct password again  ");
				gets(password);
				if(strcmp(password,pass)==0)
			{
				goto start;
			}
				else if(strcmp(password,pass)!=0) /*Last time password comparing*/
				{
					c=c++;
					if(c==2)
					printf("\n\t\tinvalid password??? last time");
					if(c==3)
					exit(0);
				}
		}
	}
	return 0;
}								//end of main function
void add()						//start of add function
{
	system("cls");
	int ch,no;
	char ans;	
	  printf("\n\n\n");														//add menu
	  printf( "\n \t\t\t 1. add record in electronics faculty");
   	  printf( "\n \t\t\t 2. add record in computer faculty");
      printf( "\n \t\t\t 3. add record in civil faculty");
      printf( "\n \t\t\t 4. return to main menu");
      printf( "\n\n");
      printf("\t\t\t Select Your Choice(1,2,3 or 4) :=> ");
	  top:scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			system("cls");										//for electronics file
			BEX=fopen("D:\\electronics.txt","ab");
			if(BEX==NULL)
			{
				printf("error in opening electronics.txt file");
				getch();
				exit(0);
			}
			
			do
			{
				input();
				fwrite(&st,sizeof(st),1,BEX);	
				printf("do you want to add another record (y for yes)");
				fflush(stdin);
				scanf("%c",&ans);			
			}while(tolower(ans)=='y');
			fclose(BEX);
			break;
		case 2:
				system("cls");
			BCT=fopen("D:\\computer.txt","ab");					//for computer file
			if(BCT==NULL)
			{
				printf("error in opening computer.txt file");
				getch();
				exit(0);
			}
			do
			{
				input();
				fwrite(&st,sizeof(st),1,BCT);	
				printf("do you want to add another record (y for yes)");
				fflush(stdin);
				scanf("%c",&ans);			
			}while(tolower(ans)=='y');
			fclose(BCT);
			break;
		case 3:
			system("cls");								//	for civil file
			CIVIL=fopen("D:\\civil.txt","ab");
			if(CIVIL==NULL)
			{
				printf("error in opening computer.txt file");
				getch();
				exit(0);
			}
			do
			{
				input();
				fwrite(&st,sizeof(st),1,CIVIL);	
				printf("do you want to add another record (y for yes)");
				fflush(stdin);
				scanf("%c",&ans);			
			}while(tolower(ans)=='y');
			fclose(CIVIL);
			break;
		case 4:
			break;
			
			default : 
			printf("\t\tenter the valid choice");
			goto top;
			break;
				
	}
}													//end of add function
void input()											//start of input function
{	
			int z;
		for(z=0;z<6;z++)
		{
			st.total_marks[z]=0;
			st.marks[z]=0;
		}
		int i;
		float sum=0,total=0;
		char ans;	
				printf("\tplease enter the first name:>");
				fflush(stdin);
				gets(st.f_name);													//name,roll no,section
				printf("\tplease enter the last name:>");
				fflush(stdin);
				gets(st.l_name);
				printf("\tplease enter the section:>");
				fflush(stdin);													
				scanf("%c",&st.section);
				printf("\tplease enter the roll number:>");
				scanf("%s",st.roll);
				printf("do u want to add marks(y for yes)");
				fflush(stdin);
				scanf("%c",&ans);
				for(i=0;i<1;i++)
				{
					if(tolower(ans)!='y')
					break;																	//input of marks
					printf("enter the total marks & marks obtained in Computer:>");
					scanf("%f%f",&st.total_marks[i],&st.marks[i]);
					i=i+1;
					printf("enter the total marks & marks obtained in Physics:>");
					scanf("%f%f",&st.total_marks[i],&st.marks[i]);
					i=i+1;
					printf("enter the total marks & marks obtained in Applied Mechanics:>");
					scanf("%f%f",&st.total_marks[i],&st.marks[i]);
					i=i+1;
					printf("enter the total marks & marks obtained in Mathematics:>");
					scanf("%f%f",&st.total_marks[i],&st.marks[i]);
					i=i+1;
					printf("enter the total marks & marks obtained in Basic Electrical:>");
					scanf("%f%f",&st.total_marks[i],&st.marks[i]);
					i=i+1;
					printf("enter the total marks & marks obtained in Drawing:>");
					scanf("%f%f",&st.total_marks[i],&st.marks[i]);
					i=i+1;
				}
				if(i!=0)
				{
				for(i=0;i<6;i++)
				{																//calculation of percent,average and obtained marks
					sum+=st.marks[i];
					total+=st.total_marks[i];
				}
				st.obt_marks=sum;
				st.avg_marks=sum/6;
				st.percent=(sum/total)*100;
				}
				printf("please enter the phone number:>");				//phone number
				fflush(stdin);
				gets(st.phone_no);
				printf("please enter the address:>");					//address
				fflush(stdin);
				gets(st.address);
				printf("\tplease enter the blood group:>");				//blood group
				fflush(stdin);
				gets(st.bloodgroup);
			
}		
int dist,frist,sec,pass;																//end of input function
void display()															//start of display function
{
	int no,fail,ch;
	char blood[5];
system("cls");
reverse:	printf("\n\n\n\n");
	printf("\n\t\t\t1.list all");
	printf("\n\t\t\t2.list of Electronics faculty");
	printf("\n\t\t\t3.list of Computer faculty");
	printf("\n\t\t\t4.list of Civil faculty");
	printf("\n\t\t\t5.list of passed student");
	printf("\n\t\t\t6.list of failed student");
	printf("\n\t\t\t7.list of student by blood group");
	printf("\n\t\t\t8.return to main menu");
	printf("\n\n\t\t\tenter the choice your choice from(1-8)=>");
upper: scanf("%d",&no);
	switch(no)
	{
		case 1:
			system("cls");										//for electronics file
			BEX=fopen("D:\\electronics.txt","rb");
			if(BEX==NULL)
			{
				printf("\n\n\t\terror in opening electronics.txt file\n");
			//	getch();
			//	exit(0);
			}
		else
		{
			printf("\n\n\t\tfaculty \"BEX\"");
			while(fread(&st,sizeof(st),1,BEX)==1)
			{
				output();
			}
		}
			BCT=fopen("D:\\computer.txt","rb");
			if(BCT==NULL)
			{
				printf("\n\n\t\terror in opening computer.txt file\n");
			//	getch();
			//	exit(0);
			}
		else
		{
			printf("\n\t\t\tfaculty \"BCT\"");
			while(fread(&st,sizeof(st),1,BCT)==1)
			{
				output();
			}
		}
			CIVIL=fopen("D:\\civil.txt","rb");
			if(CIVIL==NULL)
			{
				printf("\n\n\t\terror in opening civil.txt file");
				getch();
				break;
			//	exit(0);
			}
			printf("\n\t\t\tfaculty \"CIVIL\"");
			while(fread(&st,sizeof(st),1,CIVIL)==1)
			{
				output();
			}
			getch();
			fclose(BEX);
					fclose(BCT);
					fclose(CIVIL);
			break;
		case 2:
				system("cls");										//for electronics file
			BEX=fopen("D:\\electronics.txt","rb");
			if(BEX==NULL)
			{
				printf("\n\n\t\terror in opening electronics.txt file");
				getch();
				break;
			//	exit(0);
			}
			printf("faculty \"BEX\"");
		//	rewind(BEX);
			while(fread(&st,sizeof(st),1,BEX)==1)
			{
				output();
			}
			getch();
			fclose(BEX);
			break;
		case 3:
				system("cls");
				BCT=fopen("D:\\computer.txt","rb");
			if(BCT==NULL)
			{
				printf("\n\n\t\terror in opening computer.txt file");
				getch();
				break;
			//	exit(0);
			}
			printf("faculty \"BCT\"");
		//	rewind(BCT);
			while(fread(&st,sizeof(st),1,BCT)==1)
			{
				output();
			}
			getch();
			fclose(BCT);
			break;
		case 4:
				system("cls");
				CIVIL=fopen("D:\\civil.txt","rb");
			if(CIVIL==NULL)
			{
				printf("\n\n\t\terror in opening civil.txt file");
				getch();
				break;
			//	exit(0);
			}
			printf("faculty \"CIVIL\"");
		//	rewind(CIVIL);
			while(fread(&st,sizeof(st),1,CIVIL)==1)
			{
				output();
			}
			getch();
			fclose(CIVIL);
			break;
		case 5:
				system("cls");
			printf("enter the distiction percent=");
			scanf("%d",&dist);
			printf("enter the frist division percent=");
			scanf("%d",&frist);
			printf("enter the second division percent=");
			scanf("%d",&sec);
			printf("enter the passed division percent=");
			scanf("%d",&pass);
			system("cls");
			printf("\n\n");
			printf("\n\t\t500.all student");
			printf("\n\t\t600.electronics student");
			printf("\n\t\t700.computer student");
			printf("\n\t\t800.civil student");
			printf("\n\t\t900.return to menu");
			printf("\n\n\t\t\tenter the choice(500,600,700,800,900)=>");
		above:	scanf("%d",&ch);
			switch(ch)
			{
				case 500:
					system("cls");
						BEX=fopen("D:\\electronics.txt","rb");
						if(BEX==NULL)
					{
						printf("\n\n\t\terror in opening electronics.txt file\n\n");
					}
					else
					{
						while(fread(&st,sizeof(st),1,BEX)==1)
						{
							division1();
						}
							
							rewind(BEX);
							while(fread(&st,sizeof(st),1,BEX)==1)
						{
							division2();
							
						}
								rewind(BEX);
								while(fread(&st,sizeof(st),1,BEX)==1)
						{
								division3();
								
						}
						
							rewind(BEX);
							while(fread(&st,sizeof(st),1,BEX)==1)
						{
								division4();
								
						}
						
						fclose(BEX);
					}
							BCT=fopen("D:\\computer.txt","rb");
							if(BCT==NULL)
						{
						printf("\n\n\t\terror in opening computer.txt file\n\n");
						}
					else
					{
						while(fread(&st,sizeof(st),1,BCT)==1)
						{
							division1();
						}	
							rewind(BCT);
							while(fread(&st,sizeof(st),1,BCT)==1)
							{
								division2();
							}
							
							rewind(BCT);
							while(fread(&st,sizeof(st),1,BCT)==1)
							{
							division3();
							}
							
								rewind(BCT);
							while(fread(&st,sizeof(st),1,BCT)==1)
							{
								division4();
							}
							
							fclose(BCT);
					}
						CIVIL=fopen("D:\\civil.txt","rb");
						if(CIVIL==NULL)
						{
							printf("\n\n\t\terror in opening civil.txt file");
							getch();
							break;
							//	exit(0);
						}
							while(fread(&st,sizeof(st),1,CIVIL)==1)
							division1();
							
								rewind(CIVIL);
							while(fread(&st,sizeof(st),1,CIVIL)==1)
							division2();
						
								rewind(CIVIL);
							while(fread(&st,sizeof(st),1,CIVIL)==1)
							division3();
						
								rewind(CIVIL);
							while(fread(&st,sizeof(st),1,CIVIL)==1)
							division4();
							getch();
					fclose(CIVIL);
							break;
							
					case 600:
						system("cls");
						BEX=fopen("D:\\electronics.txt","rb");
						if(BEX==NULL)
					{
						printf("\n\t\t\terror in opening electronics.txt file");
						getch();
						break;
					}
						while(fread(&st,sizeof(st),1,BEX)==1)
							division1();
							rewind(BEX);
						while(fread(&st,sizeof(st),1,BEX)==1)
							division2();
							rewind(BEX);
						while(fread(&st,sizeof(st),1,BEX)==1)
							division3();
							rewind(BEX);
						while(fread(&st,sizeof(st),1,BEX)==1)
							division4();
							fclose(BEX);
							getch();
							break;
					case 700:
						system("cls");
						BCT=fopen("D:\\computer.txt","rb");
							if(BCT==NULL)
						{
						printf("\n\n\t\terror in opening computer.txt file");
						getch();
							break;
						}
						while(fread(&st,sizeof(st),1,BCT)==1)
						{
							division1();
						}	
							rewind(BCT);
							while(fread(&st,sizeof(st),1,BCT)==1)
							{
								division2();
							}
							rewind(BCT);
							while(fread(&st,sizeof(st),1,BCT)==1)
							{
							division3();
							}
								rewind(BCT);
							while(fread(&st,sizeof(st),1,BCT)==1)
							{
								division4();
							}
							getch();
							fclose(BCT);
							break;
					case 800:
						system("cls");
						CIVIL=fopen("D:\\civil.txt","rb");
						if(CIVIL==NULL)
						{
							printf("\n\n\t\terror in opening civil.txt file");
							getch();
							break;
						}
							while(fread(&st,sizeof(st),1,CIVIL)==1)
							division1();
								rewind(CIVIL);
							while(fread(&st,sizeof(st),1,CIVIL)==1)
							division2();
								rewind(CIVIL);
							while(fread(&st,sizeof(st),1,CIVIL)==1)
							division3();
								rewind(CIVIL);
							while(fread(&st,sizeof(st),1,CIVIL)==1)
							division4();
							getch();
					fclose(CIVIL);
							break;
					case 900:
						system("cls");
						goto reverse;
						break;
					default :
					printf("enter the valid choice");
					goto above;
					break;
			}
			break;
		case 6:
			system("cls");
			printf("enter the fail percent");
			scanf("%d",&fail);
				BEX=fopen("D:\\electronics.txt","rb");
						if(BEX==NULL)
					{
						printf("\n\t\t\terror in opening electronics.txt file");
						getch();
						break;
					}
						while(fread(&st,sizeof(st),1,BEX)==1)
						{
						
						if(st.percent<=fail)
							{
								printf("\nName=%s %s",st.f_name,st.l_name);
								printf("\nRoll number=%s",st.roll);
								printf("\nSection=%c",st.section);
								printf("\nBlood group=%s",st.bloodgroup);
								printf("\nPhone no=%s",st.phone_no);
								printf("\nAddress=%s",st.address);
								printf("\n\n    \t\tMarks obtained in each subject are:>\n");
								printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
								printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
								printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
								printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
								printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
								printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
								printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
								printf("\n\ntotal obtained marks=%f",st.obt_marks);
								printf("\nAverage marks=%f",st.avg_marks);
								printf("\nPercentage=%f\n",st.percent);
								printf("\n\t------------------------------\n\n\n\n");
							}
						}	
						BCT=fopen("D:\\computer.txt","rb");
							if(BCT==NULL)
						{
						printf("\n\n\t\terror in opening computer.txt file");
						getch();
							break;
						}
							while(fread(&st,sizeof(st),1,BCT)==1)
						{
						
						if(st.percent<=fail)
							{
								printf("\nName=%s %s",st.f_name,st.l_name);
								printf("\nRoll number=%s",st.roll);
								printf("\nSection=%c",st.section);
								printf("\nBlood group=%s",st.bloodgroup);
								printf("\nPhone no=%s",st.phone_no);
								printf("\nAddress=%s",st.address);
								printf("\n\n    \t\tMarks obtained in each subject are:>\n");
								printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
								printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
								printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
								printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
								printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
								printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
								printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
								printf("\n\ntotal obtained marks=%f",st.obt_marks);
								printf("\nAverage marks=%f",st.avg_marks);
								printf("\nPercentage=%f",st.percent);
								printf("\n\t------------------------------\n\n\n\n");
							}
						}
							CIVIL=fopen("D:\\civil.txt","rb");
						if(CIVIL==NULL)
						{
							printf("\n\n\t\terror in opening civil.txt file");
							getch();
							break;
						}
							while(fread(&st,sizeof(st),1,CIVIL)==1)
						{
						
						if(st.percent<=fail)
							{
									printf("\nName=%s %s",st.f_name,st.l_name);
								printf("\nRoll number=%s",st.roll);
								printf("\nSection=%c",st.section);
								printf("\nBlood group=%s",st.bloodgroup);
								printf("\nPhone no=%s",st.phone_no);
								printf("\nAddress=%s",st.address);
								printf("\n\n    \t\tMarks obtained in each subject are:>\n");
								printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
								printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
								printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
								printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
								printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
								printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
								printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
								printf("\n\ntotal obtained marks=%f",st.obt_marks);
								printf("\nAverage marks=%f",st.avg_marks);
								printf("\nPercentage=%f",st.percent);
								printf("\n\t------------------------------\n\n\n\n");
							}
						}
						getch();
						fclose(BEX);
					fclose(BCT);
					fclose(CIVIL);
						break;
		case 7:
			system("cls");
			printf("enter the blood group=");
			fflush(stdin);
			gets(blood);
			BEX=fopen("D:\\electronics.txt","rb");
			if(BEX==NULL)
			{
				printf("\n\t\terror in opening electronics.txt file\n");
			}
				while(fread(&st,sizeof(st),1,BEX)==1)
					{
						if(strcmp(st.bloodgroup,blood)==0)
						output();
					}
				BCT=fopen("D:\\computer.txt","rb");
			if(BCT==NULL)
			{
				printf("\n\n\t\terror in opening computer.txt file\n");
			}
						while(fread(&st,sizeof(st),1,BCT)==1)
					{
						if(strcmp(st.bloodgroup,blood)==0)
						output();
					}
			CIVIL=fopen("D:\\civil.txt","rb");
			if(CIVIL==NULL)
			{
				printf("\n\n\t\terror in opening civil.txt file");
				getch();
				break;
			}
					while(fread(&st,sizeof(st),1,CIVIL)==1)
					{
						if(strcmp(st.bloodgroup,blood)==0)
						output();
					}
					getch();
					fclose(BEX);
					fclose(BCT);
					fclose(CIVIL);
					break;
				case 8:
					fclose(BEX);
					fclose(BCT);
					fclose(CIVIL);
					system("cls");
					break;
				default :
					printf("enter the valid choice");
					goto upper;
						break;
	}					
	
	
}
void output()
{
	printf("\nName=%s %s",st.f_name,st.l_name);
	printf("\nRoll number=%s",st.roll);
	printf("\nSection=%c",st.section);
	printf("\nBlood group=%s",st.bloodgroup);
	printf("\nPhone no=%s",st.phone_no);
	printf("\nAddress=%s",st.address);
	printf("\n\n    \t\tMarks obtained in each subject are:>\n");
	printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
	printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
	printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
	printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
	printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
	printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
	printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
	printf("\n\ntotal obtained marks=%.2f",st.obt_marks);
	printf("\nAverage marks=%.2f",st.avg_marks);
	printf("\nPercentage=%.2f",st.percent);
	printf("\n\t------------------------------\n\n\n\n");
}
void division1()
{
		if(st.percent>=dist)
							{
									printf("\nName=%s %s",st.f_name,st.l_name);
									printf("\nRoll number=%s",st.roll);
									printf("\nSection=%c",st.section);
									printf("\nBlood group=%s",st.bloodgroup);
									printf("\nPhone no=%s",st.phone_no);
									printf("\nAddress=%s",st.address);
									printf("\n\n    \t\tMarks obtained in each subject are:>\n");
									printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
									printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
									printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
									printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
									printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
									printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
									printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
									printf("\n\ntotal obtained marks=%f",st.obt_marks);
									printf("\nAverage marks=%f",st.avg_marks);
									printf("\nPercentage=%f",st.percent);
									printf("\n\t------------------------------\n\n\n\n");
}
							
}
void division2()
{
		if(st.percent>=frist && st.percent<dist)
							{
								printf("\nName=%s %s",st.f_name,st.l_name);
								printf("\nRoll number=%s",st.roll);
								printf("\nSection=%c",st.section);
								printf("\nBlood group=%s",st.bloodgroup);
								printf("\nPhone no=%s",st.phone_no);
								printf("\nAddress=%s",st.address);
								printf("\n\n    \t\tMarks obtained in each subject are:>\n");
								printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
								printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
								printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
								printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
								printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
								printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
								printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
								printf("\n\ntotal obtained marks=%f",st.obt_marks);
								printf("\nAverage marks=%f",st.avg_marks);
								printf("\nPercentage=%f",st.percent);
								printf("\n\t------------------------------\n\n\n\n");
							}
}
void division3()
{
		if(st.percent>=sec && st.percent<frist)
							{
								printf("\nName=%s %s",st.f_name,st.l_name);
								printf("\nRoll number=%s",st.roll);
								printf("\nSection=%c",st.section);
								printf("\nBlood group=%s",st.bloodgroup);
								printf("\nPhone no=%s",st.phone_no);
								printf("\nAddress=%s",st.address);
								printf("\n\n    \t\tMarks obtained in each subject are:>\n");
								printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
								printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
								printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
								printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
								printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
								printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
								printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
								printf("\n\ntotal obtained marks=%f",st.obt_marks);
								printf("\nAverage marks=%f",st.avg_marks);
								printf("\nPercentage=%f",st.percent);
								printf("\n\t------------------------------\n\n\n\n");
							}
}
void division4()
{
		if(st.percent>=pass && st.percent<sec)
							{
								printf("\nName=%s %s",st.f_name,st.l_name);
								printf("\nRoll number=%s",st.roll);
								printf("\nSection=%c",st.section);
								printf("\nBlood group=%s",st.bloodgroup);
								printf("\nPhone no=%s",st.phone_no);
								printf("\nAddress=%s",st.address);
								printf("\n\n    \t\tMarks obtained in each subject are:>\n");
								printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
								printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
								printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
								printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
								printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
								printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
								printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
								printf("\n\ntotal obtained marks=%f",st.obt_marks);
								printf("\nAverage marks=%f",st.avg_marks);
								printf("\nPercentage=%f",st.percent);
								printf("\n\t------------------------------\n\n\n\n");
							}
}
void search_modify()
{
	int ch;
	char g,r[15],ph[15],fname[25],lname[25];
	system("cls");
			printf("\n\t\t1.search by name");
			printf("\n\t\t2.search by roll number");
			printf("\n\t\t3.search by phone number");
			printf("\n\t\t4.return to menu");
			printf("\n\n\t\t\tenter the choice(1,2,3,4)=>");
			read:	scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				system("cls");
				printf("\n\t\t\tenter the frist name:");
				fflush(stdin);
				gets(fname);
				printf("\n\t\t\tenter the last name:");
				fflush(stdin);	
				gets(lname);
					BEX=fopen("D:\\electronics.txt","rb+");
			if(BEX==NULL)
			{
				printf("\n\t\terror in opening electronics.txt file\n");
			}
				while(fread(&st,sizeof(st),1,BEX)==1)
					{
						if(strcmp(st.f_name,fname)==0)
						{
								if(strcmp(st.l_name,lname)==0)
							{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
								if('y'==tolower(g))
								{
								input();
								fseek(BEX,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,BEX);
								break;
								}
								if('d'==tolower(g))
								{
									if(strcmp(st.l_name,lname)==0)
									continue;
									rewind(BEX);
									
								}
							}
						}
		
					}
						fclose(BEX);
						BCT=fopen("D:\\computer.txt","rb+");
						if(BCT==NULL)
						{
							printf("\n\t\terror in opening computer.txt file\n");
						}
							while(fread(&st,sizeof(st),1,BCT)==1)
					{
						if(strcmp(st.f_name,fname)==0)
						{
								if(strcmp(st.l_name,lname)==0)
							{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
								if('y'==tolower(g))
								{
								input();
								fseek(BCT,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,BCT);
								break;
								}
							}
						}
		
					}
						fclose(BCT);
						CIVIL=fopen("D:\\civil.txt","rb+");
						if(CIVIL==NULL)
					{
							printf("\n\t\terror in opening civil.txt file");
							getch();
							break;
					}
						while(fread(&st,sizeof(st),1,CIVIL)==1)
					{
						if(strcmp(st.f_name,fname)==0)
						{
								if(strcmp(st.l_name,lname)==0)
							{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
								if('y'==tolower(g))
								{
								input();
								fseek(CIVIL,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,CIVIL);
								break;
								}
							}
						}
		
					}
						getch();
						fclose(CIVIL);
						break;
			case 2:
				system("cls");
				printf("\n\t\t\tenter the roll number you want to search:");
				fflush(stdin);	
				gets(r);
					BEX=fopen("D:\\electronics.txt","rb+");
			if(BEX==NULL)
			{
				printf("\n\t\terror in opening electronics.txt file\n");
			}
				while(fread(&st,sizeof(st),1,BEX)==1)
					{
						if(strcmp(st.roll,r)==0)
						{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
							if('y'==tolower(g))
								{
								input();
								fseek(BEX,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,BEX);
								break;
								}
						}
		
					}
						fclose(BEX);
						BCT=fopen("D:\\computer.txt","rb+");
						if(BCT==NULL)
						{
							printf("\n\t\terror in opening computer.txt file\n");
						}
							while(fread(&st,sizeof(st),1,BCT)==1)
					{
						if(strcmp(st.roll,r)==0)
						{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
						if('y'==tolower(g))
								{
								input();
								fseek(BCT,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,BCT);
								break;
								}
						}
		
					}
						fclose(BCT);
						CIVIL=fopen("D:\\civil.txt","rb+");
						if(CIVIL==NULL)
					{
							printf("\n\t\terror in opening civil.txt file");
							getch();
							break;
					}
						while(fread(&st,sizeof(st),1,CIVIL)==1)
					{
						if(strcmp(st.roll,r)==0)
						{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
							if('y'==tolower(g))
								{
								input();
								fseek(CIVIL,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,CIVIL);
								break;
								}
						}
		
					}
						getch();
						fclose(CIVIL);
						break;
			case 3:
						system("cls");
				printf("\n\tenter the phone number you want to search:");
				fflush(stdin);	
				gets(ph);
					BEX=fopen("D:\\electronics.txt","rb+");
			if(BEX==NULL)
			{
				printf("\n\t\terror in opening electronics.txt file\n");
			}
				while(fread(&st,sizeof(st),1,BEX)==1)
					{
						if(strcmp(st.phone_no,ph)==0)
						{
								output();
								printf("\n\n\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
							if('y'==tolower(g))
								{
								input();
								fseek(BEX,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,BEX);
								break;
								}
						}
		
					}
						fclose(BEX);
						BCT=fopen("D:\\computer.txt","rb+");
						if(BCT==NULL)
						{
							printf("\n\t\terror in opening computer.txt file\n");
						}
							while(fread(&st,sizeof(st),1,BCT)==1)
					{
						if(strcmp(st.phone_no,ph)==0)
						{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
							if('y'==tolower(g))
								{
								input();
								fseek(BCT,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,BCT);
								break;
								}
						}
		
					}
						fclose(BCT);
						CIVIL=fopen("D:\\civil.txt","rb+");
						if(CIVIL==NULL)
					{
							printf("\n\t\terror in opening civil.txt file");
							getch();
							break;
					}
						while(fread(&st,sizeof(st),1,CIVIL)==1)
					{
						if(strcmp(st.phone_no,ph)==0)
						{
								output();
								printf("\n\n\t\tDo you want to modify this record");
								printf("\n enter 'y' for yes or press any other key =  ");
								scanf("%c",&g);
						if('y'==tolower(g))
								{
								input();
								fseek(CIVIL,-sizeof(st),SEEK_CUR);
								fwrite(&st,sizeof(st),1,CIVIL);
								break;
								}
						}
		
					}
						getch();
						fclose(CIVIL);
						break;				
			case 4:
				break;
			default :
					printf("invalid choice\?\?--please enter correct choice");
					goto read;
					break;		
		}
}
void delete()
{
	
}
