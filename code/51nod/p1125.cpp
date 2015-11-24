#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 50000;
bool flag[N];
pair<long long, int> a[N];
long long sum, cnt;
void dfs(int k){
	if (flag[k]) return;
	flag[k] = true;
	sum += a[k].first;
	cnt++;
	dfs(a[k].second);
}
int main(){
	freopen("in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%lld", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; i++){
		if (flag[i]) continue;
		cnt = 0;
		sum = 0;
		dfs(i);
		long long tmp1 = (cnt - 2) * a[i].first + sum;
		long long tmp2 = (cnt + 1) * a[0].first + sum  + a[i].first;
		if (tmp1 < tmp2) ans += tmp1;
		else ans += tmp2;
	}
	cout<<ans<<endl;
    return 0;
}
