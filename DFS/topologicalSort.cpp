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
