#include <bits/stdc++.h>
using namespace std;

void combinations(vector<string>&v,string prefix, string code)
{
	if(code.length()==0)
	{
		v.push_back(prefix);
		v.push_back(", ");
		return;
	}
	if (code[0]=='0')
	{
		v.push_back(prefix);
		v.push_back(", ");
		return;
	}
	char temp=(code[0]-'1'+'a');
	combinations(v,prefix+temp,code.substr(1));
	if(code.length()>=2 && code[0]=='1')
	{
		temp=(10+code[1]-'1'+'a');
		combinations(v,prefix+temp,code.substr(2));
	}
	if(code.length()>=2 && code[0]=='2'&&code[1]<='6')
	{
		temp=20+code[1]-'1'+'a';
		combinations(v,prefix+temp,code.substr(2));
	}
}
 
int main()
{
    string s;
    cin>>s;
   
    vector<string> v;
    cout<<"[";
    combinations(v,"",s);
    
    v.pop_back();
    //v.pop_back();
    for(int i=0;i<v.size();i++){
    	cout<<v[i];
    }
    cout<<"]";
    return 0;
}