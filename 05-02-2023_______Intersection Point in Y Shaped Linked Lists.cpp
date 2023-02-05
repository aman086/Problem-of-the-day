//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    int solve(Node* root1 , Node* root2){
        if(root1==NULL || root2==NULL)
           return -1;
         if(root1 == root2)
            return root1->data;
          return solve(root1->next , root2->next);
          
    }
    int getLength(Node* root){
        int l = 0;
        while(root!=NULL){
            root = root->next;
            l++;
        }
        return l;
    }
    int intersectPoint(Node* head1, Node* head2)
    {
          int size1 = getLength(head1);
          int size2 = getLength(head2);
          if(size1>size2){
            //   Node* head
                int diff = size1 - size2;
                while(diff--){
                    head1 = head1->next;
                }
          }
          if(size2>size1){
              int diff = size2 - size1;
                while(diff--){
                    head2 = head2->next;
                }
          }
          return solve(head1 , head2);
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends
