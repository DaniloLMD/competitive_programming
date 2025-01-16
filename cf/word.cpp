//https://codeforces.com/problemset/problem/59/A
#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

void solve(){
    string s;
    cin>>s;
    int a,b;
    a=b=0;
    for(char c:s){
        if(c>='a')a++;
        else b++;
    }
    if(a>=b){
        for(char&c:s){
            c|=32;
        }
    }
    else{
        for(char&c:s){
            if(c>='a')c-=32;
        }
    }
    cout<<s<<"\n";
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