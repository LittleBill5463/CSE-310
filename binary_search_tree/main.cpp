#include <bits/stdc++.h>

using namespace std;

struct Node 
{
    int val;
    struct Node *left, *right;
};

Node* create(int val) 
{
    Node *temp = new Node;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node *root, int val) 
{
    if (root == NULL) 
    {
        return create(val);
    }

    if (val < root->val) 
    {
        root->left = insert(root->left, val);
    } 

    else 
    {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* search(Node *root, int val) 
{
    if (root == NULL || root->val == val) 
    {
        return root;
    }

    if (val < root->val) 
    {
        return search(root->left, val);
    } 

    else 
    {
        return search(root->right, val);
    }
}

void inorder(Node *root) 
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void preorder(Node *root) 
{
    if (root == NULL)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) 
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void levelorder (Node *root, int curr, int level) 
{
    if (root == NULL)
        return;

    if (curr == level)
        cout << root->val << " ";

    levelorder (root->left, curr + 1, level);
    levelorder (root->right, curr + 1, level);
}

Node* findMin(Node* node) 
{
    while (node->left != nullptr) 
    {
        node = node->left;
    }

    return node;
}

Node* deleteNode(Node *root, int key) 
{
    if (root == nullptr) 
    {
        return root;
    }

    if (key < root->val) 
    {
        root->left = deleteNode(root->left, key);
    }
    
    else if (key > root->val) 
    {
        root->right = deleteNode(root->right, key);
    } 
    
    else 
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        else if (root->left == nullptr) 
        {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        
        else if (root->right == nullptr) 
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main() 
{
    int number_of_queries;
    cin >> number_of_queries;
    Node *root = NULL;

    while (number_of_queries--) 
    {
        string command;
        cin >> command;

        if (command == "INSERT") 
        {
            int value;
            cin >> value;
            root = insert(root, value);
        } 
        
        else if (command == "DELETE") 
        {
            int value;
            cin >> value;
            root = deleteNode(root, value);
        } 
        
        else if (command == "SEARCH") 
        {
            int value;
            cin >> value;
            if (search(root, value) == NULL) 
            {
                cout << "False" << endl;
            } 
            
            else 
            {
                cout << "True" << endl;
            }
        } 
        
        else if (command == "INORDER") 
        {
            inorder(root);
            cout << endl;
        } 
        
        else if (command == "PREORDER") 
        {
            preorder(root);
            cout << endl;
        } 
        
        else if (command == "POSTORDER") 
        {
            postorder(root);
            cout << endl;
        } 
        
        else if (command == "LEVELORDER") 
        {
            int level;
            cin >> level;
            levelorder(root, 0, level);
            cout << endl;
        }
    }

    return 0;
}