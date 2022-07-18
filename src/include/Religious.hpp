#if !defined(__RELIGIOUS_HPP__)
	#define __RELIGIOUS_HPP__

	#include "include/Personage.hpp"

class Religious : public Personage
{
public:
	Religious();
	~Religious();

private:
	void init();
};

#endif // __RELIGIOUS_HPP__
