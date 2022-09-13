#include <bits/stdc++.h>
using namespace std;

int n[3]; int p[3]; int recipe[3];
long long r;
bool test(long long x){
    long long money = 0;
    for(int i=0; i<3; i++)
        money += max(x*recipe[i] - n[i], 0LL) * p[i];
    return money <= r;
}

int main(){
    string s; cin >> s;
    for(int i=0; i<3; i++) cin >> n[i];
    for(int i=0; i<3; i++) cin >> p[i];
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'B') recipe[0]++;
        if(s[i] == 'S') recipe[1]++;
        if(s[i] == 'C') recipe[2]++;
    }
    cin >> r;
    long long lo = 0;
    long long hi = r + 500;
    while(lo < hi){
        long long me = lo + (hi - lo + 1)/2;
        if(test(me)) lo = me;
        else hi = me - 1;
    }
    cout << lo << '\n';
    return 0;
}