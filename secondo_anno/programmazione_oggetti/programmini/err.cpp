#include "err.h"
#include "some.h"
#include <string>
using namespace std;

Result<int, string> f(int i) {
    if (i==1)
        return Result<int, string>::Ok(1);
    else return Result<int, string>::Err("f(int i): i is not 1");
}

Some<int> g() {
    return Some<int>(8);
}

int main() {
    Result<int, string> tmp = f(1);
    std::cout << tmp.unwrap() << std::endl;
    std::cout << tmp.isOk() << std::endl;
    std::cout << f(2).unwrap_err() << std::endl;
    std::cout << g().unwrap() << std::endl;
    return 0;
}
