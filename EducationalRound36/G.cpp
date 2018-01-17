#include <bits/stdc++.h>

#define LL long long int
#define F first
#define S second
#define MP make_pair
#define MAX(a, b) (a>b? a: b)
#define MIN(a, b) (a<b? a: b)
using namespace std;
typedef pair<int, int> PII;

#define N 2000001
const LL mod = 1000000007;
int n, k;
LL F[N][2], A[N*2];

LL mod_add(LL x, LL y){
	return (x + y + mod) % mod;
}
LL mod_mul(LL x, LL y){
	return (x * y) % mod;
}
LL mod_pw(LL x, LL pw){
	LL ret = 1;
	while (pw){
		if (pw & 1) ret = mod_mul(ret, x);
		if (pw >>= 1) x = mod_mul(x, x);
	}
	return ret;
}

int main(){
	scanf("%d %d", &n, &k);
	for (int i=1; i<=k; i++) F[i][1] = i;
	for (int i=2; i<=k; i++){
		if (F[i][0] == 0){
			for (int j=(i<<1); j<=k; j+=i)
				F[j][1] /= i, F[j][0]++;
			F[i][0] = -1;
		}
		else if (F[i][1] == 1){
			if (F[i][0] & 1) F[i][0] = -1;
			else F[i][0] = 1;
		}
		else {
			F[i][0] = 0;
		}
		F[i][1] = mod_pw(i, n);
	}

	for (int i=1; i<=k; i++){
		if (!F[i][0]) continue;
		for (int j=i; j<=k; j+=i){
			A[j  ] = mod_add(A[j  ], F[i][0]*F[j/i][1]);
			A[j+i] = mod_add(A[j+i], -F[i][0]*F[j/i][1]);
		}
	}
	for (int i=2; i<=k; i++)
		A[i] = mod_add(A[i], A[i-1]);
	
	LL sum = 0;
	for (int i=1; i<=k; i++)
		sum = mod_add(sum, mod_add(A[i], F[i][1]) ^ (LL)i);
	printf("%I64d\n", sum);
	return 0;
}
