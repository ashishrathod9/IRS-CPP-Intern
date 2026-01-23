#include<iostream>
#include<new>
#include<vector>
#include<stdexcept>
#include<climits>

using namespace std;

int max(int a,int b)
{
	if(a<0||b<0)
	throw invalid_argument("");
	if(a>b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int main()
{
	try
	{
		int *p=new int[10000000000000];
	}
	catch(exception& e)
	{
		cout<<e.what();
	}

	vector<int>v={1,2,3};
	try
	{
		v[5];
	}
	catch(exception& e)
	{
		cout<<e.what();
	}

	int a=-10,b=20.5;
	try
	{
		int maximum=max(a,b);
	}
	catch(invalid_argument& e)
	{
		cout<<e.what();
	}

	try
        {
        int a = INT_MAX;   
        int b = 1;

        if (a + b < a)   
        {
            throw std::overflow_error("Integer overflow");
        }

        int result = a + b;
        std::cout << result;
        }
   	 catch (const std::overflow_error& e)
   	 {
        	std::cout << e.what();
   	 }

	return 0;

}
