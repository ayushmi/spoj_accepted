#include<iostream>

using namespace std;

int main()
{
	int N,i;
	cin>>N;
	long long int t1=1,t2=3,t3;
	if(N==0){
		cout<<"1\n";
		return 0;
	}
	if(N==1)
	{
		cout<<"3\n";
		return 0;
	}
	for(i=2;i<=N;i++)
	{
		t3=2*t2+t1;
		t1=t2;
		t2=t3;
	}
	cout<<t3<<endl;
	return 0;

}
