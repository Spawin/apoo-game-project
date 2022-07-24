#if !defined(__UN_TESt0_Hpp)
	#define __UN_TESt0_Hpp

	#include "include/consts.hpp"

class Maison
{
public:
	Maison();
	~Maison();
	//

	void update();
	// virtual void render(sf::RenderTarget& target, sf::Vector2f playerPosition);

private:
	const int disposition[game::HOUSE_TILES_NUMBER]; // REVIEW -

	sf::RectangleShape background;
	sf::Sprite sprite;
	sf::Texture texture;
};

#endif // __UN_TESt0_Hpp
