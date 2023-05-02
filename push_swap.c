#include "./push_swap.h"

int main(int argc, char **argv)
{
	int n;
	char **arr;

	if (argc > 2)
	{
		n = 1;
		while (n < argc)
		{
			arr = ft_split(argv[n], ' ');
			n++;
			while (*arr)
			{
				printf("%s\n", *arr);
				arr++;
			}
			free(arr);
		}
	}
	return (0);
}
