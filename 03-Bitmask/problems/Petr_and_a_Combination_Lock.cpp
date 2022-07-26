#include <iostream>

using namespace std;

int mod(int x){
    if(x < 0) x += 360;
    if(x >= 360) x -= 360;
    return x;
}

int main(){
    int n; cin >> n;
    int arr[n];
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    bool dp[n][360];
    for(int i=0; i<n; i++){
        for(int j=0; j<360; j++) dp[i][j] = 0;
    }
    dp[0][mod(arr[0])] = 1;
    dp[0][mod(-arr[0])] = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<360; j++){
            if(dp[i-1][j]){
                dp[i][mod(j + arr[i])] = 1;
                dp[i][mod(j - arr[i])] = 1;
            }
        }
    }
    if(dp[n-1][0]) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}