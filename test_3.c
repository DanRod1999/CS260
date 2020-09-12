#include <stdio.h>

    int n = 14;//num of elements

int search(int arr[], int searched_val, int pos, int depth_count){
    depth_count = depth_count * 2;
    if(searched_val == arr[pos]){
        return 1;//element found;
    }
    else if(searched_val < arr[pos]){

        search(arr, searched_val, pos - (n/depth_count), depth_count);// move position to down by increment of 1/x
    }
        else if(searched_val > arr[pos]){

        search(arr, searched_val, pos + (n/depth_count), depth_count);// move position to up by increment of 1/x
    }
    else
        return 0;
}

int main(){


    
    int arr[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    int searched_val;
    int pos = n/2;
    int depth_count = 2;//keep track of how much is needed to add when search inside list happens over time

    printf("%d\n\n",search(arr, 7,pos, depth_count));
    printf("%d\n\n",search(arr, 8,pos, depth_count));
    printf("%d\n\n",search(arr, 8,pos, depth_count));
    printf("%d\n\n",search(arr, 5,pos, depth_count));
}