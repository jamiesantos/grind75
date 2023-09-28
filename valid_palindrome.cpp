#include <iostream>
#include <string>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
	bool ans = false;
    string s_new;
    for (auto c: s) {
      if (isalnum(c)) s_new += tolower(c);
    }
	//cout << s_new << endl;
    //ans = checkPalindrome(s_new);
    for (int i = 0; i < s_new.length()/2; ++i) {
      int i2 = s_new.length() - i - 1;
      if (s_new.at(i) != s_new.at(i2)) {
        return false;
      }
    }
    return true;
  }

/*  bool checkPalindrome(string s) {
    if (s.length() <= 1) return true;
    if (s.at(0) == s.back()) {
      cout << s << endl;
      s = s.substr(1, s.length() - 2);
    } else {
      cout << "false" << endl;
      return false;
    }
    return checkPalindrome(s);
  }
*/
};

int main() {
  Solution sol;
  string s = "A man, a plan, a canal: Panama";
//  string s = "race a car";
//  string s = "\"Sirrah! Deliver deified desserts detartrated!\" stressed deified, reviled Harris.";
  bool solution = sol.isPalindrome(s);
  cout << solution << endl;
  return 0;
}
