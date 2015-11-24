/*************************************************************************
    > File Name: p1055.cpp
    > Author: nhywieza
    > Mail: nhywieza@gmail.com 
    > Created Time: 二 11/24 10:49:37 2015
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int N = 10000;
//const int big_mod = 2097593;
short dp[N][N];
int a[N];
/*struct Node{
	int key;
	short value;
}h[big_mod];
void insert_hash(int key, short value){
	int index = key;
	while (index >= big_mod) index -= big_mod;
	while (h[index].key != 0){
		index++;
		if (index >= big_mod) index = 0;
	}
	h[index].key = key;
	h[index].value = value;
}
short get_hash(int key){
	int index = key;
	while (index >= big_mod) index -= big_mod;
	if (index <=0 ) return -1;
	while (h[index].key != key){
		if (h[index].key == 0) return -1;
		index++;
		if (index >= big_mod) index = 0;
	}
	return h[index].value;
}*/
int main(){
	int n;
	freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	/*for (int i = 0; i < n; i++){
		insert_hash(a[i], short(i));
	}*/
	short ans = 0;
	for (int i = 1; i < n; i++){
		int k = 0;
		for (int j = 0; j < i; j++){
			while (k < n && a[k] < 2 * a[j] - a[i]) k++;
			if ((a[k] + a[i]) != 2 * a[j]){
				dp[i][j] = max(dp[i][j], short(1));
			}else{
				dp[i][j] = max(dp[i][j], short(dp[j][k] + 1));
			}
			if (dp[i][j] > ans) ans = dp[i][j];
		}
	}
	printf("%d\n", ans + 1);
    return 0;
}
