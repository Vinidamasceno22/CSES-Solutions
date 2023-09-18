#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

void dfs(const vector<vi> &adj, vi &vis, int v){
    vis[v] = 1;
    for(int i = 0; i < (int)adj[v].size(); i++){
        int u = adj[v][i];
        if(!vis[u]){
            dfs(adj, vis, u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


    int n, m, a, b;
    cin >> n >> m;
    vector<vi> adj(n, vi());
    vi vis(n, 0), ans;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            ans.push_back(i + 1);
            dfs(adj, vis, i);
        }
    }

    cout << (int)ans.size() - 1 << '\n';
    for(int i = 0; i < (int)ans.size() - 1; i++){
        cout << ans[i] << ' ' << ans[i + 1]<< '\n';
    }
}