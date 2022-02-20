#ifndef _LAPS_HEADER_
#define _LAPS_HEADER_

#include <stdio.h>
#include <stdlib.h>

/* struct for cars */
/**
 * struct car_s - singly-linked list
 * @car_id: the car's ID number
 * @laps: number of laps completed
 * @next: pointer to the next node
 */
typedef struct car_s
{
	int car_id;
	size_t laps;
	struct car_s *next;
} car_t;

/* Prototypes */
void race_state(int *id, size_t size);
void insert_car(car_t **head, int id);

#endif /*_LAPS_HEADER_*/
