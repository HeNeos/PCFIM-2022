#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 100000005

bitset <N> primes;
vector <int> pr;
void sieve(){
	for(int i=2; i<N; i++){
		if(!primes[i]){
			pr.push_back(i);
			for(ll j=1LL*i*i; j<N; j+=i) primes[j] = 1;
		}
	}
}

int main(){
	sieve();
	int q; cin >> q;
	while(q--){
		int k; cin >> k;
		k--;
		cout << pr[k] << '\n';
	}
	return 0;
}
