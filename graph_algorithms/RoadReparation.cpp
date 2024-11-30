#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vii vector<vi>


int find(int v, vi& p){
    if (v != p[v]){
        p[v] = find(p[v], p);
    }
    return p[v];
}

void unite(int v, int u, vi& p, vi& rank){
    int p1 = find(v, p);
    int p2 = find(u, p);
    if (p1 != p2){
        if (rank[p1] < rank[p2]){
            p[p1] = p2;
        }
        else if (rank[p1] > rank[p2]){
            p[p2] = p[p1];
        }
        else{
            p[p2] = p1;
            rank[p1]++;
        }
    }
}

ll kruskal(int n, vector<pair<ll, pair<int, int>>>& edges){
    sort(edges.begin(), edges.end());

    vi p(n + 1), rank(n + 1);
    ll total = 0;
    
    for (int i = 1; i <= n; i++){
        p[i] = i;
        rank[i] = 0;
    }

    for (auto edge : edges){
        int a = edge.second.first;
        int b = edge.second.second;
        int c = edge.first;

        if (find(a, p) != find(b, p)){
            unite(a, b, p, rank);
            total += c;
        }
    }
    for(int i = 1; i < n; i ++){
        if (find(i, p) != find(i + 1, p)) total = -1;
    }
    return total;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<ll, pair<int, int>>> edges(m);
    for (int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, {a, b}};
    }
    ll total = kruskal(n, edges);
    if (total == -1) cout << "IMPOSSIBLE";
    else cout << total;
    cout << '\n';
    
}