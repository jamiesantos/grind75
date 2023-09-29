#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    map<char, int> s_map = mapString(s);
    map<char, int> t_map = mapString(t);
	map<char, int>::iterator it_t = t_map.begin();
    map<char, int>::iterator it_s;

    if (s_map.size() != t_map.size()) return false;

    for (it_s = s_map.begin(); it_s != s_map.end(); it_s++) {
      if (it_s->first != it_t->first || it_s->second != it_t->second) return false;
      it_t++;
    }
  
    return true;
  }

  map<char,int> mapString(string s){
    map<char, int> s_map;
    for (auto c: s) {
      if (s_map.find(c) == s_map.end()) {
        s_map[c] = 1;
      } else {
        s_map[c]++;
      }
    }
    return s_map;
  }
};

int main() {
  Solution sol;
  string s = "anagram";
  string t = "nagaram";
  cout << sol.isAnagram(s,t);
  return 0;
}
