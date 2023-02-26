# **EXTENDED UNSIGNED INTEGERS**

[Go Back](../README.md)

## **TO-DO List**

Implementation of different functions, methods, constructors, and operators that is **constexper'able**
should be `constexpr` and should follow the [guide lines](https://en.cppreference.com/w/cpp/language/constexpr)
when implementing with the `constexpr` specifier.

- [ ] Constructors
    - [X] no argument constructor
    - [X] initializer list constructor
    - [ ] unsigned integral constructor
    - [ ] string/char* constructor
    - [X] copy constructor
    - [X] copy assignment

- [ ] Arithmetic Operators
    - [X] `&operator+=(own_type const&);`
    - [X] `&operator-=(own_type const&);`
    - [X] `&operator*=(own_type const&);`
    - [ ] `&operator/=(own_type const&);`
    - [ ] `&operator%=(own_type const&);`
    - [X] `operator+(own_type const&) const;`
    - [X] `operator-(own_type const&) const;`
    - [X] `operator*(own_type const&) const;`
    - [ ] `operator/(own_type const&) const;`
    - [ ] `operator%(own_type const&) const;`

- [ ] Pre-Fix Increment/Decrement
    - [ ] `&operator++();`
    - [ ] `&operator--();`

- [ ] Post-Fix Increment/Decrement
    - [ ] `operator++(int);`
    - [ ] `operator--(int);`

- [ ] Relational Operators
    - [X] `bool operator<(own_type const&) const;`
    - [X] `bool operator>(own_type const&) const;`
    - [X] `bool operator==(own_type const&) const;`
    - [X] `bool operator!=(own_type const&) const;`
    - [X] `bool operator<=(own_type const&) const;`
    - [X] `bool operator>=(own_type const&) const;`

- [ ] Logical Operators
    - [ ] `explicit operator bool() const noexcept;`

- [ ] Bit-Wise Logical Operators
    - [ ] `&operator&=(own_type const&);`
    - [ ] `&operator|=(own_type const&);`
    - [ ] `&operator^=(own_type const&);`
    - [ ] `operator&(own_type const&) const;`
    - [ ] `operator|(own_type const&) const;`
    - [ ] `operator^(own_type const&) const;`
    - [ ] `operator~() const;`

- [ ] Shift Operators
    - [X] `&operator<<=(size_t bits);`
    - [X] `&operator>>=(size_t bits);`
    - [X] `operator<<(size_t bits) const;`
    - [X] `operator>>(size_t bits) const;`
    - [ ] `&operator<<=(own_type bits);`
    - [ ] `&operator>>=(own_type bits);`
    - [ ] `operator<<(own_type bits) const;`
    - [ ] `operator>>(own_type bits) const;`

- [ ] Output Stream Operator
    - [X] ostream operator (HEX)
    - [ ] ostream operator (OCT)
    - [ ] ostream operator (DEC)

[Go Back](../README.md)