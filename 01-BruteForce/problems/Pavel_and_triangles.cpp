#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n; cin >> n;
	ll ans = 0;
	ll aux = 0;
	for(int i=0; i<n; i++){
		ll x; cin >> x;
		ll g1 = min(aux, x/2);
		aux -= g1;
		ans += g1;
		x -= 2*g1;
		ll g2 = x/3;
		x -= 3*g2;
		ans += g2;
		aux += x;
	}
	cout << ans;
	return 0;
}
