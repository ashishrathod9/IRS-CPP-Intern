#include <fstream>
#include <iostream>

using namespace std;

int main(){

  // ofstream outfile("my.txt",ios::app);
  ofstream outfile("my.txt",ios::trunc);

  outfile<<"hello"<<endl;

  outfile<<25<<endl;

  outfile.close();

  ifstream infile;
  infile.open("my.txt");

  if(!infile  or !infile.is_open()){
    cout<<"filenot found";
  }

  string str;
  int x;
  infile>>str;
  infile>>x;

  if(infile.eof()){
    cout<<"file is end";
  }

  cout<<str<<" "<<x<<endl;





}
