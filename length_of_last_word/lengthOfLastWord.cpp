#include <iostream>

using namespace std;

class Solution {
private:
    int s_length, length, j;
public:
    int lengthOfLastWord(string s) {
        length = 0;
        j = 1;
        s_length = s.length();

        if (s_length == 0) {
            return 0;
        }

        if(s[s_length  - 1] == ' ') {
            while (s[s_length - j] == ' ') {
                j++;
            }
        }

        for (int i = s_length - j; i >= 0; i--) {
            if (s[i] == ' ') {
                return length;
            }
            length++;
        }
        return length;
    }
};