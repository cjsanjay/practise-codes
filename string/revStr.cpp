#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;


void reverseStringPrint(char *name){
	if(*name!='\0'){
		reverseStringPrint(name+1);
		cout<<*name;
	}
}

int reverseAndStore(char *name,char *name1,int count){
	if(*name!='\0'){
		count=reverseAndStore(name+1,name1,count);
		*(name1+count)=*name;
		return count+1;
	}
}

void printTable(){
	int i=1;
	for(i=1;i<=12;i++){
		for(int j=1;j<=12;j++){
			cout<<i*j<<" ";
		}		
		cout<<endl;
	}
}

int printSum(){
	ifstream myfile;
	char str[20];
	int sum=0;
	myfile.open("example.txt");
	while(getline(myfile,str)){
		sum=sum+atoi(str);
	}
	myfile.close();
	return sum;
}

int main(int argc,char *argv[]){
	char str[20],str1[20];
	int count;
	cin>>str;
	reverseStringPrint(str);
	count=reverseAndStore(str,str1,0);	
	cout<<endl;
	str1[count]='\0';		
	cout<<str1<<endl;
	printTable();
	cout<<printSum();
}
