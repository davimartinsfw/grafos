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

class List {
private:
    Node* head;

public:
    List() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
    }

    void insertAtEnd(int value) {
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

    int removeFromBeginning() {
        int value = 0;
        if (head != nullptr) {
            Node* temp = head;
            value = head->value;
            head = head->next;
            delete temp;
        }
        return value;
    }

    int removeFromEnd() {
        int value = 0;
        if (head == nullptr) return 0;

        if (head->next == nullptr) {
            value = head->value;
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            value = temp->value;
            delete temp->next;
            temp->next = nullptr;
        }
        return value;
    }

    int removeValue(int value) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp == nullptr) {
            return 0;
        }

        if (temp->value == value) {
            head = temp->next;
            delete temp;
            return value;
        }

        while (temp != nullptr && temp->value != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            return 0;
        }

        prev->next = temp->next;
        delete temp;

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

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " -> ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~List() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    List list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    
    std::cout << "check if number 20 is on list? " << list.checkValue(20) << std::endl;
    std::cout << "check if number 312 is on list? " << list.checkValue(312) << std::endl;

    std::cout << "list after insertions: ";
    list.printList();

    list.removeFromBeginning();
    std::cout << "list after remove from beginnig: ";
    list.printList();

    list.removeFromEnd();
    std::cout << "list after remove from end: ";
    list.printList();

    return 0;
}
