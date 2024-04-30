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

        while (((haystack_size - i >= needle_size) || match == true) && (needle_size - j > 0)) {
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
                    }
                    else {
                        match = false;
                    }

                    if (needle_size - temp_j == 0) {
                        return i;
                    }
                }
                i++;
                j = 0;
            }
            else {
                match = false;
                i++;
                j = 0;
            }
        }

        if (match == true) {
            return i;
        } 
        else {
            return -1;
        }
    }
};