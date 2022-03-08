#pragma once
#include <iostream>
#include <utility>

class Toy{
public:
    Toy() = delete;
    explicit Toy(std::string _name):name(std::move(_name)){};
    std::string name;
};

//---------------------------------

class shared_ptr_toy {
private:
    size_t *count;
    Toy *ptr;

public:

    shared_ptr_toy():count(nullptr),ptr(nullptr){};
    shared_ptr_toy (Toy* toy);
    shared_ptr_toy(shared_ptr_toy& other);

    size_t use_count();
    bool unique();
    Toy* get(){return ptr;}
    shared_ptr_toy& operator=(const shared_ptr_toy& other);

    void Show();
    void reset();

    ~shared_ptr_toy();
};
