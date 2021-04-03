#pragma once
/*contains information about the state description*/
#include <string>
#include <queue>

template <typename MEMBER_TYPE>
struct population_member{
	
	std::string name; /*human readable name*/
	unsigned char genome; /*genome of the member*/
	MEMBER_TYPE value; /*value of the member*/

};

typedef unsigned int Goal;

template <typename T>
population_member<T> goal_test(const std::priority_queue<population_member<T>>&, Goal, float);

template <typename T>
void print_member(const population_member<T>&);

template <typename T>
population_member<T> breed(const population_member<T>&, const population_member<T>&);
