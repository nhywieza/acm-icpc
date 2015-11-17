/*************************************************************************
    > File Name: e.cpp
    > Author: nhywieza
    > Mail: nhywieza@gmail.com 
    > Created Time: 二 11/17 16:45:41 2015
 ************************************************************************/

#include <cstdio>
#include <cstring>
#define SIZE 102
int mat[SIZE][SIZE];  /*图矩阵*/
int dp[SIZE];
int mx;
int stack[SIZE][SIZE];
int a[SIZE][SIZE];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char s[SIZE][SIZE];
int flag[10];
void dfs(int N,int num,int step){

    if(num==0){
        if(step > mx){
            mx=step;
        }
        return ;
    }

    for(int i=0;i<num;i++){
        int k = stack[step][i];
        if(step+N-k<=mx) return ;
        if(step+dp[k]<=mx) return ;
        int cnt = 0;
        for(int j=i+1;j<num;j++)
            if(!mat[k][stack[step][j]]){
                 stack[step+1][cnt++]=stack[step][j];
            }
        dfs(N,cnt,step+1);
    }
}

void run(int N){

    mx =0;
    for(int i=N-1;i>=0;i--){
        int sz =0;
        for(int j=i+1;j<N;j++)
            if(!mat[i][j]) stack[1][sz++]=j;
        dfs(N,sz,1);
        dp[i]=mx;
    }
}
int main(){
	freopen("in", "r", stdin);
	int T, nCase = 0;
	for (scanf("%d", &T); T; T--){
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++){
			scanf("%s", s[i]);
		}
		memset(flag, -1, sizeof(flag));
		int num = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (s[i][j] == '.'){
					a[i][j] = num++;
				}else{
					if (flag[s[i][j] - '0'] == -1){
						a[i][j] = num;
						flag[s[i][j] - '0'] = num++;
					}else{
						a[i][j] = flag[s[i][j] - '0'];
					}
				}
			}
		}
		memset(mat, 0 ,sizeof(mat));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				int u = a[i][j];
				for (int k = 0; k < 4; k++){
					int x = i + dx[k];
					int y = j + dy[k];
					if (x < 0 || x >= n) continue;
					if (y < 0 || y >= m) continue;
					int v = a[x][y];
					if (u == v) continue;
					mat[u][v] = true;
				}
			}
		}
		run(num);
		printf("Case #%d: %d\n", ++nCase, mx);
	}
    return 0;
}
