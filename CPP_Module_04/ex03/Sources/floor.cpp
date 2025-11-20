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

void	cleanFloor() {
	t_floor* MateriaToDelete = g_floor;
	t_floor* nodeToDelete = g_floor;
	while (MateriaToDelete != NULL) {
		delete MateriaToDelete->materia;
		MateriaToDelete->materia = NULL;
		MateriaToDelete = MateriaToDelete->next;
		delete nodeToDelete;
		nodeToDelete = MateriaToDelete;
	}
}
