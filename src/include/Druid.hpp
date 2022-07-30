#if !defined(__DRUID_HPP__)
	#define __DRUID_HPP__

	#include "include/Personage.hpp"

class Personage;

class Druid : public Personage
{
public:
	Druid();
	~Druid();

	virtual void simpleAttack(Personage& target) override;
	virtual void specialAttack(Personage& target) override;

private:
	void init();
};

#endif // __DRUID_HPP__
