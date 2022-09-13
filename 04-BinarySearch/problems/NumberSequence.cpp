#include <iostream>
using namespace std;
#define N 40005

long long dp[N];
long long acum[N];

int digits(int x){
    int ans = 0;
    while(x){
        x /= 10;
        ans++;
    }
    return ans;
}

void fill(){
    dp[0] = 0; acum[0] = 0;
    for(int i=1; i<N; i++){
        dp[i] = dp[i-1] + digits(i);
        acum[i] = acum[i-1] + dp[i];
    }
}
int main(){
    fill();
    int t; cin >> t;
    while(t--){
        long long x;
        cin >> x;
        int lo = 0;
        int hi = N-2;
        while(lo < hi){
            // F T
            int me = lo + (hi - lo)/2;
            if(acum[me] >= x) hi = me;
            else lo = me + 1;
        }
        long long res = x - acum[lo-1];
        lo = 1;
        hi = N-2;
        while(lo < hi){
            int me = lo + (hi - lo)/2;
            if(dp[me] >= res) hi = me;
            else lo = me + 1;
        }
        res = res - dp[lo-1];
        string number = to_string(lo);
        cout << number[res-1] << '\n';
    }
    return 0;
}