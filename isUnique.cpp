#include<bits/stdc++.h>
using namespace std;

bool isUnique(string s){
    // Using 26 bits of the 32 for an int
    int bitLookup = 0;
    for(auto c : s){
        if(bitLookup & (1 << (c - 'a'))) return false;
        bitLookup |= 1 << (c - 'a');
    }
    return true;
}

int main(){
    cout<<isUnique("abc")<<'\n';
    cout << isUnique("aabc") << '\n';
    return 0;
}