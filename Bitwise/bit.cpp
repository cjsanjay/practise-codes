#include<iostream>
#include<vector>
 using namespace std;
 
 
 int checkIfPalindrome(int number){
 	int temp=number; 	
 	int count,i,j;
 	count=0;
 	while(temp!=0){
 		temp=temp>>1;
 		count++;
 	}
 	if(count%2!=0){
	 	i=count/2;
	 	j=i;
	 }else{
	 	i=count/2;
	 	j=i+1;
	 }
	 i--;
	 j--;
	 while(i>=0){
	 	if(((number & (1<<i))>>i)!=((number & (1<<j))>>j)){
	 		return 0;
	 	}
	 	i--;
	 	j++;
	 }
	 return 1;	 	 	
 }
 
 int main(int argc,char* argv[]){
	int v;           // we want to find the absolute value of v
	int number;
	unsigned int r;  // the result goes here 
	int arr[]={1,2,3,4,5};
	vector<int> x(arr,arr+sizeof(arr)/sizeof(int));
	for(vector<int>::iterator it=x.begin();it!=x.end();++it){
		cout<<' '<<*it;
	}
	cout<<endl;
	/*v=-5;
	int const mask = v >> sizeof(int) * 1 - 1;
	r = (v + mask) ^ mask;
	cout<<r;
	cin>>number;
	if(checkIfPalindrome(number)){
		cout<<"Palindrome"<<endl;
	}else{
		cout<<"Not Palindrome"<<endl;
	}*/
		
 }
