#include<bits/stdc++.h>
using namespace std;

int n;

int rec(vector<int>& arr, int i, vector<int>& dp)
{
	if(i>=n) return 1e9;
	if(i==n-1) return 0;
	if(dp[i] != -1) return dp[i];

	int one=1e9, two=1e9;
	one=abs(arr[i+1]-arr[i]) + rec(arr, i+1, dp);
	if(i+2 < n) two=abs(arr[i+2]-arr[i]) + rec(arr, i+2, dp);

	return dp[i]=min(one,two);
}

int main()
{
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin >> arr[i];

	vector<int> dp(n,-1);
	cout << rec(arr,0,dp);
}