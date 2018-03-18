#include <iostream>
#include "main_lib.h"
#include "human_tree.h"
#include <thread>
#include <chrono>
#include <vector>
#include "dark_fraction.h"
void thread_for_energy_change()
{
    while(true) {
        if(energy::energy_of_player > 100)
            return;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        energy::increase_energy(generator_of_energy::how_many*10);
        std::cout << energy::energy_of_player << std::endl;
    }
}

int main() {
    std::vector <main_unit *> a(2);
    a[0] = new human_main_unit;
    a[1] = new dark_main_unit;
    a[0]->who_am_i();
    a[1]->who_am_i();
    delete a[0];
    delete a[1];
    return 0;
}