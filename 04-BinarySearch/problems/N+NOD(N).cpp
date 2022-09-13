#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define N 4000005
int divisors[N];
void sieve(){
    divisors[0] = 0; divisors[1] = 1;
    for(int i=2; i<N; i++){
        divisors[i] += 2;
        for(ll j=2*i; j<N; j+=i)
            divisors[j]++;
    }
}
#define M 80005
int table[M];
void fill(){
    table[0] = 1;
    for(int i=1; i<M; i++)
        table[i] = table[i-1] + divisors[table[i-1]];
}

int main(){
    sieve();
    fill();
    int t; cin >> t;
    for(int _=1; _<=t; _++){
        int a, b; cin >> a >> b;
        int p1 = 0; int p2 = 0;
        int lo = 0; int hi = M-5;
        while(lo < hi){
            // F T
            int me = lo + (hi-lo)/2;
            if(table[me] >= a) hi = me;
            else lo = me + 1;
        }
        p1 = lo;
        lo = 0; hi = M-5;
        while(lo < hi){
            // F T
            int me = lo + (hi-lo)/2;
            if(table[me] > b) hi = me;
            else lo = me+1;
        }
        p2 = lo;
        printf("Case %d: %d\n", _, p2-p1);
    }
    return 0;
}