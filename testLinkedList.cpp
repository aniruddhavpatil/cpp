#include<vector>
#include<iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    ListNode* head = new ListNode();
    ListNode* curr = head;
    vector<int> numbers = {0, 1, 2, 3, 4};
    for(int i = 0; i < numbers.size(); i++){
        curr ->val = numbers[i];
        if(i < numbers.size() - 1){
            curr->next = new ListNode();
        }
        curr = curr->next;
    }

    curr = head;
    while(curr){
        cout<<curr->val<<"->";
        curr = curr->next;
    }
    return 0;

}