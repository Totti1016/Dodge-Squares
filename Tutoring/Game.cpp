#include "Header.h"
#include "Header1.h"
#include <vector>
#include "score.h"
#include "Enemies.h"
#include "bullet.h"
#include <vector>
#include "abilities.h"

int main()
{
	Enemy enemyPic({});
	Coin coinPic({ });
	sf::Clock clock;
	abilities dS;
	dS.setPos();
	dS.dS();
	coinPic.textureHandler();
	coinPic.spriteHandler();

	enemyPic.textureHandler();
	enemyPic.spriteHandler();
	unsigned int collisionCounter = 0;
	bool direction = false;
	bool isFiring = false;
	const int groundHeight = 700;
	const float gravityspeed = 0.5;
	unsigned int trueCounter = 0;
	unsigned int livesCounter = 0;

	unsigned int coinCounter = 0;

	std::vector<Bullet> bulletVec;

	//---------------------------------------------------------------------------

	//adds player
	playerClass player({ 40, 40 });
	player.setPos({ 30, 700 });
	sf::RenderWindow window(sf::VideoMode(1500, 800), "Bird Shooting Game");
	window.setFramerateLimit(400);
	score collisionTyper;

	score scoreTyper; //starts score

	Enemy enemyTest({});

	Enemy enemy({ 30, 30 });
	enemy.setPos({ enemy.initialX, enemy.initialY });
	std::vector<Enemy> enemyVec;
	Enemy enemy1({30, 30 });
	Enemy enemy2({ 30, 30 });
	enemyVec.push_back(enemy1);
	enemyVec.push_back(enemy2);
	enemy1.setPos({ 100, 100 });
	enemy2.setPos({ 500, 500 });


	Coin coin({ 0 });
	std::vector<Coin*> coinVec;
	Coin coin1({ 10 });
	Coin coin2({ 10 });	
	Coin coin3({ 10 });
	Coin coin4({ 10 });		
	coinVec.push_back(&coin1);	 //add coins to vector
	coinVec.push_back(&coin2);
	coinVec.push_back(&coin3);
	coinVec.push_back(&coin4);

	coin1.setPos({ 650, 620 });
	coin2.setPos({ 200, 600 });
	coin3.setPos({ 900, 400 });
	coin4.setPos({ 1000, 100 });

	Bullet bullet({ 0, 0 });
	
	
	
	while (window.isOpen())
	{
		
		sf::Event ev;

		while (window.pollEvent(ev))
			
			switch (ev.type) {

			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyReleased:
				if (ev.key.code == sf::Keyboard::Enter) {
				
					if (direction == true) 
					{
						if (dS.abilityIsthere == true) {

							dS.drawTo(window);
							direction = false;
							clock.restart();
							
						}if (dS.abilityIsthere == false) {
							
								//checktime elapsed and compare it with cooldown of ability

								
								dS.setPos();
								dS.drawTo(window);
								direction = false;
							
						}
						
					}else if(direction == false)
					{
						if (dS.abilityIsthere == true) {
							dS.deleteDs();
							dS.drawTo(window);
							direction = false;
						
						}
						else if (dS.abilityIsthere == false) {

							dS.drawTo(window);
							direction = true;
							//dS.textTimerDelete(window);
						}

						direction = true;
						
					}
					
					
				}
				if (ev.key.code == sf::Keyboard::Space)
				{
					isFiring = true;
				}
				break;
			
				
			}


		//Coin objects



		//player movement

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			player.move(sf::Vector2f(-player.playerspeed, 0));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player.move(sf::Vector2f(player.playerspeed, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player.move({ 0, -player.playerspeed });

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player.move({ 0, player.playerspeed });

		}


		for (int i = 0; i < coinVec.size(); i++) {
			if (player.isCollidingWithCoin(coinVec[i])) {
				coinVec[i]->setPos({ 422234, 423432 });
				trueCounter++;
				scoreTyper.scoreUpdate(trueCounter, { 100, 0 });
				//std::cout << "Hit one" << std::endl;
			}
		}
		//player boundaries
		if (player.getX() < 0) {
			float currentY = player.getY();
			player.setPos({ 1500, currentY });
		}
		if (player.getX() > 1500) {
			float currentY = player.getY();
			player.setPos({ 0, currentY });
		}
		if (player.getY() > 800) {
			float currentX = player.getX();
			player.setPos({ currentX, 0 });
		}
		if (player.getY() < 0) {
			float currentX = player.getX();
			player.setPos({ currentX, 800 });
		}
		
		if (isFiring == true)
		{
			Bullet newBullet(sf::Vector2f{ 10, 3 });
			newBullet.setPos(sf::Vector2f(player.getX(), player.getY()));
			bulletVec.push_back(newBullet);
			isFiring = false;
		}
		window.clear();
		
		if (direction == true) {
			for (int i = 0; i < bulletVec.size(); i++) {
				
				bulletVec[i].fire(bullet.leftSpeed);
				bulletVec[i].drawTo(window);
				if (bulletVec[i].getX() > 1500 || bulletVec[i].getX() < 0) {
					bulletVec[i].setPos({ 3242, 4322 });
				}
			}
		}
		else if (direction == false) 
		{
			for (int i = 0; i < bulletVec.size(); i++) {
				bulletVec[i].fire(bullet.rightSpeed);
				bulletVec[i].drawTo(window);
				if (bulletVec[i].getX() > 1500 || bulletVec[i].getX() < 0) {
					bulletVec[i].setPos({ 3242, 4322 });
				}
			}
		}
			
		
		
			
			
		
		
		
		
		for (int i = 0; i < bulletVec.size(); i++)
		{
			enemy.checkColl(bulletVec[i]);
			if (enemy.collision == true && enemy.initialX == 100) {

				
					enemy.initialX = 200;
					enemy.initialY = 250;
					collisionCounter++;
					enemy.setPos({ enemy.initialX, enemy.initialY });
					
				}
			enemy.checkColl(bulletVec[i]);
			if (enemy.collision == true && enemy.initialX == 200) {


				enemy.initialX = 500;
				enemy.initialY = 600;
				collisionCounter++;
				enemy.setPos({ enemy.initialX, enemy.initialY });
				
			}
			enemy.checkColl(bulletVec[i]);
			if (enemy.collision == true && enemy.initialX == 500) {


				enemy.initialX = 300;
				enemy.initialY = 200;
				collisionCounter++;
				enemy.setPos({ enemy.initialX, enemy.initialY });
				
			}
			enemy.checkColl(bulletVec[i]); 
			if (enemy.collision == true && enemy.initialX == 300) {


				enemy.initialX = 100;
				enemy.initialY = 700;
				collisionCounter++;
				
			}
			if (collisionCounter >= 10) {
				player.setColor(sf::Color::Blue);
			}
			
			collisionTyper.scoreUpdate(collisionCounter, { 100, 50 });
				

		}
		
		if (player.getGlobal().intersects(enemy.globalBoundaries())) {
			exit(EXIT_SUCCESS);
		}
		//enemy movement
		if (enemy.getPosition().x >= 1500) 
		{
			float negativeX = (enemy.getPosition().x) * -1;
			enemy.setPos({0 , enemy.getPosition().y});
		}
		if (enemy.getPosition().y >= 800)
		{
			enemy.setPos({ enemy.getPosition().x , 1 });
		}
		if (enemy.getPosition().y == 0)
		{
			float negativeY = (enemy.getPosition().y) * -1;
			enemy.setPos({ enemy.getPosition().x , 800 });
		}

		
		//player.move(sf::Vector2f(player.playerspeedx, player.playerspeedy));
		player.drawTo(window);
		coin1.drawTo(window);
		coin2.drawTo(window);
		coin3.drawTo(window);
		coin4.drawTo(window);
		dS.drawTo(window);
		//scoreTyper.drawTo(window);
		collisionTyper.drawTo(window);
		enemy.move();
		enemy.drawTo(window);
		scoreTyper.drawTo(window);
		coinPic.coinMaker(window);
		enemyPic.enemyMaker(window);
		window.display();
		
	}


}