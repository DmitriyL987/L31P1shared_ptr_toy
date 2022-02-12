//
// Created by Demyan on 12.02.2022.
//
#include <string>
#ifndef L31P1SHARED_PTR_TOY_SHPTR_H
#define L31P1SHARED_PTR_TOY_SHPTR_H

 class Toy{
   public:
    Toy() = delete;
    Toy(std::string _name):name(_name){};
    std::string name;
};

 class shared_ptr_toy {
  private:
    static unsigned int count;
     Toy *ptr = nullptr;
  public:
     shared_ptr_toy(){++count;};

     shared_ptr_toy (Toy* _ptr):shared_ptr_toy() {ptr = _ptr;};

     shared_ptr_toy(const shared_ptr_toy& other){
        ptr = new Toy(*other.ptr);
        ++count;
    }

    shared_ptr_toy& operator=(Toy& other){
        if(this->ptr == &other) return *this;
        if(this->ptr != nullptr) delete  ptr;
        ptr = new Toy(other);
        return *this;
    }

     unsigned  int Count(){return count;}

     Toy* GetPtr(){return ptr;}

    ~shared_ptr_toy(){
        --count;
        delete ptr;
    }
};


#endif //L31P1SHARED_PTR_TOY_SHPTR_H
