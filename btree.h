//
// Created by 折棒 on 2018/10/24.
//

#ifndef BST_BTREE_H
#define BST_BTREE_H

class node{
public:
    node *left;
    node *right;
    int data;

    node():left(nullptr),right(nullptr){};
    node( int item): data(item),left(nullptr),right(nullptr){};
};

class btree{
private:
    node *root;
public:
    btree():root(nullptr){};
    ~btree();
    btree(btree&);

    void copytree(node*& subject,  node*& object);

    void detree(node *object);

    void insertNode(node*& object, int item);
    void insert( int item);

};



btree::btree(btree& object){
    root= nullptr;
    copytree(root,object.root);
}

void btree::copytree(node*& subject, node*& object) {
    if(object== nullptr){
        subject= nullptr;
        return;
    }
    else{
        subject=new node(object->data);
        copytree(subject->left,object->left);
        copytree(subject->right,object->right);
    }
}




btree::~btree(){
    detree(root);
}

void btree::detree(node *object){
    if(object==nullptr){
        return;
    }
    else{
        detree(object->left);
        detree(object->right);
        delete object;
    }
}


//////////////////////////
// Insert is totally fine

void btree::insert( int item){
    insertNode(root,item);
}

void btree::insertNode(node* & object, int item) {
    if (object == nullptr) {
        object = new node(item);
    } else {
        if (object->data < item) {
            insertNode(object->left, item);
        } else {
            insertNode(object->right, item);
        }
    }

}


#endif //BST_BTREE_H
