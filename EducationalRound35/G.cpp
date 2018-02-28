//#include <bits/stdc++.h>
#include <iostream>

#define LL long long int
#define F first
#define S second
#define MP make_pair
#define MAX(a, b) (a>b? a: b)
#define MIN(a, b) (a<b? a: b)
using namespace std;

#define MAXN 20001
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

int insert_seg(int rx, int ry, int l, int r){
	if (ry == 0){
		node[nNode].l = l;
		node[nNode].r = r;
		ry = nNode++;
	}
	if (node[rx].l == l && node[rx].r == r)
		return rx;

	int mid = (l + r)>>1;
	if (node[rx].r <= mid)
		node[ry].lc = insert_seg(rx, node[ry].lc, l, mid);
	else if (node[rx].l > mid)
		node[ry].rc = insert_seg(rx, node[ry].rc, mid+1, r);
	/*
	else{
		node[ry].lc = insert_seg(rx, node[ry].lc, l, mid);
		node[ry].rc = insert_seg(rx, node[ry].rc, mid+1, r);
	}
	*/
	return ry;
}

int migrate(int rx, int ry, int l, int r){
	if (rx == 0) return ry;
	if (node[rx].l == l && node[rx].r == r){
		ry = insert(rx, ry, 0, n-1);
		return ry;
	}
	int mid = (node[rx].l + node[rx].r)>>1;
	if (r <= mid)
		migrate(node[rx].lc, ry, l, r);
	else if (l > mid)
		migrate(node[rx].rc, ry, l, r);
	else {
		migrate(node[rx].lc, ry, l, mid);
		migrate(node[rx].rc, ry, mid+1, r);
	}
	return ry;
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
		T[_y] = migrate(T[_x], T[_y], _l, _r);
	}

	myPrint();
	return 0;
}
