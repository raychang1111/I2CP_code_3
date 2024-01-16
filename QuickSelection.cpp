// Selection in expected linear time    平均在線性時間中找第i大值       但最差還是n^2
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/   
// /*
#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <random>
using namespace std;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int quickSelection(vector<int> &arr,int l,int r,int t){
    // cout<<"-----------------------"<<endl;
    // cout<<"t :"<<t<<endl;
    // for(int i=l;i<=r;i++)
    //     cout<<arr[i]<<' ';
    // cout<<endl;
    if(l==r)
        return arr[l];
    int mptr=gen()%(r-l+1)+l;
    // -----------------------------------分割----------------------------------
    queue<int> q1,q2,q3;
    for(int i=l;i<=r;i++){
        if(arr[i]==arr[mptr])
            q2.push(arr[i]);
        else if(arr[i]>arr[mptr])
            q1.push(arr[i]);
        else
            q3.push(arr[i]);
    }
    int m=(q2.size()-1)/2+q1.size()+l;
    for(int i=l;i<=r;i++){
        if(!q1.empty()){
            arr[i]=q1.front();
            q1.pop();
        }
        else if(!q2.empty()){
            arr[i]=q2.front();
            q2.pop();
        }
        else{
            arr[i]=q3.front();
            q3.pop();
        }
    }
    /*        
    // -------------------------------另一種分割---------------------------------------
    swap(arr[mptr],arr[r]);
    int i=l,j=r-1;
    while(i<=j){
        if(arr[i]>=arr[r])
            i++;
        else{
            swap(arr[i],arr[j]);
            j--;
        }
    }
    swap(arr[i],arr[r]);
    int m=i;
    // -------------------------------------------------------------------------
    */
    // for(int i=l;i<=r;i++)
    //     cout<<arr[i]<<' ';
    // cout<<endl;
    // cout<<"i :"<<i<<endl;
    if(m+1==t)
        return arr[m];
    if(m+1>t)
        return quickSelection(arr,l,m-1,t);
    else    
        return quickSelection(arr,m+1,r,t);
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<quickSelection(arr,0,arr.size()-1,t)<<endl;
    return 0;
}
// */



/*              網路抄來的
// CPP program for implementation of QuickSelect 
#include <bits/stdc++.h> 
using namespace std; 

// Standard partition process of QuickSort(). 
// It considers the last element as pivot 
// and moves all smaller element to left of 
// it and greater elements to right 
int partition(int arr[], int l, int r) 
{ 
	int x = arr[r], i = l; 
	for (int j = l; j <= r - 1; j++) { 
		if (arr[j] >= x) { 
			swap(arr[i], arr[j]); 
			i++; 
		} 
	} 
	swap(arr[i], arr[r]); 
	return i; 
} 

// This function returns k'th smallest 
// element in arr[l..r] using QuickSort 
// based method. ASSUMPTION: ALL ELEMENTS 
// IN ARR[] ARE DISTINCT 
int quickSelection(int arr[], int l, int r, int k) 
{ 
	// If k is smaller than number of 
	// elements in array 
	if (k > 0 && k <= r - l + 1) { 

		// Partition the array around last 
		// element and get position of pivot 
		// element in sorted array 
		int index = partition(arr, l, r); 

		// If position is same as k 
		if (index - l == k - 1) 
			return arr[index]; 

		// If position is more, recur 
		// for left subarray 
		if (index - l > k - 1) 
			return quickSelection(arr, l, index - 1, k); 

		// Else recur for right subarray 
		return quickSelection(arr, index + 1, r, 
							k - index + l - 1); 
	} 

	// If k is more than number of 
	// elements in array 
	return INT_MAX; 
} 

// Driver program to test above methods 
int main() 
{ 
	int arr[] = {1,8,9,3,4,6,7,7}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 4; 
	cout << quickSelection(arr, 0, n - 1, k); 
	return 0; 
} 

*/