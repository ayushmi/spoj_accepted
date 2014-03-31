#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

char S[6110],R[6100];
int dp[6110][2];

int DP(int i, int j)
{
  if(i>=j) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  if(S[i]==S[j])dp[i][j]= DP(i+1,j-1);
  else dp[i][j] = (1+min(DP(i+1,j),DP(i,j-1)));
  return dp[i][j];
}


int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%s",S);
    //memset(dp,-1,sizeof(int)*(6110*2));
    //  int ans = DP(0,strlen(S)-1);
    int i,j,ans,len=strlen(S);
    i=0;
    j=len;
    ans=0;
    for(int k=0;k<len;k++) R[k]=S[len-k-1];
    //S+R is a palindrome but has a lot of repetitions.
    //Remove all the charaters belonging to longest common substring of S and R!!
    for(i=len;i>=0;i--)
    {
      for(j=len;j>=0;j--)
      {
	if(i==len || j==len) dp[j][1]=0;
	else if(S[i]==R[j])
	{
	  dp[j][1] = 1+dp[j+1][0];
	}
	else
	{
	  dp[j][1] = max(dp[j][0],dp[j+1][1]);
	}	
      }
      for(j=len;j>=0;j--)
	dp[j][0]=dp[j][1];
    }
    cout<<len-dp[0][0]<<endl;
  }
  return 0;
}
