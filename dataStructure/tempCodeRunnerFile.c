void freeTree(node *root)
{
    if(root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    freeTree(root);
}