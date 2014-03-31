#include<iostream>
#include<cstdio>
#include<string.h>
#define max 1000000
using namespace std;

long long int f[max];
long long int a[max];

void calculatef()
{
  //memset(f,1,sizeof(int)*max);
  for(long long int i=2;i<=max;i++) f[i]=1;
  for(long long int i=2;i<=max;i++)
  {
    long long int j=2;
    long long int k=j*i;
    while(k<max)
    {
      f[k]+=i;
      j++;
      k=i*j;
    }
  }
}

void calculatea()
{
  a[0]=0;
  a[1]=0;
  for(int i=2;i<=max;i++)
  {
    a[i] = a[i-1]+f[i];
  }  
}
int main()
{
  calculatef();
  calculatea();
  long long int t,n;
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld",&n);
    cout<<a[n]<<endl;
  }
  return 0;
}
