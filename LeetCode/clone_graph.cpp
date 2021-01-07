class Solution {
public:
  unordered_map<Node *, Node *> mapping;
  Node *cloneGraph(Node *node) {
    if (!node)
      return NULL;
    Node *new_node = new Node(node->val);
    mapping[node] = new_node;
    queue<Node *> fringe;
    fringe.push(node);
    while (!fringe.empty()) {
      Node *curr = fringe.front();
      fringe.pop();
      for (auto neighbor : curr->neighbors) {
        if (mapping.find(neighbor) == mapping.end()) {
          fringe.push(neighbor);
          mapping[neighbor] = new Node(neighbor->val);
        }
        mapping[curr]->neighbors.push_back(mapping[neighbor]);
      }
    }
    return new_node;
  }
};