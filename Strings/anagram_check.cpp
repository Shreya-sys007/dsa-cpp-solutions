#include <bits/stdc++.h>
using namespace std;
//anagram is basically if two strings are permutations of each other or not
//in anagram, LOGIC: SIMPLY THE FREQ OF EACH CHAR IN EACH STRING SHOULD MATCH
int main() {
  //to check if two strings are permutations of each other or not, we basically make hash table for each char in each string
  string s = "abc adbc";
  int n = s.size();
  string t = "acd bacb";
  int m = t.size();
  //always check size first
  if(n != m){
    return 0;
  }
  //M1. CREATE A NORMAL HASH TABLE USING MAPS
  unordered_map<int, int>hash;
  for(int i = 0; i<n; i++){
    hash[s[i]]++;
  }
  int isfound = 1;
  for(int i = 0; i<m; i++){
    if(hash[t[i]] == 0){
      isfound = 0;
      break;
    }
    hash[t[i]]--;
  }
  cout<< isfound;
}

  //M2. USING A HASH VECTOR - COUNT

int main() {

  string s = "abc adbc";
  int n = s.size();
  string t = "acd bacb";
  int m = t.size();
  //always check size first
  if(n != m){
    return false;
  }
  int isfound = 1;
  vector<int>count(26);
  for(int i = 0; i<n; i++){
    count[s[i] - 'a']++; //can use s[i]] only but if the les in string are only lowercase then we can reduce the space by this
  }
  for(int i = 0; i<m; i++){
    count[t[i] - 'a']--; //with uppercase letters simply use (.... - 'A')
  }
  for(int i = 0; i<count.size(); i++){
    if(count[i]  != 0){
      isfound = 0;
      break;
    }
  }
  cout<<isfound;
}
