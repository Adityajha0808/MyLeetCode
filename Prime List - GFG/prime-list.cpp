//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int n){
        val=n;
        next=NULL;
    }
};

*/

class Solution{
public:
    
    bool isPrime(int n) {
        if(n <= 1) return false;
        if(n <= 3) return true;
        if(n%2 == 0 or n%3 == 0) return false;
        for(int i=5; i*i <= n; i += 6)
            if(n%i == 0 or n%(i + 2) == 0)
                return false;
        return true;
    }
    
    Node* primeList(Node* head) {
        Node* temp = head;
        while(temp) {
            int n = temp->val, n1, n2;
            n1 = n2 = n;
            if(n == 1) {
                temp->val = 2;
                temp = temp->next;
                continue;
            }
            while(!isPrime(n1)) n1--;
            while(!isPrime(n2)) n2++;
            temp->val = (n-n1 > n2-n ? n2 : n1);
            temp = temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends