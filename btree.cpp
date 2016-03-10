#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data) {
    Node* newNode = new Node(); 
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode; 
}

Node* Insert(Node* root, int data) {
    if (root == NULL) {
        root = GetNewNode(data);  
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data); 
    }
    else { 
        root->right = Insert(root->right, data); 
    }
    return root;
}

void postorder(Node* p, int indent) {
    if (p != NULL) {
        if (p->right) {
            postorder(p->right, indent+4);
        } 
        if (indent) {
            cout << setw(indent) << ' '; 
        }
        if (p->right) cout << " /\n" << setw(indent) << ' ';
        cout << p->data << "\n ";
        if (p->left) { 
            cout << setw(indent) << ' ' << "\\\n";
            postorder(p->left, indent+4);
        }
    }
}


bool Search(Node* root, int data) {
    if (root == NULL) {
        return false;
    }
    else if (root->data == data) {
        return true; 
    }
    else if (data <= root->data) {
        return Search(root->left, data); 
    }
    else {
        return Search(root->right, data); 
    }
}

int main() {
    Node* root = NULL;
    root = Insert(root,666);
    root = Insert(root, 15);
    root = Insert(root, 99);
    root = Insert(root,  7);
    root = Insert(root, 10);
    root = Insert(root,120);
    root = Insert(root,210);
    root = Insert(root, 20); 
    root = Insert(root, 25); 
    root = Insert(root, 13); 
    root = Insert(root,  8); 
    root = Insert(root,777); 
    root = Insert(root,  1); 
    root = Insert(root, 93); 
    root = Insert(root, 12); 

    int start;
    cout << "enter starting number: ";
    cin >> start;
    postorder(root, start); 

}
