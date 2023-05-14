#include <iostream>
#include <algorithm> 
#include <vector>
#include <unordered_set>
using namespace std;

/*
#151 Reverse Words in a String
Attempt 1: 
Use two pointer to solve
head to locate the startIndex of a subString
tail to locate the endIndex of a subString
use str.substr(startIndex, length) to catch a word and insert it to result string

Complexity: O(N)

Q: Given an input string s, reverse the order of the words.
   
   A word is defined as a sequence of non-space characters. 
   The words in s will be separated by at least one space.

   Return a string of the words in reverse order concatenated by a single space.

   Note that s may contain leading or trailing spaces or multiple spaces between two words. 
   The returned string should only have a single space separating the words. Do not include any extra spaces.
*/

class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        bool first = true;
        int head = 0;
        int tail = 0;

        for (head = s.size() - 1, tail = s.size() - 1; head >= 0; head--) {
            if (s[head] == ' ') {
                if (head == tail) {
                    tail--;
                } else {
                    // A word from head to end
                    if (!first) {
                        result += " ";
                    } else {
                        first = false;
                    }
                    result += s.substr(head + 1, tail - head);
                    tail = head - 1;
                }
            }
        }

        // Handle first word
        if (s[0] != ' ') {
            if (first) {
                result += s.substr(0, tail + 1);
            } else {
                result += " " + s.substr(0, tail + 1); 
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]){
    vector<string> input{"the sky is blue", "  hello world  ", "a good   example", "an another test", "onlyOne"};

    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << solution.reverseWords(input[i]) << "\n";
    }
}