#include <bits/stdc++.h>

#define LL long long int
#define F first
#define S second
#define MP make_pair
#define MAX(a, b) (a>b? a: b)
#define MIN(a, b) (a<b? a: b)
using namespace std;
typedef pair<int, int> PII;

#define MAXN 200001
int n;
vector<int> e[MAXN];
int dep[MAXN], fa[MAXN], isU[MAXN];
int m_dist, m_l, root;
LL ans;
struct Node{
	int a, b, c;
};
vector<Node> op;

void DFS(int x, int fx){
	fa[x] = fx;
	if (x != fx) dep[x] = dep[fx]+1;
	if (dep[x] > m_dist) m_dist = dep[x], m_l = x;
	for (auto i:e[x]){
		if (i != fx)
			DFS(i, x);
	}
	return;
}

void Destruct(int x, int dist, int rx, int flag = 0){
	isU[x] = 1;
	for (auto i:e[x]){
		if (!isU[i])
			Destruct(i, dist+1, rx, 1);
	}
	if (flag){
		ans += dist;
		op.push_back(Node{rx, x, x});
	}
	return;
}

int main(){
	scanf("%d", &n);
	for (int i=0; i<n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}

	DFS(1, 1);
	m_dist = 0, dep[root = m_l] = 0;
	DFS(root, root);

	fa[root] = 0;
	for (int i=m_l; i; i=fa[i])
		isU[i] = 1;

	for (int i=m_l; i; i=fa[i]){
		if (dep[i] > dep[m_l]-dep[i])
			Destruct(i, dep[i], root);
		else
			Destruct(i, dep[m_l]-dep[i], m_l);
	}
	ans += (LL)(m_dist+1)*m_dist/2;

	printf("%lld\n", ans);
	for (int i=0; i<op.size(); i++)
		printf("%d %d %d\n", op[i].a, op[i].b, op[i].c);
	for (int i=m_l; i!=root; i=fa[i])
		printf("%d %d %d\n", root, i, i);

	return 0;
}
