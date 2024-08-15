#include <iostream>
#include <vector>
#include <math.h>

class Graph {
private:
    int vertex;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int vertex) {
        this->vertex = vertex;
        adjMatrix.resize(vertex, std::vector<int>(vertex, 0));
    }

    void initCompleteGraph() {
        for (int i = 0; i < vertex; i++) {
            for (int j = i + 1; j < vertex; j++) {
                addEdge(i, j);
            }
        }
    }

    void addEdge(int i, int j, int value = 1) {
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1;
    }

    int findSubgraphs() {
        int result = 0;
        for (int i = 1; i <= vertex; i++) {
            int x = pow(2, (i*(i-1)/2)) * (factorial(vertex)/(factorial(vertex-i)*factorial(i)));
            result += x;
            for(int j = 0; j < x; j++) {
                // criar todas as combinações possiveis com os subgrafos não-direcionado
                Graph subgraph(i);
            }
        }
        
        return result;
    }

    int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    void printMatrix() {
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int vertex;
    std::cout << "Digite o número de vértices do grafo: ";
    std::cin >> vertex;
    Graph g(vertex);

    g.initCompleteGraph();
    g.printMatrix();

    std::cout << g.findSubgraphs();

    return 0;
}
