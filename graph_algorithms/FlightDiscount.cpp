#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define INF 1e17

using namespace std;

void djikstra(const vector<vector<pair<int, int>>> &adj, vector<ll> &dis){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dis[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        int v = pq.top().second;
        ll dist = pq.top().first;
        pq.pop();

        if(dis[v] < dist) continue;

        for(auto &edge : adj[v]){
            int u = edge.first;
            int w = edge.second;

            if(dis[u] > dis[v] + w){
                dis[u] = dis[v] + w;
                pq.push({dis[u], u});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1), adj_inv(n + 1);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj_inv[b].push_back({a, c});
    }

    vector<ll> dis(n + 1, INF), discount_dis(n + 1, INF);

    djikstra(adj, dis);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0, 1});
    discount_dis[0];

    while(!pq.empty()){
        int v = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if(d > discount_dis[v]) continue;
        for(auto &edge : adj[v]){
            int u = edge.first;
            int w = edge.second;
            if(discount_dis[u] > min(dis[v] + w / 2, discount_dis[v] + w)){
                discount_dis[u] = min(dis[v] + w / 2, discount_dis[v] + w);
                pq.push({discount_dis[u], u});
            }
        }
    }

    cout << discount_dis[n] << '\n';
}