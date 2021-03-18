// Pong Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h" 
#include <iostream> 
#include <time.h> 
#include <stdlib.h>
#include <thread>

#include "Player.h" //ambil header file Player
#include "Score.h" //ambil header file Score

using namespace std;

int randomNumber = 0; //global variable agar bisa di pakai di semua fungsi

//fungsi untuk acak Hits
void randomHits()
{
	srand((int)time(NULL));
	randomNumber = (rand() % 100) + 1;
	this_thread::sleep_for(chrono::milliseconds(1000));
}

//fungsi untuk acak Giliran
int randomTurn()
{
	int setTurn; //variable local yang akan dimasukkan ke Main()
	for (int i = 0; i < 5; i++)
	{
		srand((int)time(NULL));//membuat seed random berdasar waktu
		setTurn = (rand() % 2) + 1;
	}
	return setTurn;
}

int main()
{
	int turn = randomTurn();//variable ini digunakan untuk menentukan giliran pertama

	Score score(0, 0);//inisialisasi score

	Player playerX = Player(), playerY;//inisialisasi pemain
	playerY = playerX;//copy player

	if (turn == 1)//jika int turn memiliki nilai 1
	{
		cout << "Player X Goes First" << endl;
		while (true)//perulangan yang diawali pemain X
		{
			thread randomX(randomHits);//menjalankan fungsi randomHits menggunakan thread
			cout << "Hits Player X = ";
			playerX.turn(randomNumber);//memasukkan nilai Random tadi kedalam Class
			if (playerX.getHits() >= 50)
			{
				score.addY();//tambah score musuh
				score.showScore();//munculkan score keduanya
			}
			randomX.join();//berhentikan thread, lanjut ke thread berikutnya

			thread randomY(randomHits);
			cout << "Hits Player Y = ";
			playerY.turn(randomNumber);
			if (playerY.getHits() >= 50)
			{
				score.addX();
				score.showScore();
			}
			randomY.join();
		}
	}
	else//jika int turn memiliki nilai selain 1
	{
		cout << "Player Y Goes First" << endl;
		while (true)//perulangan yang diawali pemain X
		{			
			thread randomY(randomHits);
			cout << "Hits Player Y = ";
			playerY.turn(randomNumber);
			if (playerY.getHits() >= 50)
			{
				score.addX();
				score.showScore();
			}
			randomY.join();

			thread randomX(randomHits);
			cout << "Hits Player X = ";
			playerX.turn(randomNumber);
			if (playerX.getHits() >= 50)
			{
				score.addY();
				score.showScore();
			}
			randomX.join();
		}
	}
}


