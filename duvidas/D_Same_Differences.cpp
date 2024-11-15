/*
https://codeforces.com/contest/1520/problem/D

Duvida: Por que nao deu TLE ?
t = 10^4
n = 2*10^5

t * n = 10^4 * 2 * 10^5 = 2 * 10^9

+ map acessando os numero, que seria log2(n) = log2(2*10^5)?

t * n * log2(n) = 2 * 10^9 * 17.6 > 2 * 10^10

*/

#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

const int N = int(2e5+50);
int v[N];
int b[N];
/*

    Aj - Ai = j - i <-> Aj - j = Ai - i
    calcula todos os Ai - i e conta quantos iguais tem
    1   2   3   4  
    1   3   3   4
    0   1   0   0

*/

void solve(){
    int n; cin >> n;

    map<int,int> mp;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        b[i] = v[i] - i;
        mp[b[i]]++;
    }

    humberto ans = 0;
    for(int i = 1; i <= n; i++){
        if(mp[b[i]]){
            ans += mp[b[i]] - 1;
        }
        mp[b[i]]--;
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}