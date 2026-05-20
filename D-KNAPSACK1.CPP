#include<bits/stdc++.h>
using namespace std;

long long n,w;

//pick-not pick, try all combinations. use dp for overlapping subproblems
long long rec(vector<vector<long long>>& arr, int index, long long weight, vector<vector<long long>>& dp)
{
	if(index==n-1)
	{
		if(arr[n-1][0]+weight <= w) return dp[index][weight]=arr[n-1][1];
		return dp[index][weight] = 0;
	}

	if(dp[index][weight] != -1) return dp[index][weight];

	long long pick=0;
	if(weight+arr[index][0] <= w) pick=arr[index][1] + rec(arr, index+1, weight+arr[index][0], dp);
	long long notpick=rec(arr, index+1, weight, dp);

	return dp[index][weight] = max(pick, notpick);
}

int main()
{
	cin >> n >> w;
	vector<vector<long long>> arr(n, vector<long long>(2)); //{weight, value}
	for(int i=0;i<n;i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}
	vector<vector<long long>> dp(n, vector<long long>(w+1, -1));
	cout << rec(arr, 0, 0, dp);
}