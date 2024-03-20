#include <vector>
#include <set>
#include <iostream>
using namespace std;

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
    vi p, rank, setSize;
    vector<uint64_t> sum;                           // vi p is the key part
    vector<set<int>> sets;
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0);
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional feature
        sets = vector<set<int>>(N);
        sum.assign(N, 0);
        for (int i = 0; i < N; i++) {
             p[i] = i; 
             sets[i].insert(i);
             sum[i] = i;
        }
        numSets = N;                                 // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return p[i] == p[j]; }

    int numDisjointSets() { return numSets; }      // optional
    int sizeOfSet(int i) { return setSize[p[i]]; } // optional
    uint64_t sumOfSet(int i) { return sum[p[i]]; }
    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set

        int x = p[i], y = p[j];          // find both rep items

        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        for (auto it : sets[x]) {
            sets[y].insert(it);
            p[it] = y;
        }
        sets[x].clear();
        sum[y] += sum[x];
        sum[x] = 0;
        // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        setSize[x] = 0;
        --numSets;                                   // a union reduces numSets
    }

    void moveElement(int i, int j) {
        int x = p[i], y = p[j];
        sum[x] -= i;
        sum[y] += i;

        sets[x].erase(i);
        sets[y].insert(i);
        setSize[x]--;
        setSize[y]++;
 
        p[i] = p[j];

    }

    void printSet()
    {
        for (int i: p) {
            cout << p[i] << " {";
            for (auto j : sets[i])
                cout << j << ", ";
            cout << '}' << endl;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, commands, commandNo, p, q, cases = 0;
    
    while (cases < 20 && cin >> n >> commands) {
        UnionFind u = UnionFind(n + 1);
        for (int i = 0; i < commands; i++)
        {

            cin >> commandNo;
            if (commandNo == 1) {
                cin >> p >> q;
                u.unionSet(p, q);
            }
            else if (commandNo == 2) {
                cin >> p >> q;
                u.moveElement(p, q);
            }
            else if (commandNo == 3) {
                cin >> p;
                cout << u.sizeOfSet(p) << " " << u.sumOfSet(p) << endl;
            }
        }

        //u.printSet();
        cases++;
    }
}