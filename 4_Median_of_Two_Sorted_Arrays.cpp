#include<bits/stdc++.h>
using namespace std;

double medianSortedArrays(int first[],int second[], int x, int y){
    if(x>y){
        return medianSortedArrays( second, first, y, x);
    }
    int low=0;
    int high=x;
    while(low<=high){
        int partitionX= (low+high)/2;
        int partitionY=(x+y+1)/2-partitionX;
        int maxLeftX=(partitionX==0)?INT_MIN: first[partitionX-1];
        int minRightX=(partitionX==x)?INT_MAX: first[partitionX];
        int maxLeftY=(partitionY==0)?INT_MIN: second[partitionY-1];
        int minRightY=(partitionY==y)?INT_MAX: second[partitionY];
        if(maxLeftX<=minRightY&& maxLeftY<=minRightX){
            if((x+y)%2==0){
                return ((double)(max(maxLeftX, maxLeftY)+min(minRightX, minRightY)))/2;
            }
            else
                return (double)max(maxLeftX,maxLeftY);
        }
        else if(maxLeftX>minRightY)high = partitionX-1;
        else low= partitionX+1;
    }
    return 0.01;
}
int main(){
    int arr1[5]={1, 2, 3, 4 ,5};
    int arr2[10]={-11, 2, 10, 12, 13, 14, 15 , 16, 17, 20};
    cout<<medianSortedArrays(arr1, arr2, 5, 10);
    return 0;

}
