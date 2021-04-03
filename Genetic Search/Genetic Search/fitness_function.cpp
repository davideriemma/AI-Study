#include "fitness_function.h"
#include "states.h"

template <typename T>
bool fitness_function(population_member<T> state, Goal goal)
{
	return !(state.value > goal); /*return true if state <= goal, false otherwise*/
}