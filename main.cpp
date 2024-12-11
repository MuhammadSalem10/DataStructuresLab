#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int _data) {
        data = _data;
        next = prev = NULL;
    }
};


class LinkedList {

public:
    Node* head;
    Node* tail;
    int counter;
    LinkedList(int value) {
          head = tail = new Node(value);
          counter = 1;
    }

    void InsertAfter(int data, int afterData) {
        Node* node = new Node(data);

        Node* current = head;
        while(current != NULL) {
            if(current->data == afterData) {
                node->next = current->next;
                current->next = node;
                counter++;
                break;
            }
            current = current->next;
        }
    }

    void InsertBefore(int data, int beforeData) {
        Node* node = new Node(data);

        Node* prev = head;
        Node* current = head->next;

        while(current != NULL) {
            if(current->data == beforeData) {
                prev->next = node;
                node->next = current;
                counter++;
                break;
            }

            current = current->next;
        }
    }

    int GetCount() {
        return counter;
    }

    int GetDataByIndex(int index) {

        Node* current = head;
        int i = 0;
        while(current != NULL && i < index) {
            current = current->next;
            i++;
        }

        if (current != NULL) {
            return current->data;
        } else {
             throw runtime_error("Not Found!");
        }
    }


    void Display() {
        Node* current = head;
        while(current != NULL) {
            cout << current->data << "\t";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList* l = new LinkedList(3);

    l->InsertAfter(5, 3);
    l->InsertAfter(17, 5);
    l->InsertAfter(18, 17);
    l->InsertAfter(4, 18);

    l->InsertBefore(9, 5);


    l->Display();

    cout << "The element at index: " << 1 << " is " << l->GetDataByIndex(17) << "\n";

    cout << "The number of elements: " << l->GetCount() << "\n";

    return 0;
}
