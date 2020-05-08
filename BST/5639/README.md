# 백준 5639 - 이진 검색 트리

![](5639.jpeg)

## 채점 현황

![](5693_score.png)

## 전체 소스 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int value;
    int depth;

    Node* left;
    Node* right;

   public:
    Node(int& value) {
        this->value = value;
        this->depth = 0;
        this->left = NULL;
        this->right = NULL;
    }

    void setLeft(Node* newNode) {
        this->left = newNode;
    }

    void setRight(Node* newNode) {
        this->right = newNode;
    }
};

Node* insert(Node* root, Node* node) {
    if (root == NULL) {
        return node;
    } else if (root->value > node->value) {
        root->setLeft(insert(root->left, node));
    } else {
        root->setRight(insert(root->right, node));
    }
    return root;
}

void PostOrder(Node* tree) {
    if (tree->left != NULL) {
        PostOrder(tree->left);
    }

    if (tree->right != NULL) {
        PostOrder(tree->right);
    }

    cout << tree->value << '\n';
}

int main(void) {
    int value;
    Node* tree = NULL;
    while (scanf("%d", &value) != EOF) {
        tree = insert(tree, new Node(value));
    }

    PostOrder(tree);

    return 0;
}
```

## 두번째 풀이 방법
```cpp
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
```