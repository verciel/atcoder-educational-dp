#include<bits/stdc++.h>
using namespace std;

long long rec(vector<int>& arr, int l, int r, vector<vector<long long>>& dp)
{
	if(l==r) return arr[l];

	if(dp[l][r] != -1) return dp[l][r];
	//2 choices, take l or take r
	//minus sign cause suppose if p1 takes x and p2 takes y then score would be x-y
	long long ans = max(arr[l]-rec(arr, l+1, r, dp), arr[r]-rec(arr, l, r-1, dp));

	return dp[l][r] = ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}	
	vector<vector<long long>> dp(n, vector<long long>(n, -1));
	cout << rec(arr,0,n-1, dp);
}