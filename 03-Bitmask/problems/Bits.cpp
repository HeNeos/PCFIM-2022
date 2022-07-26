#include <iostream>

using namespace std;

long long solve(long long l, long long r){
    if(__builtin_popcountll(r+1) == 1)
        return r;
    int l_pos = 63 - __builtin_clzll(l);
    int r_pos = 63 - __builtin_clzll(r);
    if(l_pos != r_pos)
        return (1LL<<(r_pos))-1;
    else
        return (1LL<<l_pos) + solve(l - (1LL<<l_pos), r - (1LL<<l_pos));
}


int main(){
    int n; cin >> n;
    while(n--){
        long long l, r;
        cin >> l >> r;
        cout << solve(l, r) << '\n';
    }
    return 0;
}