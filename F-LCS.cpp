#include<bits/stdc++.h>
using namespace std;

int n,m;
string s,t;

//stores the max LCS length for each state in memo dp
int rec(int i, int j, vector<vector<int>>& dp)
{
	if(i>n-1 || j>m-1) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	if(s[i] == t[j]) 
    	return dp[i][j] = 1 + rec(i+1, j+1, dp);
	else
    	return dp[i][j] = max(rec(i+1, j, dp), rec(i, j+1, dp));
}

//constructs 1 LCS by following the choices stored in memo dp
string lcs(int i, int j, vector<vector<int>>& dp)
{
	string ans;

	while(i<n && j<m)
	{
		if(s[i] == t[j])
		{
			ans+=s[i];
			i++;
			j++;

			continue;
		}
		
		int move1=dp[i+1][j];
		int move2=dp[i][j+1];

		if(move1 >= move2) i++;
		else j++;
		
	}

	return ans;
}

int main()
{
	cin >> s >> t;
	n=s.length(), m=t.length();
	vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
	if(rec(0,0,dp) > 0) cout << lcs(0,0,dp);
}