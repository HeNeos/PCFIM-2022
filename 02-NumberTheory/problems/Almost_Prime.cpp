#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 5005

int lpf[N];
void sieve(){
	for(int i=2; i<N; i++){
		if(!lpf[i]){
			lpf[i] = i;
			for(ll j=1LL*i*i; j<N; j+=i){
				if(lpf[j] == 0) lpf[j] = i;
			}
		}
	}
}

int solve(int x){
	int ans = 0;
	while(x > 1){
		int p = lpf[x];
		while(x%p == 0)
			x /= p;
		ans++;
	}
	return ans;
}

int main(){
    sieve();
    int n; 
    cin >> n;
    int ans = 0;
    for(int i=1; i<=n; i++){
    	if(solve(i) == 2) ans++;
    }
    cout << ans << '\n';
    return 0;
}
