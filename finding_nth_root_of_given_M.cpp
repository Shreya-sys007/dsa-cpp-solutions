//using helper power func instead of (int) pow( mid, N ) benefits us by preventing us from large values like mid = 10^8 etc

#include<bits/stdc++.h>
using namespace std;

long long power(int mid, int M, int N){
    long long ans = 1;

//go like if x = 2 then ans = 2 -> 2*2 -> 2*2*....N times

    for(int i=1;i<N;i++){
        ans *= mid;

        if(ans > M)
            return ans;    
    }

    return ans;
}

int main() {
    int N, M;
    cin>>N>>M;
    int l = 1, h = M;
    while(l<=h){
        int mid = l + (h-l)/2;
        int k = power(mid, M, N);
        if(k == M){
            cout<< mid;
            return 0;
        }
        else if(k < M){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    return -1;
}
