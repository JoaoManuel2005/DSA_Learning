#ifndef BTREE_NODE_H
#define BTREE_NODE_H

class btree_node {
    public:
        btree_node(int value, btree_node* left=nullptr, btree_node* right=nullptr);
        void setLeft(btree_node* node);
        void setRight(btree_node* node);
        btree_node*& getLeft();
        btree_node*& getRight();
        int getValue() const;
        void setValue(int val);
    private:
        int value;
        btree_node* left;
        btree_node* right;
};

#endif // BTREE_NODE_H