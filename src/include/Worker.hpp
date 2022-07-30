#if !defined(__WORKER_HPP__)
	#define __WORKER_HPP__

	#include "include/Personage.hpp"

class Personage;

class Worker : public Personage
{
public:
	Worker();
	~Worker();

	virtual void simpleAttack(Personage& target) override;
	virtual void specialAttack(Personage& target) override;

private:
	void init();
};

#endif // __WORKER_HPP__
