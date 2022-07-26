#include <iostream>
#include <algorithm>
using namespace std;

#define INF (1<<30)

int main(){
    int n = 4*4;
    bool arr[n];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            char x; cin >> x;
            if(x == 'b') arr[4*i+j] = 1;
            else arr[4*i+j] = 0;
        }
    }

    int ans = INF;

    for(int i=0; i<(1<<n); i++){
        bool new_arr[n];
        for(int j=0; j<n; j++) new_arr[j] = arr[j];

        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                new_arr[j] ^= 1;

                int column = j%4;
                int row = j/4;

                if(column + 1 < 4)
                    new_arr[j+1] ^= 1;
                if(column - 1 >= 0)
                    new_arr[j-1] ^= 1;
                if(row + 1 < 4)
                    new_arr[j+4] ^= 1;
                if(row - 1 >= 0)
                    new_arr[j-4] ^= 1;
            }
        }

        int sum = 0;

        for(int j=0; j<n; j++)
            sum += new_arr[j];
        
        if(sum == 0 or sum == n)
            ans = min(ans, __builtin_popcount(i));
    }

    if(ans == INF) cout << "Impossible\n";
    else cout << ans << '\n';
    return 0;
}