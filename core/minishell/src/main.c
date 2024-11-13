#include "main.h"

int	main(void)
{
	char *input;

	while (1)
	{
		input = readline("Prompt: ");
		printf("This is input stored input = %s\n", input);
		free (input);
	}
	return (0);
}
