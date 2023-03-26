#include <iostream>
#include "Automata.h"

using namespace std;

int main() {
    Automata automata;
    cout << "Current state is: " << automata.getStateString() << endl;

    automata.on();
    cout << endl << automata.getMenu() << endl;
    cout << "Current state is: " << automata.getStateString() << endl << endl;

    automata.coin(45);
    cout << "Current state is: " << automata.getStateString() << endl << endl;

    automata.choice(3);
    cout << "Current state is: " << automata.getStateString() << endl << endl;

    automata.choice(9);
    cout << "Current state is: " << automata.getStateString() << endl << endl;

    automata.coin(10);
    cout << "Current state is: " << automata.getStateString() << endl << endl;

    automata.choice(3);
    cout << "Current state is: " << automata.getStateString() << endl << endl;

    automata.off();
    cout << "Current state is: " << automata.getStateString() << endl;
    return 0;
}