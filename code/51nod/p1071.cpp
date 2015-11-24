/*************************************************************************
    > File Name: p1071.cpp
    > Author: nhywieza
    > Mail: nhywieza@gmail.com 
    > Created Time: 二 11/24 13:55:44 2015
 ************************************************************************/

#include <cstdio>
#include <cstring>

int main(){
	int n;
	scanf("%d", &n);
	int res = 0;
	for (int i = 0; i < n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		res ^= x % y;
	}
	printf("%c\n", res ? 'A' : 'B');
    return 0;
}
