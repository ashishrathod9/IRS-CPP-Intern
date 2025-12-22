#include<iostream>
#include<fstream>
#include<stdexcept>
using namespace std;

int main()
{

	try
	{
		ifstream config("config.txt");
		if(!config.is_open())
		{
			throw runtime_error("file is not exists");
		}
	}
	catch(runtime_error e)
	{
		cout<<e.what();
	}

	return 0;
}
