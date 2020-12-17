#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
#define obj vector<int>

struct Object{
    int l;
    int w;
    int h;
};

bool operator < (const Object a, const Object b) {
  return a.l < b.l || a.w < b.w || a.h < b.h;
}

ostream& operator << (ostream& os, const Object o){
    os << "[" << o.l << ", " << o.w << ", "<< o.h << "]";
    return os;
}

void objectComparison(vector<Object>& objectVector){
    priority_queue<Object> pq;
    for(auto o : objectVector){
        pq.push(o);
        // cout<<o<<'\n';
    }
    while (!pq.empty()) {
      Object curr = pq.top();
      pq.pop();
      cout<< curr;
      cout << '\n';
    }
    return;
}

void vectorComparison(vector<obj> objectVector){
    priority_queue<obj> pq;
    for(auto o : objectVector){
        pq.push(o);
    }

    while(!pq.empty()){
        obj curr = pq.top();
        pq.pop();
        for(auto val : curr){
            cout << val << ", ";
        }
        cout<<'\n';
    }
    return;
}

int main(){
  vector<Object> objectVector = {
      {1, 1, 2},
      {1, 1, 1},
      {1, 1, 3},
      {1, 2, 3},
      {3, 2, 1},
      {3, 2, 2}
  };
  objectComparison(objectVector);
  return 0;
}