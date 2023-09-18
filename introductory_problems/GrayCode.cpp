#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, l;
    cin >> n;
    m = pow(2, n);
    vector<vector<int>> binary(m, vector<int>(n, -1));
    l = 1;
    for(int i = 0; i < m/2; i++){
        binary[i][n-1] = 0;
    }
    for(int i = m/2; i < m; i++){
        binary[i][n-1] = 1;
    }
    l = 1;
    for(int j = 0; j < n - 1; j++){
        int pos = l, count = 0;
        while(count < m){
            for(int i = pos; i < pos + 2*l; i++){
                count++;
                binary[i % m][j] = 1;
            }
            pos += 2*l;
            for(int i = pos; i < pos + 2*l; i++){
                count++;
                binary[i % m][j] = 0;
            }
            pos += 2*l;
        }
        l *= 2;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << binary[i][j];
        }
        cout << '\n';
    }

}