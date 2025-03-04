/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/12/2024
*/

#include "utils.hpp"
#include "emlm/emlm.hpp"
#include <cmath>
#include <ctime>

#include "App.hpp"

float		g_delta_time = 0.0f;

mlm::vec3	rand_vec3()
{
	return (mlm::vec3(rand() / 2147483648.0f, rand() / 2147483648.0f, rand() / 2147483648.0f));
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "Invalid input!\n";
		std::cerr << "Usage:\n";
		std::cerr << "particle-system -c,--config <config file>\n";
		return (1);
	}
	try
	{
		Config 		config;
		App app;
		srand(std::time(NULL));
		config.load(argv[2]);
		app.init(config);
		std::cout << "init" << std::endl;
		while (app.is_running())
		{
			app.update();
			app.render();
		}
	}
	catch(...)
	{
		return (1);
	}
	return (0);
}
