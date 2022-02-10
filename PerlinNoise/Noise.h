#pragma once
#include <SFML/Graphics.hpp>

class Noise {
public:
	Noise();
	double time{ 0 };
	sf::VertexArray vA{ sf::Points,800 * 800 };
	int p[512];
	double fade(double t) { return t * t * t * (t * (t * 6 - 15) + 10); }
	double lerp(double t, double a, double b) { return a + t * (b - a); }
	double grad(int hash, double x, double y, double z) {
		int h = hash & 15;                      // CONVERT LO 4 BITS OF HASH CODE
		double u = h < 8 ? x : y,                 // INTO 12 GRADIENT DIRECTIONS.
			v = h < 4 ? y : h == 12 || h == 14 ? x : z;
		return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
	}
	double noise(double x, double y, double z);
	void update();
	void updatePerlin(double time);


};