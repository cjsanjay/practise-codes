#include<iostream>
#include<vector>


using namespace std;


void printSpiral(int array[3][6]){
    int r_start=0,r_end=2,c_start=0,c_end=5;
    int i=0;
    while(c_start<=c_end){
        if(r_start<=r_end){       
            for(i=c_start;i<=c_end;i++){            
               cout<<array[r_start][i]<<" ";
            }        
        }
        r_start=r_start+1;
        if(c_end>=c_start){
            for(i=r_start;i<=r_end;i++){
              cout<<array[i][c_end]<<" ";
            }
        }
        c_end=c_end-1;
        if(r_end>=r_start){      
            for(i=c_end;i>=c_start;i--){
                cout<<array[r_end][i]<<" ";
            }
        }
        r_end=r_end-1;
        if(c_start<=c_end){
            for(i=r_end;i>=r_start;i--){
                cout<<array[i][c_start]<<" ";
            }
        }    
        c_start=c_start+1;
    }
}

int main(int argc, char *argv[]){
    int array[3][6]={{1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}};
    printSpiral(array);
    cout<<"\n";     
    return 0;
}
