#include<iostream>

using namespace std;
struct Binarytreenode {
    int value;
    Binarytreenode *left;
    Binarytreenode *right;
};

Binarytreenode *creatBinarytree(int value) {
    Binarytreenode *root = new Binarytreenode;
    root->value = value;
    root->left = nullptr;
    root->right = nullptr;
    return root;
}

void connectBinarytreenode(Binarytreenode *parent, Binarytreenode *right, Binarytreenode *left) {
    if (parent != nullptr) {
        parent->left = left;
        parent->right = right;
    }
}

void printBinarytreenode(Binarytreenode *pnode) {
    if (pnode == nullptr)
        cout << "this node is NULL" << endl;
    else {
        cout << pnode->value << endl;
        if (pnode->left == nullptr)
            cout << "left  NULL" << " ";
        else
            cout << "left" << " " << pnode->left->value << " ";
        if (pnode->right == nullptr)
            cout << "right  NULL" << " " << endl;
        else
            cout << "right" << " " << pnode->right->value << endl;
    }
}

//前序遍历
void printBinarytree(Binarytreenode *root) {
    printBinarytreenode(root);
    if (root != nullptr) {
        if (root->left != nullptr)
            printBinarytree(root->left);
        if (root->right != nullptr)
            printBinarytree(root->right);
    }
}

void destroyBinarytree(Binarytreenode *root) {
    if (root != nullptr) {
        Binarytreenode *pleft = root->left;
        Binarytreenode *pright = root->right;
        delete root;
        root = nullptr;
        destroyBinarytree(pleft);
        destroyBinarytree(pright);
    }
}

int main() {
    Binarytreenode *p1 = creatBinarytree(1);
    Binarytreenode *p2 = creatBinarytree(2);
    Binarytreenode *p3 = creatBinarytree(3);
    Binarytreenode *p4 = creatBinarytree(4);
    Binarytreenode *p5 = creatBinarytree(5);
    Binarytreenode *p6 = creatBinarytree(6);
    connectBinarytreenode(p4, p3, p5);
    connectBinarytreenode(p3, p1, nullptr);
    connectBinarytreenode(p5, p2, nullptr);
    printBinarytree(p4);
    destroyBinarytree(p4);
    return 0;
}
