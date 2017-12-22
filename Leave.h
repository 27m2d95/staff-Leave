#include<iostream>
#include<string>
using namespace std;

#include"Staff.h"
#ifndef LEAVE_H
#define LEAVE_H


class Leave
{

 int day;
 int month;
 int year;
  int day1;
 int month1;
 int year1;
 string type;
 string approver;
 string status;

public:
    Staff staff;

    Leave(Staff staff,int day, int month, int year,int day1, int month1, int year1, string type, string approver, string status);


 int getDay();
 int getMonth();
 int getYear();
 string getType();
 string getApprover();
 string getStatus();
 int getDay1();
 int getMonth1();
 int getYear1();

 void setDay(int day);
 void setMonth(int month);
 void setYear(int year);
 void setType(string type);
 void setApprover(string approver);
 void setStatus(string status);
 void setDay1(int day1);
 void setMonth1(int month1);
 void setYear1(int year1);
};



#endif // LEAVE_H
