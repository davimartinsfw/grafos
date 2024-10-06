#include "graph.hpp"
#include <queue>
#include <climits>

const int INF = INT_MAX;

struct Compare {
    bool operator()(std::pair<int, int>& a, std::pair<int, int>& b) {
        return a.second > b.second;
    }
};

int dijkstraMinMax(Graph& g, int origem, int destino) {
    int n = g.getVertexCount();
    std::vector<int> dist(n, INF);
    dist[origem] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;
    pq.push({origem, 0});

    while (!pq.empty()) {
        int u = pq.top().first;
        int maxWeight = pq.top().second;
        pq.pop();

        if (u == destino) return maxWeight;

        g.findVertex(u)->forEachEdge([&](Edge* edge) {
            int v = edge->destination->value;
            int weight = edge->weight;
            int newMax = std::max(maxWeight, weight);

            if (newMax < dist[v]) {
                dist[v] = newMax;
                pq.push({v, newMax});
            }
        });
    }

    return -1;
}
