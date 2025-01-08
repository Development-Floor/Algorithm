#include <iostream>

using namespace std;

int main(void) {
    int col = 0;
    int row = 0;
    
    cin >> col >> row;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << '*';
        }
        
        cout << endl;
    }
    
    return 0;
}