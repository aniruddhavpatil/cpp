
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
    public:
    char c;
    vector<Node*> children;
    Node(){}
    Node(char c, vector<Node*> children) : c(c), children(children) {}
    
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node* root;
    
    Trie() {
        root = new Node(' ', {});
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++){
            bool found = false;
            for(auto& child : curr->children){
                if(child->c == word[i]){
                    curr = child;
                    found = true;
                    break;
                }
            }
            if(!found){
                Node* next = new Node(word[i], {});
                curr->children.push_back(next);
                curr = next;
            }
        }
        Node* last = new Node('#', {});
        curr->children.push_back(last);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++){
            bool found = false;
            for(auto& child : curr->children){
              if (child->c == word[i]) {
                    curr = child;
                    found = true;
                    break;
                }
            }
            if(!found) return false;
        }
        for(auto& child : curr->children){
            if(child->c == '#'){
                return true;
            }
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i = 0; i < prefix.size(); i++){
          bool found = false;

          for (auto &child : curr->children) {
                if (child->c == prefix[i]) {
                curr = child;
                found = true;
                break;
                }
            }
            if(!found) return false;
        }
        return true;
    }
};

ostream &operator<<(ostream &out, const Node *node) {
  out << node->c << " -> { ";
  for (auto child : node->children) {
    out << child->c << ' ';
  }
  out << "}\n";
  return out;
}

ostream &operator<<(ostream &out, const Trie *trie) {
  queue<Node *> q;
  q.push(trie->root);
  q.push(nullptr);
  while (!q.empty()) {
    Node *curr = q.front();
    q.pop();
    if (curr == nullptr) {
      out << endl;
      continue;
    }

    out << curr << endl;
    for (auto &child : curr->children) {
      q.push(child);
    }
    q.push(nullptr);
  }
  return out;
}

int main(){
    Trie* trie = new Trie();
    trie->insert("apple");
    // cout << trie;
    cout << trie->search("apple") << endl;
    cout << trie->startsWith("app") << endl;

    trie->insert("app");
    cout << trie;
}

