#include<iostream>
#include<queue>

using namespace std;


void display(int *array,int size){
	for(int i=0;i<=size;i++){
		cout<<" "<<array[i]<<endl;
	}
}

void merge(int *array,int start,int mid,int end){
	queue<int> buffer1,buffer2;
	int k;
	for(int i=start;i<=mid;i++) buffer1.push(array[i]);	
	for(int i=mid+1;i<=end;i++) buffer2.push(array[i]);	
	k=start;
	while(buffer1.size()!=0 && buffer2.size()!=0){
	    if(buffer1.front()<buffer2.front()){
	        array[k]=buffer1.front();
	        buffer1.pop();
	        k++;	        
	    }else{
	        array[k]=buffer2.front();
	        buffer2.pop();
	        k++;
	    }
	}	 
	while(buffer1.size()!=0){
	    array[k]=buffer1.front();
	    buffer1.pop();
	    k++;
	}
	while(buffer2.size()!=0){
	    array[k]=buffer2.front();
	    buffer2.pop();
	    k++;
	}
}
void mergeSort(int *array,int start,int end){
	int mid=(start+end)/2;
	if(start<end){
		mergeSort(array,start,mid);
		mergeSort(array,mid+1,end);		
		merge(array,start,mid,end);			
	}	
}



int main(int argc,char *argv[]){

	int array[]={3,5,1,3,9,6,3,45,98,89};
	mergeSort(array,0,9);
	display(array,9);
}
