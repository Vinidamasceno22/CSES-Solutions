#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define INF 1e17

using namespace std;

void floyd_warshal(vector<vector<ll>> &dis, int n){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> dis(n+1, vector<ll>(n+1, INF));

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], 1ll*c);
        dis[b][a] = min(dis[b][a], 1ll*c);
    }
    for(int i = 1; i <= n; i++){
        dis[i][i] = 0;
    }
    
    floyd_warshal(dis, n);

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << (dis[a][b] == INF ? -1 : dis[a][b]) << '\n';
    } 
}