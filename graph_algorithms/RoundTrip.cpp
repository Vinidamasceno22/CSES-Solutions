#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

stack<int> dfs(const vector<vi> &adj, vi &vis, vi &pai, int v, stack<int> &path){
    vis[v] = 1;
    path.push(v);
    stack<int> aux;
    for(int i = 0; i < (int)adj[v].size(); i++){
        int u = adj[v][i];
        if(vis[u] == 1 && u != pai[v]){
            path.push(u);
            return path;
        }
        else if(!vis[u]){
            pai[u] = v;
            aux = dfs(adj, vis, pai, u, path);
            if(!aux.empty()) return aux;
        }
    }
    path.pop();
    return aux;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    vi vis(n, 0), pai(n, -1), ans;
    stack<int> aux;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            aux = dfs(adj, vis, pai, i, aux);
            if(!aux.empty()){
                int k = aux.top();
                ans.push_back(aux.top());
                aux.pop();
                while(k != aux.top()){
                    ans.push_back(aux.top());
                    aux.pop();
                }
                cout << (int)ans.size() + 1 << '\n';
                for(int i = 0; i < (int)ans.size(); i++){
                    cout << ans[i] + 1 << ' ';
                }
                cout << k + 1 << '\n';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}