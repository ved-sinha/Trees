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

class Pair{
    public:
    int height;
    int diameter;
};

node* buildTree(node*root){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    root=new node(d);
    root->left=buildTree(root->left);
    root->right=buildTree(root->right);
    return root;
}

void print(node* root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void inorderPrint(node* root){
    if(root==NULL)
    return;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

void bfs(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* f=q.front();
        q.pop();
        cout<<f->data<<" ";
        if(f->left)
        q.push(f->left);
        if(f->right)
        q.push(f->right);
    }
    return;
}



int height(node *root){
    if(root==NULL)
    return 0;
    int hLeft=height(root->left);
    int hRight=height(root->right);
    int hRoot=max(hLeft,hRight)+1;
    return hRoot;
}

void printKthLevel(node* root,int k){
    if(root==NULL)
    return;
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
    
}

void printAllLevel(node* root){
    if(root==NULL)
    return;
    int h=height(root);
    for(int i=1;i<=h;i++){
        printKthLevel(root,i);
        cout<<endl;
    }
}

void bfsLineEnd(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f=q.front();
        q.pop();
        if(f==NULL){
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
        }
        else{
            cout<<f->data<<" ";
            if(f->left)
            q.push(f->left);
            if(f->right)
            q.push(f->right);
        }
        
    }
}

int countNodes(node* root){
    if(root==NULL)
    return 0;
    else return (countNodes(root->left)+countNodes(root->right)+1);
}

int sumNodes(node* root){
    if(root==NULL)
    return 0;
    else return (sumNodes(root->left)+sumNodes(root->right)+root->data);
}

int Cdiameter(node* root){
    if(root==NULL)
    return 0;
    
    int hL=height(root->left);
    int hR=height(root->right);
    int left=Cdiameter(root->left);
    int right=Cdiameter(root->right);
    return max(max(hL+hR,left),right);
    
}

Pair fastDiameter(node* root){
    Pair p;
    if(root==NULL){
        p.diameter=p.height=0;
        return p;
    }
    Pair left=fastDiameter(root->left);
    Pair right=fastDiameter(root->right);
    p.height=max(left.height,right.height)+1;
    p.diameter=max(max(left.height+right.height,left.diameter),right.diameter);
    return p;
    
}

int main() {
	// your code goes here
	node* root=buildTree(root);
	print(root);
	cout<<endl;
	inorderPrint(root);
	cout<<endl;
	bfs(root);
	cout<<endl;
	cout<<height(root);
	cout<<endl;
	//printAllLevel(root);
	//cout<<endl;
	bfsLineEnd(root);
	cout<<endl;
	cout<<countNodes(root)<<"\n";
	cout<<sumNodes(root);
	cout<<endl;
//	cout<<diameter(root);
	cout<<endl;
	Pair p=fastDiameter(root);
	cout<<p.diameter;
	return 0;
}
