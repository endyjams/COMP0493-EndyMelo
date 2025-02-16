#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int> &v, int exp) {
    int n = v.size();
    vector<int> sortedVector(n);
    vector<int> cnt(10, 0);

    for (int i = 0; i < n; i++) cnt[(v[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++) cnt[i] += cnt[i - 1];

    for (int i = n - 1; i >= 0; i--) sortedVector[--cnt[(v[i] / exp) % 10]] = v[i];

    for (int i = 0; i < n; i++) v[i] = sortedVector[i];
}

void radixSort(vector<int> &v) {
    int maxNum = *max_element(v.begin(), v.end());

    for (int exp = 1; maxNum / exp > 0; exp *= 10) countingSort(v, exp);
}