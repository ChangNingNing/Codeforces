#include <bits/stdc++.h>

#define LL long long int
#define F first
#define S second
#define MP make_pair
#define MAX(a, b) (a>b? a: b)
#define MIN(a, b) (a<b? a: b)
using namespace std;
typedef pair<int, int> PII;

#define N 1501
int n, m;
int a[N];

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d", &a[i]);
	int sum = 0;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			if (a[j] < a[i])
				sum++;

	scanf("%d", &m);
	for (int i=0; i<m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		if (((y - x + 1)>>1) & 1) sum += 1;
		else sum += 2;

		if ((sum & 1) && (sum = 1)) printf("odd\n");
		else printf("even\n");
	}
	return 0;
}
