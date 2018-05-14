#include <bits/stdc++.h>

#define LL long long int
#define F first
#define S second
#define MP make_pair
#define MAX(a, b) (a>b? a: b)
#define MIN(a, b) (a<b? a: b)
using namespace std;
typedef pair<int, int> PII;

LL n, q;

int main(){
	scanf("%lld %lld", &n, &q);
	for (int i=0; i<q; i++){
		LL p, iter;
		scanf("%lld", &p);
		iter = p;
		while ((iter&1) == 0){
			iter += n - (iter>>1);
		}
		printf("%lld\n", (iter+1)>>1);
	}
	return 0;
}
