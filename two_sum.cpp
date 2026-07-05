//Problem: Two SUm
//Platform: LC 
//3 Different approaches

#include<bits/stdc++.h>
using namespace std;

//Approach 1
//TC: O(n^2)
//SC: O(1)
void bruteforce(vector<int>&arr, int target, int n){
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] + arr[j] == target){
                cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
    }
    return;
}

//Approach 2
//TC: O(n)
//SC: O(n)
void hashing(vector<int>&arr, int target, int n){
    int need = 0;
    unordered_map<int, int> hash;
    for(int i = 0; i<n; i++){
        need = target - arr[i];
        if(hash.find(need) != hash.end()){
            cout<<hash[need<<" "<<i<<endl;
        }
        hash[arr[i]] = i;
    }
    return;
}

//Approach 3
//TC: O(n log n)
SC: O(1)
void optimal(vector<int>&arr, int target, int n){
    sort(arr.begin(), arr.end());
    int left = 0, right = n-1;
    while(left<right){
        if(arr[left] + arr[right] == target){
            cout<< arr[left]<<" "<<arr[right]<<endl;
            left++;
            right--;
        }
        else if(arr[left] + arr[right]< target){
            left++;
        }
        else{
            right--;
        }
    }
    return;
}

int main() {
  vector<int> arr = {4,5,1,6,2,3,0,8};
  int n = arr.size();
  //bruteforce(arr, 11, 8);
  //hashing(arr, 11, 8);
  //optimal(arr, 11, 8);
}
  
 
