#include <bits/stdc++.h>

#define LL long long int
#define F first
#define S second
#define MP make_pair
#define MAX(a, b) (a>b? a: b)
#define MIN(a, b) (a<b? a: b)
using namespace std;
typedef pair<int, int> PII;

#define N 1000001
int n;
int A[N];
int s[N];
int sz[N];
pair <int, PII> e[N];

int find_set(int x){
	if (s[x] == x) return x;
	return s[x] = find_set(s[x]);
}
void union_set(int x, int y){
	int rx = find_set(x), ry = find_set(y);
	if (rx == ry) return;
	if (sz[rx] > sz[ry])
		s[ry] = rx, sz[rx] += sz[ry];
	else
		s[rx] = ry, sz[ry] += sz[rx];
	return;
}

LL sigmaPath(){
	LL ans = 0;
	for (int i=1; i<n; i++){
		int a = e[i].S.F, b = e[i].S.S;
		int ra = find_set(a), rb = find_set(b);
		ans += (LL)sz[ra]*sz[rb]*e[i].F;
		union_set(ra, rb);
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &A[i]);
	for (int i=1; i<n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		e[i] = MP(0, MP(a, b));
	}
	LL ans = 0;

	for (int i=1; i<=n; i++) s[i] = i, sz[i] = 1;
	for (int i=1; i<n; i++) e[i].F = MAX(A[e[i].S.F], A[e[i].S.S]);
	sort(e+1, e+n);
	ans = sigmaPath();

	for (int i=1; i<=n; i++) s[i] = i, sz[i] = 1;
	for (int i=1; i<n; i++) e[i].F = -MIN(A[e[i].S.F], A[e[i].S.S]);

	sort(e+1, e+n);
	ans += sigmaPath();
	printf("%I64d\n", ans);
	return 0;
}
