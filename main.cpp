//---------------------------------------------------
//Name : Ahmad Hamdan
//Id : 1131121467
//section : TC02
//tutorial : TT03
//oopd assignment 2
//------------------------------------




#include"Staff.h"
#include"Leave.h"
#include"LinkedList.h"
#include<iostream>
#include<string>
#include <cstdlib>
#include <fstream>
#include<vector>

using namespace std;



//operator cout for Staff class.
ostream& operator<<(ostream& os, Staff s)
{
    os << " " << s.getName() << "\t" << s.getId() << "\t" << s.getPosition() <<"\t"<< s.getCategory()<<"\t" << s.getTel() <<"\t"<< s.getFaculty()<<"\t" << s.getLeavebalance() <<endl;
    return os;
}

//operator cout for Leave class.
ostream& operator<<(ostream& os, Leave c)
{
    os << " "  <<c.staff.getName() << "\t" <<c.staff.getId()<<"\t" <<c.staff.getLeavebalance()<<"\t" <<c.staff.getFaculty()<<"\t"<<c.getDay()<< "/" << c.getMonth()<<"/" << c.getYear() <<"\t"<< c.getDay1() <<"/"<<c.getMonth1() <<"/"<< c.getYear1()<< "\t"<< c.getType() <<"\t"<< c.getApprover()<<"\t" <<c.getStatus() <<endl;
    return os;
}

//Display function for Linked List.
template <typename ItemType>
void displayList(ListInterface<ItemType>* listPtr)
{
   for (int pos = 1; pos <= listPtr->getLength(); pos++)
   {
        ItemType s = listPtr->getEntry(pos);
        cout <<  s <<  endl;
        pos++;

   }
	cout << endl;
}


int main(){

ListInterface<Staff>* listPtrS = new LinkedList<Staff>(); //Linked List type Staff
ListInterface<Leave>* listPtrL = new LinkedList<Leave>(); //Linked List type Leave
//-------------------------------------
ifstream load;
ofstream load1;     //txt files definition
ofstream myfile;
//-------------------------
string name;
string id;
string position;
string category;
int tel;
string faculty;
int leavebalance;
int day;                //for cin definition
int month;
int year;
int day1;
int month1;
int year1;
string type;
string approver;
string status;
//-------------------------------------

    char choice;
    bool done = false;
    do {
        system("cls");
        listPtrL->clear();
        listPtrS->clear();
        cout << endl;
        cout <<"1. Add New Staff To System "<< endl;
        cout <<"2. Retrieve Staff Leave Info "<< endl;
        cout <<"3. Apply Leave "<< endl;
        cout <<"4. Update Leave  "<< endl;
        cout <<"5. Retrieve  All Staff info "<< endl;
        cout <<"6. Display Leave Static BY (Day/Month/Year) "<< endl;
        cout <<"Q. Quit"<< endl;
        cout << endl;
        cout <<"=>";
        cin >> choice;


        switch( choice )
        {
            case '1' :
                {
                    cout << "Enter Staff info (Name, ID, Position, Category, Tel.no, Faculty, LeaveBalance): " << endl;
                    cin >> name;
                    cin >> id;
                    cin >> position;
                    cin >> category;
                    cin >>tel;
                    cin >> faculty;
                    cin >> leavebalance;
                    listPtrS->insert(listPtrS->getLength()+1,Staff(name, id, position,category,tel,faculty,leavebalance));  //insert to linked list first


                       cout << "---------------------------------------------------------------------------------------------" <<endl;
                       cout << "Name\t" << "Id\t" << "Position\t" << "category\t" << "tel\t" << "Fcaulty\t" << "Balance\t" << "Status" <<endl;
                       cout << "----------------------------------------------------------------------------------------------" <<endl;
                       displayList(listPtrS);
                       cout << "----------------------------------------------------------------------------------------------" <<endl;

                        myfile.open ("Staff.txt",ios::app);
                        myfile << name << " ";
                        myfile << id << " ";
                        myfile << position << " ";                          //insertion Staff into txt file
                        myfile << category << " ";
                        myfile << tel << " ";
                        myfile << faculty << " ";
                        myfile << leavebalance << endl;
                        myfile.close();
                        break;
                }
            case '2' :
                {
                    cout << "Enter Staff ID : ";
                    string st;
                    cin >> st ;
                    load.open("Leave.txt");
                    while(!load.eof()){
                    load >> name >> id >> leavebalance >>faculty>> day >> month >> year>> day1 >> month1 >> year1 >> type >> approver >> status;
                     if(st == id)
                        {
                                listPtrL->insert(listPtrL->getLength()+1,Leave(Staff(name, id,leavebalance,faculty),day, month, year,day1, month1, year1, type, approver, status));

                        }

                    }


                        cout << "---------------------------------------------------------------------------------------------" <<endl;
                        cout << "Name\t" << "Id\t" << "Balance\t"<<"Faculty\t" << "From\t" << "To\t" << "Type\t" << "approver\t" << "Status" <<endl;
                        cout << "----------------------------------------------------------------------------------------------" <<endl;
                        displayList(listPtrL);
                        if (listPtrL->isEmpty()){
                            cout << "this staff has not apply for leave yet " <<endl;
                            cout << "Nothing to show " << endl;
                        }
                         cout << "----------------------------------------------------------------------------------------------" <<endl;

                       load.close();
                    break;


                }
            case '3' :
                {
                    cout << "Enter Staff info : " << endl;
                    cout << "Name :-> ";
                    cin >> name;
                    cout << "ID :-> " ;
                    cin >> id;
                    leavebalance = 10;
                    cout << "Faculty :->";
                    cin >> faculty;
                    cout << " From Date "<<endl;
                    cout << "Day :";
                    cin >> day;
                    cout <<"Month : ->";
                    cin >> month;
                    cout << "Year : ->";
                    cin >> year;
                    cout << " To Date "<< endl;
                    cout << "Day :";
                    cin >> day1;
                    cout <<"Month : ->";
                    cin >> month1;
                    cout << "Year : ->";
                    cin >> year1;
                    cout << "Type of Leave : ->";
                    cin >> type;
                    cout << "Approver :-> ";
                    cin >> approver;
                    cout << "Status :->";
                    cin >> status;
                    listPtrL->insert(listPtrL->getLength()+1,Leave(Staff(name,id,leavebalance,faculty),day, month, year,day1, month1, year1, type, approver, status));
                        myfile.open ("Leave.txt",ios::app);
                        myfile << name << " ";
                        myfile << id << " ";
                        myfile << leavebalance - 1 << " ";
                        myfile << faculty << " ";
                        myfile << day << " ";
                        myfile << month << " ";
                        myfile << year << " ";
                        myfile << day1 << " ";
                        myfile << month1 << " ";
                        myfile << year1 << " ";
                        myfile << type << " ";
                        myfile << approver << " ";
                        myfile << status << endl;
                        myfile.close();
                        cout << "added successfully" <<endl;
                        cout << "---------------------------------------------------------------------------------------------" <<endl;
                        cout << "Name\t" << "Id\t" << "Balance\t" << "Faculty\t" << "From\t" << "To\t" << "Type\t" << "approver\t" << "Status" <<endl;
                        cout << "----------------------------------------------------------------------------------------------" <<endl;
                        displayList(listPtrL);
                         cout << "----------------------------------------------------------------------------------------------" <<endl;


                    break;
                }
            case '4' :
                {
                    cout << "Enter Staff ID : ";
                    string st;
                    cin >> st ;
                    load.open("Leave.txt");
                    load1.open("Leave.txt",ios::app);
                    while(!load.eof()){
                    load >> name >> id >> leavebalance>>faculty >> day >> month >> year>> day1 >> month1 >> year1 >> type >> approver >> status;

                     if(st == id)
                        {
                              listPtrL->insert(listPtrL->getLength()+1,Leave(Staff(name, id,leavebalance,faculty),day, month, year,day1, month1, year1, type, approver, status));

                        }


                    }

                        cout << "---------------------------------------------------------------------------------------------" <<endl;
                        cout << "Name\t" << "Id\t" << "Balance\t"<< "Fculty\t"<< "From\t" << "To\t" << "Type\t" << "approver\t" << "Status" <<endl;
                        cout << "----------------------------------------------------------------------------------------------" <<endl;
                             displayList(listPtrL);
                        if (listPtrL->isEmpty()){
                            cout << "Nothing to show" <<endl;
                            cout << "this staff has not apply for leave" << endl << endl;
                            system("pause");
                            main();
                        }

                        cout << "----------------------------------------------------------------------------------------------" <<endl << endl;
                                cout << "Enter the position number that you want to update  ";
                                int ch;
                                cout << "your choice ->";
                                cin >> ch;
                                cout << "New Name ->:" ;
                                cin >> name;
                                cout << "New ID :-> " ;
                                cin >> id;
                                cout << "New balance : -> ";
                                cin >> leavebalance;
                                cout << "Faculty  :->";
                                cin >> faculty;
                                cout << " From Date "<<endl;
                                cout << "Day :";
                                cin >> day;
                                cout <<"Month : ->";
                                cin >> month;
                                cout << "Year : ->";
                                cin >> year;
                                cout << " To Date "<<endl;
                                cout << "Day :";
                                cin >> day1;
                                cout <<"Month : ->";
                                cin >> month1;
                                cout << "Year : ->";
                                cin >> year1;
                                cout << "Type of Leave : ->";
                                cin >> type;
                                cout << "Approver :-> ";
                                cin >> approver;
                                cout << "Status :->";
                                cin >> status;

                                listPtrL->remove(ch);
                                listPtrL->insert(listPtrL->getLength()+1,Leave(Staff(name, id,leavebalance,faculty),day, month, year,day1, month1, year1, type, approver, status));
                                cout << "your new record is :" <<endl;
                                displayList(listPtrL);


                                for (int i = 1; i <= listPtrL->getLength(); i++){

                                        load1 << name << " ";
                                        load1 << id << " ";
                                        load1 << leavebalance << " ";
                                        load1 << faculty << " ";
                                        load1 << day << " ";
                                        load1 << month << " ";
                                        load1 << year << " ";
                                        load1 << day1 << " ";
                                        load1 << month1 << " ";
                                        load1 << year1 << " ";
                                        load1 << type << " ";
                                        load1 << approver << " ";
                                        load1 << status << endl;


                                }

                                load.close();
                                load1.close();
                                cout <<endl<<endl<<endl;
                    break;
                }


            case '5' :
                {
                    load.open("Staff.txt");
                    while(!load.eof()){
                    load >> name >> id >> position >> category >> tel >> faculty>> leavebalance ;

                                listPtrS->insert(listPtrS->getLength()+1,Staff(name, id, position,category,tel,faculty,leavebalance));
                    }

                        cout << "---------------------------------------------------------------------------------------------" <<endl;
                        cout << "Name\t" << "Id\t" << "position\t" << "category\t" << "tel.no\t" << "faculty\t" << "balance\t"  <<endl;
                        cout << "----------------------------------------------------------------------------------------------" <<endl;
                        displayList(listPtrS);
                        if(listPtrS->isEmpty()){
                            cout<<"empty file go and add staff" <<endl;
                        }
                        cout << "----------------------------------------------------------------------------------------------" <<endl;

                       load.close();
                       break;
                }
            case '6' :
                {
                    cout << "1- for check by day " << endl;
                    cout << "2- for check by month " <<endl;
                    cout << "3- for check by Faculty " <<endl;
                    cin >> choice;
                    if (choice == '1')
                    {
                        cout << "Enter the (day/month/year) of the Leave ";
                        int d;
                        int m;
                        int y;
                        cout << "day :" ;cin >> d;
                        cout << "month:";cin >> m;
                        cout << "year :";cin >> y;

                        load.open("Leave.txt");
                        while(!load.eof()){
                        load >> name >> id >> leavebalance >>faculty>> day >> month >> year>> day1 >> month1 >> year1 >> type >> approver >> status;
                        if(d == day && m == month && y == year)
                            {
                            listPtrL->insert(listPtrL->getLength()+1,Leave(Staff(name, id,leavebalance,faculty),day, month, year,day1, month1, year1, type, approver, status));
                            }

                        }

                        cout << "---------------------------------------------------------------------------------------------" <<endl;
                        cout << "Name\t" << "Id\t" << "Balance\t"<<"faculty\t" << "From\t" << "To\t" << "Type\t" << "approver\t" << "Status" <<endl;
                        cout << "----------------------------------------------------------------------------------------------" <<endl;
                        displayList(listPtrL);
                        if (listPtrL->isEmpty()){
                            cout << "there is no record for this day " <<endl;
                            cout << "Nothing to show " << endl;
                        }
                         cout << "----------------------------------------------------------------------------------------------" <<endl;

                       load.close();

                    }
                     else if (choice == '2')
                    {
                        cout << "Enter the (month/year) of the Leave ";
                        int m;
                        int y;
                        cout << "month:";cin >> m;
                        cout << "year :";cin >> y;

                        load.open("Leave.txt");
                        while(!load.eof()){
                        load >> name >> id >> leavebalance >>faculty >>day >> month >> year>> day1 >> month1 >> year1 >> type >> approver >> status;
                        if(m == month && y == year)
                            {
                            listPtrL->insert(listPtrL->getLength()+1,Leave(Staff(name, id,leavebalance,faculty),day, month, year,day1, month1, year1, type, approver, status));
                            }

                        }

                        cout << "---------------------------------------------------------------------------------------------" <<endl;
                        cout << "Name\t" << "Id\t" << "Balance\t" <<"faculty\t"<< "From\t" << "To\t" << "Type\t" << "approver\t" << "Status" <<endl;
                        cout << "----------------------------------------------------------------------------------------------" <<endl;
                        displayList(listPtrL);
                        if (listPtrL->isEmpty()){
                            cout << "there is no record for this month " <<endl;
                            cout << "Nothing to show " << endl;
                        }
                         cout << "----------------------------------------------------------------------------------------------" <<endl;

                       load.close();

                    }
                    else if(choice == '3')
                    {
                        cout << "Enter the faculty ";
                        string st;
                        cin >> st;
                        load.open("Leave.txt");
                        while(!load.eof()){
                        load >> name >> id >> leavebalance >>faculty >>day >> month >> year>> day1 >> month1 >> year1 >> type >> approver >> status;
                        if(st == faculty)
                            {
                            listPtrL->insert(listPtrL->getLength()+1,Leave(Staff(name, id,leavebalance,faculty),day, month, year,day1, month1, year1, type, approver, status));
                            }

                        }

                        cout << "---------------------------------------------------------------------------------------------" <<endl;
                        cout << "Name\t" << "Id\t" << "Balance\t" <<"faculty\t"<< "From\t" << "To\t" << "Type\t" << "approver\t" << "Status" <<endl;
                        cout << "----------------------------------------------------------------------------------------------" <<endl;
                        displayList(listPtrL);
                        if (listPtrL->isEmpty()){
                            cout << "there is no record for this faculty " <<endl;
                            cout << "Nothing to show " << endl;
                        }
                         cout << "----------------------------------------------------------------------------------------------" <<endl;
                    }
                    break;
                }
            case 'Q' :
                {
                    done = true;
                    break;
                }
            default :
                cout <<"Invalid choice"<< endl;
        }
        system("pause");
    } while ( !done );


    cout <<"Good Bye !!"<< endl;
}


