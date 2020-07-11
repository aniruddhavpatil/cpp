#include<bits/stdc++.h>
using namespace std;

vector<string> stringParse(string s, string d){
    vector<string> ans;
    size_t curr = 0, next;
    string token;

    do{
        next = s.find(d, curr);
        token = s.substr(curr, next - curr);
        curr = next + d.length();
        ans.push_back(token);
    } while (next!=string::npos);

    return ans;
}

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