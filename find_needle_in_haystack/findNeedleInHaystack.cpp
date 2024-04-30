#include <iostream>

using namespace std;

class Solution {
private:
  int haystack_size, needle_size, i, j, temp_i, temp_j;
  bool match;

public:
  int strStr(string haystack, string needle) {
    haystack_size = haystack.length();
    needle_size = needle.length();
    i = 0;
    j = 0;

    if (haystack_size == 0 || haystack_size < needle_size) {
      return -1;
    }

    if (haystack == needle) {
      return i;
    }

    while (((haystack_size - i >= needle_size) || match == true) &&
           (needle_size - j > 0)) {
      if (haystack[i] == needle[j]) {
        j++;

        if (needle_size - j == 0) {
          return i;
        }

        match = true;
        temp_i = i + 1;
        temp_j = j;

        while (match && (haystack_size - temp_i > 0)) {
          if (haystack[temp_i] == needle[temp_j]) {
            temp_i++;
            temp_j++;
          } else {
            match = false;
          }

          if (needle_size - temp_j == 0) {
            return i;
          }
        }
        i++;
        j = 0;
      } else {
        match = false;
        i++;
        j = 0;
      }
    }

    if (match == true) {
      return i;
    } else {
      return -1;
    }
  }

  void printResult(string haystack, string needle, int returnValue) {
    if (returnValue == -1) {
      cout << "Can't find needle '" << needle << "' in the haystack '"
           << haystack << "'." << endl;
    } else {
      cout << "The index of needle '" << needle << "' in the haystack '"
           << haystack << "' is " << returnValue << "." << endl;
    }
  }
};

int main() {
  Solution S1, S2, S3, S4;

  string haystack1, needle1, haystack2, needle2, haystack3, needle3, haystack4,
      needle4, haystack5, needle5;
  int r1, r2, r3, r4, r5;

  haystack1 = "sadbutsad";
  needle1 = "sad";
  haystack2 = "leetcode";
  needle2 = "leeto";
  haystack3 = "a";
  needle3 = "a";
  haystack4 = "mississipie";
  needle4 = "issip";
  haystack5 = "aaa";
  needle5 = "aaa";

  r1 = S1.strStr(haystack1, needle1);
  r2 = S1.strStr(haystack2, needle2);
  r3 = S1.strStr(haystack3, needle3);
  r4 = S1.strStr(haystack4, needle4);
  r5 = S1.strStr(haystack5, needle5);

  S1.printResult(haystack1, needle1, r1);
  S1.printResult(haystack2, needle2, r2);
  S1.printResult(haystack3, needle3, r3);
  S1.printResult(haystack4, needle4, r4);
  S1.printResult(haystack5, needle5, r5);
}