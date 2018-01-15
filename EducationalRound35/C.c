#include <stdio.h>
#define LL long long int
LL GCD(LL a, LL b){
	LL c;
	while (a != 0){
		c = a; a = b % a; b = c;
	}
	return b;
}

LL LCM(LL a, LL b){ return a * b / GCD(a, b); }

int try (int x1, int x2, int x3, LL lcm){
	int ret = 1;
	for (LL i=3; i<lcm; i++){
		if (i%x1 == 0 || (i-1)%x2 == 0 || (i-2)%x3 == 0) continue;
		ret = 0;
		break;
	}
	return ret;
}
int main(){
	int x1, x2, x3;
	scanf("%d %d %d", &x1, &x2, &x3);
	LL lcm = LCM(LCM(x1, x2), x3), ret = 1;
	if (try(x1, x2 ,x3, lcm) || try(x1, x3, x2, lcm) ||
		try(x2, x1, x3, lcm) || try(x2, x3, x1, lcm) ||
		try(x3, x1, x2, lcm) || try(x3, x2, x1, lcm) )
		printf("YES\n");
	else printf("NO\n");
	return 0;
}
