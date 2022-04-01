#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;

int qu[MAX];
int tail = 0, head = 0;

void init() {
  head = tail = 0;
}

bool isEmpty() {
  return (head == tail);
}

bool isFull() {
  return (head == (tail + 1) % MAX);
}

void enqueue(int x) {
  if (isFull()) {
    cout << "error: 큐가 꽉참." << "\n";
    return;
  }
  qu[tail] = x;
  ++tail;
  if (tail == MAX) tail = 0;
}

int dequeue() {
  if (isEmpty()) {
    cout << "error: 큐가 비어 있음." << "\n";
    return -1;
  }
  int res = qu[head];
  ++head;
  if (head == MAX) head = 0;
  return res;
}