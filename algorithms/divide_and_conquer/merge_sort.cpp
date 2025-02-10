#include <vector>
using namespace std;

vector<int> mergeSort(vector<int> &v) {
    vector<int> v1, v2;
    
    int n = v.size();
    
    if (n == 1) return v;
    
    for (int i = 0; i < n/2; i++) v1.push_back(v[i]);
    for (int i = n/2; i < n; i++) v2.push_back(v[i]);
    
    mergeSort(v1);
    mergeSort(v2);
    
    int n1 = v1.size(), n2 = v2.size();
    
    int i = 0, j = 0, k = 0;
    
    for (i = 0; i < n && j < n1 && k < n2; i++) {
        if (v1[j] > v2[k]) {
            v[i] = v2[k++];
        } else {
            v[i] = v1[j++];
        }
    }
    
    while (j < n1) v[i++] = v1[j++];
    
    while (k < n2) v[i++] = v2[k++];
    
    return v;
}