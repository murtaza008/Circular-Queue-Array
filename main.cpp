#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;      // Array to store queue elements
    int front;     // Points to the front element
    int rear;      // Points to the last element
    int maxSize;   // Maximum capacity of the queue
    int size;      // Current number of elements in the queue

public:
    // Constructor to initialize the queue
    CircularQueue(int capacity) {
        maxSize = capacity;
        arr = new int[maxSize];
        front = -1; // Indicates the queue is initially empty
        rear = -1;
        size = 0;
    }

    // Destructor to free memory
    ~CircularQueue() {
        delete[] arr;
    }

    // Enqueue operation: Add an element to the rear of the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }

        // If the queue is empty, set front and rear to 0
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSize; // Move rear circularly
        }

        arr[rear] = value;
        size++;
        cout << value << " enqueued to queue." << endl;
    }

    // Dequeue operation: Remove the front element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return -1; // Return a sentinel value
        }

        int dequeuedValue = arr[front];

        // If the queue has only one element, reset front and rear
        if (front == rear) {
            front = rear = -1; // Reset the queue to empty state
        } else {
            front = (front + 1) % maxSize; // Move front circularly
        }

        size--;
        return dequeuedValue;
    }

    // Peek operation: Get the front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! No element to peek." << endl;
            return -1; // Return a sentinel value
        }
        return arr[front];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if the queue is full
    bool isFull() {
        return (size == maxSize);
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = 0; i < size; i++) {
                cout << arr[(front + i) % maxSize] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int capacity;
    cout << "Enter the size of the circular queue: ";
    cin >> capacity;

    CircularQueue queue(capacity);

    return 0;
}
