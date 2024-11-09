#include <iostream>
#include <queue>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST 
{
public:
    BST() : root(nullptr) {}

    void insert(int val) 
    {
        root = insertRec(root, val);
    }

    void deleteNode(int val) 
    {
        root = deleteRec(root, val);
    }

    bool search(int val) 
    {
        return searchRec(root, val);
    }

    void inorder() 
    {
        if (!root) 
        {
            cout << endl << endl;
            return;
        }
        inorderRec(root);
        cout << endl;
    }

    void preorder() 
    {
        if (!root) 
        {
            cout << endl << endl;
            return;
        }
        preorderRec(root);
        cout << endl;
    }

    void postorder() 
    {
        if (!root) 
        {
            cout << endl << endl;
            return;
        }
        postorderRec(root);
        cout << endl;
    }

    void levelOrder() 
    {
        if (!root) 
        {
            cout << endl << endl;
            return;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) 
        {
            Node* node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }

private:
    Node* root;

    Node* insertRec(Node* node, int val) 
    {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insertRec(node->left, val);
        else if (val > node->data)
            node->right = insertRec(node->right, val);
        return node;
    }

    Node* deleteRec(Node* node, int val) 
    {
        if (!node) return node;
        if (val < node->data)
            node->left = deleteRec(node->left, val);
        else if (val > node->data)
            node->right = deleteRec(node->right, val);
        else 
        {
            if (!node->left) 
            {
                Node* temp = node->right;
                delete node;
                return temp;
            } 
            else if (!node->right) 
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    }

    Node* minValueNode(Node* node) 
    {
        Node* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    bool searchRec(Node* node, int val) 
    {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return searchRec(node->left, val);
        return searchRec(node->right, val);
    }

    void inorderRec(Node* node) 
    {
        if (!node) return;
        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }

    void preorderRec(Node* node) 
    {
        if (!node) return;
        cout << node->data << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    void postorderRec(Node* node) 
    {
        if (!node) return;
        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->data << " ";
    }
};

int main() 
{
    BST tree;
    int number_of_queries;
    cin >> number_of_queries;
    while (number_of_queries--) 
    {
        string command;
        cin >> command;
        if (command == "INSERT") 
        {
            int value;
            cin >> value;
            tree.insert(value);
        } 
        else if (command == "DELETE") 
        {
            int value;
            cin >> value;
            tree.deleteNode(value);
        } 
        else if (command == "SEARCH") 
        {
            int value;
            cin >> value;
            cout << (tree.search(value) ? "True" : "False") << endl;
        } 
        else if (command == "INORDER") 
        {
            tree.inorder();
        } 
        else if (command == "PREORDER") 
        {
            tree.preorder();
        } 
        else if (command == "POSTORDER") 
        {
            tree.postorder();
        } 
        else if (command == "LEVELORDER") 
        {
            tree.levelOrder();
        }
    }
    return 0;
}
