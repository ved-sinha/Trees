#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* buildTree(){
    int d;
    cin>>d;
    
    if(d==-1){
        return NULL;
    }
    
    node*root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

void printPreorder(node*root){
    if(root==NULL)
    return;
    
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(node*root){
    if(root==NULL)
    return;
    
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPost(node*root){
    if(root==NULL)
    return;
    
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}

int main() {
    node* root=buildTree();
    printPreorder(root);
	cout<<endl;
	printInorder(root);
	cout<<endl;
	printPost(root);
	return 0;
}
