#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define INF 1e17

using namespace std;

void bellman_ford(const vector<vector<pair<int, int>>> &adj, vector<ll> &dis, int n, int m){
    dis[1] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 1; j <= n; j++){
            if(dis[j] == INF) continue;
            for(auto &edge : adj[j]){
                int u = edge.first;
                ll w = edge.second;
                dis[u] = min(dis[u], dis[j] + w);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n; j++){
            if(dis[j] == INF) continue;
            for(auto &edge : adj[j]){
                int u = edge.first;
                ll w = edge.second;
                if(dis[u] > dis[j] + w){
                    dis[u] = -INF;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<ll> dis(n + 1, INF);

    for(int i = 0; i < m; i++){
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].push_back({b, -x});
    }
    bellman_ford(adj, dis, n, m);

    cout << (dis[n] == -INF ? -1: -dis[n]) << '\n';
}