#include "pch.h"
#include <iostream>

using namespace std;

class Score {
private:
	int playerXscore;
	int playerYscore;

public:
	Score(int inputX, int inputY)//konstuktor
	{
		playerXscore = inputX;
		playerYscore = inputY;
	}

	void showScore()
	{
		cout << "X Score = " << playerXscore << "\t" << "Y Score = " << playerYscore << endl;
	}

	void addX()//jika player Y mendapat hits>50 maka method ini akan dipanggil
	{
		playerXscore++;
		//showScore();
	}
	void addY()//jika player X mendapat hits>50 maka method ini akan dipanggil
	{
		playerYscore++;
		//showScore();
	}

};