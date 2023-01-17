void inorder(BinaryTreeNode* root,vector<int> &in){
    if(root==NULL)
        return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
void preorder(BinaryTreeNode* &root,vector<int> in,int &i){
    if(root==NULL)
        return;
    root->data=in[i];
    i=i+1;
    preorder(root->left,in,i);
    preorder(root->right,in,i);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> in;
    inorder(root,in);
    int i=0;
    int size=in.size();
    preorder(root,in,i);
    return root;
    
}
