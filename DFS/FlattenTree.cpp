// Flatten the dfs tree to apply the subtree queries. 
// Subtree(2) -> [st[2], en[2]]  so that means in the range included of starting and ending of 2

#include<bits/stdc++.h>
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define CREP(i,n)       for(__typeof(n) i=n-1; i>=0; --i)
#define MYREP(i,a,b)    for(__typeof(a) i=a; i<=b; ++i)

using namespace std;

vector<int> v[100014];
bool vis[100001];
int st[10001], en[10001], start, ee;

void dfs(int src){
    vis[src] = 1;
    st[src] = ee = start++;

    for(auto &x: v[src]){
        if(!vis[x]) dfs(x);
    }
    en[src] = ee;

}

int main(){
    int n,m;
    cin>>n>>m;
    REP(i,m)  {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b), v[b].push_back(a);
    }

    dfs(1);

    MYREP(i,1, n)    cout<<st[i]<<" ";
    cout<<"\n";
    MYREP(i,1, n)    cout<<en[i]<<" ";

    // now we can query for Subtree(1) -> [st, en] in the flatten array using prefix sum, segment tree or anything

}
