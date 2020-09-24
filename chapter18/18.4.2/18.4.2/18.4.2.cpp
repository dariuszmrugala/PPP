
#include <iostream>

struct X {
    int val;

    void out(const std::string& s, int nv)
    {
        std::cerr << this << "->" << s << ": " << val << " (" << nv << ")\n";
    }

    void out1(const X& x)
    {
        std::cout << "*x=" << this << "  ";
    }

    X() { out1(*this);  out("X()", 0); val = 0;  }
    X(int v) {out1(*this); val = v; out("X(int)", v);  }
    X(const X& x) { out1(*this); out1(x); val = x.val; out("X(X&)", x.val); }
    X& operator=(const X& a) { out1(*this); out1(a); out("X::operator=()", a.val); val = a.val; return *this; }
    ~X() { out("~X()", 0); }

};

//X glob(2);

X copy(X a) { std::cout << "copy()\n";  a.val++; return a; }

X copy2(X a) { X aa = a; return aa; }

X& ref_to(X& a) { return a; }

X* make(int i) { X a(i); return new X(a); }

struct XX { X a; X b; };

int main()
{
    X loc{ 4 }; std::cout << '\n';
    X loc2{ loc }; std::cout << '\n';
    loc = X{ 5 };
    loc2 = copy(loc);
    loc2 = copy2(loc2);
}
