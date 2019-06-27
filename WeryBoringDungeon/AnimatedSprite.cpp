#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{
}

AnimatedSprite::AnimatedSprite(sf::Image image, int sourceX, int sourceY, int width, int height,
	float posX, float posY, float timeToUpdate) :
	sf::Sprite(),
	m_frameIndex(0),
	m_timeToUpdate(timeToUpdate),
	m_visible(true),
	m_currentAnimationOnce(false),
	m_image(image),
	m_currentAnimation("") {
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::addAnimation(int frames, int x, int y, std::string name, int width, int height)
{
	std::vector<sf::Texture*> rectangles;
	for (int i = 0; i < frames; i++)
	{
		sf::Texture* texture = new sf::Texture();
		sf::IntRect rect = sf::IntRect(x + (i * width), y, width, height);
		texture->loadFromImage(this->m_image, rect);
		rectangles.push_back(texture);
	}
	this->m_animation.insert(std::pair<std::string, std::vector<sf::Texture*> >(name, rectangles));
}

void AnimatedSprite::resetAnimations()
{
	this->m_animation.clear();
}

void AnimatedSprite::playAnimation(const std::string& animation, bool once)
{
	this->m_currentAnimationOnce = once;
	if (this->m_currentAnimation != animation) {
		this->m_currentAnimation = animation;
		this->m_frameIndex = 0;
	}
}

void AnimatedSprite::setVisible(bool visible)
{
	this->m_visible = visible;
}

void AnimatedSprite::stopAnimation()
{
	if (!this->m_currentAnimationOnce) {
		this->m_frameIndex = 0;
	}
	this->animationDone(this->m_currentAnimation);
}

void AnimatedSprite::update(double elapsedTime)
{
	this->m_timeElapsed += elapsedTime;
	if (this->m_timeElapsed > this->m_timeToUpdate) {
		if (this->m_frameIndex < this->m_animation[this->m_currentAnimation].size() - 1) {
			this->setTexture(*this->m_animation[this->m_currentAnimation].at(this->m_frameIndex));
			this->m_frameIndex++;
			this->m_timeElapsed = 0;
		}
		else {
			if (this->m_currentAnimationOnce == true) {
				this->m_frameIndex = this->m_animation[this->m_currentAnimation].size() - 1;
			}
			this->stopAnimation();
		}
	}
	sf::Sprite::setTexture(*m_animation[m_currentAnimation].at(m_frameIndex));
}

void AnimatedSprite::animationDone(std::string animation)
{
}
