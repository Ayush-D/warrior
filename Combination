#include <bits/stdc++.h>
using namespace std;

#define fastio          std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define LL              long long
#define LD              long double
#define MAX             200005
//#define MOD             1000000007
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define CREP(i,n)       for(__typeof(n) i=n-1; i>=0; --i)
#define MYREP(i,a,b)    for(__typeof(a) i=a; i<=b; ++i)
#define MYCREP(i,a,b)   for(__typeof(a) i=b; i>=a; --i)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T powerL(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return powerL(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

// Usually done for Calculations most optimised

const int MAXN = 1e6+5;
ll fact[MAXN], invp[MAXN];

void init(){
    fact[0] = 1, invp[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = (fact[i-1] * i) % MOD;
    invp[MAXN-1] = invFermat(fact[MAXN-1], MOD);
    for(int i = MAXN-2; i >= 1; i--)
        invp[i] = (invp[i+1] * (i+1)) % MOD;
}

ll nCr(int n, int r){
    if(r < 0 || r > n)  return 0;
    return (fact[n] * ((invp[n-r] * invp[r]) % MOD)) % MOD;
}

int main(){
    init();
    // use nCr(i,j);
}
