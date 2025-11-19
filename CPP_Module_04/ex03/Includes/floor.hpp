#pragma once

#include "./Classes/AMateria.hpp"

typedef struct s_floor {
	AMateria* materia;
	struct s_floor* next;
} t_floor;

extern t_floor* g_floor;

/*
 * INFO: save unequiped materia's in the global variable "floor"
*/
void	dropMateria(AMateria* materia);
