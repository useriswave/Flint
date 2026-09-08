#include "app/App.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    if (argc == 2) {
        try {
            App app{ argv[1] };
            app.start();
        } catch (const std::exception& e) {
            std::cout << e.what();
        }
    } else {
        std::cout << "Please enter a file path.\n";
    }
}
