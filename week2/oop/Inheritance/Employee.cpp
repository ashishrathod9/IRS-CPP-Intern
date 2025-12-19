#include<iostream>
using namespace std;

class Employee{
  private:
    int eid;
    string name;

  public:
    Employee(int e, string n){
      eid =e;
      name =n;
    }
    int getEmpId(){
      return eid;
    }
    string getName(){
      return name;
    }
};

class FullTimeEmployee : public Employee{
  private:
    int salary;

  public:
    FullTimeEmployee(int e, string n, int s):
    Employee(e,n){
      salary =s;
    }
    int getSalary(){
      return salary;
    }
};

class PartTimeEmployee : public Employee{
  private:
    int wage;

  public:
    PartTimeEmployee(int e, string n, int w):
    Employee(e,n){
      wage = w;
    }
    int getWage(){
      return wage;
    }
};

int main(){
  FullTimeEmployee fte(101, "bharat", 5000);
  PartTimeEmployee pte(102, "harsh", 2000);

  cout<<"Full Time Employee: "<<fte.getName()<<" with ID: "<<fte.getEmpId()<<" has salary: "<<fte.getSalary()<<endl;
  cout<<"Part Time Employee: "<<pte.getName()<<" with ID: "<<pte.getEmpId()<<" has wage: "<<pte.getWage()<<endl;
}
