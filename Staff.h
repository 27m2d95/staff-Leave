#include<iostream>
#include<string>
using namespace std;

#ifndef STAFF_H
#define STAFF_H

class Staff {
string name;
string id;
string position;
string category;
int tel;
string faculty;
int leavebalance;
public:

Staff(string name,string id,string position ,string category,int tel,string faculty, int leavebalance);
Staff(string name,string id,int leavebalance,string faculty);
Staff();


    string getName();
    string getId();
    string getPosition();
    string getCategory();
    int getTel();
    string getFaculty();
    int getLeavebalance();

    void setName(string name);
    void setId(string id);
    void setPosition(string position);
    void setCategory(string category);
    void setTel(int tel);
    void setFaculty(string faculty);
    void setLeavebalance(int leavebalance);

};


#endif // STAFF_H
