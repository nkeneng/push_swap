#include <stdio.h>
#include <stdlib.h>

int	is_sorted(int *numbers, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (numbers[i] > numbers[i + 1])
		{
			return i;
		}
	}
	return -1;
}

int	main(void)
{
	FILE	*fp;
	char	line[256];
	int		size;

	fp = fopen("output.txt", "r");
	if (fp == NULL)
	{
		printf("Failed to open the file.\n");
		return (1);
	}
	int *numbers = malloc(sizeof(int) * 1000);
	// assuming the file has at most 1000 numbers
	size = 0;
	while (fgets(line, sizeof(line), fp))
	{
		numbers[size++] = atoi(line);
	}
	fclose(fp);
	int sort_fail_index = is_sorted(numbers, size);
	if (sort_fail_index == -1)
	{
		printf("OK\n");
	}
	else
	{
		printf("KO\n");
		for (int i = 0; i < size; i++)
		{
			if (i == sort_fail_index)
				printf("\033[1;31m%d\033[0m ", numbers[i]); // print in red
			else
				printf("%d ", numbers[i]);
		}
		printf("\n");
	}
	free(numbers);
	return (0);
}
