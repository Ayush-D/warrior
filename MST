// Use pllk book for doubt

#include <bits/stdc++.h>
using namespace std;

struct edges{
    int edg1,edg2,dist;
};

vector<edges> adj;
int link[10001],size[10001];


int find(int x){    //find the representative of the set
    while(x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b){     //find weather a and b are in same set
    return find(a) == find(b);
}

void unite(int a, int b){   //unites the two sets first find representative and then connect smaller to larger
    a = find(a);
    b = find(b);

    if(size[a] < size[b])   swap(a,b);
    size[a] += size[b];
    link[b] = a;
}


int main(){

    int e,n;
    cin>>n>>e;
    
    for(int i=0; i<e; ++i){
        int x,y,z;
        cin>>x>>y>>z;
        adj.push_back({x, y, z});

    }

    sort(adj.begin(),adj.end(),[](edges &a, edges &b){
        return a.dist < b.dist;
    });

    
    for(int i=0;i<e;i++){
        cout<<adj[i].edg1<<" "<<adj[i].edg2<<"  "<<adj[i].dist<<"\n";
    }
    cout<<"\n";


    for(int i=1; i<=n; i++) link[i] = i;
    for(int i=1; i<=n; i++) size[i] = 1;

    int cnt = 0;
    for(int i=0; i<e; i++){
        if(!same(adj[i].edg1, adj[i].edg2)){
            unite(adj[i].edg1, adj[i].edg2);
            cnt += adj[i].dist;
        }
    }

    cout<<cnt;

    
}
