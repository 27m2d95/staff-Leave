#include<iostream>
#include<string>

using namespace std;

#include "Leave.h"
#include"Staff.h"


 int Leave::getDay()
 {
     return day;
 }
 int Leave::getMonth()
 {
     return month;
 }
 int Leave::getYear()
 {
     return year;
 }
 string Leave::getType()
 {
     return type;
 }
 string Leave::getApprover()
 {
     return approver;
 }
 string Leave::getStatus()
 {
     return status;
 }

 void Leave::setDay(int day)
 {
     this->day = day;
 }
 void Leave::setMonth(int month)
 {
     this->month = month;
 }
 void Leave::setYear(int year)
 {
     this->year = year;
 }
 void Leave::setType(string type)
 {
     this->type = type;
 }
 void Leave::setApprover(string approver)
 {
     this->approver = approver;
 }

 void Leave::setStatus(string status)
 {
     this-> status = status;
 }
 int Leave::getDay1()
 {
     return day1;
 }
 int Leave::getMonth1()
 {
     return month1;
 }
 int Leave::getYear1()
 {
     return year1;
 }
 void Leave::setDay1(int day1)
 {
     this->day1 = day1;
 }
 void Leave::setMonth1(int month1)
 {
     this->month1 = month1;
 }
 void Leave::setYear1(int year1)
 {
     this->year1 = year1;
 }



 Leave::Leave(Staff staff,int day = 0, int month= 0, int year= 0,int day1= 0, int month1= 0, int year1= 0, string type="", string approver="", string status=""):staff(staff),day(day),month(month),year(year),day1(day1),month1(month1),year1(year1),type(type),approver(approver),status(status){}
