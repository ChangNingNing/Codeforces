#include <stdio.h>
#include <string.h>

int M[501][501];
int nM[501];
int edge[100000];
int isCycle[100000];
char isVisit[501];
int n, m;

int DFS(int index, int block, int trace){
	isVisit[index] = 1;
	for (int i=0; i<nM[index]; i++){
		int ptr = M[index][i];
		if (ptr != block){
			if (isVisit[edge[ptr]] == 1){
				if (trace)
					isCycle[ptr] = 1;
				return 0;
			}
			else if (isVisit[edge[ptr]] == 0){
				if (!DFS(edge[ptr], block, trace)){
					if (trace)
						isCycle[ptr] = 1;
					return 0;
				}
			}
		}
	}
	isVisit[index] = 2;
	return 1;
}
int main(){
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		M[a][nM[a]++] = i;
		edge[i] = b;
	}

	for (int i=1; i<=n; i++){
		if (isVisit[i] != 0) continue;
		DFS(i, -1, 1);
	}

	int flag = 1;
	for (int i=0; i<m; i++){
		if (!isCycle[i]) continue;
		memset(isVisit, 0, sizeof(char)*(n+1));
		flag = 1;
		for (int j=1; j<=n && flag; j++){
			if (isVisit[j] != 0) continue;
			flag &= DFS(j, i, 0);
		}
		if (flag) break;
	}
	if (flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}
