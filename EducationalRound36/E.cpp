#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

typedef pair<int, int> pii;
set<pii> s;
set<pii>::iterator it1, it2;
int n, q, nW;
int main(){
	scanf("%d\n%d", &n, &q);

	s.insert(mp(1, n));
	nW = n;

	while (q--){
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		if (k == 1){
			it1 = s.lower_bound(mp(l, l));
			if (it1 != s.begin()){
				it2 = it1; --it2;
				if (it2->second >= r){
					s.insert(mp(it2->first, l-1));
					if (it2->second > r) s.insert(mp(r+1, it2->second));
					s.erase(it2);
					nW -= r - l + 1;
				}
				else if (it2->second >= l){
					s.insert(mp(it2->first, l-1));
					nW -= it2->second - l + 1;
					s.erase(it2);
				}
			}
			for (; it1 != s.end() && it1->second<=r;){
				nW -= it1->second - it1->first + 1;
				s.erase(it1++);
			}
			if (it1 != s.end() && it1->first <= r){
				nW -= r - it1->first + 1;
				s.insert(mp(r+1, it1->second));
				s.erase(it1);
			}
		}
		else {
			it1 = s.lower_bound(mp(l, l));
			int x = l, y = r;
			if (it1 != s.begin()){
				it2 = it1; --it2;
				if (it2->second >= r){
					printf("%d\n", nW);
					continue;
				}
				else if (it2->second >= l && it2->second < r){
					x = it2->first;
					nW -= it2->second - it2->first + 1;
					s.erase(it2);
				}
			}
			for (; it1 != s.end() && it1->second<=r;){
				nW -= it1->second - it1->first + 1;
				s.erase(it1++);
			}
			if (it1 != s.end() && it1->first <= r){
				y = it1->second;
				nW -= it1->second - it1->first + 1;
				s.erase(it1);
			}
			nW += y - x + 1;
			s.insert(mp(x, y));
		}
		printf("%d\n", nW);
	}
	return 0;
}
