class Solution {
  public:
long long nC2(int k){
  return 1LL*k*(k-1)/2;
}
    int countSubarray(vector<int>& arr) {
        // code here
      int n = arr.size();
      for(int &x: arr){
        if(x == 0){
          x = -1;
        }
      }
      long long cnt = 0;
      unordered_map<int, int>hash;
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
                cnt+= nC2(p);
                hash[prefix[i]]=0;
            }
        }
      return cnt;
    }
};
