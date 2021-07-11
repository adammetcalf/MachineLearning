#pragma once
#include <vector>


class Individual
{
private:
	std::vector<int> route;
	float fitness{};

public:
	Individual();							//constrcutor
	~Individual();							//destrucotr


};

