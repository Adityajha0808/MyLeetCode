//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    Node* treeFromString(string s) {
        int n = s.size(), k = 0;
        while(k<n and isdigit(s[k])) k++;
        string str = s.substr(0, k);
        Node* root = new Node(stoi(str));
        for(int i=k; i<n; ++i) {
            if(s[i] == '(') {
                int open = 1, close = 0, j = i+1;
                while(j<n and open != close) {
                    if(s[j] == '(') open++;
                    if(s[j] == ')') close++;
                    j++;
                }
                Node* x = new Node(0);
                x = treeFromString(s.substr(i + 1, j - i - 2));
                if(!root->left)
                    root->left = x;
                else
                    root->right = x;
                i = j - 1;
            }
        }
        return root;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends