#include <iostream>
#include <random>

#include "states.h"

template <typename T>
population_member<T> goal_test(const std::priority_queue<population_member<T>>& population, Goal goal, float epsilon)
{
	population_member<T> result = {"", 0, 0};

	for (population_member<T> member : population)
	{
		if (goal - member.value > && goal - member.value <= epsilon)
			result = member;
	}
}

template <typename T>
void print_member(const population_member<T>& member)
{
	std::cout << member.name << " [genome: " << member.genome << ", value: " << member.value << "]";
}

template <typename T>
population_member<T> breed(const population_member<T>& parent1, const population_member<T>& parent2)
{
	/*create child*/
	population_member<T> child;
	/*set mutation threshold*/
	const float mutation_treshold = 1.5;

	/*set child name*/
	child.name = parent1.name + " + " + parent2.name;

	/*set child value*/
	child.value = parent1.value + parent2.value;

	std::random_device rand;
	std::uniform_int_distribution<unsigned int> dist(0, 7);
	std::uniform_real_distribution<float> mutation_dist(0 3);

	unsigned int single_crossover_point = dist(rand);

	child.genome = (parent1.genome & (0xff << single_crossover_point)) | (parent2.genome & (0xff >> 7 - single_crossover_point));

	/*mutate*/
	if (mutation_dist(rand) > mutation_treshold)
	{
	}
	child.genome = child.genome ^ ~(1 << dist(rand));

	return child;
}
