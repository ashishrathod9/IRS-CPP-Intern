//find the addition of all odd number from 1 to 1900000000 same for even
#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

ull Oddsum=0;
ull Evensum=0;

void findeven(ull start,ull end)
{
	for(ull i=start;i<=end;++i)
	{
	if((i & 1)==0)
	{
	Evensum+=i;
	}
	}
}

void findodd(ull start,ull end)
{
        for(ull i=start;i<=end;++i)
        { 
        if((i & 1)==0)
        {
        Oddsum+=i;
        }
        }
}

int main()
{
	ull start=0,end=1900000000;
	findeven(start,end);
	findodd(start,end);
	cout<<Oddsum;
	cout<<Evensum;

	return 0;
}



