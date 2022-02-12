#include <iostream>
#include "ShPtr.h"

 Toy* make_shared_toy(std::string name)
 {
    return new Toy(name);
 }

 Toy* make_shared_toy(Toy& toy){
    return new Toy(toy.name);
}

int main() {

    shared_ptr_toy sharedPtrToy(new Toy("Ball_1")); // #1
    {
        shared_ptr_toy shptr = make_shared_toy("Bone"); // #2
        shared_ptr_toy shptr2 = make_shared_toy(*shptr.GetPtr()); //#3 bone

        std::cout << shptr2.GetPtr()->name << std::endl;
        shared_ptr_toy sharedPtrToy4(sharedPtrToy); //#4 = Ball1
        std::cout << sharedPtrToy4.GetPtr()->name << std::endl;
        std::cout << sharedPtrToy.Count() << std::endl;

        {
            shared_ptr_toy sharedPtrToy5(new Toy("Duck")); //#5
            std::cout << sharedPtrToy.Count() << std::endl;
            {
                shared_ptr_toy sharedPtrToy6(new Toy("Dog")); //#6
                shared_ptr_toy sharedPtrToy7 = sharedPtrToy5; // #7 Duck
                std::cout << sharedPtrToy7.GetPtr()->name << std::endl;
                std::cout << sharedPtrToy.Count() << std::endl;
            }
            std::cout << sharedPtrToy.Count() << std::endl;
        }
        std::cout << sharedPtrToy.Count() << std::endl;
    }
    std::cout << sharedPtrToy.Count() << std::endl;
    return 0;
}