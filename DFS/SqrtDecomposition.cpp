// Sqrt Decomposition code written by me :)

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fastio          std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define LL              long long
#define LD              long double
// #define MAX             200005
#define MOD             1000000007
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define CREP(i,n)       for(__typeof(n) i=n-1; i>=0; --i)
#define MYREP(i,a,b)    for(__typeof(a) i=a; i<=b; ++i)
#define MYCREP(i,a,b)   for(__typeof(a) i=b; i>=a; --i)
#define SET(a, b)       memset(a, b, sizeof(a))
#define pb              push_back
#define mp              make_pair
#define fi              first
#define sec             second
#define aLL(c)          (c).begin(),(c).end()
#define aLLr(c)         (c).rbegin(),(c).rend()
#define loop(c,i)       for(typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(aLL(c),x) != (c).end())
#define BLOCK 555   // Optimum in Most Cases    Mo's Algo see Anudeep Bookamrks
 
long mul(long a, long b, long c){long long res=(long long)a*b;return(res>=c?res%c:res);}
 
template <typename T> T mod(T a, T b) {return (a < b ? a : a % b);}
//(a - b) % c
template<typename T> T mod_neg(T a, T b) {a=mod(a, b);if(a<0){a+=b;}return a;}
//(a * b) % c for very large numbers, to avoid overflows
//O(1) hack taken from http://codeforces.com/blog/entry/15884
LL mulmod(LL a,LL b, LL m){LL q=(LL)(((LD)a*(LD)b)/(LD)m);LL r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
//(a ^ n)
//Complexity: O(log (n))
template <typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
//(a ^ n) % m
//Complexity : O(log (n))
 
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template <typename T>T powerL(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mulmod(x,p,m);p=mulmod(p,p,m);n>>=1;}return x;}
 
template <typename T> T InverseEuler(T a, T m){return (a==1? 1 : power(a, m-2, m));}
//gcd of 2 numbers a, b
//Complexity: O(log(max(a, b)))
template<typename T> T gcd(T a, T b) { return (b ? __gcd(a,b) : a); }
//lcm of 2 numbers a and b
//Complexity: O(log(max(a, b)))
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
template<typename T> T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T> T mod_inverse(T a, T n){T x,y;T d = extended_euclid(a, n, x, y);return (d>1?-1:mod_neg(x,n));}
template<class T> T fast_gcd(T u, T v) {
    long shl = 0; while ( u && v && u != v) { T eu = u & 1; u >>= eu ^ 1; T ev = v & 1; v >>= ev ^ 1;
        shl += (~(eu | ev) & 1); T d = u & v & 1 ? (u + v) >> 1 : 0; T dif = (u - v) >> (sizeof(T) * 8 - 1); u -= d & ~dif; v -= d & dif;
    } return std::max(u, v) << shl;
}
 
// Most immportant one best optimised 
template<class T> bool isPrime(T x) { if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
    for (T i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1; 
}
 
/*
 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// tree defined...
using namespace __gnu_pbds;
typedef tree <long, null_type, less_equal<long>, rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
//All indexing is 0-based
//methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar.
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_multiset;
 
template<class key, class value, class cmp = std::less<key>>
using tordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_map<int, int> my_map;
*/
 
/*
const long MAXS = 1e6 + 5;
LL bit[MAXS];       //1-based indexing for bit
long n;
//Complexity: O(log n)
void update(long idx, long val) {
    while (idx <= MAXS) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}
 
//Complexity: O(log n)
long long query(long idx) {
    long sum = 0;
    while(idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

*/
 
const int N = 1e6 + 5;
int seive[N];
 
void pre(){
    fill(seive+2, seive+N, 1);
 
    for(int i = 2; i < N; i++){
        if(seive[i]){
            for(int j = 2; j*i <= N; j++){
                seive[i*j] = 0;
            }
        }
    }
}


int main(){

    int n, a[100005];
    cin>>n;

    REP(i,n)cin>>a[i];
    int srt = sqrt(n);

    int block = (n + srt - 1)/srt;
    //cout<<"Total Blocks: "<<srt<<" "<<block<<nl;

    // Make array for F
    int F[srt + 5];
    fill(F, F + srt + 4, INT_MAX);

    int blk = 0;
    for(int i = 0; i < n; ){
        while(blk == i/srt){
            F[blk] = min(F[blk], a[i]);
            ++i;
        }
        blk ++;
    }

    /*
    cout<<"F array is:\n";
    REP(i,n/srt){
        cout<<F[i]<<" ";
    }
    */

    int q;
    cin>>q;
    while(q--){

        int l, r;
        int ans = INT_MAX;
        cin>>l>>r;
        // --l, --r; 1 based indexing
        // 1 to 10

        int lb = l / srt, rb = r / srt;
        //cout<<"Query block: "<<lb<<" "<<rb<<nl;

        // We need to check for same block else Wrong :{
        if(lb == rb){
            for(int i = l; i <= r; i ++){
                ans = min(ans, a[i]);
            }
            cout<<ans<<nl;
            continue;
        }

        //cout<<"Array block: "<<l<<" "<<(lb + 1)*srt - 1<<nl;
        for(int i = l; i < (lb + 1)*srt; i ++){
            ans = min(ans, a[i]);
        }
        
        //cout<<"Block of F: "<<lb+1<<" "<<rb-1<<nl;
        for(int i = lb + 1; i < rb; i ++){
            ans = min(ans, F[i]);
        }
        
        //cout<<"Array block: "<<rb*srt<<" "<<r<<nl;
        for(int i = rb*srt; i <= r; i ++){
            ans = min(ans, a[i]);
        }

        cout<<ans<<nl;

    }

}
