
/**********************************
				THE START
**********************************/

/**********************************
 Header files
**********************************/
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

/**********************************
 Class
**********************************/
class LIBRARY
 {
	public:

/**********************************
 Strucutres
**********************************/
//Structure for 'Book Details'
	struct Book
	{
		int slno;
		int bookNo;
		char bookName[50];
		float price;
		char publisher[50];
		char status[10];
	}book;
//Structure for 'Issue Details'
	struct Issue
	{
		int slno;
		char name[50];
		char phNo[50];
		int bookNo;
		int noMonth;
		int noWeek;
		int noDay;
		float charge;
		char status[10];
	}issue;

/**********************************
 Member Functions
**********************************/
//Member Functions for 'Book Details'
	void Save(Book &, int &);             //MFBD 1
	void Check(Book &, int, int &);       //MFBD 2
	void Input(Book &, int &);            //MFBD 3
	void Show(Book &);                    //MFBD 4
	void Showall(Book &);                 //MFBD 5
	void Search(Book &, int);             //MFBD 6
	void Update(Book &, int);             //MFBD 7
//Member Functions for 'Issue Details'
	int  CalChargeI(int, int, int, float);//MFID 1
	void SaveI(Issue &, int, int &);      //MFID 2
	void CheckI(Issue &, int, int &);     //MFID 3
	void IssueI(Issue &, int &);          //MFID 4
	void ShowI(Issue &);                  //MFID 5
	void ShowallI(Issue &);               //MFID 6
	void SearchI(Issue &, int);           //MFID 7
	void ReturnI(Issue &, int);           //MFID 8
 };

/**********************************
 Individual Display Functions
**********************************/
void GrandDisplay()                      //IDF 1
 {
	clrscr();
	cout<<"\t\t\t\t  WELCOME TO\n";
	for(int k=0; k<80; k++)
	cout<<"*";
	int r=8;
	for(int i=0,j; i<=r; i++)
	{
		cout<<endl;
		cout<<"\t    D";
		for(int a1=r; a1>=r,a1<=2*r; a1++)
		{
			float d=sqrt((i-r)*(i-r)+(a1-r)*(a1-r));
			if(d>r-0.5 && d<r+0.5)
			{
				cout<<"D";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<"  ";
		for(int a2=0; a2<=2*(r-1); a2++)
		{
			float d=sqrt((i-(r-1))*(i-(r-1))+(a2-(r-1))*(a2-(r-1)));
			if(d>(r-1)-0.5 && d<(r-1)+0.5)
			{
				cout<<"A";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<"  ";
		for(int a3=0; a3<=r*0.7; a3++)
		{
			float d=sqrt((i-r*0.5)*(i-r*0.5)+(a3-r*0.5)*(a3-r*0.5));
			if(d>r*0.5-0.5 && d<r*0.5+0.5)
			{
				cout<<"S";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<" ";
		for(a3=0; a3<=r*0.7; a3++)
		{
			cout<<" ";
		}
		for(int a4=0; a4<=r*0.7; a4++)
		{
			float d=sqrt((i-r*0.5)*(i-r*0.5)+(a4-r*0.5)*(a4-r*0.5));
			if(d>r*0.5-0.5 && d<r*0.5+0.5)
			{
				cout<<"S";
			}
			else
			{
				cout<<" ";
			}
		}
	}
	for(i=0,j=r; i<=r,j>=r,j<=2*r; i++,j++)
	{
		cout<<endl;
		cout<<"\t    D";
		for(int a1=r; a1>=r,a1<=2*r; a1++)
		{
			float d=sqrt((j-r)*(j-r)+(a1-r)*(a1-r));
			if(d>r-0.5 && d<r+0.5)
			{
				cout<<"D";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<"  ";
		for(int a2=0; a2<=2*(r-1); a2++)
		{
			if(i==0||a2==0||a2==2*(r-1))
			{
				cout<<"A";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<"  ";
		for(int a3=0; a3<=r*0.7; a3++)
		{
			cout<<" ";
		}
		for(a3=r*0.4; a3>=r*0.4,a3<=2*r*0.5; a3++)
		{
			float d=sqrt((i-r*0.5)*(i-r*0.5)+(a3-r*0.5)*(a3-r*0.5));
			if(d>r*0.5-0.5 && d<r*0.5+0.5)
			{
				cout<<"S";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<" ";
		for(int a4=0; a4<=r*0.7; a4++)
		{
			cout<<" ";
		}
		for(a4=r*0.4; a4>=r*0.4,a4<=2*r*0.5; a4++)
		{
			float d=sqrt((i-r*0.5)*(i-r*0.5)+(a4-r*0.5)*(a4-r*0.5));
			if(d>r*0.5-0.5 && d<r*0.5+0.5)
			{
				cout<<"S";
			}
			else
			{
				cout<<" ";
			}
		}
	}
	cout<<"\n\n\t\t\t\t BOOK WORLD !!!\n";
	for(k=0; k<80; k++)
	cout<<"*";
	cout<<setw(79)<<"Press any Key to Begin...";
	getch();
 }
void SubGrandDisplay()                   //IDF 2
 {
	clrscr();
	cout<<" \t\t\t\tA Note from the Programmer\n";
	for(int i=0; i<80; i++)
	cout<<"*";
	cout<<"\t\tDASS BOOK WORLD:A Smart Library Management System!\n";
	cout<<"   A Library Management System is a collection of different entities - books,\n";
	cout<<"  librarian, accountant, customer, student or reader, etc. It is a centralized\n";
	cout<<" place where the informations related to different types of books can be found.\n";
	cout<<"  The project undertaken does the automation of the 'LIBRARY MANAGEMENT SYSTEM'\n";
	cout<<"  in the organization. It's built on the performance, reliability, quality and\n";
	cout<<"  ease of use. It also include a number of features that further eshtablish it\n";
	cout<<"  as a better GUI application. 'LIBRARY MANAGEMENT SYSTEM' is a system having\n";
	cout<<"   Menu Derived User Interface. It consists of three menus: Main Menu, Books'\n";
	cout<<"  Menu and Issue Menu. It contains the vital data and informations reguarding\n";
	cout<<"  book, issue and customer details. Administrator of the project can enter new\n";
	cout<<" book and issue details, display all/specific book and issue details and modify\n";
	cout<<" \t\t\t\tbook and issue details.\n";
	cout<<" The main reason of developing this software is to reduce the workload and to\n";
	cout<<"    provide the ease of use to accomplish the desired task along with better\n";
	cout<<" \t\t\tservice to the customers and society.\n";
	cout<<"     Any suggestions toward the further improvement of the system shall be\n";
	cout<<"\t\t\tgreatefully received and acknowledged.\n";
	for(i=0; i<80; i++)
	cout<<"*";
	cout<<" \t\t\t\tANIKET DAS\n";
	cout<<" \t\t\tStudent Programmer  (Class: XII)\n";
	cout<<"\t\t\tKendriya Vidyalaya, Chittaranjan\n";
	cout<<setw(79)<<"Press any Key to Continue...";
	getch();
 }
void Display()                           //IDF 3
 {
	clrscr();
	cout<<"\t\t\tDASS BOOK WORLD\n";
	cout<<"\tThe National Library of India; New Town, Kolkata: 700028\n";
	cout<<"\t\t   Software: Library Management System\n";
	for(int i=0; i<80; i++)
	cout<<"_";
	cout<<"\n";
 }
void SubDisplayB()                       //IDF 4
 {
	cout<<"--------|----------|--------------------|----------|-------------------|--------";
	cout<<" Sl.No. |  Number  |        Name        |   Price  |     Publisher     | Issued\n";
	cout<<"        |          |                    |   (Rs.)  |                   |  (Y/N)\n";
	cout<<"========|==========|====================|==========|===================|========";
 }
void SubDisplayI()                       //IDF 5
 {
	cout<<"-----|---------------------------------|----------|-----------------------------";
	cout<<" Sl. |          Customer Details       |   Book   |        Issue Details       \n";
	cout<<" No. |------------------|--------------|  Number  |---------|--------|----------";
	cout<<"     |       Name       | Phone Number |          | M- W- D | Charge | Returned\n";
	cout<<"     |                  |              |          |         |  (Rs.) |    (Y/N)\n";
	cout<<"=====|==================|==============|==========|=========|========|==========";
 }
void GrandEnding()                       //IDF 6
  {
	clrscr();
	int r=6;
	for(int i=0,j=r,k; i<=r,j>=r,j<=2*r; i++,j++)
	{
		cout<<endl;
		cout<<" ";
		for(int a1=0; a1<=2*r; a1++)
		{
			if(i==0||a1==r)
			{
				cout<<"T";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<" ";
		for(int a2=0; a2<=2*r; a2++)
		{
			if(a2==0)
			{
				cout<<"h";
			}
			else
			{
				cout<<" ";
			}
		}
		for(int a3=0; a3<=2*(r-1); a3++)
		{
			float d=sqrt((i-(r-1))*(i-(r-1))+(a3-(r-1))*(a3-(r-1)));
			if(d>(r-1)-0.5 && d<(r-1)+0.5)
			{
				cout<<"A";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<"  ";
		for(int a4=0; a4<=2*(r-1); a4++)
		{
			cout<<" ";
		}
		cout<<" ";
		cout<<"K";
		for(int a5=r; a5>=r,a5<=2*r; a5++)
		{
			float d=sqrt((j-r)*(j-r)+(a5-r)*(a5-r));
			if(d>r-0.5 && d<r+0.5)
			{
				cout<<"K";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<"   ";
		for(int a6=0; a6<=2*(r-1); a6++)
		{
			if(a6==0||a6==2*(r-1))
			{
				cout<<"U";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<" ";
	}
	for(i=0,j=r,k=r-2; i<=r,j<=2*r; i++,j++,k++)
	{
		cout<<endl;
		cout<<" ";
		for(int a1=0; a1<=2*r; a1++)
		{
			if(a1==r)
			{
				cout<<"T";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<" ";
		cout<<"h";
		for(int a2=0; a2<=2*(r-1); a2++)
		{
			float d=sqrt((i-(r-1))*(i-(r-1))+(a2-(r-1))*(a2-(r-1)));
			if(d>(r-1)-0.5 && d<(r-1)+0.5)
			{
				cout<<"h";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<" ";
		for(int a3=0; a3<=2*(r-1); a3++)
		{
			if(i==0||a3==0||a3==2*(r-1))
			{
				cout<<"A";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<" ";
		cout<<"n";
		for(int a4=0; a4<=2*(r-1); a4++)
		{
			float d=sqrt((i-(r-1))*(i-(r-1))+(a4-(r-1))*(a4-(r-1)));
			if(d>(r-1)-0.5 && d<(r-1)+0.5)
			{
				cout<<"n";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<" ";
		cout<<"K";
		for(int a5=r; a5>=r,a5<=2*r; a5++)
		{
			float d=sqrt((i-r)*(i-r)+(a5-r)*(a5-r));
			if(d>r-0.5 && d<r+0.5)
			{
				cout<<"K";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<"   ";
		for(int a6=0; a6<=2*(r-1); a6++)
		{
			float d=sqrt((k-(r-1))*(k-(r-1))+(a6-(r-1))*(a6-(r-1)));
			if(d>(r-1)-0.5 && d<(r-1)+0.5)
			{
				cout<<"U";
			}
			else
			{
				cout<<" ";
			}
		}
	}
	cout<<"***\n\n";
	cout<<"\t\tThAnK U... For visiting DASS BOOK WORLD !!!\n";
	cout<<"\t\t\t   Please, visit again.\n\n";
	for(int l=0; l<80; l++)
	cout<<"*";
	cout<<"\n";
	cout<<"\t\t\t Contact No.: 0341 2526089\n";
	cout<<"\t\t\tE-mail id: dassbw@gmail.com\n";
	cout<<"\t\t\t  Website: www.dassbw.org\n";
	cout<<setw(79)<<"Press any Key to Terminate...";
	getch();
 }

/************************************
 Member Functions for 'Book Details'
************************************/
void LIBRARY::Save(Book &book, int &slno)  //MFBD 1
 {
	fstream file("BOOK.TXT", ios::nocreate|ios::app|ios::binary);
	file.write((char *)&book, sizeof(Book));
	if(file)
	{
		cout<<"\nDetails of the book are saved in file.";
	}
	else
	{
		cout<<"\nDetails can't be saved since file is not created.";
		slno--;
	}
 }
void LIBRARY::Check(Book &book1, int bNo, int &slno)  //MFBD 2
 {
	int flag=0;
	Book book;
	fstream file("BOOK.TXT", ios::in|ios::binary);
	while(file.read((char *)&book, sizeof(Book)))
	{
		if(book.bookNo==bNo)
		{
			cout<<"\nInvalid book number, it already exists in library.";
			slno--;
			flag=1;
		}
	}
	if(flag==0)
	{
		Save(book1, slno);
	}
 }
void LIBRARY::Input(Book &book, int &slno)  //MFBD 3
 {
	Display();
	Book book1;
	fstream file("BOOK.TXT", ios::in|ios::binary);
	if(file)
	{
		while(file.read((char *)&book1, sizeof(Book)))
		{
			if(book1.slno>0)
			{
				slno=book1.slno;
			}
		}
	}
	slno++;
	book.slno=slno;
	strcpy(book.status, "No");
	cout<<"Fill up the given details of book:\n\n";
	cout<<"Serial Number:  "<<book.slno<<"\n\n";
	cout<<"Book Number: _____________________________________\n";
	cout<<"Book Name: _______________________________________\n";
	cout<<"Book Price: Rs._______________________________only\n";
	cout<<"Book Publisher: __________________________________\n";
	gotoxy(17,10);
	cin>>book.bookNo;
	gotoxy(17,11);
	gets(book.bookName);
	gotoxy(17,12);
	cin>>book.price;
	gotoxy(17,13);
	gets(book.publisher);
	Check(book, book.bookNo, slno);
	getch();
 }
void LIBRARY::Show(Book &book)  //MFBD 4
 {
	int i,l1,l2;
	l1=strlen(book.bookName);
	l2=strlen(book.publisher);
	cout<<setw(6)<<book.slno<<". |";
	cout<<setw(9)<<book.bookNo<<" |";
	if(l1>18)
	{
		cout<<setw(2);
		for(i=0; i<16; i++)
		{
			cout<<book.bookName[i];
		}
		cout<<".. |";
	}
	else
	{
		cout<<setw(19)<<book.bookName<<" |";
	}
	cout<<setw(9)<<setprecision(7)<<book.price<<" |";
	if(l2>17)
	{
		cout<<setw(2);
		for(i=0; i<15; i++)
		{
			cout<<book.publisher[i];
		}
		cout<<".. |";
	}
	else
	{
		cout<<setw(18)<<book.publisher<<" |";
	}
	cout<<setw(7)<<book.status<<"\n";
	cout<<"--------|----------|--------------------|----------|-------------------|--------";
 }
void LIBRARY::Showall(Book &book)  //MFBD 5
 {
	Display();
	fstream file("BOOK.TXT", ios::in|ios::binary);
	if(file)
	{
		cout<<"Details of the books in library are as follows:\n\n";
		SubDisplayB();
		while(file.read((char *)&book, sizeof(Book)))
		{
			Show(book);
		}
	}
	else
	{
		cout<<"Details can't be shown since file is not created.";
	}
	getch();
 }
void LIBRARY::Search(Book &book, int bNo)  //MFBD 6
 {
	int flag=0;
	fstream file("BOOK.TXT", ios::in|ios::binary);
	if(file)
	{
		while(file.read((char *)&book, sizeof(Book)))
		{
			if(book.bookNo==bNo)
			{
				cout<<"\nDetails of the required book are as follows:\n\n";
				SubDisplayB();
				Show(book);
				flag=1;
			}
		}
		if(flag==0)
		{
			cout<<"\nRequired book is not found in file.";
		}
	}
	else
	{
		cout<<"\nDetails can't be searched since file is not created.";
	}
	getch();
 }
void LIBRARY::Update(Book &book, int bNo)  //MFBD 7
 {
	int pos=0,flag=0;
	fstream file("BOOK.TXT", ios::in|ios::out|ios::binary);
	if(file)
	{
		while(file.read((char *)&book, sizeof(Book)))
		{
			if(book.bookNo==bNo)
			{
				if(book.status[0]=='N')
				{
					cout<<"\nSaved details of the required book are as follows:\n\n";
					SubDisplayB();
					Show(book);
					cout<<"\nUpdate new details of the required book:\n";
					cout<<"Fill up the given details of book:\n\n";
					cout<<"Serial Number:  "<<book.slno<<"\n\n";
					cout<<"Book Number: _____________________________________\n";
					cout<<"Book Name: _______________________________________\n";
					cout<<"Book Price: Rs._______________________________only\n";
					cout<<"Book Publisher: __________________________________\n";
					gotoxy(17,21);
					cin>>book.bookNo;
					gotoxy(17,22);
					gets(book.bookName);
					gotoxy(17,23);
					cin>>book.price;
					gotoxy(17,24);
					gets(book.publisher);
					file.seekp(pos*sizeof(Book));
					file.write((char *)&book, sizeof(Book));
					cout<<"\nUpdated details of the book are saved in file.";
					flag=1;
				}
				else
				{
				cout<<"\nDetails can't be updated since the book is issued.";
				flag=1;
				}
			}
			pos++;
		}
		if(flag==0)
		{
			cout<<"\nRequired book is not found in file.";
		}
	}
	else
	{
		cout<<"\nDetails can't be updated since file is not created.";
	}
	getch();
 }

/*************************************
 Member Functions for 'Issue Details'
*************************************/
int LIBRARY::CalChargeI(int noM, int noW, int noD, float price)  //MFID 1
 {
	float charge;
	charge=((noM*30+noW*7+noD)*(price/500));
	return (charge);
 }
void LIBRARY::SaveI(Issue &issue, int bNo, int &slnoi)  //MFID 2
 {
	int pos=0;
	Book book;
	fstream file("ISSUE.TXT", ios::nocreate|ios::app|ios::binary);
	fstream file1("BOOK.TXT", ios::in|ios::out|ios::binary);
	if(file1)
	{
		while(file1.read((char *)&book, sizeof(Book)))
		{
			if(book.bookNo==bNo)
			{
				strcpy(book.status, "Yes");
				issue.charge=CalChargeI(issue.noMonth, issue.noWeek, issue.noDay, book.price);
				file.write((char *)&issue, sizeof(Issue));
				file1.seekp(pos*sizeof(Book));
				file1.write((char *)&book, sizeof(Book));
			}
			pos++;
		}
	}
	else
	{
		cout<<"\nBook can't be issued since file is not created.";
		slnoi--;
	}
	if(file)
	{
		cout<<"\nDetails of the issue are saved in file.";
		cout<<"\nTotal money charged for the issue is Rs. "<<issue.charge<<" only.";
	}
	else
	{
		cout<<"\nBook can't be issued since file is not created.";
		slnoi--;
	}
 }
void LIBRARY::CheckI(Issue &issue1, int bNo, int &slnoi)  //MFID 3
 {
	int flag=0;
	Issue issue;
	fstream file("ISSUE.TXT", ios::in|ios::binary);
	while(file.read((char *)&issue, sizeof(Issue)))
	{
		if(issue.bookNo==bNo && issue.status[0]=='N')
		{
			cout<<"\nInvalid book number, it is already issued.";
			slnoi--;
			flag=1;
		}
	}
	if(flag==0)
	{
		SaveI(issue1, bNo, slnoi);
	}
 }
void LIBRARY::IssueI(Issue &issue, int &slnoi)  //MFID 4
 {
	IssueI:
	Display();
	int flag=0;
	char choice;
	Issue issue1;
	Book book;
	fstream file("ISSUE.TXT", ios::in|ios::binary);
	fstream file1("BOOK.TXT", ios::in|ios::binary);
	if(file)
	{
		while(file.read((char *)&issue1, sizeof(Issue)))
		{
			if(issue1.slno>0)
			{
				slnoi=issue1.slno;
			}
		}
	}
	slnoi++;
	issue.slno=slnoi;
	strcpy(issue.status, "No");
	cout<<"Fill up the given details of issue:\n\n";
	cout<<"Serial Number: "<<issue.slno<<"\n\n";
	cout<<"Custimer Details:\n";
	cout<<"Customer Name: ___________________________________\n";
	cout<<"Phone Number: ____________________________________\n\n";
	cout<<"Book Number: _____________________________________\n\n";
	cout<<"Issue Details:\n";
	cout<<"No. of Months: ___________________________month(s)\n";
	cout<<"No. of Weeks: _____________________________week(s)\n";
	cout<<"No. of Days: _______________________________day(s)\n";
	gotoxy(16,11);
	gets(issue.name);
	gotoxy(16,12);
	gets(issue.phNo);
	gotoxy(16,14);
	cin>>issue.bookNo;
	gotoxy(16,17);
	cin>>issue.noMonth;
	gotoxy(16,18);
	cin>>issue.noWeek;
	gotoxy(16,19);
	cin>>issue.noDay;
	if(file1)
	{
		while(file1.read((char *)&book, sizeof(Book)))
		{
			if(book.bookNo==issue.bookNo)
			{
				cout<<"\nHave a final verification of the book to be issued.";
				cout<<"\nIf satisfied press 'Y' else press 'N'.";
				cout<<"\n\nDetails of the required book are as follows:\n\n";
				SubDisplayB();
				Show(book);
				cout<<"\nTotal Money Charged = {(0.2% of Price)x(No. of Days)}\n";
				cout<<"                    = {(0.2% of Rs."<<book.price<<")x(";
				cout<<30*issue.noMonth<<"+"<<7*issue.noWeek<<"+"<<issue.noDay<<")}\n";
				cout<<"                    = Rs. ";
				cout<<CalChargeI(issue.noMonth, issue.noWeek, issue.noDay, book.price)<<" only\n";
				cout<<"Enter choice: ";
				cin>>choice;
				if(choice=='Y'||choice=='y')
				{
					CheckI(issue, issue.bookNo, slnoi);
					flag=1;
				}
				else
				{
					slnoi--;
					goto IssueI;
				}
			}
		}
		if(flag==0)
		{
			cout<<"\nInvalid book number, book does not exist in library.";
			slnoi--;
		}
	}
	else
	{
		cout<<"\nBook can't be issued since file is not created.";
		slnoi--;
	}
	getch();
 }
void LIBRARY::ShowI(Issue &issue)  //MFID 5
 {
	int i,l;
	l=strlen(issue.name);
	cout<<setw(3)<<issue.slno<<". |";
	if(l>16)
	{
		cout<<setw(2);
		for(i=0; i<14; i++)
		{
			cout<<issue.name[i];
		}
		cout<<".. |";
	}
	else
	{
		cout<<setw(17)<<issue.name<<" |";
	}
	cout<<setw(13)<<issue.phNo<<" |";
	cout<<setw(9)<<issue.bookNo<<" |";
	cout<<setw(2)<<issue.noMonth<<"-"<<setw(2)<<issue.noWeek<<"-"<<setw(2)<<issue.noDay<<" |";
	cout<<setw(7)<<setprecision(5)<<issue.charge<<" |";
	cout<<setw(9)<<issue.status<<"\n";
	cout<<"-----|------------------|--------------|----------|---------|--------|----------";
 }
void LIBRARY::ShowallI(Issue &issue)  //MFID 6
 {
	Display();
	fstream file("ISSUE.TXT", ios::in|ios::binary);
	if(file)
	{
		cout<<"Details of the issues in library are as follows:\n\n";
		SubDisplayI();
		while(file.read((char *)&issue, sizeof(Issue)))
		{
			ShowI(issue);
		}
	}
	else
	{
		cout<<"Details can't be shown since file is not created.";
	}
	getch();
 }
void LIBRARY::SearchI(Issue &issue, int bNo)  //MFID 7
 {
	int flag=0;
	fstream file("ISSUE.TXT", ios::in|ios::binary);
	if(file)
	{
		while(file.read((char *)&issue, sizeof(Issue)))
		{
			if(issue.bookNo==bNo)
			{
				cout<<"\nDetails of the required book are as follows:\n\n";
				SubDisplayI();
				ShowI(issue);
				flag=1;
			}
		}
		if(flag==0)
		{
			cout<<"\nRequired book is not found in file.";
		}
	}
	else
	{
		cout<<"\nDetails can't be searched since file is not created.";
	}
	getch();
 }
void LIBRARY::ReturnI(Issue &issue, int bNo)  //MFID 8
 {
	int pos=0,pos1=0,flag=0,flag1=0;
	Book book;
	fstream file("ISSUE.TXT", ios::in|ios::out|ios::binary);
	fstream file1("BOOK.TXT", ios::in|ios::out|ios::binary);
	if(file && file1)
	{
		while(file1.read((char *)&book, sizeof(Book)))
		{
			if(book.bookNo==bNo)
			{
				strcpy(book.status, "No");
				file1.seekp(pos1*sizeof(Book));
				file1.write((char *)&book, sizeof(Book));
				flag1=1;
			}
			pos1++;
		}
		while(file.read((char *)&issue, sizeof(Issue)))
		{
			if(issue.bookNo==bNo)
			{
				strcpy(issue.status, "Yes");
				file.seekp(pos*sizeof(Issue));
				file.write((char *)&issue, sizeof(Issue));
				flag=1;
			}
			pos++;
		}
		if(flag==0 && flag1==0)
		{
			cout<<"\nRequired book is not found in file.";
		}
		else
		{
			cout<<"\nThe book is returned.";
		}
	}
	else
	{
		cout<<"\nDetails can't be updated since file is not created.";
	}
	getch();
 }

/**********************************
 Individual Menu Functions
**********************************/
//Menu Functions for 'Main Menu'
int menuM()                              //IMF M
 {
	Display();
	int choice;
	cout<<"Main Menu:\n\n";
	cout<<" 1. Goto Books' Menu\n";
	cout<<" 2. Goto Issue Menu\n";
	cout<<" 3. Exit\n\n";
	cout<<"Enter choice: ";
	cin>>choice;
	return(choice);
 }
//Menu Functions for 'Books' Menu'
int menuB()                              //IMF B
 {
	Display();
	int choice;
	cout<<"Books' Menu:\n\n";
	cout<<" 1. Create files\n";
	cout<<" 2. Input a book's details\n";
	cout<<" 3. Show all books' details\n";
	cout<<" 4. Search a book's details\n";
	cout<<" 5. Update a book's details\n";
	cout<<" 6. Delete files\n";
	cout<<" 7. Goto Main Menu\n";
	cout<<" 8. Exit\n\n";
	cout<<"Enter choice: ";
	cin>>choice;
	return(choice);
 }
//Menu Functions for 'Issue Menu'
int menuI()                              //IMF I
 {
	Display();
	int choice;
	cout<<"Issue Menu:\n\n";
	cout<<" 1. Issue a book\n";
	cout<<" 2. Show all books' details\n";
	cout<<" 3. Search a book's details\n";
	cout<<" 4. Show all issues' details\n";
	cout<<" 5. Search an issue's details\n";
	cout<<" 6. Return a book\n";
	cout<<" 7. Goto Main Menu\n";
	cout<<" 8. Exit\n\n";
	cout<<"Enter choice: ";
	cin>>choice;
	return(choice);
 }

/**********************************
 Main Function
**********************************/
void main()
 {
	int bNo,slno,slnoi;
	char choice;
	LIBRARY B;
	GrandDisplay();
	SubGrandDisplay();
	menuM:
	while(1)
	{
		switch(menuM())                    //Calling IMF M
		{
			case 1:
			while(1)
			{
				switch(menuB())              //Calling IMF B
				{
					case 1:
					Display();
					cout<<"The informations in the existing files will be lost!\n";
					cout<<"Do you really want to create new files?(Y/N)\n\n";
					cout<<"Enter Choice: ";
					cin>>choice;
					if(choice=='Y'||choice=='y')
					{
						cout<<"\nFiles named \"BOOK.TXT\" and \"ISSUE.TXT\" are created.";
						ofstream ("BOOK.TXT");
						ofstream ("ISSUE.TXT");
						slno=0,slnoi=0;
						getch();
					}
					break;
					case 2:
					B.Input(B.book,slno);     //Calling MFBD 3
					break;
					case 3:
					B.Showall(B.book);        //Calling MFBD 5
					break;
					case 4:
					Display();
					cout<<"Enter the book number to be searched: ";
					cin>>bNo;
					B.Search(B.book,bNo);     //Calling MFBD 6
					break;
					case 5:
					Display();
					cout<<"Enter the book number to be updated: ";
					cin>>bNo;
					B.Update(B.book,bNo);     //Calling MFBD 7
					break;
					case 6:
					Display();
					cout<<"The informations in the existing files will be lost!\n";
					cout<<"Do you really want to delete these files?(Y/N)\n\n";
					cout<<"Enter Choice: ";
					cin>>choice;
					if(choice=='Y'||choice=='y')
					{
						cout<<"Files named \"BOOK.TXT\" and \"ISSUE.TXT\" are deleted.";
						remove ("BOOK.TXT");
						remove ("ISSUE.TXT");
						getch();
					}
					break;
					case 7:
					goto menuM;
					case 8:
					Display();
					cout<<"Thank You, for using Library Management System!";
					getch();
					GrandEnding();
					return;
					default:
					cout<<"\nEntered choice is invalid.";
					getch();
				}
			}
			case 2:
			while(1)
			{
				switch(menuI())              //Calling IMF I
				{
					case 1:
					B.IssueI(B.issue,slnoi);  //Calling MFID 4
					break;
					case 2:
					B.Showall(B.book);        //Calling MFBD 5
					break;
					case 3:
					Display();
					cout<<"Enter the book number to be searched: ";
					cin>>bNo;
					B.Search(B.book,bNo);     //Calling MFBD 6
					break;
					case 4:
					B.ShowallI(B.issue);      //Calling MFID 6
					break;
					case 5:
					Display();
					cout<<"Enter the book number to be searched: ";
					cin>>bNo;
					B.SearchI(B.issue,bNo);   //Calling MFID 7
					break;
					case 6:
					Display();
					cout<<"Enter the book number to be returned: ";
					cin>>bNo;
					B.ReturnI(B.issue,bNo);   //Calling MFID 8
					break;
					case 7:
					goto menuM;
					case 8:
					Display();
					cout<<"Thank You, for using Library Management System!";
               getch();
					GrandEnding();
					return;
					default:
					cout<<"\nEntered choice is invalid.";
					getch();
				}
			}
			case 3:
			Display();
			cout<<"Thank You, for using Library Management System!";
			getch();
			GrandEnding();
			return;
			default:
			cout<<"\nEntered choice is invalid.";
			getch();
		}
	}
 }

/**********************************
				 THE END
				THANK YOU
**********************************/

