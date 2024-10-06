#include <vector>
#include <queue>
#include <limits>
#include <functional>
#include <tuple>
#include <algorithm>
#include "graph.hpp"
#include "dijkstra.hpp"

const int INF = std::numeric_limits<int>::max();

void dijkstraVisit(std::vector<int>& dist, std::vector<int>& prev, 
                   std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>& pq, 
                   int u, Edge* edge);

void dijkstraVisitWrapper(Edge* edge, void* data)
{
    auto* params = static_cast<std::tuple<std::vector<int>*, std::vector<int>*, 
                   std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>*, int>*>(data);
    dijkstraVisit(*std::get<0>(*params), *std::get<1>(*params), *std::get<2>(*params), std::get<3>(*params), edge);
}

std::vector<int> dijkstra(Graph& g, int start, int end) {
    int n = g.getVertexCount();
    std::vector<int> dist(n, INF);
    std::vector<int> prev(n, -1);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[start] = 0;
    pq.push(std::make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        Vertex* vertex = g.findVertex(u);
        auto params = std::make_tuple(&dist, &prev, &pq, u);
        vertex->forEachEdge(std::bind(dijkstraVisitWrapper, std::placeholders::_1, &params));
    }

    std::vector<int> path;
    for (int v = end; v != -1; v = prev[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());

    return path;
}

void dijkstraVisit(std::vector<int>& dist, std::vector<int>& prev, 
                   std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>& pq, 
                   int u, Edge* edge) {
    int v = edge->destination->value;
    int weight = edge->weight;

    if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        prev[v] = u;
        pq.push(std::make_pair(dist[v], v));
    }
}