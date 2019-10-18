#include <iostream>
#include "display.h"


int main(int argc , char** argv) {

    Engine::Display display("Display" , 800 , 600);

    while(!display.is_close()) {
        display.update();
        display.process_input();
        display.clear();
    }
}
