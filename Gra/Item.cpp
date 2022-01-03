#include "Item.h"
#include "Bohater.h"

Item::Item(float p_X, float p_Y)
{
	shape.setPosition(p_X, p_Y);
	shape.setSize(Vector2f(this->item_rozm, this->item_rozm));
	shape.setFillColor(Color::Yellow);
	shape.setOrigin(this->item_rozm / 2, this->item_rozm / 2);
}

void Item::setPosition(float p_X, float p_Y)
{
	shape.setPosition(p_X, p_Y);
}

void Item::drawItem(RenderWindow& target)
{
	if (shape.getPosition().x > 0 or shape.getPosition().x < 800 or shape.getPosition().y > 0 or shape.getPosition().x < 600)
		target.draw(shape);
}

void Item::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

Vector2f Item::getPosition()
{
	return shape.getPosition();
}

// Wepons    wybor bron startowej ma byc na pietrze "0"

void Item::wepon1()
{
	Item::setshot(10);
	Item::setfire(10);
	Item::setdamage(3);
}
void Item::wepon2()
{
	Item::setshot(30);
	Item::setfire(20);
	Item::setdamage(10);
}
void Item::wepon3()
{
	Item::setshot(3);
	Item::setfire(2);
	Item::setdamage(0.5);
}
/*
Bohater bohater;    to na potem, wiem ze wyglada jak gowno

void food1()	//apteczka
{
	bohater.addhp(1);
	if (bohater.gethp() > 10)
	{
		bohater.sethp(10);
	}
}
void food2()	//kanpka
{
	bohater.addhp(5);
	if (bohater.gethp() > 10)
	{
		bohater.sethp(10);
	}
}
void food3()	//pizza
{
	bohater.addhp(10);
	if (bohater.gethp() > 10)
	{
		bohater.sethp(10);
	}
}*/
int Item::grab() {
	// 1. pick random file      W I P
	//srand(time(NULL));
	//int number_of_files = 20;
	//printf_s(fname, "items/%i.txt", rand() % (number_of_files + 1));
	char fname[16] = "items/1.txt";

	// 2. open the file
	ifstream inFile;
	openFile(inFile, fname);

	// 3. process the file
	processFile(inFile);

	// 4. close the file
	inFile.close();

	return 0;
}

void Item::processFile(ifstream& inFile) {
	string line;
	float stat[3];
	int i = 0;

	while (!inFile.eof()) {
		getline(inFile, line);
		stat[i] = (float)atof(line.c_str());
		i++;
	}

	Item::addshot(stat[0]);
	Item::addfire(stat[1]);
	Item::adddamage(stat[2]);
	cout << "fire: " << Item::getfire() << endl;
	cout << "damage: " << Item::getdamage() << endl;
	cout << "shot: " << Item::getshot() << endl;
}

void Item::openFile(ifstream& inFile, string fname) {
	inFile.open(fname);
	if (inFile.is_open()) {
		cout << "Successfully opened file" << endl;
	}
	else {
		cout << "Failed to open file" << endl;
		exit(-1);
	}
}
