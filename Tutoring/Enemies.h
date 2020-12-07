#pragma once
#include "Header.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "bullet.h"
#include <stdlib.h> 

class Enemy
{
public:
	//public variables
	bool collision = false;

	Enemy(sf::Vector2f size) {
		enemy.setSize(size);
		
		enemy.setFillColor(sf::Color::Red);
	}
	void setPos(sf::Vector2f newPos) 
	{
		enemy.setPosition(newPos);
	}
	void enemyVel(sf::Vector2f velocity) {
		enemy.move(velocity);
	}

	void drawTo(sf::RenderWindow& window) {
		window.draw(enemy);
	}
	sf::FloatRect globalBoundaries() {
		return enemy.getGlobalBounds();
	}
	void checkColl(Bullet bullet) 
	{
		if (enemy.getGlobalBounds().intersects(bullet.getGlobal())) {
			collision = true;
			
		}
		else {
			collision = false;
		}
	}
	int getRight() 
	{
		return enemy.getPosition().x + enemy.getSize().x;
	}
	int getLeft() 
	{
		return enemy.getPosition().x;
	}
	int getTop() 
	{
		return enemy.getPosition().y;
	}
	int getBottom() 
	{
		return enemy.getPosition().y + enemy.getSize().y;
	}

	void afterCollision() {
		if (collision == true) {
			enemy.setPosition(sf::Vector2f(450 , 200));
		}
	}
	void spriteHandler() {
		enemySprite.setTexture(enemyText);
		
		enemySprite.setPosition(0, 50);
		enemySprite.setScale(0.08, 0.08);
	}

	void textureHandler() {
		enemyText.loadFromFile("skull icon.jpg");
	}
	void enemyMaker(sf::RenderWindow& window)
	{
		window.draw(enemySprite);
	}

	sf::Vector2f getPosition()
	{
		sf::Vector2f pos = enemy.getPosition();
		return pos;
	}

	void move()
	{
		enemy.move(movespeedx, movespeedy);
	}

	float initialX = 100;
	float initialY = 100;
	float movespeedx = 2;
	float movespeedy = 2;
private:
	sf::RectangleShape enemy;
	
	sf::Texture enemyText;
	sf::Sprite enemySprite;


};