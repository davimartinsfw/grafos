#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>
#include <functional>

class Vertex;

class Edge {
public:
    Vertex* destination;
    int weight;
    Edge(Vertex* dest, int w) : destination(dest), weight(w) {}
};

class Vertex {
public:
    int value;
    std::vector<Edge*> edges;
    bool visited;

    Vertex(int v) : value(v), visited(false) {}

    void addEdge(Vertex* v, int weight) {
        edges.push_back(new Edge(v, weight));
    }

    void removeEdge(Vertex* v) {
        edges.erase(std::remove_if(edges.begin(), edges.end(),
            [v](Edge* edge) { return edge->destination == v; }),
            edges.end());
    }

    void dfs() {
        std::cout << "Vertex " << value << " ";
        visited = true;
        for (Edge* edge : edges) {
            if (!edge->destination->visited) {
                edge->destination->dfs();
            }
        }
    }

    void printEdges() {
        std::cout << "Vertex " << value << " is connected to: ";
        for (Edge* edge : edges) {
            std::cout << edge->destination->value << "(w:" << edge->weight << ") -> ";
        }
        std::cout << "nullptr" << std::endl;
    }

    void forEachEdge(const std::function<void(Edge*)>& func) {
        for (Edge* edge : edges) {
            func(edge);
        }
    }
};

class Graph {
private:
    std::vector<Vertex*> vertices;

public:
    void addVertex() {
        vertices.push_back(new Vertex(vertices.size()));
    }

    Vertex* findVertex(int value) {
        for (Vertex* v : vertices) {
            if (v->value == value) return v;
        }
        return nullptr;
    }

    void addEdge(int v1, int v2, int weight) {
        Vertex* vertex1 = findVertex(v1);
        Vertex* vertex2 = findVertex(v2);
        if (vertex1 && vertex2) {
            vertex1->addEdge(vertex2, weight);
            vertex2->addEdge(vertex1, weight);
        }
    }

    void dfs() {
        for (Vertex* v : vertices) {
            if (!v->visited) v->dfs();
        }
    }

    void bfs() {
        if (vertices.empty()) return;
        std::queue<Vertex*> q;
        vertices[0]->visited = true;
        q.push(vertices[0]);

        while (!q.empty()) {
            Vertex* current = q.front();
            q.pop();
            std::cout << "Vertex " << current->value << " ";

            for (Edge* edge : current->edges) {
                Vertex* neighbor = edge->destination;
                if (!neighbor->visited) {
                    neighbor->visited = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void printGraph() {
        for (Vertex* v : vertices) {
            v->printEdges();
        }
    }

    void resetVisited() {
        for (Vertex* v : vertices) {
            v->visited = false;
        }
    }

    int getVertexCount() const {
        return vertices.size();
    }

    ~Graph() {
        for (Vertex* v : vertices) {
            for (Edge* e : v->edges) {
                delete e;
            }
            delete v;
        }
    }
};

#endif // GRAPH_HPP