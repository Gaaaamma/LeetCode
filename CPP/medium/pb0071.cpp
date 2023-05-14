#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

/*
#71 Simplify Path
Attempt 1: 
stack

Q: Given a string path, which is an absolute path (starting with a slash '/') 
   to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

   In a Unix-style file system, a period '.' refers to the current directory, 
   a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') 
   are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.
   
   The canonical path should have the following format:
   
   - The path starts with a single slash '/'.
   - Any two directories are separated by a single slash '/'.
   - The path does not end with a trailing '/'.
   - The path only contains the directories on the path from the root directory to the target file or directory 
     (i.e., no period '.' or double period '..')
   
   Return the simplified canonical path.
*/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        path += "/";
        int left = 1;
        for (int right = 1; right < path.size(); right++) {
            while (left < path.size() && path[left] == '/') left++;
            if (path[right] == '/' && right > left) {
                string judge = path.substr(left, right - left);
                if (judge == "..") {
                    if (!st.empty()) st.pop();
                } else if (judge != ".") st.push(judge);
                left = right;
            }
        }
        
        string result = "";
        while (!st.empty()) {
            string dir = st.top();
            reverse(dir.begin(), dir.end());
            result += dir;
            result += "/";
            st.pop();
        }
        reverse(result.begin(), result.end());
        if (result.empty()) result = "/";
        return result;
    }
};

template<class T>
void show1D(const vector<T>& input) {
    if (input.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < input.size() - 1; i++) {
        cout << input[i] << ",";
    }
    cout << input.back() << "]\n";
}
template<class T>
void show2DGraph(const vector<vector<T>>& input) {
    for (int i = 0; i < input.size(); i++) {
        show1D(input[i]);
    }
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<string> input{"//////home//test/123/", "/////home/test/../.././../abc/123/456", "/../../../home/test"};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.simplifyPath(input[i]) << "\n";
    }
}