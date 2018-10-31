#include<iostream>
#include<stdlib.h>
#include<queue>
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

void parallel_bfs(node *head)
{

		queue<node*> q;
		q.push(head);
		
		int f;
		
		while (!q.empty()) 
		{
			f = q.size();
			#pragma omp parallel for
			for (int i = 0; i < f ; i++) 
			{
				node* temp ;
				#pragma omp critical
				{
				  temp = q.front();
				  q.pop();
				  cout<<"  "<<temp->data;
				
				}
				#pragma omp critical
				{
				if(temp->left)
					q.push(temp->left);
				if(temp->right)
					q.push(temp->right);
				}		

			}
		}

}
 
int main() 
{ 
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(5); 
  root->left->right = newNode(6); 
  root->right->left = newNode(4); 
  parallel_bfs(root);
  cout<<"\n";
  return 0; 
} 
