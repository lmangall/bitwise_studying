#include <stdio.h>
#include <unistd.h>
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

unsigned char	reverse(unsigned char octet)
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

int main(void)
{
	unsigned char c = 5;
	unsigned char d = reverse(c);
	print_octet(c);
	print_octet(d);
	printf("%d\n",d);
	return (0);
}
