# funtemp
Functional data types implemented with template meta-programming


## Examples ##
```cpp
// test.cpp
#include "pair.hpp"
using namespace funtemp;

ft_typedef(int,int) Pos;

int main()
{
	Pos p1(47,59);
	std::cout << p1 << "\n";

	return 0;
}
```
Compile with `g++ -std=c++17 test.cpp -o test`. Will output:
```bash
{ first = 47; second = 59 }
```

## Immutability ##
All types are immutable. E.g. trying to redefine a field will return a compile-time error:
```cpp
Pos p1(47,59);
p1.first = 43;
```
Error output from g++ 9.3.0 :
```bash
test.cpp: In function ‘int main()’:
test.cpp:9:11: error: assignment of read-only member ‘funtemp::Pair<int, int>::first’
    9 |  p1.first = 43;
      |  ~~~~~~~~~^~~~
```
