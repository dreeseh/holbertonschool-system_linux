#ifndef _LAPS_HEADER_
#define _LAPS_HEADER_

#include <stdio.h>
#include <stdlib.h>

/* struct for cars */
/**
 * struct car_s - singly-linked list
 * @id: the car's ID number
 * @laps: number of laps completed
 * @next: pointer to the next node
 */
typedef struct car_s
{
	int id;
	int laps;
	struct car_s *next;
} car_t;

/* Prototypes */
void race_state(int *id, size_t size);
car_t *car_init(int id, car_t *next);
void free_car_list(car_t **cars);

#endif /*_LAPS_HEADER_*/
