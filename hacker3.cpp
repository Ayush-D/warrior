#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

//Remove vovels in string
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||
            s[i]=='O'||s[i]=='U'){
            s.replace(i,1,"");
            i--;
        }
    }
//Not ready
    for(int i=0;i<n;i++){
        if(s[i+1]!='a'||s[i+1]!='e'||s[i+1]!='i'||s[i+1]!='o'||s[i+1]!='u'||s[i+1]!='A'||s[i+1]!='E'||
            s[i+1]!='O'||s[i+1]!='U'){
            s.insert(i,".");
        }
    }

    cout<<s;
}