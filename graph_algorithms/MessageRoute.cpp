#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

void bfs(const vector<vi> &adj, vi &vis, vi &pai, int v){
    queue<int> q;
    q.push(v);
    vis[v] = 1;
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(int i = 0; i < (int) adj[v].size(); i++){
            int u = adj[v][i];
            if(!vis[u]){
                q.push(u);
                pai[u] = v;
                vis[u] = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vi> adj(n, vi());
    vi vis(n, 0), pai(n, -1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    bfs(adj, vis, pai, 0);

    stack<int> s;
    s.push(n - 1);
    int aux = n - 1;
    while(pai[aux] != -1){
        s.push(pai[aux]);
        aux = pai[aux];
    }
    if(s.top() != 0){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << s.size() << '\n';
        while(!s.empty()){
            cout << s.top() + 1 << ' ';
            s.pop();
        }
        cout << '\n';
    }
}