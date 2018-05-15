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

int n, m, h;
int U[MAXN];

vector<int> V[MAXN];
int C[MAXN], L[MAXN], S[MAXN], R[MAXN], t = 0, top = 0;
int SCC[MAXN], out[MAXN], nSCC = 1;

void DFS(int v){
	L[v] = C[v] = ++t;
	S[top++] = v;

	for (int e:V[v]){
		if (!C[e])
			DFS(e);
		if (!R[e])
			L[v] = MIN(L[v], L[e]);
	}

	if (C[v] == L[v]){
		for (int i = S[--top]; i!=v; i = S[--top])
			R[i] = nSCC;
		R[v] = nSCC++;
	}
	return;
}

int main(){
	scanf("%d %d %d", &n, &m, &h);
	for (int i=1; i<=n; i++)
		scanf("%d", &U[i]);
	for (int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if ((U[a]+1) % h == U[b])
			V[a].push_back(b);
		if ((U[b]+1) % h == U[a])
			V[b].push_back(a);
	}

	for (int i=1; i<=n; i++)
		if (!C[i]) DFS(i);

	for (int i=1; i<=n; i++){
		SCC[R[i]] += 1;
		for (int e:V[i])
			if (R[e] != R[i]) out[R[i]] += 1;
	}

	int min = MAXN+1, minP = -1;
	for (int i=1; i<nSCC; i++){
		if (out[i] == 0)
			if (SCC[i] < min)
				min = SCC[i], minP = i;
	}

	printf("%d\n", min);
	for (int i=1; i<=n; i++){
		if (R[i] == minP)
			printf("%d ", i);
	}
	return 0;
}
