#include<bits/stdc++.h>
using namespace std;
//NAIVE SOLN
int main() {
  string s = "This is a test text";
  int n = s.size();
  string pat = "test";
  int m = pat.size();
  //LOGIC: slide the pattern over the string s and search for each pat[j] from j = 0 to j = m. 
  for(int i = 0; i<=n-m; i++){
    int j;
    for(j = 0; j<m; j++){
      if(s[i+j] != pat[j]){
        break;
      }
    }
    if(j == m){
      cout<<i; //pt where the pattern started
    }
  }
return 0;
}

//RABIN-KARB SOLUTION
int main() {
  string s = "This is a test text";
  int n = s.size();
  string pat = "test";
  int m = pat.size();
  //LOGIC: Like in arrays in case of numbers to match the pattern we can say that the sum of the pattern and 
//the sum of the string found in string s is same. But there can be spurious hits. For this we use improved hash function
  //STEP 1. COMPUTE d^(m-1) VALUE 
  //STEP 2. COMPUTE PATTERN SUM (HASH) AND FIRST STRING S WINDOW SIZED-M SUM USING sum = sum*d + str[i]
  //STEP 3. IF THE PATTERN SUM AND THE SUBSTRING OF STRING S SUM ARE EQUAL-- MATCH CHARS.
  //STEP 4. NOW THERE CAN BE SPURIOUS HITS. FOR MAKING THE SUM OF EACH SUBSTRING DIFF, WE USE IMPROVED ROLLING HASH FXN

  //%q is done just to make the vals a bit small as they can bcm huge
  int h = 1, q = 101, d= 256;
  for(int i = 0; i<m-1; i++){
    h = (h*d)%q;
  }
  int p =0, t=0;
  for(int i = 0; i<m; i++){
    p = (p*d + pat[i])%q;
    t = (t*d + s[i])%q;
  }
  for(int i = 0; i<=n-m; i++){
    if(p == t){
        //SINCE THE HASH VAL IS SAME NOW FOLLOW NAIVE APPROACH BY CHECKING EACH CHAR OF PATTERN AND SUBSTRING
      int j;
      for(j = 0; j<m; j++){
        if(s[i+j] != pat[j]){
          break;
        }
      }
      if(j == m){
        cout<<i;
      }
    } // if p == t
      //ROLLING HASH FXN TO CHECK FOR THE OTHER SUBSTRINGS OF SIZE M IN STRING S
      if(i < n-m){ //bcz we are using s[i+m]
        t = (d*(t - s[i]*h) + s[i+m])%q;
        if(t < 0) { // t can bcm <0 on doing -s[i]*h
          t = t+ q;
          } // this if loop
        } //if i < n-m
    } // i loop
}
//KEEP ROLLING HASH FXN OUTSIDE THE IF P==T LOOP BCZ WE HAVE TO FIND THE FXN EVEN IF P != T

//KMP ALGO



  
