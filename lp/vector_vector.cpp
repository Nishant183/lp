#include <iostream>
#include<vector>    
#include <omp.h>      

using namespace std;

int main () 
{
	vector<int> v1,v2;
        
        int n = 8; 
	int c[n];                
	
	int i;      
                for(i=0; i<n; i++) {
            v1.push_back(i);
		v2.push_back(i);
        }
        
      
		
        #pragma omp parallel for shared(v1, v2, c) private(i) 
        for(i=0; i<n; i++) {
		c[i] = v1[i]+v2[i];
		        }
	
        for(i=0; i<n; i++) {
		cout<<c[i]<<" ";
        }
		
	return 0;
}