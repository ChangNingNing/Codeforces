#include <stdio.h>
#include <string.h>
char A[20], B[20], C[20];
int T[10];
void Print(int index, int n){
	for (int i=index; i<n; i++){
		for (int j=9; j>=0; j--){
			if (T[j]){
				T[j]--;
				A[i] = j+'0';
				break;
			}
		}
	}
	printf("%s\n", A);
}
int Put(int index, int n){
	if (index == n){
		Print(index, n);
		return 1;
	}
	for (int i=B[index]-'0'; i>=0; i--){
		if (T[i]){
			T[i]--;
			A[index] = i+'0';
			if (i !=B[index]-'0'){
				Print(index+1, n);
				return 1;
			}
			if (Put(index+1, n))
				return 1;
			T[i]++;
		}
	}
	return 0;
}
int main(){
	scanf("%s %s", A, B);
	int lenA = strlen(A), lenB = strlen(B);
	for (int i=0; i<lenA; i++)
		T[A[i]-'0']++;
	if (lenA == lenB)
		Put(0, lenA);
	else
		Print(0, lenA);
	return 0;
}
