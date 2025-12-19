# include <iostream>

using namespace std;

class Student{

  private:
    int roll;
    string name;
    int mathMarks;
    int phyMarks;
    int chemMarks;

  public:
    Student(int r, string n, int m,
      int p,int c){
        roll=r;
        name =n;
        mathMarks=m;
        phyMarks=p;
        chemMarks=c;
      }
    int total(){
      return mathMarks+phyMarks+chemMarks;
    }
    char grade(){
      float average = total()/3;
      if(average >60)
        return 'a';
      else if (average >=40 &&
        average<60)
      {
        return 'b';
      }else{
        return 'c';
      }
    }
};

int main(){
  Student s(1,"bharat",10,20,30);
  cout<<"total marks: "<<s.total()<<endl;
  cout<<"grade :"<<s.grade()<<endl;

  return 0;

}
