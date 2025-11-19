#include "../Includes/floor.hpp"

static t_floor* getLast() {
	t_floor* result = g_floor;
	for ( ;result->next != NULL ;) {
		result = result->next;
	}
	return result;
}

void	dropMateria(AMateria* materia) {
	if (g_floor == NULL) {
		g_floor = new t_floor;
		g_floor->materia = materia;
		g_floor->next = NULL;
		return;
	}
	t_floor* last = getLast();
	last->next = new t_floor;
	last->next->materia = materia;
	last->next->next = NULL;
}
