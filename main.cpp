#include <iostream>
#include "ShPtr.h"

Toy* make_shared_toy(std::string name){
    Toy* a = new Toy(name);
    return a;
}

Toy* make_shared_toy(Toy& toy){
    Toy* a = new Toy(toy.name);
    return a;
}

int main() {
    Toy *a = make_shared_toy("Ball");
    Toy *b = make_shared_toy(*a); //ball
    Toy *c = make_shared_toy("Clown");

    shared_ptr_toy* a_ptr = new shared_ptr_toy(c);
    shared_ptr_toy* a_ptr_2 = new shared_ptr_toy(*a_ptr);
    shared_ptr_toy a_ptr_3(b);
    shared_ptr_toy a_ptr_4(a_ptr_3);

    a_ptr->Show();		// clown
    a_ptr_2->Show();	// clown
    a_ptr_3.Show();	// ball
    a_ptr_4.Show();	// ball

    a_ptr->reset();

    a_ptr->Show();
    a_ptr_2->Show();
    a_ptr_3.Show();
    a_ptr_4.Show();

    a_ptr_3.reset();

    a_ptr->Show();
    a_ptr_2->Show();
    a_ptr_4.Show();

    std::cout << "the end" << std::endl;
    return 0;
}