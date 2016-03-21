#include<iostream>

struct Point
{
    int x, y;
};

using namespace std;

void findOverlap(Point l1,Point r1,Point l2,Point r2){
    int x_min1=l1.x;
    int x_max1=r1.x;
    int y_min1=l1.y;
    int y_max1=r1.y;
    
    if(x_min1>x_max1){
        int temp=x_min1;
        x_min1=x_max1;
        x_max1=temp;
    }
    
    if(y_min1>y_max1){
        int temp=y_min1;
        y_min1=y_max1;
        y_max1=temp;
    }
    
    int x_min2=l2.x;
    int x_max2=r2.x;
    int y_min2=l2.y;
    int y_max2=r2.y;
    
    if((x_min2>=x_min1 || x_min2<=x_max2) && (y_min2>=y_min1 ||y_min2<=y_min1)){
        cout<<"OverLap";       
    }else{
        cout<<"No Overlap";
        
    }
    
}

int main(int argc, char *argv[]){
    Point l1 = {0, 10}, r1 = {10, 0};
    Point l2 = {5, 5}, r2 = {15, 0};
    
    findOverlap(l1,r1,l2,r2);
    return 0;
}
