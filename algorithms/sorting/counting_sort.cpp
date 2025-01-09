#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> countingSort(vector<int>& initialVector) {
    int n = initialVector.size();

    int k = *max_element(initialVector.begin(), initialVector.end());
    
    vector<int> cnt(k + 1, 0);
    
    for (int i = 0; i < n; i++) cnt[initialVector[i]]++;
    
    for (int i = 1; i <= k; i++) cnt[i] += cnt[i - 1];
    
    vector <int> sortedVector(n);
    
    for (int i = n - 1; i >= 0; i--) sortedVector[--cnt[initialVector[i]]] = initialVector[i];
    
    return sortedVector;
}