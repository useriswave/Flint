// #include "../include/buffer.hpp"
// #include "../include/filehandler.hpp"
#include "../include/app.hpp"


#include <iostream>
#include <vector>

int main()
{
    App app{};
    app.start();
}

// int main()
// {
    // std::vector<std::string> lines{};
    // FileHandler fh{};
// 
    // // OPENING THE FILE AND COPYING CONTENT TO LINES
    // {
        // try {
            // fh.openAndRead("/home/wave/projects/cpp/feet/tests/test.txt", lines);
        // } catch (const std::runtime_error& e) {
            // std::cout << e.what() << '\n';
        // }
// 
        // for (const auto& line : lines) {
            // std::cout << line << '\n';
        // }
    // }
// 
    // {
        // lines.emplace_back("\nHello world this is a test!\nabcd");
// 
        // try {
            // fh.save(lines);
        // } catch (const std::runtime_error& e) {
            // std::cout << e.what() << '\n';
        // }
    // }
// }
