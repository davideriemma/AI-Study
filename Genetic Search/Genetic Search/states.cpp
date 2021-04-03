#include <iostream>
#include <random>

#include "states.h"


population_member<float> goal_test(population_type& population, Goal goal, float epsilon)
{
	population_member<float> result = {"", 0, 0}, type;
	population_type backup;

	for (unsigned int i = 0; i < population.size(); ++i)
	{
		type = population.top();
		population.pop();
		if (goal - type.value > 0 && goal - type.value <= epsilon)
			result = type;
		else
			backup.push(type);
	}

	population = backup;

	return result;
}

void print_member(struct population_member<float> const & member)
{
	std::cout << member.name << " [genome: " << std::hex << member.genome << ", value: " << member.value << "]";
}

population_member<float> breed(const population_member<float>& parent1, const population_member<float>& parent2)
{
	/*create child*/
	population_member<float> child;
	/*set mutation threshold*/
	const float mutation_treshold = 1.5;

	/*set child name*/
	child.name = parent1.name + " + " + parent2.name;

	/*set child value*/
	child.value = parent1.value + parent2.value;

	std::random_device rand;
	std::uniform_int_distribution<unsigned int> dist(0, 7);
	std::uniform_real_distribution<> mutation_dist(0, 3);

	unsigned int single_crossover_point = dist(rand);

	child.genome = (parent1.genome & (0xff << single_crossover_point)) | (parent2.genome & (0xff >> 7 - single_crossover_point));

	/*mutate*/
	if (mutation_dist(rand) > mutation_treshold)
	{
	}
	child.genome = child.genome ^ ~(1 << dist(rand));

	return child;
}
