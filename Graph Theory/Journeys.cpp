// https://www.hackerrank.com/challenges/journey-to-the-moon/problem
// Jordan Tonni
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


class DisjointSet
{
public:
    vector<int> arr;
    vector<int> rank;

    int root(const int u);
    explicit DisjointSet(const int n);
    void makeUnion(const int u, const int v);
    bool find(const int u, const int v);
    ~DisjointSet();
};


DisjointSet::DisjointSet(const int n)
{
    arr = vector<int>(n);
    rank = vector<int>(n, 1);
    for(int i = 0; i < n; ++i){
        arr[i] = i;
    }
}

DisjointSet::~DisjointSet()
{}

int DisjointSet::root(int u)
{
    while(arr[u] != u){
        arr[u] = arr[arr[u]];
        u = arr[u];
    }
    return u;
}

bool DisjointSet::find(const int u, const int v)
{
    return (root(u) == root(v));
}

void DisjointSet::makeUnion(const int u, const int v)
{
    int rootU = root(u);
    int rootV = root(v);

    if(rootU == rootV)
        return;

    int rankU = rank[rootU];
    int rankV = rank[rootV];

    if(rankU >= rankV){
        arr[rootV] = arr[rootU];
        rank[rootU] += rank[rootV];
    }
    else{
        arr[rootU] = arr[rootV];
        rank[rootV] += rank[rootU];
    }
}




DisjointSet makeGraph()
{
    int n,k;
    cin >> n >> k;
    DisjointSet graph { n };

    while(k--){
        int u,v;
        cin >> u >> v;
        graph.makeUnion(u, v);
    }
    return graph;
}

int main()
{
    DisjointSet graph = makeGraph();

    unordered_set<int> seen;
    vector<long> connSizes;

    for(int i = 0; i < graph.arr.size(); ++i){
        int p = graph.root(graph.arr[i]);

        if(seen.find(p) == end(seen)){
            seen.insert(p);
            connSizes.push_back(graph.rank[p]);
        }
    }

    vector<long long> results;
    long long sum { 0 };
    long long res { 0 };

    for(const auto size : connSizes){
        res += sum * size;
        sum += size;

    }

    cout << res << endl;

    return 0;
}


