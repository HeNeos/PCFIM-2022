#include <iostream>

using namespace std;

int main(){
    int N; 
    while(cin >> N){
        int n; cin >> n;
        int a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        int ans = -1;
        int best_time = N;
        int masks_values[(1<<n)];
        masks_values[0] = 0;
        for(int i=1; i<(1<<n); i++){
            int previous_mask = masks_values[i&(i-1)];
            int pos = __builtin_ctz(i&(-i));
            int current_sum = previous_mask + a[pos];
            masks_values[i] = current_sum;
            if(current_sum <= N){
                if(best_time > N - current_sum){
                    best_time = N - current_sum;
                    ans = i;
                }
            }
        }

        for(int i=ans; i; i&=(i-1)){
            int pos = __builtin_ctz(i&(-i));
            cout << a[pos] << " ";
        }
        cout << "sum:" << N-best_time << '\n';
    }
    return 0;
}