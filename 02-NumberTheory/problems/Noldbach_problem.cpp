#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 1005

bool p[N];
vector <int> primes;
void sieve(){
    p[1] = 1;
	for(int i=2; i<N; i++){
		if(!p[i]){
            primes.push_back(i);
            for(ll j=1LL*i*i; j<N; j+=i) p[j] = 1;
        }
    }
}

int f[N];

void fill(){
    for(int i=1; i<primes.size(); i++){
        int v = 1 + primes[i] + primes[i-1];
        if(v >= N) break;
        if(!p[v])
            f[v] = 1;
    }
    for(int i=1; i<N; i++){
    	if(f[i])
    		f[i] = f[i-1] + 1;
    	else
    		f[i] = f[i-1];
    }
}

int main(){
    sieve();
    fill();
    int n, k; 
    cin >> n >> k;
    if(f[n] >= k) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
