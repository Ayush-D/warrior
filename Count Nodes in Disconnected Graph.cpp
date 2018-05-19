#include<iostream>
#include<list>
#include<queue>
using namespace std;

//Code for more : https://ide.codingblocks.com/#/s/10939

//Adj List Implementation for Integer Nodes
class Graph{
	int V;	

	 //Array of Linked Lists of size V, V LL's are there
     list<int> *adjList;
public:
     Graph(int v){
     	V = v;
     	adjList = new list<int>[V];
     }
     void addEdge(int u,int v,bool bidir=true){
     	adjList[u].push_back(v);
     	if(bidir){
     		adjList[v].push_back(u);
     	}
     }
     void printAdjList(){
     	for(int i=0;i<V;i++){
     		cout<<i<<"->";
     		for(int node:adjList[i]){
     			cout<<node<<",";
     		}
     		cout<<endl;
     	}
     }
     
    void dfs(int s,bool *visited,int &cnt) {
    
    if (visited[s]) return;
    visited[s] = true;
    cnt++;
    // process node s
    
    for (auto u: adjList[s]) {
        dfs(u,visited,cnt);
    }

}

};


int main(){
    // v is the vertex and e is total edges
    int v,e;
    cin>>v>>e;
    
    //As counting starts from 0, so g(v) else if 1 based index then g(v+1)    
	Graph g(v);
    //As counting starts from 0, so visit[v] else if 1 based index then visited[v+1]
	bool visited[v]{0};
    
    //Adding Edges
	while(e--){
	    int x,y;
	    cin>>x>>y;
	    g.addEdge(x,y);
	}
	
    //cnt array has all the total edes in particul graph
	int cnt[v]={0};
    g.dfs(0,visited,cnt[0]);
	cout<<cnt[0]<<endl;
	
	
    int i=0;
    int k=1;
    while(1){
	
	    if(i==v){
	        break;
	    }
	
      if(visited[i]==0){
	       g.dfs(i,visited,cnt[k]);
	       cout<<cnt[k]<<endl;
	    }
	++k;
    ++i;
    }
	
	return 0;
}
/*
10 7
0 2
1 8
1 4
2 8
2 6
3 5
6 9
*/
