#include <bits/stdc++.h>
using namespace std;

void seeAndCall(string &s1,string s2){

	int len1=s1.size();	int len2=s2.size();
	int max=INT_MIN;

	string result[1000]="";

	int match[50][50];
	int k=0;

	for(int i=0;i<len1;i++){

		for(int j=0;j<len2;j++){

			if(s1[i]==s2[j]){

				if(i==0||j==0)	match[i][j]=1;

			else	match[i][j]= match[i-1][j-1] + 1;

			if(max<match[i][j]){
				k=0;	
				max=match[i][j];

				result[k] = s1.substr(i-max+1,i+1);
				k++;

			}
		if(match[i][j]==max){
			k=1;
			result[k]=s1.substr(i-max+1,i+1);
			k++;
		}	

			}

			else match[i][j]=0;
		}

	}	
	for(int i=0;i<k+1;i++)
		cout<<result[i]<<endl;
}

int main()
{
	string s1,s2;
	cin>>s1;
	cin>>s2;

	seeAndCall(s1,s2);

	return 0;
}