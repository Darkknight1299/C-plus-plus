#include<bits/stdc++.h>
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

node* buildtree(){
  int d;
  cin>>d;

  if(d==-1){
    return NULL;
  }

  node* root=new node(d);
  root->left=buildtree();
  root->right=buildtree();
  return root;
}

void print(node* root){
  if(root=NULL){
    return;
  }

  //Print root first and then children
  cout<<root->data<<" ";
  print(root->left);
  print(root->right);
}

int height(node* root){
  //Base case
  if(root==NULL){
    return 0;
  }

  //rec case
  int left_h=height(root->left);
  int right_h=height(root->right);
  return max(left_h,right_h)+1;
}

class Pair{
public:
  int height;
  int diameter;
};

Pair fastDiameter(node* root){
  Pair p;
  if(root==NULL){
    p.diameter=p.height=0;
    return p;
  }

  Pair left=fastDiameter(root->left);
  Pair right=fastDiameter(root->right);

  p.height=max(left.height,right.height)+1;
  p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
  return p;
}

int main()
{  
   #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  //  code starts

  node* root=buildtree();
  print(root);
}