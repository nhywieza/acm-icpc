/*************************************************************************
    > File Name: eight-digit2.cpp
    > Author: nhywieza
    > Mail: nhywieza@gmail.com 
    > Created Time: 三 11/18 16:04:12 2015
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9;
int st[9][N];
int op[9][N];
int pre[9][N];
int x[N];
int y[N];
int a[3][3];
int fac[10];
int mp[10];
int cnt = 0;
int dx[] = {
	0, 1, 0, -1
};
int dy[] = {
	1, 0, -1, 0
};
queue<int> q;
void init(){
	fac[0] = 1;
	for (int i = 1;i < 9; i++){
		fac[i] = fac[i - 1] * i;
	}
	memset(st, -1, sizeof(st));
}
void discal(int hash,int a[][3]){
	bool flag[10];
	memset(flag, 0, sizeof(flag));
	for (int i = 0; i < 9; i++){
		int num = hash / fac[8 - i] + 1;
		hash %= fac[8 - i];
		int x, j;
		for (x = 0, j = 1; j <= 9; j++){
			if (!flag[j]) x++;
			if (x == num) break;
		}
		a[i / 3][i % 3] = j;
		flag[j] = true;
	}
}
int cal(int a[][3]){
	bool flag[10];
	memset(flag, 0, sizeof(flag));
	int hash = 0;
	for (int i = 0; i < 9; i++){
		int x = a[i / 3][i % 3];
		int j, num;
		for (j = 1, num = 0;j < x; j++){
			if (!flag[j]) num++;
		}
		hash += fac[8 -i] * num;
		flag[x] = true;
	}
	return hash;
}
void bfs(int index, int S){
	st[index][S] = 0;
	q.push(S);
	discal(S, a);
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (a[i][j] == 9){
				x[S] = i;
				y[S] = j;
			}
		}
	}
	while (!q.empty()){
		++cnt;
		int u = q.front();
		q.pop();
		int ux = x[u];
		int uy = y[u];
		for (int i = 0; i < 4; i++){
			int vx = ux + dx[i];
			int vy = uy + dy[i];
			if (vx < 0 || vx >= 3) continue;
			if (vy < 0 || vy >= 3) continue;
			discal(u, a);
			swap(a[ux][uy], a[vx][vy]);
			int v = cal(a);
			if (st[index][v] != -1) continue;
			st[index][v] = st[index][u] + 1;
			x[v] = vx;
			y[v] = vy;
			op[index][v] = i;
			pre[index][v] = u;
			q.push(v);
		}
	}
}
void print(int index, int u){
	char ch[] = {
		'r', 'd', 'l', 'u'
	};
	if (st[index][u] == 0) return;
	print(index, pre[index][u]);
	printf("%c", ch[op[index][u]]);
}
int main(){
	freopen("in", "r", stdin);
	init();
	int u = cal(a);
	for (int i = 0; i < 9; i++){
		int num = 1;
		for (int j = 0;j < 9; j++){
			if (i == j) continue;
			a[j / 3][j % 3] = num++;
		}
		int u = cal(a);
		bfs(i, u);
	}
	int T, nCase = 0;
	for (scanf("%d",&T); T; T--){
		char s[20];
		scanf("%s", s);
		int index;
		int num = 1;
		for (int i = 0; i < 9; i++){
			if (s[i] == 'X'){
				index = i;
			}else{
				mp[s[i] - '0'] = num++;
			}
		}
		scanf("%s",s);
		for (int i = 0; i < 9; i++){
			if (s[i] == 'X'){
				a[i / 3][i % 3] = 9;
			}else{	
				a[i / 3][i % 3] = mp[s[i] - '0'];
			}
		}
		int T = cal(a);
		printf("Case %d: %d\n", ++nCase, st[index][T]);
		print(index, T);
		printf("\n");
	}
    return 0;
}
