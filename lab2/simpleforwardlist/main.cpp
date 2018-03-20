//
// Created by adrja on 15.03.2018.
//

#include "SimpleForwardList.h"


int main() {
    ForwardList *head = CreateNode(89);
    ForwardList *first = CreateNode(1717);
    ForwardList *second = CreateNode(804);
    head->next = first;
    first->next = second;
    auto *another_tail = CreateNode(651);
    auto *another_first = PushFront(another_tail, 111);
    Append(head, another_first);
    DestroyList(head);

    return 0;
}