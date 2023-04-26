#include <SFML/Graphics.hpp>
#include <chrono>  // for std::chrono::seconds
#include <thread>  // for std::this_thread::sleep_for
#include <vector>
#include <iostream>

using namespace std;

sf::RenderWindow window(sf::VideoMode(800, 600), "Not Tetris");
sf::Texture terainTexture;



void game() {
	int score = 0;
	//THE TEXT OF THE SCORE
	sf::Font font;
	if (!font.loadFromFile("C:/Users/PC/Documents/work/GothamBold.ttf")) {
		// error handling
	}
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setString("SCORE: 0");
	scoreText.setPosition(sf::Vector2f(0, 0));
	//the button
	sf::Text gameOverText("Game Over", font, 48);

	sf::Texture buttonTexture;
	if (!buttonTexture.loadFromFile("images/start.png")) {
		std::cout << "Error loading button texture." << std::endl;
		cout << "problem here";
	}

	// create the sprite for the button
	sf::Sprite button(buttonTexture);
	button.setPosition((window.getSize().x - button.getGlobalBounds().width) / 2, gameOverText.getPosition().y + gameOverText.getGlobalBounds().height + 20);

	terainTexture.loadFromFile("images/terain.png");
	sf::Sprite terain(terainTexture);
	vector<sf::Sprite>body(0);
	sf::Event event;
	sf::Texture texture;
	sf::Texture textureH;
	textureH.loadFromFile("images/img.png");
	texture.loadFromFile("images/apple.png");
	sf::Sprite a(texture);
	sf::Sprite head(textureH);
	int x = 0, y = 1;
	sf::Sprite b(texture);
	b.setPosition(rand() % 760, rand() % 560);
	b.setColor(sf::Color::Red);
	sf::FloatRect ab = head.getGlobalBounds();
	sf::FloatRect bb = b.getGlobalBounds();
	body.push_back(head);
	bool over = false;


	//first

	bool flag = true;
	while (window.isOpen() && flag==true) {
		if (button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
			button.setColor(sf::Color::Cyan);
		}
		else {
			button.setColor(sf::Color::White);
		}
		window.clear();
		window.draw(button);




		window.display();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				if (button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					flag = false;
				}
			}
		}
	}



	while (window.isOpen() && over==false) {
		sf::Vector2f position = head.getPosition();
		position.x = std::fmod(position.x + 800, 800);
		position.y = std::fmod(position.y + 600, 600);
		head.setPosition(position);
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up) {
					// Move sprite up
					//a.move(0, -10);
					y = 0, x = -1;
					if (y != 0 || x == 0)
						y = 0, x = -1;
				}
				else if (event.key.code == sf::Keyboard::Down) {
					// Move sprite down
					//a.move(0, 10);
					if ((y != 0) || x == 0)
						y = 0, x = 1;
				}
				else if (event.key.code == sf::Keyboard::Left) {
					// Move sprite left
					//a.move(-10, 0);
					if (x != 0 || y == 0)
						y = -1, x = 0;
				}
				else if (event.key.code == sf::Keyboard::Right) {
					// Move sprite right
					//a.move(10, 0);
					if (x != 0 || y == 0)
						y = 1, x = 0;
				}
			}

		}
		ab = head.getGlobalBounds();
		bb = b.getGlobalBounds();

		if (ab.intersects(bb)) {
			b.setPosition(rand() % 800, rand() % 600);
			score++;
			body.push_back(head);
		}
		/*for (int i = 3; i < body.size(); i++) {
			bb = body[i].getGlobalBounds();
			if (ab.intersects(bb)) {
				over=true;
			}
		}*/
		head.move(28 * y, 28 * x);
		window.clear();
		window.draw(terain);
		window.draw(b);
		for (int i = body.size() - 1; i > 0; i--) {
			body[i].setPosition(body[i - 1].getPosition().x, body[i - 1].getPosition().y);
			window.draw(body[i]);
		}
		body[0] = head;
		window.draw(head);

		window.display();
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	// create the button text object

	while (window.isOpen()) {
		if (button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
			button.setColor(sf::Color::Cyan);
		}
		else {
			button.setColor(sf::Color::White);
		}
		window.clear();
		
		window.draw(scoreText);


		gameOverText.setPosition((window.getSize().x - gameOverText.getGlobalBounds().width) / 2, (window.getSize().y - gameOverText.getGlobalBounds().height) / 2);
		window.draw(gameOverText);
		scoreText.setPosition(150, 200);
		scoreText.setString("YOUR SCORE: " + to_string(score));
		window.draw(scoreText);
		scoreText.setPosition(150, 250);
		//scoreText.setString("The best score: " + to_string(bestscore));
		window.draw(scoreText);
		window.draw(button);




		window.display();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				if (button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					game();
				}
			}
		}
	}
}


int main()
{
	game();

	return 0;
}
