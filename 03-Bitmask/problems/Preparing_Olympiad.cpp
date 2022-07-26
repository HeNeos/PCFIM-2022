#include <iostream>

using namespace std;

int main(){
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int ans = 0;
    for(int i=0; i<(1<<n); i++){
        int min_diff = (1<<25);
        int max_diff = -1;
        int total = 0;
        if(__builtin_popcount(i) >= 2){
            for(int j=0; j<n; j++){
                if(i & (1<<j)){
                    max_diff = max(max_diff, arr[j]);
                    min_diff = min(min_diff, arr[j]);
                    total += arr[j];
                }
            }
        }
        if(total >= l and total <= r and max_diff - min_diff >= x)
            ans++;
    }

    cout << ans << '\n';
    return 0;
}