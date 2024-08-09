#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int x) {
        value = x;
        next = nullptr;
    }
};

class Queue {
private:
    Node* head;

public:
    Queue() {
        head = nullptr;
    }

    void insert(int value) {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = node;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    int remove() {
        int value = 0;
        if (head != nullptr) {
            Node* temp = head;
            value = head->value;
            head = head->next;
            delete temp;
        }
        return value;
    }

    bool checkValue(int value) {
        Node* temp = head;

        if(temp == nullptr) {
            return false;
        }

        while (temp != nullptr && temp->value != value) {
            temp = temp->next;
        }
        
        if(temp == nullptr) {
            return false;
        }

        return temp->value == value;
    }

    void printQueue() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " -> ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~Queue() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Queue queue;

    queue.insert(10);
    queue.insert(20);
    queue.insert(30);
    queue.insert(40);
    
    std::cout << "check if number 20 is on queue? " << queue.checkValue(20) << std::endl;
    std::cout << "check if number 312 is on queue? " << queue.checkValue(312) << std::endl;

    std::cout << "queue after insertions: ";
    queue.printQueue();

    std::cout << queue.remove() << " was removed " << std::endl;
    
    std::cout << "queue after remove: ";
    queue.printQueue();

    std::cout << queue.remove() << " was removed " << std::endl;

    std::cout << "queue after remove: ";
    queue.printQueue();

    return 0;
}
