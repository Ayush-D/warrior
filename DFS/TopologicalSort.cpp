#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];

void dfs(int v, vector<int> &ans, vector<bool> &visited) {
	visited[v] = 1;
	for (int u : graph[v]) {
		if (!visited[u])
		dfs(u, ans, visited);
	}
	ans.push_back(v);
}

void topological_sort(vector<int> &ans) {
	vector<bool> visited;
	visited.assign(N, false);
	bool flag = 0;
	for (int i = 0; i < N; ++i) {
		if(!visited[i] and (int) graph[i].size()){
			flag = 1;
			dfs(i, ans, visited);
		}
	}
	reverse(ans.begin(), ans.end());
}

int main() {
	// your code goes here
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int a,b; 
		cin>>a>>b;
		graph[a].push_back(b), graph[b].push_back(a);
	}
	vector<int> ans;
	topological_sort(ans);
	
	for(auto &x: ans)	cout<<x<<" ";
	return 0;
}

// For checking cycle in directed graph
// Now just maintain the order of the topological indecies of the nodes and then check
// index[parent_node] > index[child_node] then cycle exists.
// More details:-----------------------------------------------------------
// In Topological Sort, the idea is to visit the parent node followed by the child node. 
// If the given graph contains a cycle, then there is at least one node which is a parent as 
// well as a child so this will break Topological Order. 
// Therefore, after the topological sort, check for every directed edge whether it follows the order or not.
