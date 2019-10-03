#include <deque>
#include <vector>
#include <cstdio>
#include <string>
#include <time.h>
#include<stdio.h>
#include <conio.h>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <windows.h>

using namespace std;

fstream myfile;
void usermode();
void mainmenu();
char filename [100];
typedef string treeType;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int redtext(){SetConsoleTextAttribute(hConsole, 4);};
int greentext(){SetConsoleTextAttribute(hConsole, 2);};
int whitetext(){SetConsoleTextAttribute(hConsole, 15);};
int bluetext (){SetConsoleTextAttribute(hConsole, 11);};

typedef struct node
{
    int seat_no, pin;
    char row_no, book;
    struct node *next,*prev;
}node;

class seat
{
    public:
        node *hn;
        seat(){hn = NULL;}

    void create()
    {
        int j = 1;
        char c = 'A';
        node *nn,*cn;
        volatile int k = 2;

        do{
            int i=1;
        do{
            k = (k*k)/10+100-k/2;
            nn = new node();
            nn -> next = nn -> prev = NULL;
            nn -> row_no = c;
            nn -> seat_no = i;
            nn -> pin = k;
            nn -> book = 'a';
        if(hn == NULL){
            hn = nn;
            nn -> next = nn -> prev = hn;
        }else{
            cn = hn;
            while(cn -> next != hn)
                cn = cn -> next;
                cn -> next = nn;
                nn -> prev = cn;
                nn -> next = hn;
                hn -> prev = nn;
                }
            i++;
                }while(i <= 7);
            j++;
            c++;
            }while(j <= 10);
    }

    void display()
    {
        node *cn;
        cn = hn;
        cout << "-----------------------------------------------------------------\n";
        cout << "|                         First Class                            |\n";
        while(cn -> next != hn){
            if((cn -> prev) -> row_no != cn -> row_no)
                cout << "| ";
                cout << cn -> row_no;
                cout << cn -> seat_no;
            if(cn -> book == 'a')
                cout << " -> a  ";  //green text with black background
            else
                cout << " -> b  ";  //red text
            if((cn -> next)-> row_no != cn -> row_no)
                cout<<"|\n";
            if(cn->row_no == 'C' && cn -> seat_no == 7 )
                {
                    cout<<"-----------------------------------------------------------------\n";
                    cout<<"|                         Second Class                           |\n";
                }if(cn -> row_no == 'H' && cn -> seat_no == 7 )
                    {
                        cout << "-----------------------------------------------------------------\n";
                        cout << "|                         Third Class                            |\n";
                    }
                    cn = cn -> next;
                    }
                    cout << cn -> row_no;
                    cout << cn -> seat_no;
                    if(cn -> book == 'a')
                        cout << " -> a  ";  //green text with black background
                    else
                        cout << " -> b  ";  //red text
                        cout<<"|\n";
                        cout<<"------------------------------------------------------------------\n\n";
                        cout<<"First Class -> 150       Second Class -> 100        Third Class ->60\n";
    }

    void display1(node *tmp[20], int n)
    {
        if(n != 1)
            {
                system("cls");
                cout<<"------------------------------------------------------------------\n";
                cout<<"THANK YOU!\nYOU HAVE SUCCESFULLY BOOKED THE SEATS\n" << endl;
                for(int i = 1; i < n; i++)
                    cout << tmp[i] -> row_no << tmp[i] -> seat_no << "    PIN : " << tmp[i] -> pin << "\n" << endl;
                    cout << "!!!!!!!!!!!!!!!!!!KEEP PIN SAFELY!!!!!!!!!!!!!!!!!!!\n";
                    cout << "PINS ARE REQUIRED AT THE TIME OF CANCELATION OF SEATS\n";
                    cout << "------------------------------------------------------------------\n";
                    system("pause");
                    system("cls");
            }
    }

    void book_seat()
    {

        char ch, row;
        node *cn,*temp[20];
        int n, z = 1, flag, seat;

        cout << "\nEnter Seat Number: \n";
        cin >> row >> seat;
        cn = hn;
        if(row >= 'A' && row <= 'E'){
            while(cn -> next != hn){
                if(cn -> row_no == row && cn -> seat_no == seat){
                    if(cn -> book == 'a'){
                        cn -> book = 'b';
                        temp[z] = cn;
                        z++;
                        }else{
                            cout << "INVALID CHOICE!\n";
                            cout << cn -> row_no << cn -> seat_no << " Seat is already reserved \n";
                            }
                            }
                            cn = cn -> next;
                            }if(cn -> row_no == row && cn -> seat_no == seat){
                                if(cn -> book == 'a'){
                                        cn -> book = 'b';
                                        temp[z] = cn;
                                        z++;
                                }else{
                                    cout << "INVALID CHOICE!\n";
                                    cout << cn -> row_no << cn -> seat_no << " Seat is already reserved\n";
                                    }
                                    }
                                    }else {
                                        while(cn -> prev != hn){
                                                if(cn -> row_no == row && cn -> seat_no == seat){
                                                        if(cn -> book == 'a'){
                                                            cn -> book = 'b';
                                                            temp[z] = cn;
                                                            z++;
                                                }else{
                                                    cout << "INVALID CHOICE!\n";
                                                    cout << cn -> row_no << cn-> seat_no << " Seat is already reserved \n";
                                                    }
                                                    }
                                                    cn = cn -> prev;
                                                    }
                                                    if(cn -> row_no == row && cn -> seat_no == seat){
                                                            if(cn -> book == 'a'){
                                                                cn -> book = 'b';
                                                                temp[z] = cn;
                                                                z++;
                                                    }else{
                                                        cout << "INVALID CHOICE!\n";
                                                        cout << cn -> row_no << cn -> seat_no << " Seat is already reserved\n";
                                                        }
                                                        }
                                                        }
                                                        display1(temp,z);
                                                        display();
                                                        system("pause");
    }


    };

class Person
{
    private:
        string First_Name =("*****");    //Strings have default values so that the form can
        string Last_Name =("*****"); //be displayed with incomplete fields.
        string Departure =("*****");
        string Destination =("*****");
        string IC =("00");
        int Date =(00);
        int Month =(00);
        int Year =(00);
        string Time =("00:00");
        int membershipSelection;
        string memberNotes=("*****");


    public:
        Person();
        char saveYN;
        int getDate(), getMonth(), getYear();
        string getFirst_Name(), getLast_Name(), getIC(), getDeparture(), getDestination(), getTime(), getmemberNotes();
        Person(string First_Name, string Last_Name,string Departure,string Destination,string IC, int Date, int Month,int Year, string Time, string memberNotes);

        void modify();
        void savefile();
        void deleteticket();
        void setFirst_Name(string newFirst_Name);
        void setIC(string newIC);
        void setLast_Name(string newLast_Name);
        void setDeparture(string newDeparture);
        void setDestination(string newDestination);
        void setmemberNotes(string newmemberNotes);
        void setTime(string newTime);
        void setDate(int newDate);
        void setMonth(int newMonth);
        void setYear(int newYear);

        void sorting ()
        {   // Open your text file
            ifstream file("file.txt");
            vector<string> rows;

            // Read all the lines and add them to the rows vector
            while(!file.eof())
            {
                string line;
                getline(file, line);
                rows.push_back(line);
            }

            // Sort the vector
            sort(rows.begin(), rows.end());

            // Print out all of the vectors values
            cout << "\t-------------------------------------------------------------------------\n" ;
            cout<<"\t|Train ID\tDeparture\tDestination\t    Time\tDuration|\n";
            cout << "\t-------------------------------------------------------------------------\n" ;

            vector<string>::iterator iterator = rows.begin();

            for(; iterator != rows.end(); ++iterator){

            cout << "\t|"<< *iterator << "  |"<<endl;
            }
            cout << "\t-------------------------------------------------------------------------\n" ;
            getchar();
            }

        void memberdetails()
        {
            seat s;
            system("cls");

            memberform();
            cout << "\tPlease enter customer first name: ";
            cin >> ws;
            getline (cin, First_Name);

            memberform();
            cout << "\tPlease enter customer surname: ";
            cin >> Last_Name;

            memberform();
            cout << "\tPlease enter IC: ";
            cin >> IC;

            memberform();
            cout << "\tPlease enter Ticket Date(DD): ";
            cin >> Date;
            while (cin.fail() || Date > 31 || Date < 1)
            {
                    cin.clear(); cin.ignore();
                    cout << "\n\tPlease enter a valid date (1-31): ";
                    cin >> Date;
            };

            memberform();
            cout << "\tPlease enter Ticket Month(MM): ";
            cin >> Month;
            while (cin.fail() || Month > 12 || Month < 1)
            {
                cin.clear(); cin.ignore();
                cout << "\n\tPlease enter a valid month (1-12): ";
                cin >> Month;
            }

            memberform();
            cout << "\tPlease enter Ticket Year(YY): ";
            cin >> Year;
            while (cin.fail() || Year > 99 || Year < 1)
            {
                cin.clear(); cin.ignore();
                cout << "\n\tPlease enter a valid Year (1-99): ";
                cin >> Year;
            }

            memberform();
            cout << "\tPlease enter time of the ticket: ";
            cin >> Time;

            memberform();
            cout << "\tPlease enter customers current location: ";
            cin >> ws;
            getline (cin,Departure);

            memberform();
            cout << "\tPlease enter customer desired location: ";
            cin >> ws;
            getline (cin,Destination);

            memberform();
            cout << "\tPlease enter any additional notes:\n\t";
            cin.ignore();
            getline (cin, memberNotes);

            memberform();
            cout << "\tSave these details to a file? <Y/N> ";
            cin >> saveYN;
            if (saveYN == 'y' || saveYN == 'Y')
            {
                savefile();
                system("cls");

            }
            usermode();
        }

        void memberform()
        {
            system ("cls");
            bluetext();
            cout << "\t\t\t      Book a ticket\n";
            whitetext();
            cout << "\t________________________________________________________________\n\n";
            cout << "\tBooking Form   \t";
            cout << "\t     Full name :  ";
            if (First_Name != "*****"){greentext();};   // If the field is not the default
            cout << First_Name << " ";                  // value use green text, then
            whitetext();                          // revert back to white text.
            if (Last_Name != "*****"){greentext();};
            cout << Last_Name << "\n";
            whitetext();
            cout << "\t\t\t\t\t    IC :  ";
            if (IC != "00"){greentext();};
            cout << IC <<" ";
            whitetext();
            cout << "\n\t\t\t\t          Date :  ";
            if (Date != 00){greentext();};
            cout << Date << "/";
            whitetext();
            if (Month != 00){greentext();};
            cout << Month << "/";
            whitetext();
            if (Year != 00){greentext();};
            cout << Year;
            whitetext();
            cout << "\n\t\t\t\t\t  Time :  ";
            if (Time != "00:00"){greentext();};
            cout << Time << "\n";
            whitetext();
            cout << "\t________________________________________________________________\n\n";
            cout << "\t\t\t           Your Destination!   \n";
            cout << "\n\t\t\t\t\t  From :  ";
            if (Departure != "*****"){greentext();};
            cout << Departure << " ";
            whitetext();
            cout << "\n\t\t\t\t\t    To :  ";
            if (Destination != "*****"){greentext();};
            cout << Destination << " ";
            whitetext();
            cout << "\n\n\tNotes: ";
            if (memberNotes != "*****"){greentext();};
            cout << memberNotes;
            whitetext();
            cout << "\n\t________________________________________________________________\n\n";
            cout << "\n";
        }

        void password()
        {    string pass;
            int passCount = 0;
            system("cls");

            cout << "\n\n\n\t\t\t\t******************\n";
            cout <<       "\t\t\t\t**Enter Password**\n";
            cout <<       "\t\t\t\t******************\n";
            cout <<       "\n\n\t\t\t\t>";
            cin  >> pass;                   //Promps user for password

            while (pass != "password")
                {
                    passCount ++;
                    redtext();
                    cout << "\t\t\t\tPassword Incorrect!\n";

                    if (passCount >= 3)                         //Three failed attemps exits program
                    {
                        redtext();
                        cout << "\n\t\t\t\tLOGIN FAILED!";
                        whitetext();
                        exit(0);
                    };

                    whitetext();
                    cout << "\t\t\t\tTry Again:\n\t\t\t\t>";
                    cin >> pass;
                };
            greentext();
            cout << "\n\t\t\t\tPassword Accepted!\n\t\t\t\tPress any key to continue...";
            whitetext();
            cin.ignore();
            cin.get();
            admin();



        }

        void admin()
        {
            int c;


            system("cls");
            cout << "\n              ------------------------------------";
            cout << "\n              High-Speed Train Reservation System ";
            cout << "\n                          Admin Mode               ";
            cout << "\n              ------------------------------------" << endl << endl;
            cout << "              ====================================\n";
            cout << "              |    [1]   Sort File (Train ID)    |\n";
            cout << "              |    [2]   Back                    |\n";
            cout << "              ====================================\n\n";
            cout << "\n\t\tSelect an option: ";
            cin >> c;
            switch(c)
            {
                case 1: system("cls");
                        sorting();
                        system("pause");
                        admin();

                    break;
                case 2: system("cls");
                        mainmenu();

                    break;
                default: getch();
                         cout << "\n\t\t\tInvalid Option ! Enter again.";
                         getch();
                         system("cls");
                         admin();
            }
            getch();

        }

};

Person MMU;
void Person::deleteticket()
{
    int status;
    system("cls");
	cout << "Enter IC: ";
	cin.ignore();
	gets(filename);
	status = remove(filename);
	if(status == 0)
	{
		cout << "File " << filename << " deleted successfully !\n";
	}else{
	    cout << "\nUnable to delete file " << filename << "\n";
		perror("Error Message ");
		}
	getch();
}

void Person::modify()
{
    ifstream myfile(filename);
    cout << "\n\n     Please type your IC you\n";
    cout << "     wish to modify OR\n";
    cout << "     type z (Lower case) to return to main menu: ";
    cin.ignore();
    gets (filename);
    if (filename[0]  != 'z')
    {
        while(!filename)
            {
            cout << "Member does not exist\n";
            gets (filename);
            }
        remove(filename);
        memberdetails();
    }
    usermode();
}

void Person::savefile()
{
    string saveFileName;
    stringstream out;
    out << IC << " " ;
    saveFileName = out.str();
    ofstream myfile;                                  //Save file structure
    myfile.open (saveFileName.c_str(), ios::out);
    myfile << "\n"<< First_Name << "\n";
    myfile << Last_Name << "\n";
    myfile << Departure << "\n";
    myfile << Destination << "\n";
    myfile << IC << "\n";
    myfile << Date << "\n";
    myfile << Month << "\n";
    myfile << Year << "\n";
    myfile << Time << "\n";
    myfile << memberNotes << "\n";
    myfile.close();
    memberform();
    greentext();
    cout << "\tDetails have been saved\n\n\t";
    whitetext();
    system ("pause");
}

class BinarySearchTree
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           //treeType data;
           Person data;
        };
        tree_node* root;

    public:
        BinarySearchTree()
        {
           root = NULL;
        }
        bool isEmpty() const { return root==NULL; }
        void insert(Person);
        void search(string key);
};

Person::Person(){}
Person::Person(string newFirst_Name, string newLast_Name, string newIC, string newDeparture, string newDestination, int newDate, int newMonth, int newYear, string newTime, string newmemberNotes)
{
    First_Name = newFirst_Name;
    Last_Name = newLast_Name;
    IC = newIC;
    Departure = newDeparture;
    Destination = Destination;
    Date = newDate;
    Month = newMonth;
    Year = newYear;
    Time = newTime;
    memberNotes = newmemberNotes;
}

string Person::getFirst_Name() {return First_Name;}
string Person::getLast_Name() {return Last_Name;}
string Person::getIC() {return IC;}
string Person::getDeparture() {return Departure;}
string Person::getDestination() {return Destination;}
int Person::getDate() {return Date;}
int Person::getMonth() {return Month;}
int Person::getYear() {return Year;}
string Person::getTime() {return  Time;}
string Person::getmemberNotes() {return memberNotes;}

void Person::setFirst_Name(string newFirst_Name) {First_Name = newFirst_Name;}
void Person::setLast_Name(string newLast_Name) {Last_Name = newLast_Name;}
void Person::setIC(string newIC) {IC = newIC;}
void Person::setDeparture(string newDeparture) {Departure = newDeparture;}
void Person::setDestination(string newDestination) {Destination = newDestination;}
void Person::setDate(int newDate) {Date = newDate;}
void Person::setMonth(int newMonth) {Month = newMonth;}
void Person::setYear(int newYear) {Year = newYear;}
void Person::setTime(string newTime) {Time = newTime;}
void Person::setmemberNotes(string newmemberNotes) {memberNotes = newmemberNotes;}


void BinarySearchTree::insert(Person p)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t -> data = p;
    t -> left = NULL;
    t -> right = NULL;
    parent = NULL;
    // is this a new tree?
    if(isEmpty()) root = t;
    else
    {
        //Note: ALL insertions are as leaf nodes
        tree_node* curr;
        curr = root;
        // Find the Node's parent
        while(curr)
        {
            parent = curr;
            if(t -> data.getFirst_Name() > curr -> data.getFirst_Name()) curr = curr -> right;
            else curr = curr->left;
        }
        if(t -> data.getFirst_Name() < parent -> data.getFirst_Name())
           parent -> left = t;
        else
           parent -> right = t;
    }
}



void BinarySearchTree::search(string key)
{
    bool found = false;
    if(isEmpty())
    {
        cout << "\t\tData Not Found! " << endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
         if(curr -> data.getFirst_Name() == key)
         {
            found = true;
            system("cls");
            cout << "\t\tFirst name: " << curr -> data.getFirst_Name() << endl;
            cout << "\t\tLast name: " << curr -> data.getLast_Name() << endl;
            cout << "\t\tIC number: " << curr -> data.getDestination() << endl;
            cout << "\t\tDepart location: " << curr -> data.getIC() << endl;
            cout << "\t\tDestination: " << curr -> data.getDeparture() << endl;
            cout << "\t\tDate: " << curr -> data.getDate() << "/" << curr -> data.getMonth() << "/" << curr -> data.getMonth() << endl;
            cout << "\t\tTime: " << curr -> data.getTime() << endl;
            system("pause");
            usermode();
            break;
         }
         else
         {
             parent = curr;
             if(key > curr -> data.getFirst_Name())
                curr = curr-> right;
             else
             curr = curr->left;
         }
    }
    if(!found)
    {
        cout << "Data not found! "<<endl;
        return;
    }
}

void fillTree( BinarySearchTree *b)
{
    int Date, Month, Year;
    string First_Name, Last_Name, IC, Departure, Destination, Time, membershipType, memberNotes;
    ifstream myfile(filename);
    cout<<"\t\tEnter IC : ";
    cin.ignore();
    gets (filename);
    myfile.open(filename,ios::in);

    if(!myfile) {
            cout << endl << "\t\tError opening file. " << endl << endl;
            system("Pause");
            usermode();
    }

    while(myfile >> First_Name >> Last_Name >> IC >> Departure >> Destination  >> Date >> Month >> Year >> Time >> memberNotes)
    {
        MMU.setFirst_Name(First_Name);
        MMU.setLast_Name(Last_Name);
        MMU.setIC(IC);
        MMU.setDeparture(Departure);
        MMU.setDestination(Destination);
        MMU.setDate(Date);
        MMU.setMonth(Month);
        MMU.setYear(Year);
        MMU.setTime(Time);
        MMU.setmemberNotes(memberNotes);

        (*b).insert(MMU);
    }
    myfile.close();
}

void usermode()
{
    seat s;
    int opt;
    string key;
    Person user;
    BinarySearchTree b;

    s.create();
    system("cls");
	cout << "\n              ------------------------------------";
	cout << "\n              High-Speed Train Reservation System ";
	cout << "\n                          User Mode               ";
	cout << "\n              ------------------------------------" << endl << endl;
	cout << "              ====================================\n";
	cout << "              |    [1]  Book Ticket              |\n";
	cout << "              |    [2]  Search Ticket            |\n";
	cout << "              |    [3]  Cancel Ticket            |\n";
	cout << "              |    [4]  Modify Ticket            |\n";
    cout << "              |    [5]  Main Menu                |\n";
	cout << "              ====================================\n\n";
	cout << "\n\t\tSelect an option: ";
	cin >> opt;
	if (opt > 5 || opt < 1){
        cout << endl << endl;
        cout << setw(27) << "\n            Invalid !!! Please enter again ! ";
        getch();
        system("cls");

	}else{
	switch(opt)
	{
		case 1: s.create();
                s.display();
                s.book_seat();
                user.memberdetails();
                break;

        case 2: fillTree(&b);
                cout << "\t\tEnter name : ";
                cin >> key;
                b.search(key);
				break;

        case 3: system("cls");
                user.deleteticket();
                break;

        case 4: user.modify();
                break;

        default: system("cls");
                 mainmenu();

}
	}
}
void mainmenu()
{
    int mode;
    time_t currentTime;

    Person admin;
	time(&currentTime);

    system ("title High-Speed Train Reservation System");
	cout << "\n\t\t   " << ctime(&currentTime);

    cout << "    ----------------------------------------------------" << endl;
	cout << "    Welcome to the High-Speed Train Reservation System !" << endl;
	cout << "    ----------------------------------------------------" << endl << endl;
	cout << "   ======================================================" << endl;
    cout << left << setw(27) << "   [1]  User Mode" << endl;
	cout << setw(27) << "   [2]  Admin Mode" << endl;
	cout << setw(27) << "   [3]  Exit" << endl;
	cout << "   ======================================================" << endl << endl;
	cout << setw(27) << "   Please select a mode: ";
    cin >> mode;
    try{
        if(mode==1)
            {
                throw(mode);
        }
        }catch(int e){
            usermode();
            }try{
                if(mode==2){
                        throw(mode);
                }
                }catch(int e){
                    admin.password();
                    }try{
                        if(mode==3){
                                throw(mode);
                        }
                        }catch(int e){
                            system("cls");
                            cout << endl << endl;
                            cout << "      ---------------------------------------------------------" << endl;
                            cout << "      Thank You for using High-Speed Train Reservation System !" << endl;
                            cout << "      ---------------------------------------------------------" << endl;
                            cout << "\n\n\t\t\tBrought to you by \n\n";
                            cout << "\t\tEugene Low Chun Chuan   1161103561\n";
                            cout << "\t\tDavid Ang Huang Qiang   1151105412\n";
                            cout << "\t\tJustin John Rajoo       1161103503\n";
                            cout << endl << endl;
                            getch();
                            exit(0);
                            }try{
                                if(mode>3||mode<1){
                                        throw(mode);
                                }
                                }catch(int e){
                                    system("cls");
                                    cout << "\n      ---------------------------------------------------------" << endl;
                                    cout<<" \tInvalid Option! Enter Again!"<< endl;
                                    cout << "      ---------------------------------------------------------\n" << endl;
                                    cout << endl << endl<<"\t";
                                    system("pause");
                                    system("cls");
                                    }
}

int main()
{
    mainmenu();
    return 0;
}
