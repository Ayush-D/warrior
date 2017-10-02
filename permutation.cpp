#include <iostream>
using namespace std;

void printPerm(char *input,int i){
		
	if(input[i]=='\0'){
		cout<<input<<endl;
		return ;
	}
	for(int j=i;input[j]!='\0';j++){
		swap(input[i],input[j]);
		printPerm(input,i+1);

		swap(input[i],input[j]);
	}

}

int main(){

	char input[]="abc";
	printPerm(input,0);
	return 0;
}