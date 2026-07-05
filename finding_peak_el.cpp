//find the peak element in the given sorted array using BS method
//TC: O(log n)
//SC: O(1)
//LOGIC: If the array is sorted in ascending order then the slope is ascending so peak must occur on right as we go
//Similarly, if array is sorted in descending order, then the slope is descending and peak must occur towards the left
//IMP: the two ptrs shouldn't be equal to each other bcz if suppose l== h then mid = h then using mid +1 
//will make the code go out of bounds

#include<bits/stdc++.h>
using namespace std;

int peakel(vector<int>&arr, int l, int h){
    while(l<h){
        int mid = l + (h-l)/2;
        if(arr[mid] <= arr[mid+1]){
            l = mid+1;
        }
        else{
            h = mid;
        }
    }
    return l;
}

int main() {
    vector<int>arr= {1,2,4,5,6,7,8,3};
    int n = arr.size();
    cout<<peakel(arr, 0, n-1);
}
