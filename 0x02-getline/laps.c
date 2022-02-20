#include "laps.h"

/**
 * race_state - tracks the number of laps made by cars in a race
 * @id: an array of int representing the “identifier” of each car
 * @size: is the size of this array
 * Return: is void
 **/
void race_state(int *id, size_t size)
{
	static car_t *head;
	size_t i;
	car_t *node;

	/* if size is 0, reset cars list */
	if (size == 0)
	{
		while (head)
		{
			node = head;
			head = head->next;
			free(node);
		}
		return;
	}

	i = 0;
	while (i < size)
	{
		insert_car(&head, id[i]);
		i++;
	}

	printf("Race state:\n");
	for (node = head ; node != NULL ; node = node->next)
	{
		printf("Car %d [%lu laps]\n", node->car_id, node->laps);
	}
}

/**
 * insert_car - inserts a car into the race
 * @id: an array of int representing the “identifier” of each car
 * @head: points to the head of the linked list
 * Return: is void
 */
void insert_car(car_t **head, int id)
{
	car_t *new, *temp;

	if (*head == NULL || id < (*head)->car_id)
	{
		new = malloc(sizeof(car_t));
		if (new == NULL)
			exit(EXIT_FAILURE);
		new->car_id = id;
		new->laps = 0;
		new->next = *head;
		*head = new;
		printf("Car %d joined the race\n", id);
		return;
	}

	new = *head;

	while (new->next && new->next->car_id <= id)
	{
		new = new->next;
	}

	if (new->car_id == id)
	{
		new->laps++;
		return;
	}

	temp = malloc(sizeof(car_t));

	if (temp == NULL)
	{
		exit(EXIT_FAILURE);
	}

	temp->car_id = id;
	temp->laps = 0;
	temp->next = new->next;
	new->next = temp;
	printf("Car %d joined the race\n", id);
}
