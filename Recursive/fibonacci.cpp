#include<iostream>

using namespace std;

int fib(int number){
	if(number==1){
		return 0;
	}
	if(number<=3 && number>=2){
		return 1;
	}else{
		return(fib(number-1)+fib(number-2));
	}
}

int main(int argc, char*argv[]){
	int number;
	cin>>number;
	cout<<fib(number);
	return 0;
}
