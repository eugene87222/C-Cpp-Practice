#ifndef BIGNUM_H
#define BIGNUM_H

using namespace std;

const int MAX=4500;
const long long int BASE=1000000000;
const int WIDTH=9;

class BigNum{
private:
    long long int number[MAX];
public:
    BigNum();
    BigNum(const BigNum&);
    BigNum(const string&);

    int len() const;
    bool isneg() const;
    bool operator<(const BigNum&) const;
    bool operator>(const BigNum&) const;
    bool operator!=(const BigNum&) const;
    bool operator==(const BigNum&) const;
    bool operator>=(const BigNum&) const;
    bool operator<=(const BigNum&) const;

    BigNum operator-() const;
    BigNum operator~() const;
    BigNum operator+(const BigNum&) const;
    BigNum operator-(const BigNum&) const;    
    BigNum operator*(const long long int&) const;    
    BigNum operator*(const BigNum&) const;    
    BigNum operator/(const long long int&) const;    
    BigNum operator/(const BigNum&) const;
    BigNum operator%(const long long int&) const;
    
    BigNum operator++();     //prefix
    BigNum operator++(int);  //postfix
    
    void operator+=(const BigNum&);
    void operator-=(const BigNum&);
    void operator*=(const long long int&);
    void operator*=(const BigNum&);
    void operator/=(const long long int&);
    void operator/=(const BigNum&);

    friend istream& operator>>(istream&,BigNum&);
    friend ostream& operator<<(ostream&,const BigNum&);
};
#endif // BIGNUM_H
