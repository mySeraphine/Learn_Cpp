#include <iostream>

using namespace std;
class Node {
public:
    int data;
    Node *lchild;
    Node *rchild;
};

void CreatTree(Node* &node,int data) {
    if (data<11){
        if (data == -1) {
            node = nullptr;
        } else {
            node = new Node;
            (node)->data = data;
            cout<<data<<"storaged"<<endl;

            CreatTree((node)->lchild,data+1);
            CreatTree((node)->rchild,data+2);
        }
    } else{
        return;
    }

}


int main() {
    Node *root = nullptr;

    CreatTree(root,0);
    return 0;
}

