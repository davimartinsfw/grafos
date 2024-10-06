#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
#include "graph.hpp"  // Assuming you have a graph.hpp file

// Function declarations
std::vector<int> dijkstra(Graph& g, int start, int end);

void dijkstraVisitWrapper(Edge* edge, void* data);

void dijkstraVisit(std::vector<int>& dist, std::vector<int>& prev, 
                   std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>& pq, 
                   int u, Edge* edge);

// Constant declaration
extern const int INF;

#endif // DIJKSTRA_HPP