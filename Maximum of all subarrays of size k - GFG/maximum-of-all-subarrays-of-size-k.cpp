//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector <int> res;
        deque<int> q;
        
        int i = 0;
        
        //iterating over first k elements or first window of array.
        for(i = 0;i<k;i++)
        {
            //for every element, the previously smaller elements 
            //are useless so removing them from deque.
            while((!q.empty()) && (arr[i] >= arr[q.back()]))
                q.pop_back();
            
            //adding new element at back of deque.   
            q.push_back(i);
            
        }
        
        //iterating over the rest of the elements.
        for(;i<n;i++)
        {
            //the element at the front of the deque is the largest 
            //element of previous window, so adding it to the list.
            res.push_back (arr[q.front()]);
            
            //removing the elements which are out of this window.
            while((!q.empty()) && (q.front() <= i-k))
            q.pop_front();
            
            //removing all elements smaller than the element being  
            //added currently (removing useless elements).
            while((!q.empty()) && (arr[i] >= arr[q.back()])) 
            q.pop_back();
            
            //adding new element at back of deque. 
            q.push_back(i);
            
        }
        
        //the element at the front of the deque is the largest 
        //element of last window, so adding it to the list.
        res.push_back (arr[q.front()]);
        q.pop_front();
        
        //returning the list.
        return res;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends