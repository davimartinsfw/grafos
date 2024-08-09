#include <iostream>

class Node {
public:
    int value;
    Node* previous;

    Node(int x) {
        value = x;
        previous = nullptr;
    }
};

class Stack {
private:
    Node* head;

public:
    Stack() {
        head = nullptr;
    }


    void insert(int value) {
        Node* node = new Node(value);
        node->previous = head;
        head = node;
    }

    int remove() {
        int value = 0;
        if (head == nullptr) return 0;

        if (head->previous == nullptr) {
            value = head->value;
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            head = head->previous;
            value = temp->value;
            delete temp;
            temp = nullptr;
        }
        return value;
    }

    bool checkValue(int value) {
        Node* temp = head;

        if(temp == nullptr) {
            return false;
        }

        while (temp != nullptr && temp->value != value) {
            temp = temp->previous;
        }
        
        if(temp == nullptr) {
            return false;
        }

        return temp->value == value;
    }

    void printStack() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " -> ";
            temp = temp->previous;
        }
        std::cout << std::endl;
    }

    ~Stack() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->previous;
            delete temp;
        }
    }
};

int main() {
    Stack stack;

    stack.insert(10);
    stack.insert(20);
    stack.insert(30);
    stack.insert(40);
    
    std::cout << "check if number 20 is on stack? " << stack.checkValue(20) << std::endl;
    std::cout << "check if number 312 is on stack? " << stack.checkValue(312) << std::endl;

    std::cout << "stack after insertions: ";
    stack.printStack();

    std::cout << stack.remove() << " was removed " << std::endl;
    
    std::cout << "stack after remove: ";
    stack.printStack();

    std::cout << stack.remove() << " was removed " << std::endl;

    std::cout << "stack after remove: ";
    stack.printStack();

    return 0;
}
