/*************************************************************************
    > File Name: p1020.cpp
    > Author: nhywieza
    > Mail: nhywieza@gmail.com 
    > Created Time: 四 11/19 18:20:48 2015
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int N = 1000;
const int K = 20000;
const int mod = int(1e9) + 7;
int dp[N + 1][K + 1];
int main(){
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= N; i++){
		for (int j = 0; j <= (i - 1) * i / 2 && j <= K; j++){
			if (j == 0){
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
			if (j >= i) dp[i][j] = (dp[i][j] + mod - dp[i - 1][j - i]) % mod;
		}
	}
	int T;
	freopen("in", "r", stdin);
	for (scanf("%d", &T); T; T--){
		int n,k;
		scanf("%d %d", &n, &k);
		printf("%d\n", dp[n][k]);
	}
    return 0;
}
