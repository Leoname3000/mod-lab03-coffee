#include <iostream>
#include "Automata.h"

Automata::Automata() {
    cash = 0;
    menu = {"Espresso", "Cappuccino", "Latte", "Hot Chocolate", "Double Chocolate", "Hot Water"};
    prices = {60, 65, 70, 50, 75, 20};
    state = OFF;
}

void Automata::on() {
    if (state != OFF) return;
    if (menu.size() != prices.size()) {
        cout << "Incorrect menu/prices info" << endl;
        return;
    }
    cout << endl << "Starting up..." << endl;
    state = WAIT;
}
void Automata::off() {
    if (state != WAIT) return;
    cout << "Shutting down..." << endl;
    state = OFF;
}
void Automata::coin(unsigned int amount) {
    if (state != WAIT && state != ACCEPT) return;
    state = ACCEPT;
    cash += amount;
    cout << "Balance: " << cash << endl;
}
void Automata::cancel() {
    if (state != ACCEPT) return;
    state = WAIT;
    change();
}
void Automata::change() {
    if (state != WAIT) return;
    cout << "Your change: " << cash << endl;
    cash = 0;
}
void Automata::choice(unsigned int id) {
    if (state != ACCEPT) return;
    state = CHECK;
    check(id);
}
void Automata::check(unsigned int id) {
    if (state != CHECK) return;
    if (id >= prices.size()) {
        cout << "No item with id " << id << endl;
        state = ACCEPT;
    }
    else if (cash < prices[id]) {
        cout << "Not enough balance" << endl;
        state = ACCEPT;
    }
    else {
        cash -= prices[id];
        cook(id);
    }
}
void Automata::cook(unsigned int id) {
    cout << "Cooking " << menu[id] << "..." << endl;
    state = COOK;
    finish();
}
void Automata::finish() {
    if (state != COOK) return;
    cout << "Your drink is ready!" << endl;
    state = WAIT;
    if (cash > 0) change();
}

string Automata::getMenu() {
    string result;
    for (size_t i = 0; i < menu.size(); i++) {
        result += menu[i] + " - " + to_string(prices[i]) + "\n";
    }
    return result;
}
string Automata::getStateString() {
    switch (state) {
        case OFF: return "Off";
        case WAIT: return "Wait";
        case ACCEPT: return "Accept";
        case CHECK: return "Check";
        case COOK: return "Cook";
    }
}
Automata::STATES Automata::getState() {
    return state;
}
