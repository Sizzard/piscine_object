#include "Bank.hpp"

Bank::Bank(int liquidity) : liquidity(liquidity) {

}

void Bank::createAccount(int id, int value) {  // throw if id already exists
    if (clientAccounts.find(id) != clientAccounts.end()) {
        throw std::invalid_argument("Account with id already exists");
    }

    Account newAccount;
    newAccount.id = id;
    newAccount.value = value;

    clientAccounts[id] = newAccount;
}

void Bank::deleteAccount(int id) { // throw if id doesn't exists
    if (clientAccounts.find(id) == clientAccounts.end()) {
        throw std::invalid_argument("Invalid account id to delete");
    }
    clientAccounts.erase(id);
}

int Bank::getLiquidity() {
    return liquidity;
}

void Bank::addLiquidity(int liquidityToAdd) {
    liquidity += liquidityToAdd;
}

void Bank::addMoneyToAccount(int valueToAdd, int id) { // throw if id doesn't exists
    if (clientAccounts.find(id) == clientAccounts.end()) {
        throw std::invalid_argument("Invalid account id to add money to");
    }
    if (valueToAdd >= 0) {
        liquidity += valueToAdd * 0.05;
        clientAccounts[id].value += valueToAdd * 0.95;
    }
    else {
        clientAccounts[id].value += valueToAdd;
    }
}