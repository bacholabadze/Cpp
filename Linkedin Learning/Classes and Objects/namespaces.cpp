/* 
The using declaration
When we use using directive, we import all the names in the namespace and they are available throughout the program, that is they have a global scope.

But with using declaration, we import one specific name at a time which is available only inside the current scope.

NOTE: The name imported with using declaration can override the name imported with using directive

Consider a file Namespace.h: */
#include <iostream>

namespace X
{
    void f()
    {
        printf("f of X namespace\n");
    }
    void g()
    {
        printf("g of X namespace\n");
    }
}

namespace Y
{
    void f()
    {
        printf("f of Y namespace\n");
    }
    void g()
    {
        printf("g of Y namespace\n");
    }
}

//----------- Now let's create a new program file with name program2.cpp with below code:


//#include "Namespace.h";

void h()
{
    using namespace X;  // using directive
    using Y::f; // using declaration
    f();    // calls f() of Y namespace
    X::f(); // class f() of X namespace
}

/// --------------------------------------------------------------Example 2-------------------------------------------------------------------------------

//#include <cstdio>
//#include <string>
//
//namespace bw {
//	const std::string prefix = "(bw::string) ";
//
//	class string {
//		std::string _s = "";
//		string();
//	public:
//		string(const std::string& s) : _s(prefix + s) {}
//		//const char* c_str() const { return _s.c_str(); }
//		//operator std::string& () { return _s; }
//		operator const char* () const { return _s.c_str(); }
//	};
//	
//}; // namespace bwstring
//
//using namespace bw;
//int main() {
//	const std::string s1("This is a string");
//	std::puts(s1.c_str());
//
//	string s2(s1);
//	std::puts(s2);
//
//	return 0;
//}
