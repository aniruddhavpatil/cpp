#include<bits/stdc++.h>
using namespace std;

vector<bool> checkOperations(vector<int> a, vector<char> signs, vector<int> b, vector<int> c){
    vector<bool> ans;
    for(int i = 0; i < a.size(); i++){
        bool curr = false;
        if(signs[i] == '+'){
            if(a[i] + b[i] == c[i]) curr = true;
        }
        else{
            if(a[i] - b[i] == c[i]) curr = true;
        }
        ans.push_back(curr);
    }
    return ans;
}

vector<bool> isSubmatrixFull(vector<vector<int>> numbers){
    int col_len = numbers[0].size();
    if(col_len < 3 ) return {};
    unordered_map<int, int> cache;
    vector<bool> ans;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            cache[numbers[i][j]]+=1;
        }
    }

    for(int o = 0; o < col_len - 2; ++o){
        bool c = true;
        for(int i = 0; i < 3; i++){
            cache[numbers[i][o+2]]+=1;
        }
        for (int i = 1; i <= 9; i++) {
            if (cache[i] != 1) c = false;
        }
        ans.push_back(c);
        for(int i  = 0; i < 3; i++){
            cache[numbers[i][o]]-=1;
        }
    }
    return ans;
}

int main(){

    vector<int> a = {3, 2, -1, 4};
    vector<int> b = {2, 7, -5, 2};
    vector<char> signs = {'+', '-', '-', '+'};
    vector<int> c = {5, 5, 4, 2};
    // auto ans = checkOperations(a,signs,b,c);
    // for(auto a : ans){ cout << a << endl;}
    vector<vector<int>> numbers = {
        { 1, 2, 3, 2, 5, 7 },
        { 4, 5, 6, 1, 7, 6 },
        { 7, 8, 9, 4, 8, 3 },
    };
    
    // auto ans = isSubmatrixFull(numbers);
    // for(auto a : ans){
    //     cout<<a<<' ';
    // }

    

    return 0;
}