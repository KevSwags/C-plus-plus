#include <iostream>
using namespace std;

int main() {

    int exercises;
    int score=0;
    int total=0;
    double score_total=0;
    double total_points=0;

    cout << "How many exercises to input: ";
    cin >> exercises;

    for(int i=1; i<= exercises; i++) {
        cout << "Score received for exercise " << i << ": ";
        cin >> score; 
        cout << "Total points possible for exercise " << i << ": ";
        cin >> total;

        score_total = score_total + score;
        total_points = total_points + total;
    }

    cout << "Your total is " << score_total << " out of " << total_points << ", or " <<  (score_total/total_points)*100 << endl;

    return 0;
}