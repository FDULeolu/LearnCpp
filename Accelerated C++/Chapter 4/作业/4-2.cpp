#include <iostream>
#include <vector>
#include <iomanip>

using std::cout;
using std::vector;
using std::endl;

int main(){
    for (int i=1; i<101; i++){
        cout << std::setw(3) << i << " "; 
        cout << std::setw(5) << i * i << endl;
    }
    return 0;
}