#include <vector>
#include<iostream>
#include<map>

using namespace std;


int main(){


  vector<int>  v = {1,2,3,4};

  v.push_back(33);
  v.pop_back();

  for(int x:v){
    cout<<x;
  }

  vector<int>::iterator itr= v.begin();

  for (itr = v.begin(); itr !=v.end();itr++){
    cout<<*itr;
  }


  map<int, string> m;
  m.insert(pair<int,string>(1,"bharat"));
  m.insert(pair<int,string>(2,"himanshu"));
  m.insert(pair<int,string>(3,"yash"));

  map<int, string>::iterator itr;
  for(itr = m.begin(); itr != m.end(); itr++){
    cout<<itr->first<<" "<<itr->second<<endl;
  }

  map<int, string>::iterator itr1;
  itr1.find(2);
  cout<<itr->first<<" "<<itr->second<<endl;



  return 0;
}
