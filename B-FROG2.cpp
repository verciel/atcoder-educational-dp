#include<bits/stdc++.h>
using namespace std;

int n,k;

int rec(vector<int>& arr, int i, vector<int>& dp)
{
	if(i>=n) return 1e9;
	if(i==n-1) return 0;

	if(dp[i] != -1) return dp[i];

	int ans=1e9;
	for(int jump=1;jump<=k;jump++)
	{
		if(i+jump < n)
		{
			ans=min(ans, abs(arr[i]-arr[i+jump])+rec(arr,i+jump,dp));
		}
	}
	return dp[i]=ans;
}

int main()
{
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin >> arr[i];

	vector<int> dp(n,-1);
	cout << rec(arr,0,dp);
}