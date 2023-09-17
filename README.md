# Big Decimal Integer

## Description:

### In this Repo it is required to develop a new C++ type (class) that can hold unlimited decimal integer values and performs arithmetic operations on them. You will develop in C++ a class, BigDecimalInt that supports writingstatements with very long integer values.

### Like this:

![Alt text](image.png)

### Design the class BigDecimalInt that has the following public interface (set of operations available to use by developers using the class):

a.BigDecimalInt (string decStr); // Initializes fromstring & rejects bad input<br>
b.BigDecimalInt (int decInt); // Initialize from integer<br>
c.BigDecimalInt operator+ (BigDecimalInt anotherDec);<br>
d.BigDecimalInt operator- (BigDecimalInt anotherDec);<br>
e.bool operator< (BigDecimalInt anotherDec);<br>
f.bool operator> (BigDecimalInt anotherDec);<br>
g.bool operator==(BigDecimalInt anotherDec);<br>
h.BigDecimalInt operator= (BigDecimalInt anotherDec);<br>
i.int size();<br>
j.int sign();<br>
