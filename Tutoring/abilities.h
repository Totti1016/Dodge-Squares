#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <time.h>
#include "score.h"
#include <string>
class abilities 
{
public:
	
	void setPos() {
		abilitySprite.setColor(sf::Color(255, 255, 255, 255));
		abilitySprite.setPosition({ 1300, 600 });
		abilityIsthere = true;
	}
	void dS()
	{

		if (!(abilityTexture.loadFromFile("icon ability.jpg"))) {
			std::cout << "Could not load from file" << std::endl;
		}
		abilitySprite.setTexture(abilityTexture);
		abilitySprite.setScale(sf::Vector2f({ 0.4, 0.4 }));
	}
	
	void deleteDs()
	{
		abilitySprite.setColor(sf::Color(255, 255, 255, 100));
		abilityIsthere = false;
		
	}
	
	void drawTo(sf::RenderWindow &window) 
	{
		window.draw(abilitySprite);
	}


	void textTimerDelete(sf::RenderWindow &window) 
	{
		timerText.setPosition(sf::Vector2f{ 2222, 2222 });
		//window.draw(timerText);
	}
	
	bool abilityIsthere;

private:
	sf::Clock clock;
	sf::Texture abilityTexture;
	sf::Sprite abilitySprite;
	
	sf::Text timerText;
	
};