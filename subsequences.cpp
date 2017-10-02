#include <iostream>
using namespace std;

void printsub(char*inp,char *out,int i,int j){

	if(inp[i]=='\0'){
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	//1.lelo
	out[j]=inp[i];
	printsub(inp,out,i+1,j+1);
	//2.chodh do
	printsub(inp,out,i+1,j);
}

int main()
{
	char input[]="abc";
	char output[10];
	int i=0,j=0;
	printsub(input,output,i,j);
	return 0;
}