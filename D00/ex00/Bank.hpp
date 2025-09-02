#pragma once

#include <iostream>
#include <vector>
#include <map>



class Bank
{
    private:

        typedef struct s_Account {
            int id;
            int value;
            int getId(){
                return id;
            };
            int getValue(){
                return value;
            };
        }   Account;

        int liquidity;
        std::map<int, Account> clientAccounts;

    public:
        Bank(int liquidity);

        void createAccount(int id, int value);
        void deleteAccount(int id);
        int getLiquidity();
        void addLiquidity(int newLiquidity);
        void addMoneyToAccount(int valueToAdd, int id);

        Account& operator[](size_t idx) {
            if (clientAccounts.find(idx) == clientAccounts.end()){
                throw std::invalid_argument("Invalid account id");
            }
            return clientAccounts[idx];
        }

        friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
        {
            p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
            return (p_os);
        }

        friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
        {
            p_os << "Bank informations : " << std::endl;
            p_os << "Liquidity : " << p_bank.liquidity << std::endl;
            for (std::map<int, Account>::const_iterator it = p_bank.clientAccounts.begin(); it != p_bank.clientAccounts.end(); it++) {
                p_os << it->second << std::endl;
            }
            return (p_os);
        }


};