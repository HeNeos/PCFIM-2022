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
	for(int i=0; i<pr.size(); i+=100){
		if(pr[i] > 100000000) break;
		cout << pr[i] << '\n';
	}
	return 0;
}
