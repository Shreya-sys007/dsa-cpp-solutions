//Thought this whole logic myself...kinda happy....that too in less than avg time
class Solution {
  public:
    long long factorial(int k){
        return 1LL*k*(k-1)/2;
    }
    int findSubarray(vector<int> &arr) {
        // code here.
        int n = arr.size();
        unordered_map<int, int>hash;
        long long cnt = 0;
        if(arr.size() == 0){
            return 0;
        }
        vector<int>prefix(n);
        prefix[0] = arr[0];
        hash[0] = 1;
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }
        for(int x: prefix){
            hash[x]++;
        }

        for(int i = 0; i<n; i++){
            if(hash[prefix[i]] > 1){
                int p = hash[prefix[i]];
                factorial(p);
                cnt+= factorial(p);
                hash[prefix[i]]=0;
            }
        }
        //         int p = hash[prefix[i]];
        //         factorial(p);
        //         cnt += factorial(p);
        //         //cnt += nC2 values
        //     }
        // }
        return cnt;
    }
};
