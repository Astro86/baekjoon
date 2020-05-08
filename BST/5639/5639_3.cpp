#include <bits/stdc++.h>
using namespace std;

class Node {
    int value;

    Node* left;
    Node* right;

   public:
    Node(int value) : value(value), left(NULL), right(NULL) {}

    void insert(int value) {
        if (this->value > value) {
            if (this->left == NULL) {
                this->left = new Node(value);
            } else {
                this->left->insert(value);
            }
        } else {
            if (this->right == NULL) {
                this->right = new Node(value);
            } else {
                this->right->insert(value);
            }
        }
    }

    void postOrder() {
        if (this->left) {
            this->left->postOrder();
        }

        if (this->right) {
            this->right->postOrder();
        }

        cout << value << '\n';
    }
};

int main(void) {
    int value;
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> value;
    Node* BST = new Node(value);
    while (cin >> value) {
        BST->insert(value);
    }
    BST->postOrder();
    return 0;
}