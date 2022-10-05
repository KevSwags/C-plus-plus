#include <iostream>
using namespace std;

void towerOfHanoi(int n, char leaving, char going_to, char remainder)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, leaving, remainder, going_to);
    cout << "Move disk " << n << " from rod " << leaving <<
        " to rod " << going_to << endl;
    towerOfHanoi(n - 1, remainder, going_to, leaving);
}

int main()
{
    int n = 4;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}