#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string> &v) {
    sort(v.begin(), v.end());

    string first = v.front();
    string last = v.back();

    int idx = 0;

    while (idx < first.size() && idx < last.size() && first[idx] == last[idx]) idx++;

    return first.substr(0, idx);
}