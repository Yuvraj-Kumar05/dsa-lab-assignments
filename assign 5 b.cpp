#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

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

int countAndDelete(int key) {
    int count = 0;
    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* temp = head;
    while (temp && temp->next) {
        if (temp->next->data == key) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            count++;
        } else temp = temp->next;
    }
    return count;
}

void display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, val, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEnd(val);
    }
    cin >> key;
    int count = countAndDelete(key);
    cout << "Count: " << count << " , Updated Linked List: ";
    display();
}
