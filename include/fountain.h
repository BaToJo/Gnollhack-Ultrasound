/*
* Copyright 2020 Janne Gustafsson
*/ 

#ifndef FOUNTAIN_H
#define FOUNTAIN_H

/* Fountain types */
enum fountain_types
{
	FOUNTAIN_MAGIC = 0,
	FOUNTAIN_HEALING = 1,
	FOUNTAIN_MANA = 2,
	FOUNTAIN_POWER = 3,
	FOUNTAIN_POISON = 4,
	FOUNTAIN_WATER = 5,
	FOUNTAIN_VARIATIONS
};

#define FOUNTAIN_TYPE_MASK 15

#define LAST_SHUFFLED_FOUNTAIN FOUNTAIN_POISON
#define LAST_FOUNTAIN FOUNTAIN_WATER
#define MAX_FOUNTAINS (FOUNTAIN_TYPE_MASK + 1)

#endif

