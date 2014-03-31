#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
  long long int T;
  long long int At,Bt;
  int people[100010];
  scanf("%lld",&T);
  while(T--)
  {
    scanf("%lld%lld",&At,&Bt);
    for(long long int i=0;i<At;i++)
      scanf("%d",&people[i]);
    long long int sum=0,count=0;
    long long int sumi=0,counti=0;
    long long int k=0;
    for(long long int i=0;i<At;i++)
    {
      //ith iteration how can we reach ith station optimal solution.
      if(sumi+people[i]<=Bt)
      {
	  sumi+=people[i];
	  counti++;
      }
      else
      {
	//if not able to reach ith station. Try to find when can we reach it.
	while(sumi+people[i]>Bt)
	{
	  sumi-=people[k];
	  counti--;
	  k++;
	}
	sumi+=people[i];
	counti+=1;
      }
      if(count<counti || (count == counti && sum>sumi) )
      {
	count=counti;
	sum=sumi;
      }
    }
    cout<<sum<<" "<<count<<endl;
  }
  return 0;
}
