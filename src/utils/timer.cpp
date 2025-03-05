#include <chrono>

namespace timer {
	static std::chrono::_V2::system_clock::time_point	begin;

	void	start()
	{
		begin = std::chrono::high_resolution_clock::now();
	}

	double	u_elapsed()
	{
		std::chrono::_V2::system_clock::time_point	end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> ret = end - begin;
		return (ret.count() * 1000000.0);
	}

	double	ms_elapsed()
	{
		std::chrono::_V2::system_clock::time_point	end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> ret = end - begin;
		return (ret.count() * 1000.0);
	}

	double	s_elapsed()
	{
		std::chrono::_V2::system_clock::time_point	end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> ret = end - begin;
		return (ret.count());
	}
}
