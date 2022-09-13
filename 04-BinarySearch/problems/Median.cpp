#include <iostream>
#include <algorithm>
#include <vector>
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n; vector <int> a;

long long count(int x){
    long long ans = 0;
    for(int i=0; i<n; i++){
        int lo = i;
        int hi = n-1;
        while(lo < hi){
            int me = lo + (hi-lo+1)/2;
            if(a[me] - a[i] <= x) lo = me;
            else hi = me - 1;
        }
        ans += (lo-i);
    }
    return ans;
}

bool test(int x){
    long long amount = 1LL*n*(n-1)/2;
    return count(x) >= (amount+1)/2;
}

int main(){
    FIFO;
    while(cin >> n){
        a.clear();
        a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int lo = 0;
        int hi = a[n-1] - a[0];
        while(lo < hi){
            int me = lo + (hi-lo)/2;
            if(test(me)) hi = me;
            else lo = me+1;
        }
        cout << lo << '\n';
    }
    return 0;
}