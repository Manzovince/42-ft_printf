# ft_printf

# TO DO

- [x] Vous devez recoder la fonction printf de la libc
- [x] Votre fonction s’appelera ft_printf et sera prototypée de la même façon que printf
- [ ] Vous devez gérer les conversions suivantes : csp
- [x] Vous devez gérer les conversions suivantes : diouxX avec les flags hh, h, l, ll
- [ ] Vous devez gérer la conversion suivante : f avec les flags l et L
- [x] Vous devez gérer le %%
- [x] Vous devez gérer les flags #0-+ et espace
- [x] Vous devez gérer la taille minimum du champ
- [x] Vous devez gérer la précision

## man printf

#### Format = % [flags] [field_width] [.precision] [length_modifier] conversion_character

### diouxX
The int (or appropriate variant) argument is converted to signed decimal (d and i), unsigned octal (o), unsigned decimal (u), or unsigned hexadecimal (x and X) notation.
The letters `abcdef` are used for x conversions; the letters `ABCDEF` are used for X conversions. The precision, if any, gives the minimum number of digits that must appear; if the converted value requires fewer digits, it is padded on the left with zeros.

### DOU
The long int argument is converted to signed decimal, unsigned octal, or unsigned decimal, as if the format had been ld, lo, or lu respectively. These conversion characters are deprecated, and will eventually disappear.

### eE
The double argument is rounded and converted in the style [-]d.ddde+-dd where there is one digit before the decimal-point character and the number of digits after it is equal to the precision; if the precision is missing, it is taken as 6; if the precision is zero, no decimal-point character appears.
An E conversion uses the letter `E` (rather than `e`) to introduce the exponent.
The exponent always contains at least two digits; if the value is zero, the exponent is 00.

### fF
The double argument is rounded and converted to decimal notation in the style [-]ddd.ddd, where the number of digits after the decimal-point character is equal to the precision specification.
If the precision is missing, it is taken as 6; if the precision is explicitly zero, no decimal-point character appears. If a decimal point appears, at least one digit appears before it.

### gG
The double argument is converted in style f or e (or F or E for G conversions).
The precision specifies the number of significant digits. If the precision is missing, 6 digits are given; if the precision is zero, it is treated as 1.  Style e is used if the exponent from its conversion is less than -4 or greater than or equal to the precision.  Trailing zeros are removed from the fractional part of the result; a decimal point appears only if it is followed by at least one digit.

### aA
The double argument is rounded and converted to hexadecimal notation in the style [-]0xh.hhhp[+-]d, where the number of digits after the hexadecimal- point character is equal to the precision specification.  
If the precision is missing, it is taken as enough to represent the floating-point number exactly, and no rounding occurs.  If the precision is zero, no hexadecimal- point character appears.  The p is a literal character `p`, and the exponent consists of a positive or negative sign followed by a decimal number representing an exponent of 2.  
The A conversion uses the prefix `0X` (rather than `0x`), the letters `ABCDEF` (rather than `abcdef`) to represent the hex digits, and the letter `P` (rather than `p`) to separate the mantissa and exponent.

For a, A, e, E, f, F, g, and G conversions, positive and negative infinity are represented as inf and -inf respectively when using the lowercase conversion character, and INF and -INF respectively when using the uppercase conversion character.  Similarly, NaN is represented as nan when using the lowercase conversion, and NAN when using the uppercase conversion.

Note that there may be multiple valid ways to represent floating-point numbers in this hexadecimal format.  For example, 0x1.92p+1, 0x3.24p+0, 0x6.48p-1, and 0xc.9p-2 are all equivalent.  The format chosen depends on the internal representation of the number, but the implementation guarantees that the length of the mantissa will be minimized.  Zeroes are always represented with a mantissa of 0 (preceded by a `-`` if appropriate) and an exponent of +0.

### C
Treated as c with the l (ell) modifier.

### c
The int argument is converted to an unsigned char, and the resulting character is written.

If the l (ell) modifier is used, the wint_t argument shall be converted to a wchar_t, and the (potentially multi-byte) sequence representing the single wide character is written, including any shift sequences.
If a shift sequence is used, the shift state is also restored to the original state after the character.

### S
Treated as s with the l (ell) modifier.

### s
The char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character; if a precision is specified, no more than the number specified are written.  If a precision is given, no null character need be present; if the precision is not specified, or is greater than the size of the array, the array must contain a terminating NUL charac-
ter.

If the l (ell) modifier is used, the wchar_t * argument is expected to be a pointer to an array of wide characters (pointer to a wide string).  For each wide character in the string, the (potentially multi-byte) sequence representing the wide character is written, including any shift sequences.  If any shift sequence is used, the shift state is also restored to the original state after the string.  Wide characters from the array are written up to
(but not including) a terminating wide NUL character; if a precision is specified, no more than the number of bytes specified are written (including shift sequences).  Partial characters are never written.  If a precision is given, no null character need be present; if the precision is not specified, or is greater than the number of bytes required to render the multibyte representation of the string, the array must contain a terminating wide NUL
character.

### p
The void * pointer argument is printed in hexadecimal (as if by `%#x` or
`%#lx`).

### n
The number of characters written so far is stored into the integer indicated
by the int * (or variant) pointer argument.  No argument is converted.  The
format argument must be in write-protected memory if this specifier is used;
see SECURITY CONSIDERATIONS below.

### %
A `%` is written.  No argument is converted. The complete conversion specification is `%%`.

The decimal point character is defined in the program's locale (category LC_NUMERIC).

In no case does a non-existent or small field width cause truncation of a numeric field; if the result of a conversion is wider than the field width, the field is expanded to contain the conversion result.

## Cool links

- http://personal.ee.surrey.ac.uk/Personal/R.Bowden/C/printf.html
- https://www.cprogramming.com/tutorial/printf-format-strings.html
- https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html
- https://docs.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=vs-2019
