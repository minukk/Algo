// 자기 참조 구조체
struct Node {
  Node* next;
  string name;

  Node(string name_ ="") : next(NULL), name(name_) {}
}