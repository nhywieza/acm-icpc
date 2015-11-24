/*************************************************************************
    > File Name: p1052.cpp
    > Author: nhywieza
    > Mail: nhywieza@gmail.com 
    > Created Time: 四 11/19 19:03:50 2015
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 5001;
const int M = 5001;
const int INF = 10000000;
long long dp[2][M][2];
int a[N];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 0; i <= 1 i++){
		for (int j = 0;j <=m; j++){
			dp[i][j][0] = -INF;
			dp[i][j][1] = -INF;
		}
	}
	dp[0][0][0] = 0;
	dp[0][0][1] = 0;
	for (int i = 1; i <= n; i++){
		dp[i & 1][0][0] = 0;
		dp[i & 1][0][1] = 0;
		for (int j = 1; j <= m; j++){
			dp[i & 1][j][0] = max(dp[i & 1 ^ 1][j][0], dp[i & 1 ^ 1][j][1]);
			dp[i & 1][j][1] = max(dp[i & 1 ^ 1][j- 1][0], dp[i & 1 ^ 1][j - 1][1]) + a[i];
			dp[i & 1][j][1] = max(dp[i & 1][j][1], dp[i & 1 ^ 1][j][1] + a[i]);
		}
	}
	cout<<max(dp[n&1][m][0], dp[n&1][m][1])<<endl;
	return 0;
}
