#if !defined(__HALL_HPP__)
	#define __HALL_HPP__

class Hall
{
public:
	Hall();
	~Hall();

	static float getMIN_WIDTH();
	static float getMIN_HEIGHT();

private:
	static const float MIN_WIDTH;  // REVIEW - Mais faire attention avec l'utilisation dans Position
	static const float MIN_HEIGHT; // REVIEW -
};

#endif // __HALL_HPP__
