#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    int st[n];
    int S = 0;
    for(int i=0; i<n; i++){
        cin >> st[i];
        S += st[i];
    }
    int ans = S;
    for(int i=0; i<(1<<n); i++){
        int current_sum = 0;
        for(int j=0; j<n; j++){
            if(i & (1<<j))
                current_sum += st[j];
        }
        ans = min(ans, abs(S-2*current_sum));
    }
    cout << ans << '\n';
    return 0;
}