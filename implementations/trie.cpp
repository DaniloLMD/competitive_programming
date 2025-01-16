/*
    https://vjudge.net/contest/677561#problem/

    Trie (Prefix Tree)
    m = size of string
    k = size of alphabet

    Time  : O(m)
    Memory: O(m * k)
    -> We can change the array in the node structure to a map, obtaining
        Time  : O(m * log)
        Memory: O(m)    
*/

#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

const int K = 26;

struct Node{
    int next[26];
    bool output = false; //flag to see if it is a whole word or not yet
    int value = 0;

    Node(){
        for(int i = 0; i < K; i++) next[i] = -1;
    }
};
vector<Node>trie(1);

void add_string(string&s, int value){
    int v=0;
    for(char c:s){
        int idx=c-'a';
        if(trie[v].next[idx]==-1){
            trie[v].next[idx]=trie.size();
            trie.emplace_back();
        }
        v=trie[v].next[idx];
    }
    trie[v].output = true;
    trie[v].value = value;
}

int find_string(string& s){
    int v = 0;
    int sz = 0;

    for(auto c: s){
        sz++;   
        v=trie[v].next[c-'a'];
        if(v==-1) break;
        if(trie[v].output && sz == s.size())break;
    }

    if(v != -1 && trie[v].output && sz == s.size()) return trie[v].value;
    return 0;
}

void solve(){
    int n,m;
    cin>>m>>n;

    while(m--){
        string s;
        int val;
        cin>>s>>val;
        add_string(s,val);
    }
    
    while(n--){
        humberto ans=0;
        while(1){
            string s;
            cin>>s;
            if(s==".")break;
            ans+=find_string(s);
        }
        cout<<ans<<"\n";
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