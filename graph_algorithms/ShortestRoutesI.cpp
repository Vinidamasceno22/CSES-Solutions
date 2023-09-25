#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define MAXN 100000
#define INF 1e17

using namespace std;

void djikstra(const vector<vector<pair<int, int>>> &adj, vector<ll> &dis){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dis[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        int v = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        ll d = dis[v];
        if(dist > d) continue;
        for(auto &i : adj[v]){
            int u = i.first;
            ll w = i.second;

            if(dis[u] > d + w){
                dis[u] = d + w;
                pq.push({dis[u], u});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<ll> dis(n, INF);

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }
    
    djikstra(adj, dis);

    for(int i = 0; i < n; i++){
        cout << dis[i] << ' ';
    }

}