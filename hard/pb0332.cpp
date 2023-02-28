#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
#332 Reconstruct Itinerary
Attempt 1: 
Use backtracking to find result

Complexity: O(N)

Q: You are given a list of airline tickets where tickets[i] = [fromi, toi] 
   represent the departure and the arrival airports of one flight. 
   Reconstruct the itinerary in order and return it.

   All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". 
   If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order 
   when read as a single string.

   For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].

   You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
*/

class Solution {
public:
    int ticketCount;
    bool findOne;
    vector<vector<int>> table;
    vector<string> path;
    vector<vector<string>> result;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ticketCount = tickets.size();
        path.clear();
        path.push_back("JFK");
        findOne = false;
        result.clear();

        // Count number of country
        unordered_map<string, int> uomap;
        for (int i = 0; i < tickets.size(); i++) {
            for (int j = 0; j < tickets[i].size(); j++) {
                uomap.insert({tickets[i][j], 0});
            }
        }
        vector<pair<string, int>> mapping(uomap.begin(), uomap.end());
        sort(mapping.begin(), mapping.end(), [](pair<string, int> a, pair<string, int> b){return a.first < b.first;});
        for (int i = 0; i < mapping.size(); i++) {
            uomap[mapping[i].first] = i;
        }
        
        // Create table
        vector<int> pattern(uomap.size() ,0);
        table = vector<vector<int>>(uomap.size(), pattern);
        for (int i = 0; i < tickets.size(); i++) {
            table[uomap[tickets[i][0]]][uomap[tickets[i][1]]] += 1;
        }
    
        // Find Path
        backtracking(mapping , uomap["JFK"]);
        if (result.empty())
            return vector<string>{};
        else return result.front();
    }
    void backtracking(vector<pair<string, int>> mapping , int index) {
        if (path.size() == ticketCount + 1) {
            result.push_back(path);
            findOne = true;
            return;
        }
        for (int i = 0; i < table[index].size(); i++) {
            if (findOne) return;
            if (table[index][i] > 0) {
                table[index][i] -= 1;
                path.push_back(mapping[i].first);
                backtracking(mapping, i);
                path.pop_back();
                table[index][i] += 1;
            }
        }
    }
};

void output(vector<string> input) {
    if (input.empty()) {
        cout << "[]\n";
    } else {
        cout << "[";
        for (int i = 0; i < input.size() - 1; i++) {
            cout << input[i] << ", ";
        }
        cout << input.back() << "]\n";
    }
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<string>>> input {  
        {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}},
        {{"JFK","SFO"}, {"JFK","ATL"}, {"SFO","ATL"}, {"ATL","JFK"}, {"ATL","SFO"}}};

    for (int i = 0; i < input.size(); i++) {
        output(solution.findItinerary(input[i]));
    }
}