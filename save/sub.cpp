// https://codeforces.com/contest/1807/problem/G2
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define dbg(x) cout << #x << " = " << x << endl;
#define all(v) v.begin(), v.end()

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

void test(){    
    int n;
    cin>>n;
    vector<int>b(n);
    for(int&x:b)cin>>x;
    
    sort(all(b));
    
    if(b[0]>1){
        cout<<"NO\n";
        return;
    }
    
    ll sum=1;
    for(int i=1;i<b.size();i++){
        if(b[i] > sum){
            cout<<"NO\n";
            return;
        }
        sum+=b[i];
    }
    cout<<"YES\n";

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

/*

1 ... 1 x y

x <= n

y = x + 1 + 1 + 1...
y = x + (y-x)


x = 4
1 1 1 1 x
x + 1
x + 2
x + 3



1
1 1
1 2 1



*/