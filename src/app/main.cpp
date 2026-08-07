#include "app/App.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    if (argc == 2) {
        try {
            App app{ argv[1] };
            app.start();
        } catch (std::out_of_range& e) {
            std::cout << e.what();
        } catch (std::runtime_error& e) {
            std::cout << e.what();
        }
    } else {
        std::cout << "Please enter a file path.\n";
    }
}
