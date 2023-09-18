#include<bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vii vector<vi>

using namespace std;

void hanoi(int inicio, int fim, int aux, int n){
    if (n != 0){
    hanoi(inicio, aux, fim, n-1);
    cout << inicio << ' ' << fim << '\n';
    hanoi(aux, fim, inicio, n-1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    cout << pow(2, n) - 1 << '\n';
    hanoi(1, 3, 2, n);
}