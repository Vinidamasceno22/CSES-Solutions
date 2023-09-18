#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n), res(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    res[0] = 0;
    cout << res[0];
    for(int i = 1; i < n; i++){
        int j = i;
        if(v[i] <= v[i - 1]){
            int aux;
            while(true){
                aux = v[res[j - 1] - 1];
                j = res[j - 1];
                if(j == 0) break;
                if(aux < v[i]) break;
            }
        }
        res[i] = j;
        cout << ' ' << res[i];
    }
    cout << '\n';
}