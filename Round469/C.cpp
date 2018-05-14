#include <bits/stdc++.h>

#define LL long long int
#define F first
#define S second
#define MP make_pair
#define MAX(a, b) (a>b? a: b)
#define MIN(a, b) (a<b? a: b)
using namespace std;
typedef pair<int, int> PII;

#define MAXC 200001
char S[MAXC];
int n;

vector<int> T[MAXC];
int par = -1, mpar = -1;

int main(){
	scanf("%s", S);
	n = strlen(S);
	for (int i=0; i<n; i++){
		if (S[i] == '0') {
			T[++par].push_back(i+1);
		}
		else if (S[i] == '1'){
			if (par < 0){
				printf("-1\n");
				return 0;
			}
			else {
				T[par--].push_back(i+1);
			}
		}
		mpar = MAX(mpar, par);
	}

	if (par != mpar){
		printf("-1\n");
		return 0;
	}
	printf("%d\n", mpar+1);
	for (int i=0; i<=mpar; i++){
		int num = T[i].size();
		printf("%d ", num);
		for (int j=0; j<num; j++)
			printf("%d%c", T[i][j], " \n"[j==num-1]);
	}
	return 0;
}
