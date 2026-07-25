//EG. string : " the sky   is  blue  "
//output: "blue is sky the"
class solution{
public:
  void reversestring(string s){
    int n = s.size();
    int i = 0, j = 0;
    while(i < n){
      while(i == n || s[i] == ' '){
        i++;
      }
      if(s[i] != ' '){
        s[j] = s[i];
        i++;
        j++;
      }
      while(i == n || s[i] == ' '){
        i++;
      }
      if(s[i-1] != ' ' && i < n){
        s[j] = ' ';
        j = j+1;
      }
    }
    s.resize(j);
    return s;
  }
};
