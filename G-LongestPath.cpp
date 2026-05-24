#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& adjlist, int node, vector<int>& dp)
{
	if(dp[node] != -1) return dp[node];

	int cnt=0;
	for(auto&it:adjlist[node])
	{
		cnt=max(1+dfs(adjlist, it, dp), cnt); 
	}
	return dp[node] = cnt;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> adjlist(n+1);	
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin >> u >> v;
		adjlist[u].push_back(v);
	}

	int ans=0;
	vector<int> dp(n+1, -1);
	for(int i=0;i<=n;i++)
	{
		
		ans=max(dfs(adjlist, i, dp), ans);
		
	}
	
	cout << ans;
}