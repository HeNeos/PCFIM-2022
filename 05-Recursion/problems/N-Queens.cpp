#include <iostream>
#include <vector>
using namespace std;
int n;

int ans = 0;
void print_sol(vector <int> &queens){
    char table[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            table[i][j] = '*';
        }
    }
    for(int i=0; i<n; i++)
        table[i][queens[i]] = 'Q';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << table[i][j];
        }
        cout << '\n';
    }
    cout << "=================\n";
}

bool check(int c, int r, vector <int> &queens){
    for(int i=0; i<c; i++){
        if(queens[i] == r) return false;
        if(c - i == abs(queens[i] - r)) return false;
    }
    return true;
}

void solve(int c, vector <int> &queens){
    if(c == n){
        //print_sol(queens);
        return;
    }
    // probar por las n filas en la columna c
    for(int i=0; i<n; i++){
        if(check(c, i, queens)){
            queens[c] = i;
            solve(c+1, queens);
            queens[c] = -1;
        }
    }
    return;
}

int main(){
    cin >> n;
    vector <int> queens(n, -1);
    solve(0, queens);
    cout << ans << '\n';
    return 0;
}

// 8^8 * 8^2 = n^(n+2) = 8^10 = 5e8