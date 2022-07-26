#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, U, R, D, L;
        cin >> n >> U >> R >> D >> L;
        /*
            0---1
            |   |
            |   |
            2---3
        */
        int valid[4] = {U, D, L, R};
        bool found = true;
        for(int i=0; i<(1<<4); i++){
            // UP, DOWN, LEFT, RIGHT
            int values[4] = {0, 0, 0, 0};
            for(int j=0; j<4; j++){
                if(i & (1<<j)){
                    values[j/2]++;
                    values[2+j%2]++;
                }
            }
            found = true;
            for(int j=0; j<4; j++){
                if(valid[j] - values[j] > n-2 || valid[j] - values[j] < 0)
                    found = false;
            }
            if(found){
                cout << "YES\n";
                break;
            }
        }
        if(!found) cout << "NO\n";
    }
    return 0;
}