#include <iostream>

int main() {

    int cokeVotes = 0;
    int pepsiVotes = 0;

    char input;

    while (true) {
        std::cout << "Preference? ";
        std::cin >> input;

        if (input == 'q' || input == 'Q') {
            break;
        }

        if (input == 'c' || input == 'C') {
            cokeVotes++;
        }

        if (input == 'p' || input == 'P') {
            pepsiVotes++;
        }
    }

    if (pepsiVotes > cokeVotes) {
        std::cout << "Pepsi Wins";
    } else if (cokeVotes > pepsiVotes) {
        std::cout << "Coke Wins";
    } else {
        std::cout << "TIE!";
    }

    return 0;
}