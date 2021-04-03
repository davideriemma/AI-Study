#pragma once
/*contains information about the state description*/
#include <string>
#include <queue>

template <typename MEMBER_TYPE>
struct population_member{
	
	std::string name; /*human readable name*/
	unsigned char genome; /*genome of the member*/
	MEMBER_TYPE value; /*value of the member*/

	bool operator()(const population_member<MEMBER_TYPE>& member1, const population_member<MEMBER_TYPE>& member2)
	{
		return member1.value < member2.value;
	}
};

typedef unsigned int Goal;
typedef std::priority_queue<population_member<float>, std::vector<population_member<float>>, population_member<float>> population_type;

population_member<float> goal_test(population_type&, Goal, float);

void print_member(struct population_member<float> const& member);

population_member<float> breed(const population_member<float>&, const population_member<float>&);
