void inser(Node* v, Node* p) {
  v-> next = p->next;
  p->next = v;
}