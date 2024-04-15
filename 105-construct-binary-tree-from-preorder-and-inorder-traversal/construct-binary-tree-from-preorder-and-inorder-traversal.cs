/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public TreeNode calc(Dictionary<int, int> Inorder, int[] preorder, int l, int r, ref int ind)
    {
    int n = preorder.Count();
    if(ind==n || l>r)
        return null;
    else
    {
        int pos = Inorder[preorder[ind]];
        TreeNode root=new TreeNode();
        root.val=preorder[ind];
        ind++;
        root.left=calc(Inorder, preorder, l, pos-1, ref ind);
        root.right=calc(Inorder, preorder, pos+1, r, ref ind);
        return root;
    }
    }
    public TreeNode BuildTree(int[] preorder, int[] inorder) {
        Dictionary<int, int> Inorder = new Dictionary<int, int>();
        int n = inorder.Count();

        for(int i=0; i<n; i++)
        {
           Inorder[inorder[i]]=i;
        }
        int ind=0;
        return calc(Inorder, preorder, 0, n-1, ref ind);
    }
}