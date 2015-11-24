/*************************************************************************
    > File Name: p1128.cpp
    > Author: nhywieza
    > Mail: nhywieza@gmail.com 
    > Created Time: 二 11/24 16:32:11 2015
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <climits>
const int N = 50000;
long long a[N];
int n, k;
bool check(long long limit){
	int res = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++){
		if (a[i] > limit) return false;
		if (res > k) return false;
		if (sum + a[i] > limit){
			sum = a[i];
			res++;
		}else{
			sum += a[i];
		}
	}
	return res < k;
}
int main(){
	freopen("in", "r", stdin);
	scanf("%d %d",&n, &k);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	long long l = 1, r = LLONG_MAX;
	while (l < r){
		long long mid = (l + (r - l) / 2);
		if (check(mid)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	printf("%lld\n", l);
    return 0;
}
