#include <iostream>
#include "err_v2.h"

Result<int, unsigned int> f(int x) {
	if (x%2) return Result<int, unsigned int>::Ok(x+1);
	else return Result<int, unsigned int>::Err(x-1);
}

int main(void) {
	std::cout << f(4).unwrap_err() << '\n';
	std::cout << f(5).unwrap() << '\n';
}
