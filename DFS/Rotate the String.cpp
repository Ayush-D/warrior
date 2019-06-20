#include<bits/stdc++.h>
using namepsace std;

int main(){

    string s;
    cin>>s;
    int k;
    cin>>k;

    int n = s.size();
    reverse(s.begin(),   s.begin()+k);
    reverse(s.begin()+k, s.end());
    reverse(aLL(s));

    cout<<s;

}
