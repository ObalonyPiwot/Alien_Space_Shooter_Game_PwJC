#include <iostream>
#include <vector>
#include "run_game.h"
#include "button.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;
int main()
{
	// - okno
	RenderWindow window(VideoMode(800, 600), "Menu");
	window.setFramerateLimit(30);
	Event event;
	Texture texture;
	if (!texture.loadFromFile("DATA/TEXTURE/BACKGROUND/back.png"))
		cout << "Nie wczytano_1 \n";
	Sprite sprite(texture);
	sprite.setScale(Vector2f(0.5, 0.6));
	
	// - muzyka w tle
	SoundBuffer buffer;
	Sound sound;
	if (!buffer.loadFromFile("DATA/SOUND/MUSIC/title.wav"))
		cout << "samples error ";
	sound.setBuffer(buffer);
	sound.play();
	
	// - buttons 
	vector<Button> menu_buttons;
	Button new_button(window.getPosition().x/2+ 80, 150, 150, 80, 1, "Zacznij gre");
	new_button.setTexture();
	menu_buttons.push_back(new_button);
	Button new_button_1(window.getPosition().x / 2 + 80, 300, 150, 80, 2, "Wyjdz");
	new_button.setTexture();
	menu_buttons.push_back(new_button_1);


	// - myszka
	Vector2i position;

	while (window.isOpen())
	{
		window.clear(Color::White);
		window.draw(sprite);
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				break;
			}
		}
		position = Mouse::getPosition(window);
		for (int i = 0; i < (int)menu_buttons.size(); i++)
		{
			switch(menu_buttons[i].checkMouse(position))
			{
			case 1:

				sound.stop();
				window.close();
				runGame();
				break;
			case 2:
				sound.stop();
				window.close();
				break;
			}
				
			menu_buttons[i].draw(window);
		}
			
		window.display();
	}
	return 0;
}