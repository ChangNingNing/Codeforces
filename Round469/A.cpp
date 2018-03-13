#include <bits/stdc++.h>

#define LL long long int
#define F first
#define S second
#define MP make_pair
#define MAX(a, b) (a>b? a: b)
#define MIN(a, b) (a<b? a: b)
using namespace std;
typedef pair<int, int> PII;

int l, r, a;
int ans = 0;

int main(){
	scanf("%d %d %d", &l, &r, &a);
	if (l > r){
		int t = l;
		l = r, r = t;
	}
	if (r - l <= a){
		a -= r - l;
		l = r;
	}
	else {
		l += a;
		a = 0;
	}
	if (a){
		l += a/2;
		r += a/2;
	}
	int tmp = MIN(l, r);
	l -= tmp, r -= tmp, ans += tmp<<1;
	printf("%d\n", ans);
	return 0;
}
