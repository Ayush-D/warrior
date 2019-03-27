//Ayushdeep
//Sublime Text IDE used
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define fastio          std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define CREP(i,n)       for(__typeof(n) i=n-1; i>=0; --i)
#define MYREP(i,a,b)    for(__typeof(a) i=a; i<=b; ++i)
#define MYCREP(i,a,b)   for(__typeof(a) i=b; i>=a; --i)
#define SET(a, b)       memset(a, b, sizeof(a))
#define pb              push_back


//(a + b)%c
template<typename T> T add(T a, T b, T c){T x=a+b;return (x>=c ? x-c : x);}
//(a - b)%c
template<typename T> T sub(int a, int b, int c) { int res = a - b; return (res < 0 ? res + c : res);}

//(a * b) % c
LL mul(LL a, LL b, LL c){long long res=(long long)a*b;return(res>=c?res%c:res);}

template <typename T> T mod(T a, T b) {return (a < b ? a : a % b);}
//(a - b) % c
template<typename T> T mod_neg(T a, T b) {a=mod(a, b);if(a<0){a+=b;}return a;}
//(a ^ n)
//Complexity: O(log (n))
template <typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
//(a ^ n) % m
//Complexity : O(log (n))
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template <typename T>T powerL(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mulmod(x,p,m);p=mulmod(p,p,m);n>>=1;}return x;}


int X[8] = {1,1,0,-1,-1,-1, 0, 1}; // trick to explore an implicit 2D grid
int Y[8] = {0,1,1, 1, 0,-1,-1,-1};

int X[4]={0 ,0 , 1 , -1};
int Y[4]={-1 , 1 , 0 , 0};
***********Used X and Y*******

LL MOD = 998244353;
const int N = 1e5 + 5;
vector<int> g[N];
int dp1[100005],dp2[100005];

void dfs(int s, int par){
	int sum1 = 0, sum2 = 0;
	
	for(auto x: g[s]){
		if(x == par)	continue;
		dfs(x,s);
		sum1 += dp2[x];
		sum2 += max(dp2[x],dp1[x]);
	}
	dp1[s] = s + sum1;
	dp2[s] = sum2;
}

int f[N],gs[N],diameter;

void dfs2(int s,int par){
	
	int ans = 0;
	for(auto x: g[s]){
		if(x == par)	continue;
		dfs2(x,s);
		ans = max(ans, 1 + f[x]);
	}
	f[s] = ans;
}

//pV is parent of node V
void dfs1(int V, int pV){
    //this vector will store f for all children of V
    vector<int> fValues;

    //traverse over all children
    for(auto v: g[V]){
    if(v == pV) continue;
    dfs(v, V);
    fValues.push_back(f[v]);
    }

    //sort to get top two values
    //you can also get top two values without sorting(think about it) in O(n)
    //current complexity is n log n
    sort(fValues.begin(),fValues.end());

    //update f for current node
    f[V] = 0;
    if(!fValues.empty()) f[V] = 1 + fValues.back();

    if(fValues.size()>=2)
         gs[V] = 2 + fValues.back() + fValues[fValues.size()-2];

    diameter = max(diameter, max(f[V], gs[V]));
}

int main(){

	int n,m;
	cin>>n>>m;

	while(m--){
		int x,y;cin>>x>>y;g[x].pb(y),g[y].pb(x);
	}

	dfs2(1,0);
	dfs1(1,0);
	cout<<"It is f[v]: \n";
	MYREP(i,1,n){
		cout<<f[i]<<" ";
	}
	cout<<"Now it is gs[v]";

	MYREP(i,1,n){
		cout<<gs[i]<<" ";
	}

}
/*
5 4
1 2
1 3
2 4
2 5
*/
