using namespace std;

long long binaryExponentiation(long long a, long long b) {
    if (b == 0) return 1;

    long long currValue = binaryExponentiation(a, b / 2);

    // In case current exp is even
    if (b % 2 == 0) return currValue * currValue;

    // In case current exp is odd
    return currValue * currValue * a; 
}