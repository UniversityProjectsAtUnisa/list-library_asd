#include <stdlib.h>
#include <stdio.h>
#include "list.h"

bool is_greater(int a, int b) {
    if(a>b)
        return true;
    else
        return false;
}

bool is_equal(int a, int b) {
    if(a==b)
        return true;
    else
        return false;
}

void info_print(int info) {
    printf("%d ", info);
}

TNode* node_create(TInfo info) { 
    TNode *new_node;
    new_node=(TNode *)malloc(sizeof(TNode)); 
    if(new_node==NULL)
        return NULL;
    new_node->info=info;
    new_node->link=NULL;
    return new_node;
}

void node_destroy(TNode* node) {
    free(node);
    node=NULL;
}

TList list_create(){
    return NULL;
}

TList list_insert(TList l, TInfo info) {
    TNode* new_node;
    TList new_list;
    if((l==NULL) || (is_greater(l->info, info))) {
        new_node=node_create(info);
        if(new_node==NULL)
            return NULL;
        new_node->link=l;
        return new_node;
    }
    new_list=list_insert(l->link, info);
    l->link=new_list;
    return l;
}

TList list_delete_node(TList l, TInfo info) {
    TNode* node;
    if(l==NULL || is_greater(l->info, info))
        return l;
    if(is_equal(l->info, info)) {
        node=l->link;
        node_destroy(l);
        return node;
    }
    l->link=list_delete_node(l->link, info);
    return l;
}

TNode* list_search(TList l, TInfo info) {
    if(l==NULL || is_greater(l->info, info))
        return NULL;
    if(is_equal(l->info, info))
        return l;
    return list_search(l->link, info);
}

void list_visit(TList l) {
    if(l==NULL)
        return;
    info_print(l->info);
    list_visit(l->link);
}