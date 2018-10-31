#include <stdlib.h> 
#include <stdio.h> 
#include <iostream> 
#include <stack> 
  
using namespace std; 
  
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
struct node* newNode(int data) 
{ 
    struct node* node = new struct node; 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
} 
  

void parallel_dfs(node *root)
{

		if(root == NULL)
			return;
			
			
		stack<node*> s;
		s.push(root);
		node *temp;
		
		while (!s.empty()) 
		{
			#pragma omp parallel for
			{
			
				#pragma omp critical
				{
				  temp = s.top();			
				  cout<<"  "<<temp->data;
				  s.pop();  
				
				}
				#pragma omp critical
				{
				if(temp->right)
					s.push(temp->right);
				if(temp->left)
					s.push(temp->left);
				}		

			}
		}

}

  
int main() 
{ 
  struct node *root = newNode(10); 
  root->left        = newNode(8); 
  root->right       = newNode(2); 
  root->left->left  = newNode(3); 
  root->left->right = newNode(5); 
  root->right->left = newNode(2); 
  parallel_dfs(root);
  cout<<"\n";
  return 0; 
} 


