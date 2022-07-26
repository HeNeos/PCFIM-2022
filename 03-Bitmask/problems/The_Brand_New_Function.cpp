#include <iostream>
#include <set>
using namespace std;

int main(){
    int n; cin >> n;
    set <int> ans;
    set <int> current;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        set <int> new_current;
        new_current.insert(x);
        ans.insert(x);
        for(auto v:current){
            new_current.insert(v | x);
            ans.insert(v | x);
        }
        current = new_current;
    }
    cout << ans.size() << '\n';
    return 0;
}