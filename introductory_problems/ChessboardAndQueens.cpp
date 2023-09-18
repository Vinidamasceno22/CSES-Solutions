#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

vector<vector<char>> m(8, vector<char>(8));

int queens(int n){
    if (n == 8) return 1;

    int ans = 0;
    for(int i = 0; i < 8; i++){
        bool ok = true;
        if (m[i][n] == '.'){
            for(int j = n - 1; j >= 0; j--){
                if (m[i][j] == 'Q'){
                    ok = false;
                    break;
                }
            }
            if(!ok) continue;
            int k = i + 1;
            for(int j = n - 1; j >= 0 && k < 8; j--){
                if(m[k][j] == 'Q'){
                    ok = false;
                    break;
                }
                k++;
            }
            if(!ok) continue;
            k = i - 1;
            for(int j = n - 1; j >= 0 && k >= 0; j--){
               if(m[k][j] == 'Q'){
                    ok = false;
                    break;
                }
                k--;
            }
            if(!ok) continue;      
            m[i][n] = 'Q';

            ans += queens(n+1);
            m[i][n] = '.';
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> m[i][j];
        }
    }

    cout << queens(0) << '\n';

}