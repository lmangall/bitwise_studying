
In C, the data type unsigned char represents an octet, also known as an 8-bit unsigned integer. 
In the context of binary, an 'unsigned char' represents an 8-bit value, where each bit can be either 0 or 1. The term "octet" is often used to refer to a sequence of 8 bits.


## printing an octet

```c

void	print_octet(unsigned char octet)
{
	int i = 8;
	unsigned char ret;

	while (i--)
	{
		ret = (octet >> i) & 1;
		ret = ret + '0';
		write (1, &ret, 1);
	}
		write (1, "\n", 1);
}

int main(void)
{
	unsigned char c = 65;// 65= 01000001
	print_octet(c);
	return (0);
}
```

The `print_octet` function takes an `unsigned char` parameter named `octet`. It uses a loop to iterate over each bit of the `octet` value. Inside the loop, it performs a right shift operation (`octet >> i`) followed by a bitwise AND operation with `1` (`& 1`). This extracts the individual bit at the current position (`i`) and stores it in the variable `ret`.

The `ret` value is then converted to a character representation by adding the ASCII value of `'0'`. This converts the bit value `0` or `1` to the corresponding character `'0'` or `'1'`.


| Decimal |   128    |   64     |   32     |   16     |   8      |   4      |   2      |   1      |
|---------|----------|----------|----------|----------|----------|----------|----------|----------|
| Binary  | 10000000 | 01000000 | 00100000 | 00010000 | 00001000 | 00000100 | 00000010 | 00000001 |
| 64 + 1  | 00000000 | 01000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000001 |
|    65   | 01000001 |




## Swap bits

```C
void	swap_octet(unsigned char octet)
unsigned char	swap_ octet (unsigned char octet)
{
	unsigned char ret = 0;

	ret = (octet >> 4 | octet << 4);

	return (ret);
}
```
> A nibble is a unit of digital information that represents four bits, half of an octet (eight bits). The term "nibble" is derived from "nybble," which is a humorous spelling based on the word "byte."

The `swap_octet` function swaps the nibbles within the `octet` value by performing a bit-level manipulation using right-shift, left-shift, and bitwise OR operations. The function returns the resulting swapped value.

The `octet` value is right-shifted by 4 positions (`octet >> 4`) to move the most significant nibble (bits 7-4) to the least significant position (bits 3-0). Simultaneously, the `octet` value is left-shifted by 4 positions (`octet << 4`) to move the least significant nibble to the most significant position.
The bitwise OR operator (`|`) is used to combine the right-shifted and left-shifted values, effectively swapping the nibbles.

## Reverse bits

- [Version from geeksforgeeks](https://www.geeksforgeeks.org/reverse-actual-bits-given-number/)
```C
// C implementation to reverse bits of a number
#include <stdio.h>
 
// function to reverse bits of a number
unsigned int reverseBits(unsigned int n)
{
    unsigned int rev = 0;
 
    // traversing bits of 'n' from the right
    while (n > 0) {
        // bitwise left shift 'rev' by 1
        rev <<= 1;
 
        // if current bit is '1'
        if (n & 1 == 1)
            rev ^= 1;
 
        // bitwise right shift 'n' by 1
        n >>= 1;
    }
    // required number
    return rev;
}
// This code is contributed by Sania Kumari Gupta// (kriSania804)
```
The result of bitwise XOR operator is 1 if the corresponding bits of two operands are opposite. It is denoted by `^`.
Each bit in the result is set if the corresponding bits in the operands are different, and cleared if they are the same.

The `^=` operator is a compound assignment operator that combines the bitwise XOR operation with assignment. It performs the XOR operation between the left-hand side (LHS) operand and the right-hand side (RHS) operand, and then assigns the result back to the LHS operand.

In the given context, the variable `rev` is being toggled using the `^=` operator with the value `1`. The XOR operation with `1` effectively flips the value of `rev`. If `rev` is initially `0`, the XOR operation with `1` sets it to `1`. If `rev` is initially `1`, the XOR operation with `1` clears it back to `0`. Therefore, the `^=` operator is used to alternate the value of `rev` between `0` and `1`.

```
In binary: 
	     0100
	   ^ 0011
	    ------
 Result: 0111  => (7)

 Example: 4^3 = 7


 ```


```C
unsigned char	reverse(unsigned char octet)//we pass 65 = 01000001
{
	int i = 8;
	int j = 0;
	unsigned char ret = 0;
	unsigned char ret1 = 0;

	while (i--)
	{
		ret = (octet >> j) & 1;
		ret = ret << i;
		ret1 = ret1 | ret;
		j++;
	}
	return (ret1);
}

```
The `reverse` function iterates over the bits of the `octet` value, extracts each bit, and combines them in reverse order using bit-level manipulation and bitwise OR operations.

1. A loop is used to iterate over each bit of the `octet` value. The loop starts from the most significant bit (bit 7) and goes down to the least significant bit (bit 0). The loop counter `i` is decremented in each iteration, and another counter `j` is incremented to keep track of the current bit position.
2. Inside the loop, the bit at the current position (`j`) is extracted using a right-shift operation (`(octet >> j) & 1`). This operation moves the bit at position `j` to the least significant bit (bit 0) and masks all other bits.
3. The extracted bit (`ret`) is then shifted left by `i` positions (`ret = ret << i`) to move it to the reversed position. The shifting operation depends on the value of `i`, which decreases with each iteration.
4. The bitwise OR operator (`|`) is used to combine the shifted bit (`ret`) with the intermediate result (`ret1`). This operation accumulates the reversed bits.

