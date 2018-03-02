#include <bits/stdc++.h>

#define LL long long int
#define F first
#define S second
#define MP make_pair
#define MAX(a, b) (a>b? a: b)
#define MIN(a, b) (a<b? a: b)
using namespace std;

#define MAXN 200001
#define MAXA 101

struct Node {
	int l, r;
	int lc, rc;
};

Node node[MAXN*105];
int T[MAXA];
int nNode = 1, n, q;

int insert(int root, int l, int r, int pos){
	if (root == 0){
		node[nNode].l = l;
		node[nNode].r = r;
		root = nNode++;
	}
	if (l == r)
		return root;
	int mid = (l + r)>>1;
	if (pos <= mid)
		node[root].lc = insert(node[root].lc, l, mid, pos);
	else
		node[root].rc = insert(node[root].rc, mid+1, r, pos);
	return root;
}

void split(int& rx, int& rt, int l, int r, int pos){
	if (rx == 0) return;
	if (r <=pos) return;
	if (l > pos){
		rt = rx;
		rx = 0;
		return;
	}
	int mid = (l + r)>>1;
	node[nNode].l = l;
	node[nNode].r = r;
	rt = nNode++;
	split(node[rx].lc, node[rt].lc, l, mid, pos);
	split(node[rx].rc, node[rt].rc, mid+1, r, pos);
	if (node[rx].lc==0 && node[rx].rc==0) rx = 0;
	if (node[rt].lc==0 && node[rt].rc==0) rt = 0;
	return;
}

int merge(int rx, int rt){
	if (rx == 0) return rt;
	if (rt == 0) return rx;
	node[rx].lc = merge(node[rx].lc, node[rt].lc);
	node[rx].rc = merge(node[rx].rc, node[rt].rc);
	return rx;
}

int ans[MAXN];
void DFS(int value, int root){
	if (root == 0) return;
	if (node[root].l == node[root].r){
		ans[node[root].l] = value;
		return;
	}
	DFS(value, node[root].lc);
	DFS(value, node[root].rc);
	return;
}
void myPrint(){
	for (int i=1; i<MAXA; i++)
		DFS(i, T[i]);
	for (int i=0; i<n; i++)
		printf("%d%c", ans[i], " \n"[i==n-1]);
	return;
}

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		int a;
		scanf("%d", &a);
		T[a] = insert(T[a], 0, n-1, i);
	}
	scanf("%d", &q);
	for (int i=0; i<q; i++){
		int _l, _r, _x, _y;
		scanf("%d %d %d %d", &_l, &_r, &_x, &_y);
		if (_x == _y) continue;
		_l--, _r--;
		int t1 = 0, t2 = 0;
		split(T[_x], t1, 0, n-1, _l-1);
		split(t1, t2, 0, n-1, _r);
		T[_y] = merge(T[_y], t1);
		T[_x] = merge(T[_x], t2);
	}

	myPrint();
	return 0;
}
