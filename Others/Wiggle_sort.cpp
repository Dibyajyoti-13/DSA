// https://www.naukri.com/code360/problems/wiggle-sort_3155169?leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h> 
vector<int> wiggleSort(int n, vector<int> arr) {
    // Write your code here.
    for(int i = 0; i < n - 1; i++){
        if((i&1) == (arr[i] < arr[i + 1]))
        swap(arr[i], arr[i + 1]);
    }
    return arr;
}
