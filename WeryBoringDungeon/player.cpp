#include "Player.h"


Player::Player()
{
}

Player::Player(sf::Image image, int x, int y) :
	AnimatedSprite(image, 0, 0, 100, 100, x, y, 100)
{
	setupAnimations();
	playAnimation("stay", true);
	AnimatedSprite::setPosition(x, y);
	setPosition(x, y);

}

void Player::setupAnimations()
{
	addAnimation(2, 0, 0, "moveUp", 100, 100);
	addAnimation(2, 0, 100, "moveDown", 100, 100);
	addAnimation(2, 0, 200, "moveLeft", 100, 100);
	addAnimation(2, 0, 300, "moveRight", 100, 100);
	addAnimation(1, 0, 100, "stay", 100, 100);
}

void Player::animationDone(std::string currentAnimation) {}

void Player::update(double elapsedTime)
{
	AnimatedSprite::update(elapsedTime);
}

void Player::setAnimation(std::string anim)
{
	playAnimation(anim);
}

Player::~Player()
{
}
