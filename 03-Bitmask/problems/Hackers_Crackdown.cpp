#include <iostream>
#include <vector>
using namespace std;

#define INF (1<<30)

int main(){
    for(int test=1; ; test++){
        int N; cin >> N;
        if(N == 0) break;
        int a[N]; int cover[(1<<N)]; int dp[(1<<N)];
        fill_n(a, N, 0); fill_n(cover, (1<<N), 0); fill_n(dp, (1<<N), 0);
        for(int i=0; i<N; i++){
            int x; cin >> x;
            a[i] |= (1<<i);
            for(int j=0; j<x; j++){
                int v; cin >> v;
                a[i] |= (1<<v);
            }
        }
        for(int i=0; i<(1<<N); i++){
            for(int j=0; j<N; j++){
                if(i & (1<<j))
                    cover[i] |= a[j];
            }
        }
        for(int i=0; i<(1<<N); i++){
            for(int j=i; j; j=i&(j-1)){
                if(cover[j] == (1<<N) - 1) dp[i] = max(dp[i], 1 + dp[i^j]);
            }
        }
        cout << "Case " << test << ": " << dp[(1<<N) - 1] << '\n';
    }
    return 0;
}