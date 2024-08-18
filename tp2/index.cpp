#include <iostream>
#include <vector>
#include <cmath>
#include <utility>  // Para std::pair

// Função para calcular o fatorial de um número
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Função para calcular a combinação C(n, r)
int combination(int n, int r) {
    if (r == 0 || r == n) return 1;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Função auxiliar para gerar combinações
void generateCombinations(const std::vector<int>& vertices, std::vector<int>& currentCombination,
                          int start, int k, std::vector<std::vector<int> >& result) {
    if (currentCombination.size() == static_cast<size_t>(k)) {
        result.push_back(currentCombination);
        return;
    }

    for (int i = start; i < static_cast<int>(vertices.size()); ++i) {
        currentCombination.push_back(vertices[i]);
        generateCombinations(vertices, currentCombination, i + 1, k, result);
        currentCombination.pop_back();
    }
}

// Função auxiliar para gerar subgrafos a partir de um conjunto de vértices
void generateSubgraphEdges(const std::vector<int>& combination, std::vector<std::pair<int, int> >& currentEdges,
                           int start, std::vector<std::vector<std::pair<int, int> > >& result) {
    result.push_back(currentEdges);  // Adicionar o subgrafo sem novas arestas

    for (int i = start; i < static_cast<int>(combination.size()); ++i) {
        for (int j = i + 1; j < static_cast<int>(combination.size()); ++j) {
            currentEdges.push_back(std::make_pair(combination[i], combination[j]));
            generateSubgraphEdges(combination, currentEdges, i + 1, result);
            currentEdges.pop_back();
        }
    }
}

int main() {
    int n;
    std::cout << "Digite o número de vértices: ";
    std::cin >> n;

    std::vector<int> vertices;
    for (int i = 0; i < n; ++i) {
        vertices.push_back(i);
    }

    int totalSubgraphs = 0;

    // Realizar o somatório da fórmula e gerar subgrafos
    for (int i = 1; i <= n; ++i) {
        int comb = combination(n, i);  // C(n, i)
        int power = static_cast<int>(pow(2, (i * (i - 1)) / 2));  // 2^(i * (i-1) / 2)
        totalSubgraphs += comb * power;

        // Gerar todas as combinações de vértices para subgrafos com i vértices
        std::vector<std::vector<int> > combinations;
        std::vector<int> currentCombination;
        generateCombinations(vertices, currentCombination, 0, i, combinations);

        // Para cada combinação de vértices, gerar todas as combinações de arestas
        std::cout << "\nSubgrafos com " << i << " vértices:\n";
        for (std::vector<std::vector<int> >::const_iterator it = combinations.begin(); it != combinations.end(); ++it) {
            const std::vector<int>& combination = *it;
            std::vector<std::vector<std::pair<int, int> > > subgraphs;
            std::vector<std::pair<int, int> > currentEdges;
            generateSubgraphEdges(combination, currentEdges, 0, subgraphs);

            for (std::vector<std::vector<std::pair<int, int> > >::const_iterator jt = subgraphs.begin(); jt != subgraphs.end(); ++jt) {
                const std::vector<std::pair<int, int> >& subgraph = *jt;
                std::cout << "Vértices: { ";
                for (std::vector<int>::const_iterator vit = combination.begin(); vit != combination.end(); ++vit) {
                    std::cout << *vit << " ";
                }
                std::cout << "} Arestas: { ";
                for (std::vector<std::pair<int, int> >::const_iterator eit = subgraph.begin(); eit != subgraph.end(); ++eit) {
                    const std::pair<int, int>& edge = *eit;
                    std::cout << "{" << edge.first << "," << edge.second << "} ";
                }
                std::cout << "}\n";
            }
        }
    }

    std::cout << "\nNúmero total de subgrafos: " << totalSubgraphs << std::endl;

    return 0;
}
