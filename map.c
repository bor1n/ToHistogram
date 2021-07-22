#include "map.h"

t_map new_map(int size)
{
	t_map map;

	map.size = size;
	map.pairs = calloc(map.size, sizeof(t_pair));
	map.length = 0;
	return (map);
}

/**
 * Adds a pair to map
 *
 *
 * */
t_map *put(t_map *map, char *key, const int *value)
{
	t_map nmap;
	t_pair pair;
	int count;

	count = 0;
	if (map == 0)
	{
		printf("Map is null");
		return 0;
	}
	pair.key = strdup(key);
	pair.value = *value;
	//TODO: implement dynamic allocation
	while (map->pairs[count] != 0 || count != map->size)
	{
		map->pairs++;
		count++;
	}
	if (count == map->size)
		map->pairs = realloc(map->pairs, (count * 2) * sizeof(t_pair));
	*map->pairs = pair;
	return (0);
}