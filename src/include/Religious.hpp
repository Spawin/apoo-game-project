#if !defined(__RELIGIOUS_HPP__)
	#define __RELIGIOUS_HPP__

	#include "include/Personage.hpp"

class Religious : public Personage
{
public:
	Religious();
	~Religious();

	virtual void simpleAttack(Personage& target) override;
	virtual void specialAttack(Personage& target) override;

private:
	void init();
};

#endif // __RELIGIOUS_HPP__
