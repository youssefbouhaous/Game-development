#include <SFML/Graphics.hpp>
#include <chrono>  // for std::chrono::seconds
#include <thread>  // for std::this_thread::sleep_for
#include <iostream>


int bestscore = 0;



using namespace std;
int main();

void GameOver() {
    sf::Font font;
    if (!font.loadFromFile("images/GothamBold.ttf")) {
        // error handling
    }
    sf::RenderWindow window(sf::VideoMode(500, 650), "Display Image");
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setString("SCORE: 0");
    scoreText.setPosition(sf::Vector2f(0, 0));
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(scoreText);
        window.display();
    }
    main();
}



void game() {

    //THE TEXT OF THE SCORE
    sf::Font font;
    if (!font.loadFromFile("images/GothamBold.ttf")) {
        // error handling
    }
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setString("SCORE: 0");
    scoreText.setPosition(sf::Vector2f(0, 0));

    // Load the image
    sf::Texture texture;
    sf::Texture texturef;
    sf::Texture texturebg;
    sf::Texture wall;
    sf::Texture wall2;
    sf::Texture wall3;
    wall.loadFromFile("images/walcopie.png");
    if (!texture.loadFromFile("images/bird.png")) {
        cout<< "problem in the image of the bird"; // error loading image
    }
    texturef.loadFromFile("images/bird2.png");
    texturebg.loadFromFile("images/bg.jpg");

    sf::Sprite bg(texturebg);

    // Create a sprite with the image
    int score = 0;
    bool flagw1 = 1;
    bool flagw2 = 1;
    sf::Sprite spritew(wall);

    sf::Sprite bird(texture);
    sf::Sprite swall1(wall);
    sf::Sprite swall1o(wall);
    sf::Sprite swall2(wall);
    sf::Sprite swall2o(wall);

    int dx = 50;
    // Set the origin of the sprite to the center of the texture
    sf::Vector2u textureSize = texture.getSize();
    // Create the window
    sf::RenderWindow window(sf::VideoMode(500, 650), "Display Image");
    int x = 2;

    bird.setPosition(100, 300);

    sf::FloatRect spriteBounds = bird.getGlobalBounds();
    sf::FloatRect wall1Bounds = swall1.getGlobalBounds();
    sf::FloatRect wall1oBounds = swall1o.getGlobalBounds();
    sf::FloatRect wall2Bounds = swall2.getGlobalBounds();
    sf::FloatRect wall2oBounds = swall2o.getGlobalBounds();
    swall1.setPosition(500, 500);
    swall2.setPosition(750, 500);

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
    // create the button text object

    bool gameIsOver = false;
    bool buttonIsPressed = false;
    begin:
    // Start the game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        bird.setTexture(texture);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                // Move the sprite Up

                if (event.key.code == sf::Keyboard::Up) {
                    bird.move(0, -40);
                    bird.setTexture(texturef);
                }
            }
        }
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        //cout << mousePos.x<<" "<<mousePos.y<<endl;
        //THE GRAVITY APPLIED ON THE BIRD
        bird.move(0, 5);
        
        //THE update of the bounds
         spriteBounds = bird.getGlobalBounds();
         wall1Bounds = swall1.getGlobalBounds();
         wall1oBounds = swall1o.getGlobalBounds();
         wall2Bounds = swall2.getGlobalBounds();
         wall2oBounds = swall2o.getGlobalBounds();

         cout << bird.getPosition().y << " " << swall1.getPosition().x << endl;
         if (swall1.getPosition().x == 100 || swall2.getPosition().x==100) {
             score++;
             bestscore = max(bestscore, score);
         }

        //THE CHECK OF THE GAMEOVER
        if (bird.getPosition().y>550 || spriteBounds.intersects(wall1Bounds) || spriteBounds.intersects(wall1oBounds) || spriteBounds.intersects(wall2Bounds) || spriteBounds.intersects(wall2oBounds)) {
            break;
        }


        //THE MOVEMENT OF THE WALLS

        if (swall1.getPosition().x <= -50) {
            swall1.setPosition(500, 500-rand()%300);
        }
        if (swall2.getPosition().x <= -50) {
            swall2.setPosition(500, 500-rand()%300);
        }
        swall1.move(-5, 0);
        swall1o.setPosition(swall1.getPosition().x, swall1.getPosition().y - 1100);
        swall2.move(-5, 0);
        swall2o.setPosition(swall2.getPosition().x, swall2.getPosition().y - 1100);
        scoreText.setString("SCORE: "+to_string(score));
        //THE DISPLAY OF THE OBJECTS OF THE GAME
        window.clear();
        window.draw(bg);
        window.draw(swall1);
        window.draw(swall1o);
        window.draw(swall2);
        window.draw(swall2o);
        window.draw(bird);
        window.draw(scoreText);
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    gameOverText.setFillColor(sf::Color::Red);
    scoreText.setFillColor(sf::Color::Black);
    
    while (window.isOpen()) {
        if (button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
            button.setColor(sf::Color::Cyan);
        }
        else {
            button.setColor(sf::Color::White);
        }

        window.draw(bg);
        window.draw(swall1);
        window.draw(swall1o);
        window.draw(swall2);
        window.draw(swall2o);
        window.draw(bird);
        window.draw(scoreText);


        gameOverText.setPosition((window.getSize().x - gameOverText.getGlobalBounds().width) / 2, (window.getSize().y - gameOverText.getGlobalBounds().height) / 2);
        window.draw(gameOverText);
        scoreText.setPosition(150, 200);
        scoreText.setString("YOUR SCORE: " + to_string(score));
        window.draw(scoreText);
        scoreText.setPosition(150, 250);
        scoreText.setString("The best score: " + to_string(bestscore));
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
                    window.close();
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
