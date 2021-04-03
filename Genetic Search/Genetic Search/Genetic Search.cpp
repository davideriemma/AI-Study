#include <iostream>
#include <string>
#include <queue>

#include "states.h"

const static population_member<float> data[] = {
	{"Sleeping bag", 0x1, 1.5},
	{"Tent", 0x10, 3.5},
	{"Sleeping Pad", 0x100, 4.5},
	{"Tarpulin", 0x1000, 2},
	{"Cooking stove", 0x10000, 1.7},
	{"Pillow", 0x100000, 0.7},
	{"Lamp", 0x1000000, 1},
	{"Toilet Pochette", 0x10000000, 2}
};

void fill_population(std::priority_queue<population_member<float>>& population);

int main(int argc, char ** argv)
{
	/*initalization*/
	Goal goal = std::stoi(std::string(argv[1]), nullptr, 10);
	float epsilon = std::stof(std::string(argv[2]), nullptr);

	/*this queue represents the population of the algorithm*/
	std::priority_queue<population_member<float>> population, new_population, * population_ptr = &population, * new_population_ptr = &new_population, *temp;
	/*this rapesents the result*/
	population_member<float> result;

	/*initialize the population*/
	fill_population(population);

	/*display the inital state*/
	std::cout << "Initial state of population" << std::endl;

	for (int i = 0; i < population.size(); ++i)
	{
		population_member<float> temp = population.top();
		print_member(temp);
		population.pop(); /*ahimè, per questo non possiamo fare niente: per leggere i valori dobbiamo necessariamente svuotare la queue*/
	}

	fill_population(population);

	/*parent declaration*/
	population_member<float> parent1, parent2;

	/*test for goal*/
	result = goal_test(*population_ptr, goal, epsilon);

	while (result.name == "")
	{
		/*do genetic algorithm*/
		
		for (int i = 0; i < population_ptr->size(); ++i)
		{
			parent1 = population_ptr->top();
			population_ptr->pop();
			parent2 = population_ptr->top();
			population_ptr->pop();

			new_population_ptr->push(breed(parent1, parent2));
		}

		/*ora si spiega la macchietta dei puntatori, che vengono utilizzati per scambiare agevolmente il ruolo delle due popolazioi, 
		facendo diventare nuova la popolazione vecchia (il suo container viene svuotato)*/

		/*do the swap of population roles*/
		temp = new_population_ptr;
		new_population_ptr = population_ptr;
		population_ptr = temp;

		result = goal_test(*population_ptr, goal, epsilon);
	}

	return 0;
}

void fill_population(std::priority_queue<population_member<float>>& population)
{

	for (auto element : data)
	{
		population.push(element);
		std::cout << "Inserting " << element.name << " into the population" << std::endl;
	}

	return;
}
