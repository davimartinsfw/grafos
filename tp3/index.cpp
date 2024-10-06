#include <iostream>
#include "graph.hpp"
#include "dijkstra.hpp"

// Include the function declarations
int dijkstraMaxMin(Graph& g, int origem, int destino);
int dijkstraMinMax(Graph& g, int origem, int destino);

int main(int argc, char* argv[])
{
    Graph g;

    // Add vertices
    for (int i = 0; i < 6; ++i)
    {
        g.addVertex();
    }

    // Add edges (directed)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 3);

    std::cout << "Estrutura do grafo:\n";
    g.printGraph();

    int start = 0;
    int end = 5;

    if (argc < 2) {
        std::cout << "Por favor, especifique um algoritmo: dijkstra, maxmin ou minmax\n";
        return 1;
    }

    std::string algorithm = argv[1];

    if (algorithm == "dijkstra") {
        std::cout << "\nEncontrando o caminho mais curto do vértice " << start << " ao vértice " << end << ":\n";
        std::vector<int> shortestPath = dijkstra(g, start, end);
        std::cout << "Caminho mais curto: ";
        for (size_t i = 0; i < shortestPath.size(); ++i) {
            std::cout << shortestPath[i];
            if (i < shortestPath.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    } else if (algorithm == "maxmin") {
        int result = dijkstraMaxMin(g, start, end);
        if (result == -1)
            std::cout << "Não há caminho entre " << start << " e " << end << std::endl;
        else
            std::cout << "O valor máximo mínimo no caminho de " << start << " a " << end << " é: " << result << std::endl;
    } else if (algorithm == "minmax") {
        int result = dijkstraMinMax(g, start, end);
        if (result == -1)
            std::cout << "Não há caminho entre " << start << " e " << end << std::endl;
        else
            std::cout << "O peso máximo mínimo no caminho de " << start << " a " << end << " é: " << result << std::endl;
    } else {
        std::cout << "Algoritmo desconhecido. Por favor, especifique dijkstra, maxmin ou minmax.\n";
        return 1;
    }

    return 0;
}