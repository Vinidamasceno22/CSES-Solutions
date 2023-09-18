#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

bool dfs(const vector<vi> &adj, vi &vis, int v){
    bool ok = true;
    for(int i = 0; i < (int)adj[v].size(); i++){
        int u = adj[v][i];
        if(!vis[u]){
            vis[u] = vis[v] * (-1);
            ok = ok && dfs(adj, vis, u);
        }
        else if(vis[u] == vis[v]) return false;
    }
    return ok;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    vector<vi> adj(n, vi());
    vi vis(n, 0);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    bool ok = true;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vis[i] = 1;
            ok = ok && dfs(adj, vis, i);
        }
    }

    if(ok){
        for(int i = 0; i < n; i++){
            cout << (vis[i] == -1 ? 2 : 1)<< ' ';
        }
        cout << '\n';
    }
    else{
        cout << "IMPOSSIBLE\n";
    }
}