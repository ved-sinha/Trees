#include <iostream>
#include<queue>
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

int height(node* root){
    if(root==NULL)
    return 0;
    else return max(height(root->left),height(root->right))+1;
}

void printKthLevel(node*root,int k){
    if(root==NULL)
    return;
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
}

//Takes o(n^2) as for n height we have to iterate n times;

void printAllLevels(node*root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        printKthLevel(root,i);
        cout<<endl;
    }
    return;
}

void bfs(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        
        node* f=q.front();
        
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty())
                q.push(NULL);   
        }
        else{
        cout<<f->data<<" ";
        q.pop();
        if(f->left){
            q.push(f->left);
        }
        if(f->right){ 
            q.push(f->right);
        }
      }
    }
    
    return;
}

//Count the number of nodes and sum of all nodes

int countNodes(node*root){
    if(root==NULL)
    return 0;
    else return (countNodes(root->left)+countNodes(root->right)+1);
}

int sumNodes(node*root){
    if(root==NULL)
    return 0;
    else return (root->data+sumNodes(root->left)+sumNodes(root->right));
}

//o(n^2) approach since for n height we are doing it every time we are calling
//diameter(left) or (right) so for every node height is calculated and its n^2

int diameter(node*root){
    if(root==NULL)
    return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    int op1=h1+h2;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    int res=max(max(op1,op2),op3);
    return res;
}

int main() {
    node* root=buildTree();
    /*printPreorder(root);
	cout<<endl;
	printInorder(root);
	cout<<endl;
	printPost(root);
	cout<<endl;
	cout<<height(root);
	cout<<endl;
	cout<<"Printing all levels"<<"\n";
	printAllLevels(root);*/
	
	cout<<"Printing By BFS"<<"\n";
	bfs(root);
    //cout<<"The node count is "<<countNodes(root)<<endl;
    //cout<<"The sum of nodes is "<<sumNodes(root)<<endl;;
    cout<<"The diameter of the tree is "<<diameter(root)<<endl;;
	return 0;
}
