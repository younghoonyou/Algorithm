//https://www.acmicpc.net/problem/1991
#include<iostream>
using namespace std;
struct Node{
    char data;
    Node* left;
    Node* right;
}nodeBuffer[27];
int cnt=0;
void preOrder(Node* temp){
    if(temp==nullptr) return ;
    cout<<temp->data;
    preOrder(temp->left);
    preOrder(temp->right);
}
void midOrder(Node* temp){
    if(temp==nullptr) return ;
    midOrder(temp->left);
    cout<<temp->data;
    midOrder(temp->right);
}
void postOrder(Node* temp){
    if(temp==nullptr) return ;
    postOrder(temp->left);
    postOrder(temp->right);
    cout<<temp->data;
}
int main(){
    int N;
    char root,left,right;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>root>>left>>right;
        nodeBuffer[root-'A'].data = root;
        if(left!='.') nodeBuffer[root-'A'].left = &nodeBuffer[left-'A'];
        if(right!='.') nodeBuffer[root-'A'].right = &nodeBuffer[right-'A'];
    }
    preOrder(&nodeBuffer[0]);
    cout<<'\n';
    midOrder(&nodeBuffer[0]);
    cout<<'\n';
    postOrder(&nodeBuffer[0]);
    return 0;
}//Linked_List , Tree