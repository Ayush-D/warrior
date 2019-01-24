#include <bits/stdc++.h>
using namespace std;

#define fastio          std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

char dp[105][105];

string lcs(string a, string b, int i, int j, string k){
    if(i == -1 || j == -1){
        return k;
    }
    if(a[i] == b[j]){
        return lcs(a,b,i-1,j-1,a[i]+k);
    }

    string t1 = lcs(a,b,i-1,j,k);
    string t2 = lcs(a,b,i,j-1,k);
    if(t1.size() > t2.size())   return t1;
    else return t2;
}

int main(){
    fastio;
    string s1,s2;
    cin>>s1>>s2;

    cout<<lcs(s1,s2,s1.size(),s2.size(),"");

}
