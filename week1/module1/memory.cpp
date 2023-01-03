// #include <bits/stdc++.h>
#include<iostream>

using namespace std;

class Student{

public:
    string name;
    int std_id;
    int age;
    string father_name;
    string mother_name;
    Student(){
        
    }
       
    Student(string name, int id, int age, string f_name, string m_name){
        this->name = name;
        std_id=id;
        this->age=age;
        father_name=f_name;
        mother_name=m_name;
    }

    Student(string s, int id, int ag){
        name=s;
        std_id=id;
        age=ag;
    }
 
    ~Student(){
        cout<<"called";
        print_info();
    }
    void print_info(){
        cout<<name<<" "<<std_id<<" "<<age<<" "<<father_name<<" "<<mother_name<<"\n";
    }
    void serInformation(string s, int id, int age){
        name=s;
        std_id=id;
        age=age;
    }
};
class Rectangle{
public:
    int width,height;
    Student s;
    // area
    int calulate_area(){
        return height*width;
    }
    int calculate_perimeter(){
        return 2*(height+width);
    }
};
class Person{
public:
    string name;
    Person *father,*mother;
    Person(){
        father=NULL;
        mother=NULL;
    }
    Person(string name, string f_name, string m_name){
       this->name = name;
       father = new Person;
       father->name = f_name;
       mother= new Person;
       mother->name = m_name;
    }
    void print_information(){
        cout<<"name = "<<name<<"\n";
        cout<<"Fathers name = "<<father->name<<"\n";
        cout<<"Mother name ="<<mother->name<<"\n";
    }
    ~Person(){
        cout<<"Called\n";
        if(father != NULL)
           delete father;
        if(mother != NULL)
           delete mother;
    }
};

class User{
protected:
    string name;
    int age;
};

class Admin: User{
private:
    string designation;
public:
    void Set(string s, int ag, string dg){
        name=s;
        age=ag;
        designation=dg;
    }
    void print(){
        cout<<name<<"\n";
        cout<<age<<"\n";
        cout<<designation<<"\n";
    }
};

int main()
{
    // Student s("A",10,20,"B","C");
    // s.print_info();
    // Student s2("R",10,20);
    // s2.print_info();
    // Student s3;
    Person p("A","B","C");
    p.print_information();
    return 0;
}