/************************************************************************/
/*                                                                      */
/*   kernel.h                                                           */
/*                                                                      */
/*   User defined kernel function. Feel free to plug in your own.       */
/*                                                                      */
/*   Copyright: Alessandro Moschitti                                    */
/*   Date: 20.11.06                                                     */
/*                                                                      */
/************************************************************************/

TKP tree_kernel_params[MAX_NUMBER_OF_TREES]={
{PARTIAL_TREE_KERNEL,PARTIAL_TREE_KERNEL,.4,.4,1,1}, 
{STRING_KERNEL,STRING_KERNEL,.01,.01,1,1}, 
{PARTIAL_TREE_KERNEL,PARTIAL_TREE_KERNEL,.4,.4,1,1},
{PARTIAL_TREE_KERNEL,PARTIAL_TREE_KERNEL,.4,.4,1,1}, 
{STRING_KERNEL,STRING_KERNEL,.4,.4,1,1}, 
{PARTIAL_TREE_KERNEL,PARTIAL_TREE_KERNEL,.4,.4,1,1}};

// implementation 

double custom_kernel(KERNEL_PARM *kernel_parm, DOC *a, DOC *b) 
{

  int i;
  double Poly=0, TK0=0, TK2=0, TK3=0;
  
i=0;    
       TK0  = tree_kernel(kernel_parm, a, b, atoi(kernel_parm->custom), atoi(kernel_parm->custom)); // Evaluate tree kernel between the two i-th trees.

       Poly = basic_kernel(kernel_parm, a, b, i, i); // Compute standard kernel (selected according to the "second_kernel" parameter).

   return Poly +TK0*kernel_parm->tree_constant; // best k1*k2+k2; // 
}
