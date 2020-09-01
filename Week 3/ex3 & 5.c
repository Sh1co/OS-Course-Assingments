#include <stdio.h>

typedef enum { false, true } bool;
typedef struct ll *node;

struct ll{
    int value;
    struct ll *next;
    struct ll *prev;
};


void print_list(node cnode){
    printf("%d \n", cnode->value);
    if(cnode->next!=NULL)print_list(cnode->next);
}

node create_node(int val){
    node n;
    n = (node)malloc(sizeof(struct ll));
    n->value=val;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

bool insert_node(node inode,node cnode, int after_val){
    if(cnode->value==after_val){
        inode->next = cnode->next;
        cnode->next = inode;
        inode->prev = cnode;
        if(inode->next!=NULL)inode->next->prev = inode;
        return true;
    }
    else if(cnode->next!=NULL)insert_node(inode,cnode->next,after_val);
    else return false;
}

bool delete_node(node cnode, int val){
    if(cnode->value==val){
        cnode->prev->next = cnode->next;
        cnode->next->prev = cnode->prev;
    }
    else if(cnode->next!=NULL)delete_node(cnode->next,val);
    else return false;
}

int main(){
    node first = create_node(5);
    insert_node(create_node(4),first,5);
    insert_node(create_node(3),first,5);
    insert_node(create_node(2),first,5);
    insert_node(create_node(1),first,5);
    print_list(first);
    printf("\n \n");
    delete_node(first,3);
    print_list(first);

}
