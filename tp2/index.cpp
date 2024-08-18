#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>

class Graph {
private:
    std::map<char, std::set<char> > adjList;
    std::vector<char> vertices;

public:
    Graph(int vertexCount, char startLetter = 'a') {
        char vertex = startLetter;
        for (int i = 0; i < vertexCount; i++) {
            vertices.push_back(vertex);
            adjList[vertex] = std::set<char>();
            vertex++;
        }
    }

    void addEdge(char u, char v) {
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    void initCompleteGraph() {
        int size = vertices.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                addEdge(vertices[i], vertices[j]);
            }
        }
    }

    void printGraph() const {
        std::cout << "Vértices: { ";
        for (char v : vertices) {
            std::cout << v << " ";
        }
        std::cout << "}" << std::endl;

        std::cout << "Arestas: { ";
        for (const auto &pair : adjList) {
            for (char neighbor : pair.second) {
                if (pair.first < neighbor) {
                    std::cout << "{" << pair.first << "," << neighbor << "} ";
                }
            }
        }
        std::cout << "}" << std::endl;
    }

    void generateSubgraphs(int k) {
        std::vector<std::vector<char> > combinations;
        std::vector<char> currentCombination;
        generateCombinations(vertices, currentCombination, 0, k, combinations);

        std::cout << "\nSubgrafos com " << k << " vértices:\n";
        for (const auto& combination : combinations) {
            Graph subgraph(k, combination[0]);
            for (char v : combination) {
                subgraph.addVertex(v);
            }
            subgraph.initCompleteGraph();
            subgraph.printGraph();
        }
    }

    int findSubgraphs() {
        int totalSubgraphs = 0;
        for (int i = 1; i <= vertices.size(); i++) {
            generateSubgraphs(i);
            totalSubgraphs += combination(vertices.size(), i);
        }
        return totalSubgraphs;
    }

    // Função para gerar combinações de vértices
    void generateCombinations(const std::vector<char>& vertices, std::vector<char>& currentCombination,
                              int start, int k, std::vector<std::vector<char> >& result) {
        if (currentCombination.size() == k) {
            result.push_back(currentCombination);
            return;
        }

        for (int i = start; i < vertices.size(); i++) {
            currentCombination.push_back(vertices[i]);
            generateCombinations(vertices, currentCombination, i + 1, k, result);
            currentCombination.pop_back();
        }
    }

    // Função para adicionar vértices ao subgrafo
    void addVertex(char v) {
        if (adjList.find(v) == adjList.end()) {
            adjList[v] = std::set<char>();
        }
    }

    // Função para calcular combinações matemáticas (nCr)
    int combination(int n, int r) {
        if (r == 0 || r == n) return 1;
        return combination(n - 1, r - 1) + combination(n - 1, r);
    }
};

int main() {
    int numVertices;
    std::cout << "Digite o número de vértices do grafo: ";
    std::cin >> numVertices;

    Graph g(numVertices);
    g.initCompleteGraph();
    g.printGraph();
    
    int totalSubgraphs = g.findSubgraphs();
    std::cout << "Número total de subgrafos: " << totalSubgraphs << std::endl;

    return 0;
}
