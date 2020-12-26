class Solution {
public:
  vector<ListNode *> reverseSection(ListNode *head, ListNode *tail) {
    if (head == tail)
      return {head, tail};
    ListNode *prev = nullptr, *curr = head, *nxt = head->next;
    while (prev != tail) {
      // cout<<curr->val<<"->";
      nxt = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
    }
    // cout<<endl;
    return {tail, head};
  }

  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode *m_head, *n_head;
    int diff = n - m;
    if (diff == 0)
      return head;
    m_head = head;
    ListNode *m_prev = nullptr, *n_next = nullptr;
    for (int i = 0; i < m - 1; i++) {
      m_prev = m_head;
      m_head = m_head->next;
    }
    n_head = m_head;
    for (int i = 0; i < diff; i++) {
      n_head = n_head->next;
      n_next = n_head->next;
    }

    auto section = reverseSection(m_head, n_head);
    m_head = section[0];
    n_head = section[1];
    ListNode *temp = m_head;
    // cout<<m_head->val<<' '<<n_head->val<<endl;
    // while(temp){
    // cout<<temp->val<<"->";
    //     temp = temp->next;
    // }
    if (m_prev) {
      m_prev->next = m_head;
    } else
      head = m_head;

    n_head->next = n_next;

    return head;
  }
};