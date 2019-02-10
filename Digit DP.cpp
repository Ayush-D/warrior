// From https://github.com/flash7even/Programming-Contest/blob/master/Code%20Repository/Dynamic%20Programming/Digit%20DP/Digit-DP.cpp
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

std::vector<int> num;
int a,b,d,k;
int DP[15][15][2];
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

int go(int pos, int cnt, int fl){

    if(pos == num.size()){
        if(cnt == k)    return 1;
        return 0;
    }
    if(cnt > k)     return 0;

    if(DP[pos][cnt][fl] != -1) return DP[pos][cnt][fl];

    int lmt;
    if(fl){ //num is already smaller
        lmt = 9;
    }else lmt = num[pos];

    int res = 0;
    for(int i = 0; i <= lmt; i++){
        int nf = fl;
        int ncnt = cnt;
        if(fl == 0 && i < lmt) nf = 1; /// The number is getting smaller at this position
        if(i == d) ncnt++;
        res += go(pos+1, ncnt, nf);
    }
    return DP[pos][cnt][fl] = res;
}

int solve(int b){
    num.clear();
    while(b>0){
        num.pb(b%10);
        b/=10;
    }
    reverse(num.begin(),num.end());
    memset(DP,-1,sizeof DP);
    return go(0,0,0);
}

int main(){
    cin>>a>>b>>d>>k;
    cout<<solve(b) - solve(a-1);
}
