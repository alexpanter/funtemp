#include "pair.hpp"
using namespace funtemp;

ft_typedef(int,int) Pos;

int main()
{
	funtemp::Pair<int,int> p1(47, 59);
	std::cout << p1 << "\n";

	return 0;
}
