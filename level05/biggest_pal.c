#include <unistd.h>

void print_pal(char* str, int low, int high)
{
	while (low <= high)
		write(1, &str[low++], 1);
}

void biggest_pal(char *str)
{
	int	i;
	int len;
	int low;
	int high;
	int max_len;
	int start;

	len = 0;
	while (str[len])
		len++;
	i = 1;
	max_len = 1;
	while (++i < len)
	{ 
		low = i - 1;
		high = i;
		while (low >= 0 && high < len && str[low] == str[high])
		{
			if (high - low + 1 > max_len)
			{
				start = low;
				max_len = high - low + 1;
			}
			--low;
			++high;
		}
		low = i - 1;
		high = i + 1;
		while (low >= 0 && high < len && str[low] == str[high])
		{
			if (high - low + 1 > max_len)
			{
				start = low;
				max_len = high - low + 1;
			}
			--low;
			++high;
		}
	}
	print_pal(str, start, start + max_len - 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		biggest_pal(argv[1]);
	write(1, "\n", 1);
	return 0;
}
