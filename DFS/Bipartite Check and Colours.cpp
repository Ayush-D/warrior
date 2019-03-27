Bipartite Graph Check: problem link: https://codeforces.com/problemset/problem/1093/D


vector <int> v[N];  // Graph
int cnt[2];         // No. of colour of each category required
int col[N];         // Initalize it with -1, Will store the colour of every node
bool bad;           // if not bipartite then it's bad

void dfs(int src, int c){
	col[src] = c;
	++cnt[c];
	for(auto to : v[src]){
		if(col[to] == -1) dfs(to, 1 - c);  // If they are not visited then go to these node
		if((col[src] ^ col[to]) == 0)     // If same colour of adjacent neighbour then it's not bipartite
			bad = true;
	}
}
