#include<iostream>
#include<cstdio>

using namespace std;

// long long int MinSmoke(int i,int n)
// {
//   if(i>n)
//   {
//     updatedColor[i]=0;
//     return 0;
//   }
//   else if(i==n) return 0;
//   long long int ans=0;
//   long long int ans1 = MinSmoke(i+1,n) + updatedColor[i+1]*color[i]; 
//   long long int ans2 = MinSmoke(i+2,n) + color[i]*color[i+1] + updatedColor[i+2]*((color[i]+color[i+1])%100);
//   return min(ans1,ans2);
// }

int main()
{
  int n;
  int color[105];
  long long int opt[105][105];
  int  optColor[105][105];
  long long int ans[105][105];

  while(scanf("%d",&n)==1)
  {
  
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&color[i]);
    opt[i][i] = color[i];
    optColor[i][i] = color[i];
    ans[i][i]=0;
  }
  
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
      {
	opt[j][i] = -1;
	optColor[j][i] = -1;
	ans[j][i]=0;
      }
  }
  for(int diff=1;diff<=n-1;diff++)
  {
    for(int i=diff+1;i<=n;i++)
      {
	int j = i-diff;
	long long int val=1000000000;
	for(int temp = 1; temp<=diff;temp++)
	  {
	    long long int possible=optColor[i-temp][j]*optColor[i][i-temp+1];
	    //if(possible<opt[i][j] || opt[i][j]==-1 || optColor[i][j]==-1)
	    //{
	    long long int possibleVal = ans[i-temp][j]+ans[i][i-temp+1]+possible;
	    if(val>possibleVal)
	      {
		val = possibleVal;
		//	cout<<val<<" "<<possible<<endl;//possible;
		opt[i][j]=possible;
		optColor[i][j]=(optColor[i-temp][j]+optColor[i][i-temp+1])%100;
	      }
	    // else if(possible == opt[i][j])
	    //   {
	    // 	val = ans[i-temp][j]+ans[i][i-temp+1]+possible;
	    // 	int possibleColor = (optColor[i-temp][j]+optColor[i][i-temp+1])%100;
	    // 	if(optColor[i][j] > possibleColor) optColor[i][j]=possibleColor;
	    //   }
	  }
	ans[i][j]=val;
      }
  }

  cout<<ans[n][1]<<endl;
  }//cout<<MinSmoke(0,n)<<endl;
  return 0;
}
