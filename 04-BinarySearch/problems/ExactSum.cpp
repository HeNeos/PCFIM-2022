#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int firstGreater(vector <int> &a, int x, int lo = 0, int hi = n-1){
    while(lo < hi){
        int me = lo + (hi - lo)/2;
        if(a[me] >= x) hi = me;
        else lo = me + 1;
    }
    return lo;
}

int main(){
    string line;
    while(cin >> n){
        vector <int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int m; cin >> m;
        int p = firstGreater(a, m/2);
        for(int p1=p; p1<n; p1++){
            int p2 = firstGreater(a, m-a[p1], 0, p1-1);
            if(p2 < p1 && a[p1] + a[p2] == m){
                printf("Peter should buy books whose prices are %d and %d.\n\n", a[p2], a[p1]);
                break;
            }
        }
    }
    return 0;
}