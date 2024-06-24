#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }
    void enqueue(int value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = nullptr;
        if (rear == nullptr) {
            front = rear = temp;
            cout << "Customer " << value << " arrives (enqueue): Added ticket number " << value << endl;
            return;
        }
        rear->next = temp;
        rear = temp;
        cout << "Customer " << value << " arrives (enqueue): Added ticket number " << value << endl;
    }
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty, no customers to serve." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        cout << "Now serving ticket number " << temp->data << endl;
        delete temp;
    }
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void display() {
        if (front == nullptr) {
            cout << "Queue status: []" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue status: [";
        while (temp != nullptr) {
            cout << temp->data;
            temp = temp->next;
            if (temp != nullptr) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};
int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();

    return 0;
}