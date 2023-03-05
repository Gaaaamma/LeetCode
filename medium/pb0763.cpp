#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
#763 Partition Labels
Attempt 1: 
calculate the frequency and use unordered_set to solve

Complexity: O(N) 

Q: You are given a string s. 
   We want to partition the string into as many parts as possible so that each letter appears in at most one part.

   Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
   Return a list of integers representing the size of these parts.
*/     
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Calculate the frequency
        vector<int> result;
        vector<int> alphabet(26, 0);
        for (int i = 0; i < s.size(); i++) {
            alphabet[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size();) {
            unordered_set<char> set;
            set.insert(s[i]);
            int count = 0;
            while (!set.empty()) {
                set.insert(s[i]);
                count++;
                alphabet[s[i] - 'a']--;
                if (alphabet[s[i] - 'a'] == 0)
                    set.erase(s[i]);
                i++;
            }
            result.push_back(count);
        }
        return result;
    }
};

void output(vector<int> result) {
    if (result.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < result.size() - 1; i++) {
        cout << result[i] << ", ";
    }
    cout << result.back() << "]\n";
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<string> input{"ababcbacadefegdehijhklij", "eccbbbbdec"};
    for (int i = 0; i < input.size(); i++) {
        output(solution.partitionLabels(input[i]));
    }
}