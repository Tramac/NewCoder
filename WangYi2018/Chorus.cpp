#include <stdio.h>
#include <stdlib.h>

typedef long long llong;

inline void getMin(llong& n, llong x) {
	n > x && (n = x);
}

#define MAXN 2020

int n;
int v[MAXN], cost[MAXN];

void read() {
	scanf("%d%d", &n, v);
	for (int i = 1; i < n; ++i) {
		scanf("%d", v + i);
		cost[i] = abs(v[i] - v[i - 1]);
	}
}

llong dp[MAXN][MAXN];

void work() {
	llong res = (1ll << 63) - 1;
	for (int i = 2; i < n; ++i) {
		//    dp[i][0] = dp[i - 1][0] + cost[i];
		dp[i][i - 1] = dp[i - 1][i - 2] + cost[i - 1];
	}
	for (int i = 2; i < n; ++i) {
		for (int j = 0; j < i - 1; ++j) {
			dp[i][j] = dp[i - 1][j] + cost[i];
			getMin(dp[i][i - 1], dp[i - 1][j] + abs(v[i] - v[j]));
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		getMin(res, dp[n - 1][i]);
	}
	printf("%lld\n", res);
}

int main() {
	read();
	work();
	return 0;
}
