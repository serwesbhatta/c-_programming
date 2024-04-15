#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  bool match = true;
  int i = 0;
  string result = "";
  char temp;

public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) {
      return "";
    }

    while (match) {
      if (i >= strs[0].size()) {
        break;
      }

      temp = strs[0][i];

      for (int j = 1; j < strs.size(); j++) {
        if (i <= strs[j].size() && temp == strs[j][i]) {
          match = true;
        } else {
          match = false;
          break;
        }
      }

      if (match == true) {
        result += temp;
      }

      i++;
    }
    return result;
  }
};

int main() {
  Solution S;
  string prefix;
  vector<string> array = {"flower", "flow", "flee"};

  prefix = S.longestCommonPrefix(array);

  cout << prefix;
}