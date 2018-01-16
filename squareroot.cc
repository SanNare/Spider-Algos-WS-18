#include<iostream>
using namespace std;

// Finding precise square root using biary search
int main()
{
	double left,right,x;
	cin>>x; //number to find square root of
	/*
	initialising left bound and right bound depending on number
	being greater than or less than 1
	*/
	if(x<1.0)
	{
		left=x;   
		right=1.0; 
	}
	else
	{
		left=1.0;
		right=x;
	}
	while(left<right)
	{
		double mid=left+0.5*(right-left);
		double midsqr=mid*mid;
		if(midsqr<x+0.000001 && midsqr>x-0.000001) //precise upto one millionth
		{
			cout<<mid;
			break;
		}
		else if(midsqr>x)
			right=mid;
		else
			left=mid;
	}

	return 0;
}