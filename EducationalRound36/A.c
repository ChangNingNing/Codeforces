#include <stdio.h>
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int min = 10000;
	for (int i=0; i<n; i++){
		int a;
		scanf("%d", &a);
		if (k % a == 0 && k / a < min)
			min = k / a;
	}
	printf("%d\n", min);
	return 0;
}
