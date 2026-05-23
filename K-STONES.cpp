#include<bits/stdc++.h>
using namespace std;

int n;
//returns true if current player reaches a winning state
bool rec(int k, vector<int>& arr, vector<int>& dp)
{
	//current player loses as no stones left
	if(k==0) return false;

	if(dp[k] != -1) return dp[k];

	bool ans=false;
	for(int i=0;i<n;i++)
	{
		if(k-arr[i] >= 0)
		{
			//if after making a move, the opponent is in a losing state, then current state is winning
			if(!rec(k-arr[i], arr, dp))
			{
				ans=true;
				break;
			}
		}
	}

	return dp[k]=ans;
}

int main()
{
	int k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin >> arr[i];
	vector<int> dp(k+1, -1);
	rec(k, arr, dp) == true ? cout << "First" : cout << "Second";
}