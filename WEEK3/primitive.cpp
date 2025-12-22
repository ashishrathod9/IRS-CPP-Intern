#include<iostream>
using namespace std;

int main()
{
	try
	{
		throw 2;
	}
	catch(int x)
	{
		cout<<"caught"<<x;
	}

	return 0;
}
