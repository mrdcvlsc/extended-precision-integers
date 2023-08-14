# **EXTENDED UNSIGNED INTEGERS**

[Go Back](../README.md)

## **TO-DO List**

Implementation of different functions, methods, constructors, and operators that is **constexper'able**
should be `constexpr` and should follow the [guidelines](https://en.cppreference.com/w/cpp/language/constexpr)
when implementing with the `constexpr` specifier.

- [X] Constructors
    - [X] no argument constructor
    - [X] initializer list constructor
    - [X] unsigned integral constructor
    - [X] string/char* constructor
    - [X] copy constructor
    - [X] copy assignment

- [X] Arithmetic Operators
    - [X] `&operator+=(own_type const&);`
    - [X] `&operator-=(own_type const&);`
    - [X] `&operator*=(own_type const&);`
    - [X] `&operator/=(own_type const&);`
    - [X] `&operator%=(own_type const&);`
    - [X] `operator+(own_type const&) const;`
    - [X] `operator-(own_type const&) const;`
    - [X] `operator*(own_type const&) const;`
    - [X] `operator/(own_type const&) const;`
    - [X] `operator%(own_type const&) const;`

- [X] Pre-Fix Increment/Decrement
    - [X] `&operator++();`
    - [X] `&operator--();`

- [X] Post-Fix Increment/Decrement
    - [X] `operator++(int);`
    - [X] `operator--(int);`

- [X] Relational Operators
    - [X] `bool operator<(own_type const&) const;`
    - [X] `bool operator>(own_type const&) const;`
    - [X] `bool operator==(own_type const&) const;`
    - [X] `bool operator!=(own_type const&) const;`
    - [X] `bool operator<=(own_type const&) const;`
    - [X] `bool operator>=(own_type const&) const;`

- [X] Logical Operators
    - [X] `explicit operator bool() const noexcept;`

- [X] Bit-Wise Logical Operators
    - [X] `&operator&=(own_type const&);`
    - [X] `&operator|=(own_type const&);`
    - [X] `&operator^=(own_type const&);`
    - [X] `operator&(own_type const&) const;`
    - [X] `operator|(own_type const&) const;`
    - [X] `operator^(own_type const&) const;`
    - [X] `&operator&=(limb_t);`
    - [X] `&operator|=(limb_t);`
    - [X] `&operator^=(limb_t);`
    - [X] `operator&(limb_t) const;`
    - [X] `operator|(limb_t) const;`
    - [X] `operator^(limb_t) const;`
    - [X] `operator~() const;`

- [X] Shift Operators
    - [X] `&operator<<=(size_t bits);`
    - [X] `&operator>>=(size_t bits);`
    - [X] `operator<<(size_t bits) const;`
    - [X] `operator>>(size_t bits) const;`

- [X] Output Stream Operator
    - [X] ostream operator (HEX)
    - [X] ostream operator (OCT)
    - [X] ostream operator (DEC)

[Go Back](../README.md)