/*************************************************************************
    > File Name: eight-digit.cpp
    > Author: nhywieza
    > Mail: nhywieza@gmail.com 
    > Created Time: 三 11/18 10:23:11 2015
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9;
int st[N];
int op[N];
int pre[N];
int x[N];
int y[N];
queue<int> q;
int a[3][3];
int fac[10];
int dx[] = {
	0, 1, 0, -1
};
int dy[] = {
	1, 0, -1, 0
};
void init(){
	fac[0] = 1;
	for (int i = 1;i < 9; i++){
		fac[i] = fac[i - 1] * i;
	}
}
void discal(int hash){
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
int cal(){
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
void bfs(){
	memset(st, -1, sizeof(st));
	memset(pre, -1, sizeof(pre));
	memset(op, -1, sizeof(op));
	st[0] = 0;
	x[0] = 2;
	y[0] = 2;
	q.push(0);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		int ux = x[u];
		int uy = y[u];
		for (int i = 0; i < 4; i++){
			int vx = ux + dx[i];
			int vy = uy + dy[i];
			if (vx < 0 || vx >= 3) continue;
			if (vy < 0 || vy >= 3) continue;
			discal(u);
			swap(a[ux][uy], a[vx][vy]);
			int v = cal();
			if (st[v] != -1) continue;
			st[v] = st[u] + 1;
			op[v] = i;
			pre[v] = u;
			x[v] = vx;
			y[v] = vy;
			q.push(v);
		}
	}
}
void dfs(int u){
	char ch[] = {
		'r', 'd', 'l', 'u'	
	};
	if (u == 0){
		return;
	}
	printf("%c", ch[op[u]]);
	dfs(pre[u]);
}
int main(){
	freopen("in", "r", stdin);
	init();
	bfs();
	char s[9][9];
	while (scanf("%s", s[0]) != EOF){
		for (int i = 1; i < 9; i++){
			scanf("%s", s[i]);
		}
		for (int i = 0; i < 9 ; i++){
			int x;
			if (s[i][0] == 'x') x = 9;
			else x = s[i][0] - '0';
			a[i / 3][i % 3] = x;
		}
		int v = cal();
		if (st[v] == -1) printf("unsolvable");
		else dfs(v);
		printf("\n");
	}
    return 0;
}
