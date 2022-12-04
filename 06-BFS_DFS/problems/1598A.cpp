#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define N 105

bool G[2][N];
int n;
void fill(){
    for(int i=0; i<N; i++){
        G[0][i] = 0;
        G[1][i] = 0;
    }
}

bool is_valid(int row, int col){
    if(row < 0 or row > 1) return false;
    if(col < 0 or col > n-1) return false;
    return true;
}

bool dfs(){
    // cout << "================\nDFS:\n";
    pair <int, int> final_node(1, n-1);
    pair <int, int> source(0, 0);
    bool visited[2][n];
    for(int i=0; i<n; i++){
        visited[0][i] = false;
        visited[1][i] = false;
    }
    visited[0][0] = true;
    stack <pair<int, int> > s;
    s.push(source);
    while(!s.empty()){
        pair<int, int> current_node = s.top();
        s.pop();
        int current_row = current_node.first;
        int current_col = current_node.second;
        cout << current_row << " " << current_col << '\n';
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                if(i == 0 and j == 0) continue;
                int new_row = current_row + i;
                int new_col = current_col + j;
                pair <int, int> new_node(new_row, new_col);
                if(is_valid(new_row, new_col) && visited[new_row][new_col] == false){
                    if(G[new_row][new_col] == 0){
                        visited[new_row][new_col] = true;
                        s.push(new_node);
                    }
                }
            }
        }
    }
    return visited[1][n-1];
}

bool bfs(){
    // cout << "================\nBFS:\n";
    queue <pair<int, int> > q;
    pair <int, int> final_node(1, n-1);
    pair <int, int> source(0, 0);
    bool visited[2][n];
    for(int i=0; i<n; i++){
        visited[0][i] = false;
        visited[1][i] = false;
    }
    visited[0][0] = true;
    q.push(source);
    while(!q.empty()){
        pair<int, int> current_node = q.front();
        q.pop();
        int current_row = current_node.first;
        int current_col = current_node.second;
        cout << current_row << " " << current_col << '\n';
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                if(i == 0 and j == 0) continue;
                int new_row = current_row + i;
                int new_col = current_col + j;
                pair <int, int> new_node(new_row, new_col);
                if(is_valid(new_row, new_col) && visited[new_row][new_col] == false){
                    if(G[new_row][new_col] == 0){
                        visited[new_row][new_col] = true;
                        q.push(new_node);
                    }
                }
            }
        }
    }
    return visited[1][n-1];
}

int main(){
    int t; cin >> t;
    while(t--){
        fill();
        cin >> n;
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                char x; cin >> x;
                if(x == '0') G[i][j] = 0;
                else G[i][j] = 1;
            }
        }
        // bfs();
        // dfs();
        if(bfs()) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}
