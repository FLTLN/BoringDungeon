#pragma once

#include "AnimatedSprite.h"
#include <string>

class Player : public AnimatedSprite
{
public:
	Player();
	Player(sf::Image image, int x, int y);
	~Player();
	void update(double elapsedTime);
	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();
	void setAnimation(std::string animation);

private:
	float m_dx, m_dy;
};
