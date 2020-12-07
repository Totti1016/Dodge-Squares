#pragma once
#include "Enemies.h"
class Bullet 
{
public:
	Bullet(sf::Vector2f size) {
		bullet.setSize(size);
		bullet.setFillColor(sf::Color::Red);

	}
	int leftSpeed = -10;
	int rightSpeed = 10;
	void fire(int speed) 
	{
		bullet.move(speed, 0);
	}
	int getX() 
	{
		return bullet.getPosition().x;
	}
	void setPos(sf::Vector2f newPos) {
		bullet.setPosition(newPos);
	}
	int getRight()
	{
		return bullet.getPosition().x + bullet.getSize().x;
	}
	int getLeft()
	{
		return bullet.getPosition().x;
	}
	int getTop()
	{
		return bullet.getPosition().y;
	}
	int getBottom()
	{
		return bullet.getPosition().y + bullet.getSize().y;
	}
	void drawTo(sf::RenderWindow& window) {
		window.draw(bullet);
	}
	sf::FloatRect getGlobal() {
		
		return bullet.getGlobalBounds();
	}
private:
	sf::RectangleShape bullet;
};