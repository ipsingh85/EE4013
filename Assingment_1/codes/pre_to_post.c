#include<stdio.h>
#include<limits.h>



// traversal of BST from preorder traversal

 
// Function to find postorder traversal from
// preorder traversal.
void findPostOrderUtil(int pre[], int n, int minval,
                       int maxval, int* preIndex)
{
 
    // If entire preorder array is traversed then
    // return as no more element is left to be
    // added to post order array.
    if (*preIndex == n)
        return;
 
    // If array element does not lie in range specified,
    // then it is not part of current subtree.
    if (pre[*preIndex] < minval || pre[*preIndex] > maxval) {
        return;
    }
 
    // Store current value, to be printed later, after
    // printing left and right subtrees. Increment
    // preIndex to find left and right subtrees,
    // and pass this updated value to recursive calls.
    int val = pre[*preIndex];
    *preIndex=*preIndex+1;
 
    // All elements with value between minval and val
    // lie in left subtree.
    findPostOrderUtil(pre, n, minval, val, preIndex);
 
    // All elements with value between val and maxval
    // lie in right subtree.
    findPostOrderUtil(pre, n, val, maxval, preIndex);
 
    
    printf(" %d",val);
}
 
// Function to find postorder traversal.
void findPostOrder(int pre[], int n)
{
 
    // To store index of element to be
    // traversed next in preorder array.
    // This is passed by reference to
    // utility function.
    //int preIndex;
    int preIndex= 0;
 
    findPostOrderUtil(pre, n, INT_MIN, INT_MAX, &preIndex);
    
}
 
// Driver code
int main(void)
{
    //int pre[] = { 15,10,12,11,20,18,16,19 };
    //different size tree
    //int pre[]={7, 5, 3, 6, 9};//for size of 5
    int pre[]={15,10,8,6,9,12,20,16,25,24,26};//size of 11 
    //postorder of this tree is 6,9,8,12,10,16,24,26,25,20,15
    int n = sizeof pre / sizeof pre[0];
 
    // Calling function
    findPostOrder(pre, n);
    return 0;
}
