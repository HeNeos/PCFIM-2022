#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int ones = 0;
    vector <int> num;
    for(int i=0; i<30; i++){
        if(n & (1<<i)){
            if(i == 0) ones++;
            else num.push_back((1<<i));
        }
    }
    if(num.size() + ones > k || n < k){
        cout << "NO\n";
        return 0;
    }
    int rnd = k - ones - num.size();
    for(int i=0; i<rnd; i++){
        int cur = num.back();
        num.pop_back();
        if(cur == 2) ones += 2;
        else{
            num.push_back(cur/2);
            num.push_back(cur/2);
        }
    }
    cout << "YES\n";
    for(auto cur:num) cout << cur << ' ';
    for(int i=0; i<ones ;i++) cout << 1 << ' ';
    cout << endl;
}