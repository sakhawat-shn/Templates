#include<bits/stdc++.h>
using namespace std;

///----start--------its from cp-algorithms
/* The adjacency matrix adj[][] of size n×n stores the weights of the edges, 
 * and it uses the weight INF if there doesn't exist an edge between two 
 * vertices. The algorithm uses two arrays: the flag selected[], which 
 * indicates which vertices we already have selected, and the array min_e[]
 * which stores the edge with minimal weight to an selected vertex for each 
 * not-yet-selected vertex (it stores the weight and the end vertex). The algorithm 
 * does n steps, in each iteration the vertex with the smallest edge weight
 * is selected, and the min_e[] of all other vertices gets updated.
*/

int n;
vector<vector<int>> adj; // adjacency matrix of graph
const int INF = 1000000000; // weight INF means there is no edge

struct Edge {
    int w = INF, to = -1;
};

void prim() {
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            exit(0);
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }

    cout << total_weight << endl;
}
///--------------end----------

int main()
{


    return 0;
}
