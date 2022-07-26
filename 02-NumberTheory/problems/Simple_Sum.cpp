#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define N 10000005

int phi[N];
void sieve(){
	phi[1] = 1;
	for(int i=2; i<N; i++){
		if(phi[i] == 0){
			phi[i] = i-1;
			for(ll j=2LL*i; j<N; j+=i){
				if(phi[j] == 0) phi[j] = j;
				phi[j] = phi[j]/i*(i-1);
			}
		}
	}
}

int main(){
    FIFO;
    sieve();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll ans = 0;
        for(int i=1; i*i<=n; i++){
            if(n%i == 0){
                ans += 1LL * i * phi[i];
                if(i != n/i) ans += 1LL * (n/i) * phi[n/i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
