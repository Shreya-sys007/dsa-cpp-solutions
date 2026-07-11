//we used a set just to either choose a number or skip it if duplicate
//CANNOT USE: v[i] = arr[arr[i]%m] bcz u used the loop from 0 to n and vector v is of size m

class Solution {
  public:
    vector<int> quadraticProbing(vector<int>& arr, int m) {
        // code here
        int n = arr.size();
        unordered_set<int>st;
        vector<int>v(m, -1);
        for(int i = 0; i<n; i++){
            if(st.find(arr[i]) != st.end()){
                continue;
            }
            else{
                st.insert(arr[i]);
            }
            int hv = arr[i]%m;
            if(v[hv] == -1){
                v[arr[i]%m] = arr[i];
            }
            else{
                //collision
                for(int j = 0; j<m; j++){
                    int t = (hv + j*j)%m;
                    if(v[t] == -1 ){
                        v[t] = arr[i];
                        break;
                    }
                }
            }
        }
        return v;
    }
};
