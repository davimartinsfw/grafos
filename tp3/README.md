# Algoritmos de Grafos

Este projeto implementa três algoritmos de grafos: Dijkstra, MaxMin e MinMax.

## Requisitos

- Compilador C++ que suporte C++11 ou superior
- Sistema operacional compatível (Linux, macOS, Windows com WSL)

## Compilação

Para compilar o programa, execute o seguinte comando no terminal:

```
g++ -std=c++11 -o main index.cpp graph.cpp dijkstra.cpp MinMax.cpp
```


## Execução

Após a compilação, você pode executar o programa usando um dos seguintes comandos:

- Para o algoritmo de Dijkstra:
  ```
  ./graph_algorithm dijkstra
  ```

- Para o algoritmo MaxMin:
  ```
  ./graph_algorithm maxmin
  ```

- Para o algoritmo MinMax:
  ```
  ./graph_algorithm minmax
  ```

## Modificando o Grafo

Para modificar o grafo, siga estas instruções no arquivo `index.cpp`:

1. Altere o número de vértices:
   ```cpp
   for (int i = 0; i < NUM_VERTICES; ++i)
   {
       g.addVertex();
   }
   ```
   Substitua `NUM_VERTICES` pelo número desejado de vértices.

2. Adicione ou modifique as arestas:
   ```cpp
   g.addEdge(origem, destino, peso);
   ```
   - `origem`: vértice de origem (0 a NUM_VERTICES-1)
   - `destino`: vértice de destino (0 a NUM_VERTICES-1)
   - `peso`: peso da aresta (deve ser positivo)

Restrições:
- O grafo deve ser conexo (todos os vértices devem ser alcançáveis)
- As arestas devem ter pesos positivos
- O grafo é direcionado (as arestas têm uma direção específica)

Exemplo de adição de uma nova aresta:

g.addEdge(2, 5, 7); // Adiciona uma aresta do vértice 2 ao vértice 5 com peso 7


Após modificar o grafo, recompile o programa usando o comando de compilação fornecido acima.

## Observações

- Certifique-se de que o grafo permaneça conexo após as modificações
- Todos os pesos das arestas devem ser positivos
- Lembre-se de que o grafo é direcionado, então `g.addEdge(a, b, w)` adiciona uma aresta de `a` para `b`, mas não de `b` para `a`
