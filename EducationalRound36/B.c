#include <stdio.h>

#define MIN(a, b) (a<b? a: b)
#define ABS(a) (a<0? -(a): a)
int main(){
	int n, pos, l, r;
	scanf("%d %d %d %d", &n, &pos, &l, &r);
	int sec = 0;
	if (l > 1 && r == n){
		sec = ABS(pos - l) + 1;
	}
	else if (l == 1 && r < n){
		sec = ABS(r - pos) + 1;
	}
	else if (l > 1 && r < n){
		sec = MIN(ABS(pos-l), ABS(r-pos)) + 1;
		sec += r - l + 1;
	}
	printf("%d\n", sec);
	return 0;
}
