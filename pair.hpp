#include <iostream>
// NOTE: For niceness, we can actually implement a functional language like this! :)

// simple tuple class
namespace funtemp
{
	template<class T, class U> struct Pair {
		typedef T Head;
		typedef U Tail;
		Pair() : first(T()), second(U()) {}
		Pair(T _first, U _second) : first(_first), second(_second) {}

		template<class T1, class T2, class T3, class T4>
		Pair(Pair<T1,T2>&& t1, Pair<T3,T4>&& t2)
			: first{ Pair<T1,T2>(t1) },
			  second{ Pair<T3,T4>(t2) }
		{}

		const Head first;
		const Tail second;
	};


	template<class T, class U>
	std::ostream& operator<<(std::ostream& s, Pair<T,U> t) {
		return s << "{ first = " << t.first
		         << "; second = " << t.second << " }";
	}

	// declare a CopyTuple class
	template<typename T> struct CopyPair;

	// add a template to this specialization
	template<class T, class U>
	struct CopyPair<Pair<T,U> > {
		typedef Pair<T, U> result;
	};
}

#define ft_typedef(t1, t2) typedef funtemp::CopyPair<funtemp::Pair<t1,t2>>::result
