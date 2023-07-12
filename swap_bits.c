#include <stdio.h>
#include <unistd.h>



unsigned char	swap_ octet (unsigned char octet)
{
	unsigned char ret = 0;

	ret = (octet >> 4 | octet << 4);

	return (ret);
}

int main(void)
{
	unsigned char c = 65;
	unsigned char d = swap(c);
	print_octet(c);
	print_octet(d);
	printf("%d\n",d);
	return (0);
}
