#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
	int t,N,i,distance,fuel;
	scanf("%d",&t);
	long long int current_fuel=0,current_distance=0;
	vector< pair<int,int> > fuel_stations;

	while(t--)
	{
		scanf("%d",&N);
		vector< pair<int,int> > fuel_stations;
		priority_queue< int > Q;
		for(i=0;i<N;i++)
		{
			scanf("%d%d",&distance,&fuel);
			fuel_stations.push_back(pair<int,int>(distance,fuel));
		}
		fuel_stations.push_back(pair<int,int>(0,0));
		scanf("%lld%lld",&current_distance,&current_fuel);
		sort(fuel_stations.begin(), fuel_stations.end() );
		int count=0;
		for(i=fuel_stations.size()-1;i>=0;i--)
		{
			while(current_distance-fuel_stations[i].first > current_fuel && !Q.empty())
			{
				current_fuel=current_fuel+Q.top();
				Q.pop();
				count++;
			}
			if(current_distance-fuel_stations[i].first>current_fuel) break;
			Q.push(fuel_stations[i].second);
		}
		if(i>=0)
			cout<<"-1\n";
		else
			cout<<count<<endl;
	}
	return 0;
}

