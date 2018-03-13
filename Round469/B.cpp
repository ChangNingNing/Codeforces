#include <bits/stdc++.h>

#define LL long long int
#define F first
#define S second
#define MP make_pair
#define MAX(a, b) (a>b? a: b)
#define MIN(a, b) (a<b? a: b)
using namespace std;
typedef pair<int, int> PII;

#define MAXN 100001
int n, m;
int A[2][MAXN];
int ans = 0;

int main(){
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++)
		scanf("%d", &A[0][i]);
	for (int i=0; i<m; i++)
		scanf("%d", &A[1][i]);

	int ptr[2] = {0}, f = 0, tmp = 0;
	while (ptr[0]<n || ptr[1]<m){
		if (tmp == 0){
			f = !(A[0][ptr[0]] > A[1][ptr[1]]);
			tmp = A[f][ptr[f]++];
		}
		if (tmp >= A[!f][ptr[!f]])
			tmp -= A[!f][ptr[!f]++];
		else {
			tmp = A[!f][ptr[!f]++] - tmp;
			f = !f;
		}
		if (tmp == 0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
