#include<iostream>
#include<cstdio>
#include<assert.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  while(n!=0 && m!=0)
  {
    
    int y[505][505],b[505][505];
    int u[505][505],l[505][505];
    //cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
	scanf("%d",&y[i][j]);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
	scanf("%d",&b[i][j]);

    for(int i=0;i<=n;i++)
    {
      u[i][0]=0;
      l[i][0]=0;
    }
    
    int vu[505],L;
    for(int i=0;i<=m;i++)
    {
      u[i][0]=0;
      l[i][0]=0;
      vu[i] = 0;
    }

    u[1][1]=b[1][1];
    l[1][1]=y[1][1];
    for(int i=1;i<=n;i++)
    {
      L=0;
      for(int j=1;j<=m;j++)
      {
	L+=y[i][j];
	vu[j]+=b[i][j];
	//cout<<"vu at j = "<<j<<" "<<vu[j]<<endl;
	u[i][j] = max(l[i][j-1],u[i][j-1])+vu[j];
	l[i][j] = max(l[i-1][j],u[i-1][j]) + L;
      }
      //cout<<"L:"<<L<<endl;
    }

    cout<<max(u[m][n],l[m][n])<<endl;
    cin>>n>>m;
  }
  return 0;

}
