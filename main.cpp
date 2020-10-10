#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Apple {
public:

    // Factory Method, note it's static
    static Apple* make_apple(string choice);

    // method that we will use polymorphically per product
    virtual void io() = 0;

    // Note: need to specify an explicicit default destructor
    virtual ~Apple() = default;
};

class iPhone : public Apple {
public:
    void io() {
        cout << "iPhone: touchscreen\n";
    }
};

class iPad : public Apple {
public:
    void io() {
        cout << "iPad: touchscreen & keyboard\n";
    }
};

class Mac : public Apple {
public:
    void io() {
        cout << "Mac: keyboard\n";
    }
};

class defaultValue : public Apple {
public:
    void io() {
        cout << "---------------\n";
    }
};


// this is the FACTORY Method
// it does need to know about the derived methods
// but this allows us to abstract this from our 
// "client" calling code in main()
Apple* Apple::make_apple(string choice) {
    if (choice == "iPhone")
        return new iPhone;
    else if (choice == "iPad")
        return new iPad;
    else if (choice == "Mac")
        return new Mac;
    else
        return new defaultValue;
}


// main() is considered the "client"
// while in this example we could hard code the
// derived classes since we are making a menu anyway
// imagine having 

int main(int argc, char* argv[]) {

    vector<Apple*> products;

    for (int i = 0; i < argc; i++) {
        products.push_back(Apple::make_apple(argv[i]));
        products[i]->io();
    }
    return 0;
}