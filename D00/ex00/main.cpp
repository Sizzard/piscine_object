#include "Bank.hpp"

int main()
{

    try {
        Bank bank = Bank(999);
        bank.createAccount(0, 100);
        bank.createAccount(1, 100);

        std::cout << "ID is : " <<  bank[0].getId() <<  ", Value is : " <<  bank[0].getValue()  << std::endl;

        bank.addLiquidity(-200);
        bank.addMoneyToAccount(400, 0);

        std::cout << "Bank : " << std::endl;
        std::cout << bank << std::endl;
    }
    catch(const std::invalid_argument& e) {
        std::cerr << "Error thrown : " << e.what() << std::endl;
    }

	return (0);
}
