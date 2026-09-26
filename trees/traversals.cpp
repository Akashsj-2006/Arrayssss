#include<iostream>
#include<queue>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
        
}

void preorder(node *root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelOrder(node *root)
{
    if(root == NULL)
        return;
    queue<node*> q;
    q.push(root);

    while(!q.empty())
        {
            node *current= q.front();
            q.pop();
            cout<<current->data<<" ";
            if(current->left)
                q.push(current->left);
            if(current->right)
                q.push(current->right);
        }
    
}
int main()
{
    int val = 10;
    struct node *root = new node(val);
    root->left = new node(11);
    root->right = new node(12);
    root->left->left = new node(13);
    root->left->right = new node(14);
    cout<<"Inorder Traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"PreOrder Traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"PostOrder Traversal: ";
    postorder(root);
    cout<<endl;
    cout<<"LevelOrder Traversal: ";
    levelOrder(root);
    cout<<endl;
}