// https://codeforces.com/contest/1826/problem/B

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
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<int> a;
    int ok=1;
    for(int i=0, j = n-1; i<j; i++, j--){
        a.push_back(abs(v[i] - v[j]));
        if(v[i] != v[j]) ok = 0;
    }    

    if(ok){
        cout<<"0\n";
        return;
    }

    int ans = a[0];
    for(int i=1;i<a.size();i++) ans=__gcd(ans, a[i]);
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


/*

a       b

a = b mod x
x | (a-b) 

10 13
1
3



*/
