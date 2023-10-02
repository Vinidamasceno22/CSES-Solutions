#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

void dfs(const vector<vi> &adj, vi &topo_sort, vi &vis, int v){
    vis[v] = 1;
    for(int u : adj[v]){
        if(!vis[u]) dfs(adj, topo_sort, vis, u);
    }
    topo_sort.push_back(v);
}

bool topological_sort(const vector<vi> &adj, int n, vi &topo_sort){
    vi vis(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(adj, topo_sort, vis, i);
    }
    for(int i = 0; i < n / 2; i++){
        int aux = topo_sort[i];
        topo_sort[i] = topo_sort[n - i - 1];
        topo_sort[n - i - 1] = aux;
    }
    vis.assign(n + 1, 0);
    for(int v : topo_sort){
        vis[v] = 1;
        for(int u : adj[v]){
            if(vis[u]) return false;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    vi topo_sort;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    if(topological_sort(adj, n, topo_sort)){
        for(int i = 0; i < n; i++){
            cout << topo_sort[i] << ' ';
        }
        cout << '\n';
    }
    else{
        cout << "IMPOSSIBLE\n";
    }

}