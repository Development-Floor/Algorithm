#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
    int A = 0;
    int P = 0;
    
    cin >> A >> P;
    
    unordered_map<int, int> map;
    
    int number = 0;
    
    for (int i = 0; map.find(A) == map.end(); i++) {
        map[A] = i;
        number = 0;
        
        while (A > 0) {
            number = number + pow(A % 10, P);
            A /= 10;
        }
        
        A = number;
    }
    
    cout << map[A] << endl;
    
    return 0;
}