#include <stdio.h>

#define MIN(a, b) (a<b? a: b)

int main(){
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	int r = MIN(a, b), l = 1;
	while (l <= r){
		int mid = (l + r) >> 1;

		int _a = a / mid, _b = b / mid;
		if (_a + _b >= n) l = mid+1;
		else r = mid-1;
	}
	printf("%d\n", r);
	return 0;
}
