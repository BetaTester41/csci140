#include <iostream>
#include <memory> // remember!!!

struct TestThing // identical to class
{
    std::string type;

    TestThing(std::string type) : type{type}
    {
        std::cout << type << " constructed\n";
    }
    ~TestThing() { std::cout << type << " destruction is inevitable\n"; }
};

int main(int argc, char const *argv[])
{
    // std::unique_ptr<int> uptr{std::make_unique<int>(5)};
    std::unique_ptr<TestThing> uptr{std::make_unique<TestThing>("Unique")};

    {
        std::shared_ptr<TestThing> sptr{std::make_shared<TestThing>("Shared")};
    }
    // std::shared_ptr<int> sptr{std::make_shared<int>(10)}; // has a built in counter
    // std::weak_ptr<int> wptr{sptr};                        // can point to shared pointer, does't affect the shared object

    // std::cout << *uptr << std::endl;
    // std::cout << *sptr << std::endl;

    return 0;
}

/*
- Remember which library smart pointer come from (memory)
- Remember how to make a shared pointer (std::make_shared<type<(constDat))
*/
