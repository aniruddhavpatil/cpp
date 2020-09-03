#include<bits/stdc++.h>
#include "stringParse.h"
using namespace std;


int main(){

    vector<string> ans = stringParse("1->2->3->4->5", "->");
    string out = "[";
    for(int i = 0; i < ans.size(); ++i){
        out+=ans[i];
        if(i < ans.size() - 1) out+=", ";
    }
    out+="]";
    cout<<out<<'\n';
    return 0;
}