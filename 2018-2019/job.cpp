// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<iostream> 
#include<algorithm> 
using namespace std; 
  
// A structure to represent a job 
struct Job 
{ 
   char id;      // Job Id 
   int dead;    // Deadline of job 
   int profit;  // Profit if job is over before or on deadline 
}; 
  
// This function is used for sorting all jobs according to profit 
bool comparison(Job a, Job b) { 
     return (a.profit > b.profit); 
} 
  
// Returns minimum number of platforms reqquired 
void printJobScheduling(Job arr[], int n) 
{ 
    // Sort all jobs according to decreasing order of prfit 
    sort(arr, arr+n, comparison); 
  
    int result[n]; // To store result (Sequence of jobs) 
    bool slot[n];  // To keep track of free time slots 
  
    // Initialize all slots to be free 
    for (int i=0; i<n; i++) 
        slot[i] = false; 
  
    // Iterate through all given jobs 
    for (int i=0; i<n; i++) 
    { 
       // Find a free slot for this job (Note that we start 
       // from the last possible slot) 
       for (int j=min(n, arr[i].dead)-1; j>=0; j--) 
       { 
          // Free slot found 
          if (slot[j]==false) 
          { 
             result[j] = i;  // Add this job to result 
             slot[j] = true; // Make this slot occupied 
             break; 
          } 
       } 
    } 
  
    // Print the result 
    for (int i=0; i<n; i++) 
       if (slot[i]) 
         cout << arr[result[i]].id << " "; 
} 
  
// Driver program to test methods 
int main() 
{ 
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
                   {'d', 1, 25}, {'e', 3, 15}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Following is maximum profit sequence of jobsn"; 
    printJobScheduling(arr, n); 
    return 0; 
} 



// C++ Program to find the maximum profit job sequence  
// from a given array of jobs with deadlines and profits 
#include<bits/stdc++.h> 
using namespace std; 
  
// A structure to represent various attributes of a Job 
struct Job 
{ 
    // Each job has id, deadline and profit 
    char id; 
    int deadLine, profit; 
}; 
  
// A Simple Disjoint Set Data Structure 
struct DisjointSet 
{ 
    int *parent; 
  
    // Constructor 
    DisjointSet(int n) 
    { 
        parent = new int[n+1]; 
  
        // Every node is a parent of itself 
        for (int i = 0; i <= n; i++) 
            parent[i] = i; 
    } 
  
    // Path Compression 
    int find(int s) 
    { 
        /* Make the parent of the nodes in the path 
           from u--> parent[u] point to parent[u] */
        if (s == parent[s]) 
            return s; 
        return parent[s] = find(parent[s]); 
    } 
  
    // Makes u as parent of v. 
    void merge(int u, int v) 
    { 
        //update the greatest available 
        //free slot to u 
        parent[v] = u; 
    } 
}; 
  
// Used to sort in descending order on the basis 
// of profit for each job 
bool cmp(Job a, Job b) 
{ 
    return (a.profit > b.profit); 
} 
  
// Functions returns the maximum deadline from the set 
// of jobs 
int findMaxDeadline(struct Job arr[], int n) 
{ 
    int ans = INT_MIN; 
    for (int i = 0; i < n; i++) 
        ans = max(ans, arr[i].deadLine); 
    return ans; 
} 
  
int printJobScheduling(Job arr[], int n) 
{ 
    // Sort Jobs in descending order on the basis 
    // of their profit 
    sort(arr, arr + n, cmp); 
  
    // Find the maximum deadline among all jobs and 
    // create a disjoint set data structure with 
    // maxDeadline disjoint sets initially. 
    int maxDeadline = findMaxDeadline(arr, n); 
    DisjointSet ds(maxDeadline); 
  
    // Traverse through all the jobs 
    for (int i = 0; i < n; i++) 
    { 
        // Find the maximum available free slot for 
        // this job (corresponding to its deadline) 
        int availableSlot = ds.find(arr[i].deadLine); 
  
        // If maximum available free slot is greater 
        // than 0, then free slot available 
        if (availableSlot > 0) 
        { 
            // This slot is taken by this job 'i' 
            // so we need to update the greatest  
            // free slot. Note that, in merge, we  
            // make first parameter as parent of  
            // second parameter. So future queries 
            // for availableSlot will return maximum 
            // available slot in set of  
            // "availableSlot - 1" 
            ds.merge(ds.find(availableSlot - 1),  
                             availableSlot); 
  
            cout << arr[i].id << " "; 
        } 
    } 
} 
  
// Driver program to test above function 
int main() 
{ 
    Job arr[] =  { { 'a', 2, 100 }, { 'b', 1, 19 },  
                   { 'c', 2, 27 },  { 'd', 1, 25 },  
                   { 'e', 3, 15 } }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Following jobs need to be "
         << "executed for maximum profit\n"; 
    printJobScheduling(arr, n); 
    return 0; 
    return 0; 
} 











#include <stdio.h> 
  
int josephus(int n, int k) 
{ 
  if (n == 1) 
    return 1; 
  else
    /* The position returned by josephus(n - 1, k) is adjusted because the 
       recursive call josephus(n - 1, k) considers the original position  
       k%n + 1 as position 1 */
    return (josephus(n - 1, k) + k-1) % n + 1; 
} 
  
// Driver Program to test above function 
int main() 
{ 
  int n = 14; 
  int k = 2; 
  printf("The chosen place is %d", josephus(n, k)); 
  return 0; 
} 






