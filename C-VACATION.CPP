#include<bits/stdc++.h>
using namespace std;

int n;
// while accessing dp we use last+1 to avoid negative indexing
// last=-1 noprevious task
// last=0 previous task 0
// last=1 previous task 1
// last=2 previous task 2
int rec(vector<vector<int>>& arr, int row, int last, vector<vector<int>> &dp)
{
	if(row==n-1)
	{
		int ans=0;
		for(int i=0;i<3;i++)
		{
			if(last != i) ans=max(ans, arr[n-1][i]);
		}
		return ans;
	}

	if(dp[row][last+1] != -1) return dp[row][last+1];

	int ans=0;
	for(int i=0;i<3;i++)
	{
		if(i != last) ans=max(ans, arr[row][i] + rec(arr,row+1,i,dp)); 
	}

	return dp[row][last+1]=ans;
}

int main()
{
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(3));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(4,-1));
	cout << rec(arr, 0, -1, dp);
}