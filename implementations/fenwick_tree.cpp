/*
    https://vjudge.net/contest/625128#problem/B
    Given an array of n integers, your task is to process q queries of the form: what is the xor sum of values in range [a,b] ?
*/

//Indexar os vetores a partir do 1, e v[0] = 0;

#include <bits/stdc++.h>
using namespace std;
#define humberto long long

const int N = int(2e5+5);
humberto v[N];
humberto bit[N]; //fenwick tree

//soma os elementos de 1 a x O(log n)
//para determinar a soma de L até R, fazer query(R) - query(L-1).
int query(int x){
    int soma = bit[x];
    x -= (x&-x);

    while(x){
        soma ^= bit[x];
        x -= (x&-x); //pegar o menor bit ativo de x
    }

    return soma;
}

//a[x] += v     O(log n)
void update(int x, int v){
    while(x < N){
        bit[x] ^= v;
        x+= (x&-x); //menor bit ativo
    }
}

int main(){

    int n, q;

    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> v[i];
        update(i, v[i]);
    }

    while(q--){
        int l,r;
        cin >> l >> r;
        cout << (query(r) ^ query(l-1)) << "\n";
    }



    return 0;
}