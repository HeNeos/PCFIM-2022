#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        // x - floor(x/n) == k
        // x == k + floor(x/n)
        // x == k + a
        // k+a == a*n + b
        // 0 <= k+a - a*n == b < n
        // -k <= a*(1-n) < n-k
        // k-n < a*(n-1) <= k
        // (k-n)/(n-1) < a <= k/(n-1)
        // (k-1)/(n-1) - 1 < a <= k/(n-1)
        // a = (k-1)/(n-1)
        // x = k + (k-1)/(n-1)
        cout << k + (k-1)/(n-1) << '\n';
    }
    return 0;
}
