/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/12/2024
*/

#include "utils.hpp"
#include "emlm/emlm.hpp"
#include <cmath>
#include <ctime>

#include "App.hpp"

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
		while (app.is_running())
		{
			app.update();
			app.render();
		}
	}
	catch(const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	catch(const std::exception &e)
	{
		return (1);
	}
	return (0);
}
