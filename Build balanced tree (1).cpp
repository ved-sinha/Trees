#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* buildBalanced(int *a,int s,int e){
    
    if(s>e)
    return NULL;
    
    int mid=(s+e)/2;
    node* root=new node(a[mid]);
    
    root->left=buildBalanced(a,s,mid-1);
    root->right=buildBalanced(a,mid+1,e);
    
    return root;
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


int main() {
	// your code goes here
	int a[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    a[i]=i;
	}
	int mid=n/2;
	
    node*root=buildBalanced(a,0,n-1);
    bfsLineEnd(root);
	return 0;
}
