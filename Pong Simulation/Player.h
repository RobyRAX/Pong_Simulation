#include "pch.h"
#include <iostream>

using namespace std;

class Player {
private:
	enum player { playerX = 1, playerY = 2 };//sejenis variabel yang memungkinkan kita memberi alias pada suatu nilai
	int hits;

public:
	void turn(int inputHits)//isi Hits
	{
		hits = inputHits;
		cout << hits << endl;
	}
	int getHits()//fungsi getter untuk mengambil nilai Hits agar bisa digunakan sebagai kondisi
	{
		return hits;
	}
};

