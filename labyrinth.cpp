#include<bits/stdc++.h>
using namespace std;

bool isEscapePossible(
    int n,
    int m,
    vector<vector<int>> obstacles,
    vector<vector<int>> teleport
    ){
    vector<vector<pair<char, pair<int, int>>>> grid(n, vector<pair<char, pair<int, int>>>(m, {'.', {-1, -1}}));
    cout<<"OBS\n";
    for(auto obs: obstacles){
        grid[obs[0]][obs[1]].first = 'o';
    }
    cout << "TP\n";
    for(auto tp: teleport){
        grid[tp[0]][tp[1]].first = 't';
        grid[tp[0]][tp[1]].second.first = tp[2];
        grid[tp[0]][tp[1]].second.second = tp[3];
    }
    cout << "LOOP\n";
    int i = 0, j = 0;
    while(!(i == n-1 && j == m-1)){
        cout<<i<<' '<<j<<endl;
        char curr = grid[i][j].first;
        if(curr == 'x' || curr == 'o') return false;
        else if (curr == 't'){
            grid[i][j].first = 'x';
            auto tp = grid[i][j].second;
            tie(i,j) = tp;
            // i = tp.first;
            // j = tp.second;
        }
        else if (curr == '.'){
            grid[i][j].first = 'x';
            if(j +1 < m){
                j+=1;
            }
        }
    }
    return true;
}


int main(){

    int n = 4, m = 4;
    vector<vector<int>> obastacle;
    vector<vector<int>> teleport = {{0,2,3,1}};
    bool escape = isEscapePossible(n, m, obastacle, teleport);
    if(escape){
        cout<<"Escape is possible\n";
    }
    else{
        cout<<"Escape is not possible\n";
    }
}