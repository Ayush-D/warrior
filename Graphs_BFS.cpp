#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 1e5+5;
//Declarations of parent(p) and visited(used) and d(dist) and adj list

vector<int> adj[kMaxN];
vector<bool> used(kMaxN);
vector<int> d(kMaxN), p(kMaxN);

void bfs(int s,int u){

    queue<int> q;   // queue is shaan of bfs
    
    q.push(s);
    used[s] = true;
    p[s] = -1;
   
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    
    if (!used[u]) {
        cout << "No path!";
    } else {
      
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
       
        reverse(path.begin(), path.end());
        cout << "Path: ";
        
        for (int v : path)
            cout << v << " ";
    }

}

int main(){
    int n,e,s;  // n = no of nodes and s as source node for bfs or dfs
    cin>>n>>e;
    
    while(e--){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    }

    s = 1;
    bfs(s,4);
}
/*  Sample Test
6
8
0 1
2 3
0 4
5 4
2 1
3 5
2 4
5 1

*/
