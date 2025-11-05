// https://codeforces.com/contest/1808/problem/B

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define dbg(x) cout << #x << " = " << x << endl;
#define all(v) v.begin(), v.end()

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

void test(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(m+1, vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>v[j][i];
        }
    }

    for(auto&x:v)sort(all(x));

    vector<vector<ll>> p(m+1, vector<ll>(n+1));

    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            p[j][i] = p[j][i-1] + v[j][i];
        }
    }

    ll ans=0;
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            ans += 1ll*(i-1) * v[j][i] - p[j][i-1]; 
        }
    }
    
    cout<<ans<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        test();
    }

    return 0;
}