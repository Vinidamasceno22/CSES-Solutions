#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int q;
    ll k;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> k;
        int j = 1;
        ll aux = 9, ten = 10, ant = 0, MIN = 0;
        while(k - ant > aux){
            ant += aux;
            MIN += 9 * ten / 10;
            j++;
            aux = 9 * ten * j;
            ten *= 10;
        }
        string s = to_string(MIN +(k - ant + j - 1) / j);
        cout << s[(k - ant + j - 1) % j] <<'\n';

        
    }    
}