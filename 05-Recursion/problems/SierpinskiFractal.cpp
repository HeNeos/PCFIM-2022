#include <iostream>

using namespace std;
#define N 1000

char table[N][N];

void fill(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) table[i][j] = ' ';
    }
}

void print_1(int r, int c){
    table[r][c] = '/'; table[r][c+1] = '_'; table[r][c+2] = '_'; table[r][c+3] = '\\';
    table[r-1][c+1] = '/'; table[r-1][c+2] = '\\'; 
}

void print_n(int r, int c, int n){
    if(n == 1){
        print_1(r, c);
        return;
    }
    print_n(r, c, n-1);
    print_n(r, c+(1<<n), n-1);
    print_n(r - (1<<(n-1)), c+(1<<(n-1)), n-1);
}

void print_table(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cout << table[i][j];
        cout << '\n';
    }
}

int main(){
    fill();
    int n = 6;
    print_n((1<<n)-1, 0, n);
    print_table();
    return 0;
}