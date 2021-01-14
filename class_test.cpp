#include<iostream>
#include<vector>

using namespace std;

class BFS {
    public:
        vector<string> v = {"This", "is", "a", "vector", "in", "the", "class"};
        void test() {
            cout << "Test passed.\n";
            return;
        }

        void print_vector() {
            for(auto i : v){
                cout<< i << ' ';
            }
            cout<<'\n';
            return;
        }
};

int main() {
    BFS instance;
    instance.test();
    instance.print_vector();
    return 0;
}