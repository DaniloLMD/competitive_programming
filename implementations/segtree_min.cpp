/*
    https://vjudge.net/contest/627952#problem/A
    Given an array of n integers, process q queries of the following type:
    1. update the value at position k to u
    2. what is the minimum value in range [a,b] ?
*/

#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';

const int N = int(2e5+50); //tamanho do vetor
int seg[4*N]; //segtree 
int v[N]; //vetor

int n, q; //tamanho do vetor, numero de queries
int ql, qr; //indices [l,r] da query

int merge(int v1, int v2){
    return min(v1, v2);
}

/**
 * @brief constroi a segree indo dos indices [L,R] do vetor. Ex de uso: build(1,1,n) : constroi a seg começando no indice 1 representando [1,n] do vetor
 * @param pos indice atual da seg tree
 * @param l,r intervalo [l,r] do vetor original que a posicao atual da seg representa
*/
void build(int pos, int l, int r){
    if(l == r){
        seg[pos] = v[l-1];
        return;
    }

    int mid = (l+r)/2;
    build(2*pos, l, mid);
    build(2*pos+1, mid+1, r);

    seg[pos] = merge(seg[2*pos], seg[2*pos+1]);
}

/**
 * @brief processa uma query indo dos indices [ql, qr] do vetor.
 * @param pos posicao atual da seg
 * @param l, r intervalo [l,r] que o indice "pos" da seg representa no vetor original
*/
int query(int pos, int l, int r){
    if(l > qr || r < ql) return INT_MAX;
    if(ql <= l && qr >= r) return seg[pos];


    int mid = (l+r)/2;
    return merge(query(2*pos, l, mid), query(2*pos+1, mid+1, r));
}

/**
 * @brief atualiza o indice P do vetor original para VAL na segtree
 * @param pos posicao atual da seg
 * @param val valor a ser inserido
 * @param l, r intervalo [l,r] que a posicao atual da seg representa
 * @param p indice a ser alterado
*/
void update(int pos, int val, int l, int r, int p){
    if(l == r){
        v[p] = val;
        seg[pos] = val;
        return;
    }
    
    int mid = (l+r)/2;
    if(p <= mid) update(2*pos, val, l, mid, p);
    else update(2*pos+1, val, mid+1, r, p);

    seg[pos] = merge(seg[2*pos], seg[2*pos+1]);
}


void solve(){
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> v[i];

    build(1, 1, n);

    for(int i = 0; i < q; i++){
        int op, a, b;
        cin >> op >> ql >> qr;

        if(op == 1){//update
            update(1, qr, 1, n, ql);
        }
        else{//min
            cout << query(1, 1, n) << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}