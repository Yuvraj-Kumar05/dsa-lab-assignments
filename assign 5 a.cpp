#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insertBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void insertBefore(int key, int val) {
    if (!head) return;
    if (head->data == key) {
        insertBeginning(val);
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != key) temp = temp->next;
    if (temp->next) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAfter(int key, int val) {
    Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (temp) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteBeginning() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteSpecific(int key) {
    if (!head) return;
    if (head->data == key) {
        deleteBeginning();
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != key) temp = temp->next;
    if (temp->next) {
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }
}

void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found" << endl;
}

void display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, val, key;
    while (true) {
        cout << "\n1.Insert Beginning\n2.Insert End\n3.Insert Before\n4.Insert After\n5.Delete Beginning\n6.Delete End\n7.Delete Specific\n8.Search\n9.Display\n10.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; insertBeginning(val); break;
            case 2: cin >> val; insertEnd(val); break;
            case 3: cin >> key >> val; insertBefore(key, val); break;
            case 4: cin >> key >> val; insertAfter(key, val); break;
            case 5: deleteBeginning(); break;
            case 6: deleteEnd(); break;
            case 7: cin >> key; deleteSpecific(key); break;
            case 8: cin >> key; searchNode(key); break;
            case 9: display(); break;
            case 10: return 0;
        }
    }
}
