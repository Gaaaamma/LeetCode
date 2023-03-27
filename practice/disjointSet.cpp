#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    int count;
    vector<int> set;

public:
    DisjointSet(int count) {
        this->count = count;
        set = vector<int>(this->count, -1);
    }
    
    int find(int element) {
        int root = element;
        vector<int> compression;
        compression.reserve(count);
        while (set[root] >= 0) {
            compression.push_back(root);
            root = set[root];
        }
        for (int i = 0; i < compression.size(); i++) {
            set[compression[i]] = root;
        }
        return root;
    }

    void setUnion(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        int countA = set[rootA];
        int countB = set[rootB];
        
        if (countA < countB) {
            set[rootA] += set[rootB];
            set[rootB] = rootA;
        } else {
            set[rootB] += set[rootA];
            set[rootA] = rootB;
        }
    }

    void show() {
        for (int i = 0; i < count; i++) {
            cout << set[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int count = 10;
    DisjointSet dj(count);
    int u,v;
    while (cin >> u >> v) {
        if (u == -1 && v == -1) break;
        if (dj.find(u) == dj.find(v)) {
            cout << u << " && " << v << " are in the same set\n";
        } else {
            dj.setUnion(u, v);
        }
        dj.show();
    }
    dj.show();
}