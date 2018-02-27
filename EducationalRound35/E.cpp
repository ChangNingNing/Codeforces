#include <bits/stdc++.h>

#define LL long long int
#define F first
#define S second
#define MP make_pair
#define MAX(a, b) (a>b? a: b)
#define MIN(a, b) (a<b? a: b)
using namespace std;

#define MAXN 200001
int n, k;
int ans[MAXN];
stack<int> s;

int main(){
	scanf("%d %d", &n, &k);
	int index = 1;
	for (int i=0; i<n; i++){
		int tmp;
		if (i<k) scanf("%d", &tmp);
		else if (s.size()) tmp = s.top()-1;
		else tmp = n;
		s.push(tmp);
		ans[i] = tmp;
		while (s.size() && s.top() == index){
			s.pop();
			index++;
		}
	}
	if (index == n+1)
		for (int i=0; i<n; i++)
			printf("%d%c", ans[i], " \n"[i==n-1]);
	else
		printf("-1\n");
	return 0;
}
