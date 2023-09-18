#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

vector<vector<pair<int, int>>> bfs(vector<vector<char>> &matrix, int x, int y, int n, int m){
    vector<vector<pair<int, int>>> pai(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;
    q.push({x, y});
    while((int) q.size() != 0){
        pair<int, int> coord = q.front();
        q.pop();
        x = coord.first;
        y = coord.second;
        if(x - 1 >= 0 && (matrix[x - 1][y] == '.' || matrix[x - 1][y] == 'B')){
            matrix[x - 1][y] = 'U';
            pai[x - 1][y] = {x, y};
            q.push({x - 1, y});
        }
        if(x + 1 < n && (matrix[x + 1][y] == '.' || matrix[x + 1][y] == 'B')){
            matrix[x + 1][y] = 'D';
            pai[x + 1][y] = {x, y};
            q.push({x + 1, y});
        }
        if(y - 1 >= 0 && (matrix[x][y - 1] == '.' || matrix[x][y - 1] == 'B')){
            matrix[x][y - 1] = 'L';
            pai[x][y - 1] = {x, y};
            q.push({x, y - 1});
        }
        if(y + 1 < m && (matrix[x][y + 1] == '.' || matrix[x][y + 1] == 'B')){
            matrix[x][y + 1] = 'R';
            pai[x][y + 1] = {x, y};
            q.push({x, y + 1});
        }
    }
    return pai;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m, x, y, xb, yb;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    vector<vector<pair<int, int>>> pai;
    stack<char> ans;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 'A'){
                x = i;
                y = j;
            }
            else if(matrix[i][j] == 'B'){
                xb = i;
                yb = j;
            }
        }
    }
    
    pai = bfs(matrix, x, y, n, m);
    ans.push(matrix[xb][yb]);
    pair<int, int> p = pai[xb][yb];

    if(p.first == -1){
        cout << "NO\n";
    }
    else{
        while(matrix[p.first][p.second] != 'A'){
            ans.push(matrix[p.first][p.second]);
            p = pai[p.first][p.second];
        }
        cout << "YES\n" << (int) ans.size() << '\n';
        for(int i = 0; (int) ans.size(); i++){
            cout << ans.top();
            ans.pop();
        }
        cout << '\n';
    }
}