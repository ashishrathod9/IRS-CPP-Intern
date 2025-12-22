#include<iostream>
#include<exception>
#include<stdexcept>
using namespace std;

class custom : public exception
{
	public:
	const char* what() const noexcept override
	{
		return "divide zero";
	}
};

int main()
{
	int a=5,b=0;
	try
	{
		if(b==0)
		throw custom();
		else
		cout<<"evrything is ok";
	}
	catch(const exception& e)
	{
		cout<<e.what();
	}

	return 0;
}
