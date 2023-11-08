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

bool search(Node *root, vector<int>& result, int val) 
{
    if (root == NULL || root->val == val) 
    {
        return false;
    }

    if (val < root->val) 
    {
        result.push_back(root->val);
        return search(root->left, result, val);
    } 

    else if (val > root->val)
    {
        result.push_back(root->val);
        return search(root->right, result, val);
    }

    else
    {
        result.push_back(root->val);
        return true;
    }
}

void inorder(Node *root, vector<int>& result) 
{
    if (root == NULL)
        return;

    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

void preorder(Node *root,vector<int>& result) 
{
    if (root == NULL)
        return;

    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

void postorder(Node *root, vector<int>& result) 
{
    if (root == NULL)
        return;

    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->val);
}

void levelorder (Node *root, vector<int>& result, int curr, int level) 
{
    if (root == NULL)
        return;

    if (curr == level)
        result.push_back(root->val);

    levelorder (root->left, result, curr + 1, level);
    levelorder (root->right, result, curr + 1, level);
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
    vector<int> result;
    
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
            result.clear();
            
            if(search(root, result, value))
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(-2);
            }
            
        } 
        
        else if (command == "INORDER") 
        {
            result.clear();
            inorder(root, result);
            
        } 
        
        else if (command == "PREORDER") 
        {
            result.clear();
            preorder(root, result);
            
        } 
        
        else if (command == "POSTORDER") 
        {
            result.clear();
            postorder(root, result);
            
        } 
        
        else if (command == "LEVELORDER") 
        {
            int level;
            cin >> level;
            result.clear();
            levelorder(root, result, 0, level);
            
        }
    }
    
    for (int val : result) 
    {
        if (val == -1)
        {
            cout << "True" << endl;
        }

        else if (val == -2)
        {
            cout << "False" << endl;
        }

        else 
        {
            cout << val << " ";
        }
    }
    
    return 0;
}
