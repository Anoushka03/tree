#include<bits/stdc++.h>
using namespace std;
struct tree
{
   // public:
    int data;
     struct tree* left;
     struct tree * right;
};
struct tree * push( int key)
{
     struct tree *newnode=(struct tree*)malloc(sizeof(struct tree*));
     newnode->data=key;
     newnode->left=newnode->right=NULL;
    return newnode;
}
void print(tree* head)
{
    queue<struct tree*> q;
    q.push(head);
    while(!q.empty())
    {
        struct tree* node=q.front();
        cout<<node->data<<" ";
        if(node->left!=NULL)
            q.push(node->left);
        if(node->right!=NULL)
            q.push(node->right);
        q.pop();
    }
}
int main()
{
    struct tree *root=push(1);
    root->left=push(-50);
    root->right=push(30);
    root->left->left=push(-90);
    root->left->left->left=push(19);
    root->left->right=push(140);
    root->right->right=push(50);
    root->right->right->left=push(-20);
    root->right->right->right=push(1);
    print(root);
}
