#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
        long long int N,i,j;
        scanf("%lld",&N);
        vector<long long int> c,p;
        while(N)
        {       
                long long int ans=0;
                c.clear();
                p.clear();
                for(i=0;i<N;i++)
                {
                        scanf("%lld",&j);
                        c.push_back(j);
                }
                for(i=0;i<N;i++)
                {
                        scanf("%lld",&j);
                        p.push_back(j);
                }
                sort(c.begin(),c.end());
                sort(p.begin(),p.end());
                for(i=0;i<N;i++)
                {
                        ans+=c[i]*p[N-i-1];
                }
                printf("%lld\n",ans);
		scanf("%lld",&N);
        }
	return 0;
}
