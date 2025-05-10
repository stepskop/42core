#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    s = mstack;

    MutantStack<int> m;

    m = mstack;

    MutantStack<int>::iterator another_it = m.begin();
    MutantStack<int>::iterator another_ite = m.end();
    while (another_it != another_ite) {
        std::cout << *another_it << std::endl;
        ++another_it;
    }
    return 0;
}
