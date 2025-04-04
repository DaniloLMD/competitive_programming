//https://codeforces.com/contest/1881/problem/D

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define dbg(x) cout << #x << " = " << x << endl;
#define all(v) v.begin(), v.end()

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e4+50;
const int X = 1e6+50;
// vector<int>d[X];
int d[X];
int v[N];
int comp[X];

void sieve(){
    for(int i=2; i < X; i++){
        if(!comp[i]){
            // d[i].push_back(i);
            d[i]=i;
            for(int j=i+i;j<X;j+=i){
                comp[j]=1;
                // d[j].push_back(i);
                d[j]=i;
            }
        }
    }
}

void test(){
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
    
        int t=v[i];
        while(t!=1){
            mp[d[t]]++;
            t/=d[t];
        }

    }

    for(auto [x,y]: mp){
        if(y%n!=0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve();

    int t = 1;
    cin >> t;
    while(t--){
        test();
    }

    return 0;
}

/*

[100,2,50,10,1
100 = 1 * 2 * 2 * 5 * 5
2 = 1 * 2
50 = 1 * 2 * 5 * 5
10 = 1 * 2 * 5
1 =  1

1: 5
2: 5
5: 5
tudo ok tudo bacana tudo legal da pra didir sim senhor 

*/