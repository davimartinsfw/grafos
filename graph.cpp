#include <iostream>
#include <functional>

template <typename T>
class Node {
public:
    T value;
    Node* next;

    Node(T x) {
        value = x;
        next = nullptr;
    }
};

template <typename T>
class List {
private:
    Node<T>* head;

public:
    int length;

    List() {
        head = nullptr;
        length = 0;
    }

    void insert(T value) {
        Node<T>* node = new Node<T>(value);
        if (head == nullptr) {
            head = node;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = node;
        }
        length++;
    }

    T removeValue(T value) {
        Node<T>* temp = head;
        Node<T>* prev = nullptr;

        if (temp == nullptr) {
            return T();
        }

        if (temp->value == value) {
            head = temp->next;
            delete temp;
            length--;
            return value;
        }

        while (temp != nullptr && temp->value != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            return T();
        }

        prev->next = temp->next;
        delete temp;

        length--;

        return value;
    }

    bool checkValue(T value) {
        Node<T>* temp = head;

        if (temp == nullptr) {
            return false;
        }

        while (temp != nullptr && temp->value != value) {
            temp = temp->next;
        }

        return temp != nullptr;
    }

    void forEach(std::function<void(T)> func) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            func(temp->value);
            temp = temp->next;
        }
    }

    void printList() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value->value << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    Node<T>* getHead() {
        return head;
    }

    ~List() {
        Node<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class Vertex {
public:
    int value;
    List<Vertex*> edges;
    bool visited;

    Vertex(int v) : value(v) {}

    void addEdge(Vertex* v) {
        edges.insert(v);
    }

    void removeEdge(Vertex* v) {
        edges.removeValue(v);
    }

    void dfs() {
        std::cout << "Vertex " << value << " ";
        visited = true;
        // chamar forEach da lista
        edges.forEach([this](Vertex* neighbor) {
            if (!neighbor->visited) {
                neighbor->dfs();
            }
        });
    }

    void printEdges() {
        std::cout << "Vertex " << value << " is connected to: ";
        edges.printList();
    }
};

class Graph {
private:
    List<Vertex*> vertex;

public:
    Graph() {}

    void addVertex() {
        Vertex* v = new Vertex(vertex.length);
        vertex.insert(v);
    }

    Vertex* findVertex(int value) {
        Node<Vertex*>* temp = vertex.getHead();
        while (temp != nullptr) {
            Vertex* v = temp->value;
            if (v->value == value) {
                return v;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void addEdge(int v1, int v2) {
        Vertex* vertex1 = findVertex(v1);
        Vertex* vertex2 = findVertex(v2);
        if (vertex1 && vertex2) {
            vertex1->addEdge(vertex2);
            vertex2->addEdge(vertex1);
        }
    }

    void dfs() {
        vertex.forEach([](Vertex* v) {
            if (!v->visited) {
                v->dfs();
            }
        });
    }

    void printGraph() {
        Node<Vertex*>* temp = vertex.getHead();
        while (temp != nullptr) {
            Vertex* v = temp->value;
            v->printEdges();
            temp = temp->next;
        }
    }

    ~Graph() {
        Node<Vertex*>* temp = vertex.getHead();
        while (temp != nullptr) {
            Vertex* v = temp->value;
            delete v;
            temp = temp->next;
        }
    }
};

int main() {
    Graph g;

    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);

    g.printGraph();

    g.dfs();

    return 0;
}
