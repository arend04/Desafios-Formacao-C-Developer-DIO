#include <iostream>
#include <algorithm>

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) : data(value), left(NULL), right(NULL), height(1) {}
};

class AVLTree {
public:
    AVLTree() : root(NULL) {}

    int getHeight(Node* node) {
        if (node == NULL) {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == NULL) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* insert(Node* node, int data) {
        if (node == NULL) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        } else {
            return node; // Não permite valores duplicados
        }

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1) {
            if (data < node->left->data) {
                return rotateRight(node);
            } else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (balance < -1) {
            if (data > node->right->data) {
                return rotateLeft(node);
            } else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    void insert(int data) {
        root = insert(root, data);
    }

    void printInOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        printInOrder(node->left);
        std::cout << node->data << " ";
        printInOrder(node->right);
    }

    void printInOrder() {
        printInOrder(root);
        std::cout << std::endl;
    }
    
 
private:
    Node* root;
};

int main() {
    AVLTree avl;

    avl.insert(30);
    avl.insert(20);
    avl.insert(40);
    avl.insert(10);
   	avl.insert(25);

    std::cout << "In-order traversal of AVL tree: ";
    avl.printInOrder();
    
     

    return 0;
}

