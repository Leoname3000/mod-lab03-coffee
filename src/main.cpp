// Copyright 2022 UNN-IASR

#include <iostream>
#include "Automata.h"

int main() {
    Automata automata;
    std::cout << "Current state is: " << automata.getStateString() << "\n";

    automata.on();
    std::cout << std::endl << automata.getMenu() << std::endl;
    std::cout << "Current state is: " << automata.getStateString() << "\n\n";

    automata.coin(45);
    std::cout << "Current state is: " << automata.getStateString() << "\n\n";

    automata.choice(3);
    std::cout << "Current state is: " << automata.getStateString() << "\n\n";

    automata.choice(9);
    std::cout << "Current state is: " << automata.getStateString() << "\n\n";

    automata.coin(10);
    std::cout << "Current state is: " << automata.getStateString() << "\n\n";

    automata.choice(3);
    std::cout << "Current state is: " << automata.getStateString() << "\n\n";

    automata.off();
    std::cout << "Current state is: " << automata.getStateString() << "\n";
    return 0;
}
