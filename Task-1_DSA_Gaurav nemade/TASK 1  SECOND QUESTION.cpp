/*

	1. To declare a priority queue & push all the elements in it.
	2. While (below steps will be inside loop) the number of elements in minimum heap is > 1. 
        3. To extract the minimum and second minimum from minimum heap.
        4. To add the above 2 values and insert to the minimum heap.
        5. create variable for total cost and keep incrementing it by the sum of extracted values.
	6. Last step is - To return the value of total cost.
*/
 

#include <bits/stdc++.h> 
using namespace std;

int minimumCost(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int> > pqObj(arr, arr + n);
 
	int total_cost = 0;

	//loop until priority queue size is reach to 1
	while (pqObj.size() > 1) {
		//get minimum 
		int first = pqObj.top();
		pqObj.pop();
        //get 2nd minimum
		int second = pqObj.top();
		pqObj.pop();
 
		//and then connect to the ropes. update result
		total_cost += first + second;
		//and then add the new rope to priority queue
		pqObj.push(first + second);
	}

    //return the total cost
	return total_cost;
}
 
int main()
{
    int len[] = { 4, 3, 2, 6 };
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Output: Total cost for connecting ropes will be: " << minimumCost(len, size);
    return 0;
}