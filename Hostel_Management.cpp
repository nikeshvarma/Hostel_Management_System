/*
CREATED BY : NIKESH VARMA
CREATED : 10/07/2019
PROJECT : HOSTEL MANAGEMENT SYSTEM PROGRAM
UNDER GUIDENCE OF : PROF. ANITA YADAV
LAST UPDATED : 13/07/2019
*/

//HEADER FILES


#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>


fstream file;   				//GLOBEL OBJECT CREATED FOR FILE

class hostel 				//CLASS
{
	char y_name[40], f_name[40];   	//DATA MEMBERS
	char add[100];
	int  roll_no, age;
	float charge, charge1, charge2;

public:
	void registration();
	void display();
	void view_all();
	void search();
	void charges();
	void facilities();
	void update();
	void del();

}hos;	//CLASS GLOBAL OBJECT CREATED

int i;

void main()               			//MAIN FUNCTION STARTED
{
	textbackground(3);
	textcolor(BLACK);

	clrscr();
	int choice;
	for ( ; ;)
	{
	clrscr();

	for (i=0; i<80; i++)
	{ delay(8);
	cout<<"^";
	}

	cout<<endl<<"\t\t\t***HOSTEL MANAGEMENT SYSTEM***"<<endl<<endl;

	for (i=0; i<80; i++)
	{ delay(8);
	cout<<"^";
	}

	cout<<endl;
	delay(300);
	cout<<"\t\t\t\t ********"<<endl;
	cout<<"\t\t\t\t * MENU *"<<endl;
	cout<<"\t\t\t\t ********"<<endl<<endl<<endl;
	delay(200);
	cout<<"\t\t\t 1. REGISTRATIONS"<<endl;
	delay(200);
	cout<<"\t\t\t 2. VIEW ALL REGISTRATIONS"<<endl;
	delay(200);
	cout<<"\t\t\t 3. SEARCH"<<endl;
	delay(200);
	cout<<"\t\t\t 4. FACILITIES"<<endl;
	delay(200);
	cout<<"\t\t\t 5. FEES STRUCTURE"<<endl;
	delay(200);
	cout<<"\t\t\t 6. UPDATE"<<endl;
	delay(200);
	cout<<"\t\t\t 7. DELETE"<<endl;
	delay(200);
	cout<<"\t\t\t 8. EXIT"<<endl<<endl;
	delay(200);

	cout<<"\t\t\t Enter your choice: ";
	cin>> choice;
	clrscr();

	switch(choice)
	{
		case 1:
			clrscr();
			file.open("hostel.txt",ios::app|ios::out);
			if (!file)
			cout<<"\t\t\t file not created"<<endl;
			else
			{
			for (i=0; i<80; i++)
			{ delay(10);
			cout<<"-";
			}
			cout<<endl<<"\t\t\t REGISTRATION FORM"<<endl;
			for (i=0; i<80; i++)
			{ delay(10);
			cout<<"-";
			}
			cout<<endl;
			hos.registration();
			file.write((char*)&hos,sizeof(hos));
			file.close();
			}
		break;

		case 2:
			clrscr();
			for (i=0; i<80; i++)
			cout<<"-";
			cout<<endl<<"\t\t\t REGISTRATIONS LISTS"<<endl;
			for (i=0; i<80; i++)
			cout<<"-";

			hos.view_all();
		break;

		case 3:
			clrscr();
			hos.search();
		break;

		case 4:
			clrscr();
			hos.facilities();
		break;

		case 5:
			clrscr();
			hos.charges();
		break;

		case 6:
			clrscr();
			hos.update();
		break;

		case 7:
			clrscr();
			hos.del();
		break;

		case 8:
			exit(0);
		break;

		default :
			cout<<"\t\t\t Invalid Option"<<endl;
	        }
	getch();
	}
}                     	 		//MAIN CLOSE


void hostel::registration()
{
	cout<<"\t\t\t 1) Your name: ";
	fflush(stdin);
	gets(y_name);
	cout<<"\t\t\t 2) Father name: ";
	fflush(stdin);
	gets(f_name);
	cout<<"\t\t\t 3) Roll No. : ";
	fflush(stdin);
	cin>>roll_no;
	cout<<"\t\t\t 4) Your Age: ";
	cin>>age;
	cout<<"\t\t\t 5) Your Address: ";
	fflush(stdin);
	gets(add);
	cout<<endl<<endl;
	for (int i=0; i<80; i++)
	{
	delay(10);
	cout<<"*";
	}
	delay(100);
	cout<<endl<<"\t\t\t Registration Completed"<<endl<<endl;
	cout<<"\t\t    ****Thanks for Registration****"<<endl;
}


void hostel::display()
{
	cout<<"\n\n\t\t\t 1) Roll No. : ";
	cout<<roll_no<<endl;
	cout<<"\t\t\t 2) Name : ";
	cout<<y_name<<endl;
	cout<<"\t\t\t 3) Father Name : ";
	cout<<f_name<<endl;
	cout<<"\t\t\t 4) Age: "<<age<<endl;
	cout<<"\t\t\t 5) Address : ";
	cout<<add;
}


void hostel::search()
{
	for (i=0; i<80; i++)
	cout<<"-";
	int input;
	cout<<endl<<"\t\t\t\t SEARCH "<<endl;
	for (i=0; i<80; i++)
	cout<<"-";

	cout<<"\t\t\tDO NOT ENTER WRONG ROLL NO."<<endl;
	cout<<"\t\t  Enter Roll No. of student to search: ";
	cin>>input;
	cout<<endl<<endl;

	for (i=0; i<80; i++)
	cout<<"-";

	cout<<endl<<"\t\t\t ***SEARCH RESULTS****"<<endl<<endl;
	for (i=0; i<80; i++)
	cout<<"-";


	file.open("hostel.txt",ios::in);
	file.read((char*)&hos,sizeof(hos));

	while(!file.eof())
	{
		if(input==roll_no)
		{
		display();
		break;
		}
		file.read((char*)&hos,sizeof(hos));
	}
	 file.seekg(0);
}


void hostel::facilities()
{         int ch1, ch2;

	for (i=0; i<80; i++)
	cout<<"=";
	cout<<endl<<"\t\t\t COLLEGE FACILITIES"<<endl;
	for (i=0; i<80; i++)
	cout<<"=";

	cout<<endl<<"\t\t\t THE FACILITIES PROVIDED IN OUR HOSTEL ARE AS "<<endl;
	cout<<"\t\t\t 1. Bed"<<endl<<"\t\t\t 2. Mess"<<endl;
	cout<<"\t\t\t Enter Your Choice: ";
	cin>>ch1;

	switch(ch1)
	{
	case 1:
		cout<<"\t\t\t 1. Single Bed"<<endl<<"\t\t\t 2. Double Bed"<<endl;
		cout<<"\t\t\t Enter your choice: ";
		cin>>ch2;

		switch(ch2)
		{
		case 1:
			cout<<"\t\t\tSINGLE BED IS SUITABLE FOR SINGLE STUDENT"<<endl;
			charge1 = 500;
			break;
		case 2:
			cout<<"\t\t\tDOUBLE BED IS SUITABLE FOR TWO STUDENTS"<<endl;
			charge2 = 1000;
			break;
		default:
			cout<<"\t\t\t Invalid Option"<<endl;
		}
		break;

	case 2:
		cout<<"\t\t\tOUR MESS PROVIDES YOU SUMPTUOUS FOOD."<<endl;
		cout<<"\t\t\tFOOD IS HYGENIC AND 100% VEG."<<endl;
		break;

	default:
		cout<<"\n\t\t\t INVALID OPTION"<<endl;

	}
}


void hostel::view_all()
{
	file.open("hostel.txt",ios::in);
	file.read((char*)&hos,sizeof(hos));

	while(!file.eof())
	{
		display();
		file.read((char*)&hos,sizeof(hos));
	}
	file.close();


}


void hostel::del()
{
	fstream fin;
	fstream fout;
	int r;
	cout<<"\t\t THE RECORD OF STUDENT DELETED PERMANANTLY"<<endl<<endl;
	cout<<"\t\t Enter Roll No.to delete : ";
	cin>>r;

	fin.open("hostel.txt",ios::in);
	fout.open("temp.txt",ios::out);
	if (!fout)
	cout<<"File not created"<<endl;
	else
	{
	fin.read((char*)&hos,sizeof(hos));
		while(!fin.eof())
	{
		if (roll_no!=r)
		{
		fout.write((char*)&hos,sizeof(hos));
		}
	fin.read((char*)&hos,sizeof(hos));
	}
	fin.close();
	fout.close();
	remove("hostel.txt");
	rename((char*)"temp.txt",(char*)"hostel.txt");
	cout<<"\t\t\t RECORD DELETED SUCCESSFULLY"<<endl;

     }
}


void hostel::charges()
{
	for (i=0; i<80; i++)
	cout<<"=";
	cout<<endl<<"\t\t\t HOSTEL FEES STRUCTURE"<<endl<<endl;
	for (i=0; i<80; i++)
	cout<<"=";

	cout<<endl<<"\t\t\t HOSTEL FEES - 60000"<<endl;
	cout<<"\t\t\t MESS FEES - INCLUDED IN HOSTEL FEES"<<endl;
	cout<<"\t\t\t SINGLE BED - 500/MONTH"<<endl;
	cout<<"\t\t\t DOUBLE BED - 800/ MONTH"<<endl;
}


void hostel::update()
{
	int r, position;

	for (i=0; i<80; i++)
	cout<<"-";
	cout<<endl<<"\t\t\t STUDENT DETAILS ARE UPDATE HERE"<<endl;
	for (i=0; i<80; i++)
	cout<<"-";

	cout<<endl<<"\t\t\t Enter Roll No. : ";
	cin>>r;

	file.open("hostel.txt",ios::out|ios::in);


	while (!file.eof())
	{
		file.read((char*)&hos,sizeof(hos));
		if (roll_no==r)
		{
		position=file.tellg();
		cout<<"\n\t\t UPDATE DEATAILS OF STUDENT"<<endl<<endl;

		file.seekg(position-sizeof(hos));

		cout<<"\t\t\t Enter Name: ";
		gets(y_name);
		cout<<"\t\t\t Father Name: ";
		gets(f_name);
		cout<<"\t\t\t Address : ";
		gets(add);

		file.write((char*)&hos,sizeof(hos));
		cout<<"\n\t\t DETAILS UPDATED SUCCESSFULLY"<<endl;
		break;
		}
		else
		{
		cout<<"\n\n\t\t\t NO MATCH FOUND"<<endl;
		break;
		}
	}
		file.close();
}
