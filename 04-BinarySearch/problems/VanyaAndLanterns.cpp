#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-10
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int n, l;
vector <int> a;
bool test(double x){
    bool isPossible = true;
    double high = 0;
    for(int i=0; i<n; i++){
        double current_down = max(0.0, a[i] - x);
        double current_high = min(1.0*l, a[i] + x);
        if(current_down - high > EPS){
            isPossible = false;
            break;
        }
        high = current_high;
    }
    if(l - high > EPS) isPossible = false;
    return isPossible;
}

int main(){
    FIFO;
    cin >> n >> l;
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    double lo = 0; double hi = l;
    int iterations = 0;
    while(hi - lo > EPS and iterations < 1000){
        double me = (lo+hi)/2;
        if(test(me)) hi = me;
        else lo = me;
        iterations++;
    }
    printf("%.10lf\n", hi);
    return 0;
}