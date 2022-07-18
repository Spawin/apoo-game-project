#if !defined(__WORKER_HPP__)
	#define __WORKER_HPP__

	#include "include/Personage.hpp"

class Worker : public Personage
{
public:
	Worker();
	~Worker();

private:
	void init();
};

#endif // __WORKER_HPP__
