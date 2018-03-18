//
// Created by adrja on 15.03.2018.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H

typedef struct flist{
    struct flist * next;
    int data;
} ForwardList;

ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);

ForwardList *PushFront(ForwardList *list, int value);
void Append(ForwardList *list, ForwardList *tail);


#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H
