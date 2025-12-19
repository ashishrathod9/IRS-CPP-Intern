#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

struct Student {
  int id;
  char name[50];
  float gpa;

  void display() const{
    cout<<id<<" "<<name<<" "<<gpa<<endl;
  }
};


void writeBinaryFile(const string& filename){

  ofstream outfile(filename, ios::binary);

  if(!outfile){
    cerr<<"error in file open"<<endl;
    return;
  }

  Student students[] = {
    {1,"bharat",1.0},
    {1,"kishan",2.0},
    {1,"malay",3.0}
  };

  int count =3;

  outfile.write(
    reinterpret_cast<char*>(&count),sizeof(count));

  outfile.write(
    reinterpret_cast<char*>(&students),sizeof(Student)*count);


  cout<<"binary data written"<<endl;

}

void readBinaryFile(const string& filename){

  ifstream infile(filename, ios::binary);

  if(!infile){
    cerr<<"error opening file"<<endl;
    return;
  }

  int count;
  infile.read(reinterpret_cast<char*>(&count),sizeof(count));

  vector<Student> students(count);

   infile.read(reinterpret_cast<char*>(students.data()), sizeof(Student) * count);

  infile.close();

  cout<<"\ndata read form binary file"<<endl;

  for(const auto& s : students){
    s.display();
  }
}

int main(){

  writeBinaryFile("students.bin");
  readBinaryFile("students.bin");

  return 0;


}
