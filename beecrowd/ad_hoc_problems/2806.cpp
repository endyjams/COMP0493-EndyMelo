#include <bits/stdc++.h>
using namespace std;

unordered_set<string> typicalIngredients;
unordered_map<string, vector<string>> portions;
unordered_map<string, bool> isATypicalPortion;

bool isTypical(string portion) {
    if (isATypicalPortion.find(portion) != isATypicalPortion.end()) return isATypicalPortion[portion];

    vector <string> components = portions[portion];
    int typicalCount = 0;

    for (string component : components) {
        if (typicalIngredients.find(component) != typicalIngredients.end() ||
            (portions.find(component) != portions.end() && isTypical(component))) {
            typicalCount++;
        }
    }
    
    return isATypicalPortion[portion] = typicalCount > components.size() / 2;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        string ingredient; cin >> ingredient;
        
        typicalIngredients.insert(ingredient);
    }

    int M; cin >> M;

    vector<string> portionsOrder(M);
    for (int i = 0; i < M; i++) {
        string portionName; cin >> portionName;
        int K; cin >> K;

        vector<string> components(K);
        for (int j = 0; j < K; j++) cin >> components[j];

        portions[portionName] = components;
        portionsOrder[i] = portionName;
    }

    for (const auto p : portionsOrder) {
        if (isTypical(p)) {
            cout << "porcao tipica" << endl;
        } else {
            cout << "porcao comum" << endl;
        }
    }

    return 0;
}