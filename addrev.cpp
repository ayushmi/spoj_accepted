#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
  long long int t,a,b,sum,newa,newb,newsum;
  scanf("%lld",&t);
  while(t--)
  {
    newa=0;
    newb=0;
    newsum=0;
    scanf("%lld%lld",&a,&b);
    while(a>0)
    {
      newa*=10;
      newa+=a%10;
      a=a/10;
    }
    while(b>0)
    {
      newb*=10;
      newb+=b%10;
      b=b/10;
    }
    sum = newa+newb;
    while(sum>0)
    {
      newsum=newsum*10;
      newsum+=sum%10;
      sum=sum/10;
    }
    cout<<newsum<<endl;
  }
  return 0;
}
