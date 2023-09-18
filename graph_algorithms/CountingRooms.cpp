#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

void dfs(vector<vi> &rooms, int i, int j, const int &n, const int &m, const int &ans){
    rooms[i][j] = ans;
    if(i - 1 >= 0 && rooms[i - 1][j] == 0) dfs(rooms, i - 1, j, n, m, ans);
    if(i + 1 < n && rooms[i + 1][j] == 0) dfs(rooms, i + 1, j, n, m, ans);
    if(j - 1 >= 0 && rooms[i][j - 1] == 0) dfs(rooms, i, j - 1, n, m, ans);
    if(j + 1 < m && rooms[i][j + 1] == 0) dfs(rooms, i, j + 1, n, m, ans);
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m, ans = 0;
    char x;
    cin >> n >> m;
    vector<vector<int>> rooms(n, vi(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> x;
            rooms[i][j] = (x == '.' ? 0 : -1);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(rooms[i][j] == 0){
                ans++;
                dfs(rooms, i, j, n, m, ans);
            }
        }
    }

    cout << ans << '\n';
}