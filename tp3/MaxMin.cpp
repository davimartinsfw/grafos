#include "graph.hpp"
#include <queue>
#include <climits>

const int INF = INT_MIN;

struct Compare {
    bool operator()(std::pair<int, int>& a, std::pair<int, int>& b) {
        return a.second < b.second;
    }
};

int dijkstraMaxMin(Graph& g, int origem, int destino) {
    int n = g.getVertexCount();
    std::vector<int> dist(n, INF);
    dist[origem] = INT_MAX;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;
    pq.push({origem, INT_MAX});

    while (!pq.empty()) {
        int u = pq.top().first;
        int minWeight = pq.top().second;
        pq.pop();

        if (u == destino) return minWeight;

        g.findVertex(u)->forEachEdge([&](Edge* edge) {
            int v = edge->destination->value;
            int weight = edge->weight;
            int newMin = std::min(minWeight, weight);

            if (newMin > dist[v]) {
                dist[v] = newMin;
                pq.push({v, newMin});
            }
        });
    }

    return -1;
}
