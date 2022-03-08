#include "ShPtr.h"

shared_ptr_toy::shared_ptr_toy(Toy* toy):count(new size_t(1)),ptr(toy){};

shared_ptr_toy::shared_ptr_toy(shared_ptr_toy& other):count(other.count),ptr(other.ptr){
    (*count)++;
}

shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy& other){
    if(this != &other){
        if(count){
            if(*count == 1){
                delete count;
                delete ptr;
            } else (*count)--;
        }
        ptr = other.ptr;
        count = other.count;
        (*count)++;
    }
    return *this;
}

shared_ptr_toy::~shared_ptr_toy(){
    reset();
}

void shared_ptr_toy::reset(){
    if(count){
        if((*count) == 1){
            delete count;
            delete ptr;
        } else (*count)--;
    }
}

size_t shared_ptr_toy::use_count(){
    return (count) ? *count : 0;
}

bool shared_ptr_toy::unique(){
    if (count) return ((*count)==1);
    return false;
}

void shared_ptr_toy::Show(){
    if(count) {
        std::cout  << "\ttoy = \"" << ptr->name << "\""
                   << "\n\tThere are = "<< use_count() << " links left" <<  std::endl;
    } else std::cout << "\nNull pointer" << std::endl;
}