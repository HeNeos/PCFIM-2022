#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MOD 1000000007

typedef vector<vector<ll> > Matrix;

Matrix ones(int n) {
	Matrix r(n,vector<ll>(n));
	for(int i=0; i<n; i++) r[i][i]=1;
	return r;
}
Matrix operator*(Matrix &a, Matrix &b){
	int n = a.size(), m = b[0].size(), z = a[0].size();
	Matrix r(n, vector<ll>(m));
	for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<z; k++){
		        r[i][j] += a[i][k]*b[k][j],
                r[i][j] %= MOD;
            }
        }
    }
	return r;
}
Matrix be(Matrix b, ll e) {
    Matrix r = ones(b.size());
    if(e == 0) return r;
    Matrix aux = be(b, e/2);
    aux = aux*aux;
    if(e%2 == 1) aux = aux*b;
	return aux;
}

int main(){
    int t; cin >> t;
    while(t--){
        int m, n; cin >> m >> n;
        Matrix M(m, vector<ll>(m));
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++) cin >> M[i][j];
        }
        Matrix ans = be(M, n);
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++) cout << ans[i][j] << " ";
            cout << '\n';
        }
    }
    return 0;
}
