#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<double> &arr) {
    int n = arr.size();

    if (n == 0) return;

    vector<vector<double>> buckets(n);

    for (int i = 0; i < n; i++) {
        int bucketIndex = static_cast<int>(n * arr[i]);
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) sort(buckets[i].begin(), buckets[i].end());

    int index = 0;

    for (int i = 0; i < n; i++) {
        for (double value : buckets[i]) arr[index++] = value;
    }
}
