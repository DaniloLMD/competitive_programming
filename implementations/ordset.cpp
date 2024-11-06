/*
    https://cses.fi/problemset/task/2163/
    Consider a game where there are n children (numbered 1,2,...,n) in a circle.
    During the game, repeatedly k children are skipped and one child is removed from the circle.
    In which order will the children be removed?

    outra solução possivel alem de ordset: segtree de quantas pessoas tem entre [l,r] e busca binaria buscando o primeiro indice a esquerda que tem K caras
*/

#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()
 
/*
Ordset é basicamente um set (mais lento, constante alta na complexidade), que suporta 2 operacoes adicionais:
- order_of_key (k) : Number of items strictly smaller than k .
- find_by_order(k) : K-th element in a set (counting from zero).
*/
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
 
void solve(){
    int n, k;
    cin >> n >> k;
 
    ordered_set st;
 
    for(int i = 1; i <= n; i++){
        st.insert(i);
    }
 
    int idx = 0;
    while(st.size()){
        idx = (idx + k) % st.size();
        auto x = st.find_by_order(idx);
        cout << *x << ' ';
        st.erase(x);
    }
    cout << "\n";    
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