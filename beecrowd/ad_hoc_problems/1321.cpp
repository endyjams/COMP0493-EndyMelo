#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    vector <int> princessCards(3);
    vector <int> princeCards(2);
    
    while (true) {
        bool hasNumDiffThanZero = false;
        
        for (int i = 0; i < 3; i++) {
            cin >> princessCards[i];
            
            if (princessCards[i]) {
                hasNumDiffThanZero = true;
            }
        }
        
        for (int i = 0; i < 2; i++) {
            cin >> princeCards[i];
            
            if (princeCards[i]) {
                hasNumDiffThanZero = true;
            }
        }
        
        if (!hasNumDiffThanZero) break;
        
        sort(princessCards.begin(), princessCards.end());
        
        bool princeCanWin = false;
        
        for (int c = 1; c <= 52; c++) {
            bool hasAnyCardsEqualToExistingOnes = false;
            for (int k : princessCards) if (k == c) hasAnyCardsEqualToExistingOnes = true;
            for (int k : princeCards) if (k == c) hasAnyCardsEqualToExistingOnes = true;
            
            if (hasAnyCardsEqualToExistingOnes) continue;
            
          vector<int> newPrincessCards = princessCards;
          vector <int> newPrinceCards = princeCards;
          newPrinceCards.push_back(c);
          sort(newPrinceCards.begin(), newPrinceCards.end());
          
          int princessPoints = 0;
          
            for (int i = 2; i >= 0; i--) {
                for (int j = 0; j < 3; j++) {
                    if (newPrincessCards[j] > newPrinceCards[i] && newPrinceCards[i] != 0 && newPrincessCards[j] != 0) {
                        princessPoints++;
                        newPrincessCards[j] = newPrinceCards[i] = 0;
                        break;
                    }
                }
            }
            
            int numberOfTies = 0;
            
            for (int i = 2; i >= 0; i--) {
                for (int j = 0; j < 3; j++) {
                    if (newPrincessCards[j] == newPrinceCards[i] && newPrinceCards[i] != 0 && newPrincessCards[j] != 0) {
                        numberOfTies++;
                        newPrincessCards[j] = newPrinceCards[i] = 0;
                        break;
                    }
                }
            }
            
            if ((princessPoints == 0 && numberOfTies <= 1) || (princessPoints == 1 && numberOfTies == 0)) {
                princeCanWin = true;
                cout << c << '\n';
                break;
            }
        }
        
        if (!princeCanWin) {
            cout << -1 << '\n';
        }
    }
    return 0;
}