// https://codeforces.com/contest/1853/problem/B

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define dbg(x) cout << #x << " = " << x << endl;
#define all(v) v.begin(), v.end()

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
#define int long long

const int N = (2e5+5) * 3;
pair<int,int> dp[N];

void test(){
    int n,k;
    cin>>n>>k;

    if(k > 3 * n){
        cout<<"0\n";
        return;
    }

    int ans=0;
    for(int a=0; a <= n; a++){
        // (n - X * a) / Y
        ll x = n - 1ll * dp[k].first * a;

        if((x % dp[k].second != 0)) continue;
        int b = x / dp[k].second;
        if(a > b) continue;
        if((1ll * dp[k].first * a + dp[k].second * b) != n) continue;
        ans++;
    }

    cout<<ans<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1] = {1, 0};
    dp[2] = {0, 1};
    for(int i=3;i<N;i++){
        dp[i] = {dp[i-1].first + dp[i-2].first, dp[i-1].second + dp[i-2].second};    
    }

    int t = 1;
    cin >> t;
    while(t--){
        test();
    }

    return 0;
}
 
/*  

          b
          b
          a
        b b
        a a
    b b b b
    a b b b
a b   a a a
a b c d e f 
1 0 1 1 2 3
0 1 1 2 3 5


a b
c = a + b
d = c + b = a + b + b = n

n = a + b + b-

k <= n

    .   a   .
n = X * a + Y * b

b = (n - X * a) / Y
Y | n - 

n = 5
k = 3
0  

*/