#include <iostream>
#include "display.h"


int main(int argc , char** argv) {

    Engine::Display display("Display" , 800 , 600);
    display.run();

}
