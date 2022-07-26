#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; long long m; cin >> n >> m;
    vector <int> left;
    vector <int> right;
    for(int v=1; v<n; v++){
        if(m <= (1LL<<(n-v-1)))
            left.push_back(v);
        else{
            m -= (1LL<<(n-v-1));
            right.push_back(v);
        }
    }
    left.push_back(n);
    for(int i=0; i < left.size(); i++) cout << left[i] << " ";
    for(int i=right.size()-1; i>=0; i--) cout << right[i] << " ";
    cout << '\n';
    return 0;
}
