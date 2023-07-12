#include <stdio.h>
#include <unistd.h>

void	print_octet(unsigned char octet)
{
	int i = 8;
	unsigned char ret;

	while (i--)
	{
		ret = (octet << i) & 128;
		if(ret == 0)
			ret = ret + 48;
		else	
			ret = (ret - 127) + '0';
		write (1, &ret, 1);
	}
		write (1, "\n", 1);

}

int main(void)
{
	unsigned char c = 65;
	print_octet(c);
	return (0);
}
