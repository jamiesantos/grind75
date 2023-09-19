#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    if (s.length() % 2 != 0) {
      return false;
    }
    stack <char> stack;
    string left =  "([{";
    string right = ")]}";
    int idxL = -1;
    int idxR = -1;
	for (int i = 0; i < s.length(); i++) {
      char c = s.at(i);
      idxL = left.find(c);
      if (idxL != std::string::npos) {
        stack.push(idxL);
	  } else {
        idxR = right.find(c);
        if (!stack.empty() && (stack.top() == idxR)) {
          stack.pop();
        } else {
          cout << "false" << endl;
          return false;
        }
      }
    }
    if (stack.size() > 0) {
      return false;
    }
    cout << "true" << endl;
    return true;
  }
};

int main() {
  Solution sol;
  string s = "){";
  sol.isValid(s);
  return 0;
}
