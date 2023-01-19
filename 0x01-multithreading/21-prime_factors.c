#include "multithreading.h"

/**
 * prime_factors - factorizes a number into a list of prime factors
 * @s: the string representation of the number to factorize
 * Return: list_t list of prine factors
 */
list_t *prime_factors(char const *s)
{
	unsigned long num;
	unsigned long *temp;
	unsigned long prime = 2;
	list_t *list = malloc(sizeof(list_t));

	list_init(list);

	num = strtoul(s, NULL, 10);
	while (prime * prime <= num)
	{
		while (num % prime == 0)
		{
			temp = malloc(sizeof(unsigned long));
			*temp = prime;
			list_add(list, temp);
			num /= prime;
		}
		prime += 1 + (prime != 2);

	}

	if (num >= 2)
	{
		temp = malloc(sizeof(unsigned long));
		*temp = num;
		list_add(list, temp);
	}

	return (list);
}
