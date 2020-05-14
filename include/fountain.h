/*
* Copyright 2020 Janne Gustafsson
*/ 

#ifndef FOUNTAIN_H
#define FOUNTAIN_H

/* Fountain types */
#define FOUNTAIN_MAGIC 0
#define FOUNTAIN_HEALING 1
#define FOUNTAIN_MANA 2
#define FOUNTAIN_POWER 3
#define FOUNTAIN_POISON 4
#define FOUNTAIN_WATER 5
#define FOUNTAIN_TYPE_MASK 15

#define LAST_SHUFFLED_FOUNTAIN FOUNTAIN_POISON
#define LAST_FOUNTAIN FOUNTAIN_WATER
#define MAX_FOUNTAINS (FOUNTAIN_TYPE_MASK + 1)

#endif

