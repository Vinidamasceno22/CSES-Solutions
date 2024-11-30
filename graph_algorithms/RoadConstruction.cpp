#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vii vector<vi>

using namespace std;

int find(int v, vi& p){
    if (v != p[v]){
        p[v] = find(p[v], p);
    }
    return p[v];
}

void unite(int v, int u, vi &p, vi &rank, vi &size){
    int p1 = find(v, p);
    int p2 = find(u, p);
    if (p1 != p2){
        if (rank[p1] < rank[p2]){
            p[p1] = p2;
            size[p2] += size[p1];
        }
        else if (rank[p1] > rank[p2]){
            p[p2] = p1;
            size[p1] += size[p2];
        }
        else{
            p[p1] = p2;
            size[p2] += size[p1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    int max_size = 1, num_components = n;
    vector<pair<int, int>> edges(m);
    vi p(n + 1), size(n + 1, 1), rank(n + 1, 0);
    for (int i = 1; i <= n; i++){
        p[i] = i;
    }

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        int p_a = find(a, p);
        int p_b = find(b, p);
        if(p_a != p_b){
            unite(a, b, p, rank, size);
            max_size = max(max_size, max(size[p_a], size[p_b]));
            num_components--;
        }
        cout << num_components << " " << max_size << '\n';
    }
}