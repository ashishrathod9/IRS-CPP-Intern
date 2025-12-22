#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
	string input;
	cin>>input;
	try
	{
		int number=stoi(input);
	}
	catch(invalid_argument& e)
	{
		cout<<e.what();
	}

	return 0;
}
