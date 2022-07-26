#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define N 1000005
ll ans[N];

int divisors[N];
void sieve(){
    divisors[1] = 1;
	for(int i=1; i<N; i++){
		for(int j=i; j<N; j+=i) divisors[j]++;
	}
}

void fill(){
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 3;
    for(int i=3; i<N; i++){
        ans[i] = (2*ans[i-1] + divisors[i])%MOD;
        ans[i] = ((ans[i] - divisors[i-1])%MOD + MOD)%MOD;
    }
}
int main(){
    sieve();
    fill();
    int n; cin >> n;
    cout << ans[n];
    return 0;
}
