#include <iostream>
#include <queue>

struct node
{
  std::string position;
  node *first;
  node *second;
};

struct org_tree
{
  node *root;

  static org_tree create_org_structure(const std::string &pos)
  {
    org_tree tree;
    tree.root = new node{pos, NULL, NULL};
    return tree;
  }

  static node *find(node *root, const std::string &value)
  {
    if (root == NULL)
      return NULL;

    if (root->position == value)
      return root;

    auto firstFound = org_tree::find(root->first, value);

    if (firstFound != NULL)
      return firstFound;

    return org_tree::find(root->second, value);
  }
};