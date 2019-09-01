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
    vector<int> arr;
    q.push(head);
    int count=0,flag=0,num=0,c=0,sum=0;
    while(!q.empty())
    {
        struct tree* node=q.front();
        //cout<<node->data<<" ";
        if(node->left!=NULL)
        {
            q.push(node->left);
            c++;
        }
        if(node->right!=NULL)
        {
            q.push(node->right);
            c++;
        }
        flag++;
        if(flag<count)
        {
            cout<<node->data<<" ";
            sum+=node->data;
        }
        else
        {
            flag=0;
            num++;
            count=pow(2,num);
            if(count>c)
            {
                count=c;
                
            }
            c=0;
            sum+=node->data;
            if(sum==0)
            {
                arr.push_back(num-1);
            }
            sum=0;
            cout<<node->data<<"\n";
        }
        q.pop();
    }
    cout<<"For level\n";
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<"\n";
    }
}
int main()
{
    struct tree *root=push(1);
    root->right=push(90);
    root->right->right=push(0);
    root->right->left=push(-60);
    root->left=push(-40);
    root->left->right=push(20);
    root->left->left=push(40);
    //root->right->right->left=push(-20);
    //root->right->right->right=push(1);
    print(root);
}
