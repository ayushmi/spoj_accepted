#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int Visited[100005],Cover[100005];
vector<int> t[100005];
int dp[100005][2];
void VCover(int v,int N)
{
  Visited[v]=1;
  int flag=0,i;
  long long int count1=0,count2=0;
  for(i=0;i<t[v].size();i++)
  {
    if(Visited[t[v][i]]==-1)
    {
      VCover(t[v][i],N);
      count1+=dp[t[v][i]][1];
      count2+=min(dp[t[v][i]][1],dp[t[v][i]][0]);
    }
  }
  dp[v][0] = count1;
  dp[v][1] = count2+1;
 }

int main()
{
	int N,i,v1,v2,root;
	
	memset(Visited,-1,sizeof(int)*100005);
	//	memset(parent,-1,sizeof(int)*100005);;
	memset(Cover,-1,sizeof(int)*100005);
	cin>>N;
	for(i=0;i<N-1;i++)
	{
		cin>>v1>>v2;
		t[v1-1].push_back(v2-1);
		t[v2-1].push_back(v1-1);
	}
	//for(i=0;i<N;i++)
	//cout<<"parent of"<<i<<"is :"<<parent[i]<<endl;
	//cout<<"root:"<<root<<endl;
	VCover(0,N);
	//for(i=0;i<N;i++)
	cout<<min(dp[0][0],dp[0][1])<<endl;
}
