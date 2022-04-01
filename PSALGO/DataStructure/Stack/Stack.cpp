#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;

int st[MAX];
int top = 0;

void init() {
  top = 0;
}

bool isEmpty() {
  return (top == 0);
}

bool isFull() {
  return (top == MAX);
}

void push(int x) {
  if (isFull()) {
    cout << "error: 스택 풀" << "\n";
  }
  st[top] = x;
  ++top;
}

int pop() {
  if (isEmpty()) {
    cout << "error: 스택 비어있음." << "\n";
  }
  --top;
  return st[top];
}