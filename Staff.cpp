#include<iostream>
#include<string>

using namespace std;
#include "Staff.h"

    string Staff::getName()
    {
        return name;
    }
    string Staff::getId()
    {
        return id;
    }
    string Staff::getPosition()
    {
        return position;
    }
    string Staff::getCategory()
    {
        return category;
    }
    int Staff::getTel()
    {
        return tel;
    }
    string Staff::getFaculty()
    {
        return faculty;
    }
    int Staff::getLeavebalance()
    {
        return leavebalance;
    }



    void Staff::setName(string name)
    {
        this->name = name;
    }
    void Staff::setId(string id)
    {
        this ->id = id;
    }
    void Staff::setPosition(string position)
    {
        this->position = position;
    }
    void Staff::setCategory(string category)
    {
        this->category = category;
    }
    void Staff::setTel(int tel)
    {
        this->tel = tel;
    }
    void Staff::setFaculty(string faculty)
    {
        this->faculty = faculty;
    }
    void Staff::setLeavebalance(int leavebalance)
    {
        this-> leavebalance = leavebalance;
    }
Staff::Staff(string name = "",string id="",string position="" ,string category="",int tel=0,string faculty="", int leavebalance=0):
        name(name), id(id), position(position),category(category),tel(tel),faculty(faculty),leavebalance(leavebalance){}
Staff::Staff(string name = "",string id = "", int leavebalance=10, string faculty = ""):name(name),id(id),leavebalance(leavebalance), faculty(faculty){}
Staff::Staff(){}
