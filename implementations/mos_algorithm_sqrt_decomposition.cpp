/*
    https://vjudge.net/contest/634350#problem/A

    Given an array of n integers, your task is to process q queries of the form: what is the sum of values in range [a,b]?
*/

#include <bits/stdc++.h>
#define humberto long long
using namespace std;
#define dbg(x) cout << #x << " = " << x << '\n';

const int N = int(2e5+5);
const int  K = 447;

//query entre o intervalo [l,r] e indice i (indice que foi chamada, pois depois de ordenar precisa printar no msm indice de entrada)
struct query{
    int l, r, i;
};

//compara 2 query usando sqrt decomposition
bool comp(query a, query b){
    if(a.l/K == b.l/K){
        if((a.l/K)&1){
            return a.r/K > b.r/K;
        }
        return a.r/K < b.r/K;
    }
    return a.l/K < b.l/K;
}

int a[N]; //vetor
query q[N]; //vetor de queries
humberto ans[N]; //vetor que guarda os valores da cada query no indice correto
int qe; //quantidade de queries
humberto s = 0; //valor da soma atual

void add(int x){
    s += a[x];
}

void rmv(int x){
    s -= a[x];
}

humberto calc(){
    return s;
}

void solve(){
    int a = 0, b = -1;

    for(int i = 0; i < qe; i++){
        int l = q[i].l;
        int r = q[i].r;
        int idx = q[i].i;

        while(a > l) { add(--a); }
        while(a < l) { rmv(a++); }
        while(b > r) { rmv(b--); }
        while(b < r) { add(++b); }

        ans[idx] = calc();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n >> qe;

    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < qe; i++){
        cin >> q[i].l >> q[i].r;
        q[i].i = i;
        q[i].l--;
        q[i].r--;
    }

    sort(q, q+qe, comp);

    solve();

    for(int i = 0; i < qe; i++){
        cout << ans[i] << '\n';
    }

}