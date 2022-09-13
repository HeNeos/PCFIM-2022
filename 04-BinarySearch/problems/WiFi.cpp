#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

bool test(double x, vector <int> &houses){
    double lastPosition = houses[0] + x;
    int used = 1;
    for(int i=1; i<m; i++){
        if(abs(houses[i] - lastPosition) > x){
            lastPosition = houses[i] + x;
            used++;
        }
    }
    return used <= n;
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        vector <int> houses(m);
        for(int i=0; i<m; i++) cin >> houses[i];
        sort(houses.begin(), houses.end());
        double lo = 0.0; double hi = 1000000.0;
        for(int _=0; _<200; _++){
            double me = (lo + hi)/2;
            if(test(me, houses)) hi = me;
            else lo = me;
        }
        printf("%.1lf\n", lo);
    }
    return 0;
}