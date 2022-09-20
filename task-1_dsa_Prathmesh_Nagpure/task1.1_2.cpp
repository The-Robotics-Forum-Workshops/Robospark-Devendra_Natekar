/*

2. Given “n” ropes of different lengths, connect them into a single rope with 
minimum cost. Assume that the cost to connect two ropes is the same as the 
sum of their lengths.

Algorithm:
Insert all given elements in the min heap, to get the minimum 2 ropes which can be joined and are pushed again to the min heap 
where they are added again until the heap is empty, thus minimum cost is obtained

*/

#include<bits/stdc++.h>
using namespace std;

int findMinimumCost(int arr[], int n) {
   priority_queue< int, vector<int>, greater<int>>queue(arr, arr+n);

   int minCost = 0;

   while (queue.size() > 1) {              
      int item1 = queue.top();            
      queue.pop();

      int item2 = queue.top();          
      queue.pop();

      minCost += item1 + item2;         
      queue.push(item1 + item2);
   }
   return minCost;
}

int main() {
   int ropeLength[] = {4, 3, 2, 6, 5, 7, 12};
   int n = 7;
   cout << "Total minimum cost: " << findMinimumCost(ropeLength, n);
}