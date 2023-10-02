#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define INF 1e7

using namespace std;

vector<vector<char>> bfs(const vector<vector<char>> &matrix,vector<vi> &dis, int n, int m, char c){
    queue<pair<int, int>> q;
    vector<vector<char>> pai(n, vector<char>(m, 'A'));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == c){
                q.push({i, j});
                dis[i][j] = 0;
            }
            else if(matrix[i][j] == '#'){
                dis[i][j] = -1;
            }
        }
    }

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        
        if(i - 1 >= 0 && dis[i - 1][j] == INF){
            dis[i - 1][j] = dis[i][j] + 1;
            pai[i - 1][j] = 'U';
            q.push({i - 1, j});
        }
        if(i + 1 < n && dis[i + 1][j] == INF){
            dis[i + 1][j] = dis[i][j] + 1;
            pai[i + 1][j] = 'D';
            q.push({i + 1, j});
        }
        if(j - 1 >= 0 && dis[i][j - 1] == INF){
            dis[i][j - 1] = dis[i][j] + 1;
            pai[i][j - 1] = 'L';
            q.push({i, j - 1});
        }
        if(j + 1 < m && dis[i][j + 1] == INF){
            dis[i][j + 1] = dis[i][j] + 1;
            pai[i][j + 1] = 'R';
            q.push({i, j + 1});
        }
    }    

    return pai;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m)), pai(n, vector<char>(m, 'A'));
    vector<vi> monster_dis(n, vi(m, INF)), dis(n, vi(m, INF));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    bfs(matrix, monster_dis, n, m, 'M');
    pai = bfs(matrix, dis, n, m, 'A');

    int x = -1, y = -1;

    for(int i = 0; i < n; i++){
        if(dis[i][0] < monster_dis[i][0]){
            x = i;
            y = 0;
        }
        else if(dis[i][m - 1] < monster_dis[i][m - 1]){
            x = i;
            y = m - 1;
        }
    }
    for(int i = 0; i < m; i++){
        if(dis[0][i] < monster_dis[0][i]){
            x = 0; 
            y = i;
        }
        else if(dis[n - 1][i] < monster_dis[n - 1][i]){
            x = n - 1;
            y = i;
        }
    }
    if(x != -1){
        cout << "YES\n";
        stack<char> path;
        while(pai[x][y] != 'A'){
            path.push(pai[x][y]);
            if(pai[x][y] == 'D') x--;
            else if(pai[x][y] == 'U') x++;
            else if(pai[x][y] == 'L') y++;
            else y--;
        }
        cout << path.size() << '\n';
        while(!path.empty()){
            cout << path.top();
            path.pop();
        }
        cout << '\n';
    }
    else{
        cout << "NO\n";
    }
    
}