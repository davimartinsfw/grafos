#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>

class Graph {
private:
    std::map<char, std::set<char>> adjList; // Lista de adjacência
    std::vector<char> vertices;

public:
    Graph(int vertexCount, char startLetter = 'a', int sum = 1) {
        char vertex = startLetter;
        for (int i = sum, count = 0; count < vertexCount; i++, count++) {
            vertices.push_back(vertex);
            adjList[vertex] = std::set<char>();
            vertex += sum == 1 ? 1 : i;
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
        for (char v : vertices)
        {
            std::cout << v << " ";
        }
        std::cout << "}" << std::endl;

        std::cout << "Arestas: { ";
        for (const auto &pair : adjList) {
            for (char neighbor : pair.second) {
                if (pair.first < neighbor) { // Evita duplicação de arestas
                    std::cout << "{" << pair.first << "," << neighbor << "} ";
                }
            }
        }
        std::cout << "}" << std::endl;
    }

    int findSubgraphs() {
        int result = 0;
        int vertexCount = vertices.size();
        for (int i = 1; i <= vertexCount; i++) {
            int combination = (factorial(vertexCount) / (factorial(vertexCount - i) * factorial(i)));
            int x = pow(2, (i * (i - 1) / 2)) * combination;
            result += x;
            char letter = 'a';
            int sum = 1;
            int p = 1;
            for (int j = 0; j < x; j++) {
                if(j == 0) letter = 'a';
                // criar todas as combinações possiveis com os subgrafos não-direcionado
                // 4 x 1 | 6 x 2 | 8 x 4 | 64 x 1
                if (i == 1) {
                    Graph subgraph(i, letter);
                    subgraph.printGraph();
                    letter+=1;
                } else if(i == 2) {
                    if(combination==j) {
                        letter += 1;
                        sum = 1;
                    } else if(j == (combination+vertexCount)) {
                        letter += 1;
                        sum = 1;
                    }
                    if(j % 2 == 0) {
                        if(pow(2, p) == j) {
                            sum++;
                            p++;
                        }
                        Graph subgraph(i, letter, sum);
                        subgraph.initCompleteGraph();
                        subgraph.printGraph();
                    } else {
                        Graph subgraph(i, letter, sum);
                        subgraph.printGraph();
                    }
                } else if (i == 3) {

                }
            }
        }
        return result;
    }

    Graph generateSubgraph() {

    }

    int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }
};

int main() {
    int numVertices;
    std::cout << "Digite o número de vértices do grafo: ";
    std::cin >> numVertices;

    Graph g(numVertices);

    g.initCompleteGraph();
    g.printGraph();
    int subgraphs =  g.findSubgraphs();
    std::cout << "Número de subgrafos: " << subgraphs << std::endl;

    return 0;
}
