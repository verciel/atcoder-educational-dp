#include<bits/stdc++.h>
using namespace std;

int h,w;
int mod = 1e9+7;

int rec(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& dp)
{
	if(row >= h || col >= w) return 0;
	if(row == h-1 && col == w-1) return 1;

	if(dp[row][col] != -1) return dp[row][col];

	int right=0, down=0;
	//mpve possible if no obstacle and not out of bounds
	if(col+1 < w && grid[row][col+1] != '#') right+= rec(grid, row, col+1, dp);
	if(row+1 < h && grid[row+1][col] != '#') down+= rec(grid, row+1, col, dp);
	return dp[row][col] = (right+down)%mod;
}

int main()
{
	cin >> h >> w;	

	vector<vector<char>> grid(h, vector<char> (w));
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin >> grid[i][j];
		}
	}

	vector<vector<int>> dp(h, vector<int>(w, -1));
	cout << rec(grid, 0, 0, dp);	
}