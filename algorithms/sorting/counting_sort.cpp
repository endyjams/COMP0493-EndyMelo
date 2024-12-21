#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    
    vector <int> initialVector(n);
    
    for (int i = 0; i < n; i++) cin >> initialVector[i];
    
    int k = *max_element(initialVector.begin(), initialVector.end());
    
    vector <int> cnt(k + 1, 0);
    
    for (int i = 0; i < n; i++) cnt[initialVector[i]]++;
    
    for (int i = 1; i <= k; i++) cnt[i] += cnt[i - 1];
    
    vector <int> sortedVector(n, 0);
    
    for (int i = 0; i < n; i++) sortedVector[--cnt[initialVector[i]]] = initialVector[i];
    
    return 0;
}


/*
fornecer a entrada no formato:
n, onde n é o tamanho do array
seguido pelo array desejado

exemplo de entrada:
5
9 1 4 2 6
*/
