#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int count(string a,int start)
{
	if(a[start]=='0') return 0;
	if(a.length()-start !=1 && a[start+1]=='0') return count(a,start+2);
	if(a.length()- start <= 1) return 1;
	int val = (a[start]-'0')*10+(a[start+1]-'0');
	if(val <=26)
	{
		if(a.length() - start == 2 && a[start+1]!='0') return 2;
		else if(a.length()-start == 2) return 1;
		return (count(a,start+1)+count(a,start+2));
	}
	else return (count(a,start+1));
}

int main()
{
	string a;
	int i;
	long long int DP[5001];
	while(1)
	{
		for(i=0;i<5001;i++) DP[i]=0;
		cin>>a;
		if(a=="0\0") break;
		DP[0]=1;
		for(i=1;i<a.length();i++)
		{
			if(a[i]!='0') DP[i]=DP[i-1];
			if((a[i-1]-'0')*10 + a[i]-'0' <=26 && a[i-1]!='0') 
			{
				if(i==1) DP[i]+=1;
				else DP[i]+=DP[i-2];
			}
		}
		cout<<DP[a.length()-1]<<endl;
	}
	return 0;
}
