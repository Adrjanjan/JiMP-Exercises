//
// Created by adrja on 15.03.2018.
//

#include "SimpleForwardList.h"

ForwardList *CreateNode(int value) {
    auto *node = new ForwardList;
    node->value = value;
    node->next = nullptr;
    return node;
}

void DestroyList(ForwardList *list) {
    if (list != nullptr) {
        ForwardList *tmp = list;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
            delete list;
        }
        delete tmp;
    }
}

ForwardList *PushFront(ForwardList *list, int value) {

    if (list == nullptr) {
        return nullptr;
    } else {
        ForwardList *tmp = CreateNode(value);
        tmp->next = list;
        list = tmp;

        return list;
    }
}

void Append(ForwardList *list, ForwardList *tail) {

    if (list == nullptr) {
        list = tail;
    } else {
        ForwardList *tmp = list;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = tail;
    }
}
