#pragma once

#include "./Classes/AbstractClasses/AMateria.hpp"

typedef struct s_floor {
	AMateria* materia;
	struct s_floor* next;
} t_floor;

extern t_floor* g_floor;

/*
 * INFO: save unequiped materia's in the global variable "floor"
*/
void	dropMateria(AMateria* materia);

/*
 * INFO: delete the memory allocated by the materia's on the "floor"
*/
void	cleanFloor();
