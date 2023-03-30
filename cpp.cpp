#include <unistd.h>
#include <gpiod.hpp>
#include <iostream>

extern "C" void cppmain(void) {
    ::gpiod::chip chip("gpiochip0");

    auto line = chip.get_line(23);  // GPIO23
    line.request({"example", gpiod::line_request::DIRECTION_OUTPUT, 0}, 1);

    for (auto i: {200000, 500000, 200000, 1600000, 700000}) {
        std::cout << "Line 23, signal period: " << i << "us" << std::endl;
        line.set_value(0);
        usleep(i);
        line.set_value(1);
        usleep(i);
    }
    line.release();
}