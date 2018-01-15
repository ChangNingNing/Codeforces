#include <stdio.h>
#include <limits.h>

int main(){
	int N;
	scanf("%d", &N);
	int min = INT_MAX, minP = -1, near = INT_MAX;
	for (int i=0; i<N; i++){
		int tmp;
		scanf("%d", &tmp);
		if (tmp == min){
			if (i - minP < near)
				near = i - minP;
			minP = i;
		}
		else if (tmp < min){
			min = tmp;
			minP = i;
			near = INT_MAX;
		}
	}
	printf("%d\n", near);
	return 0;
}
