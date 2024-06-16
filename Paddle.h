#pragma once
#ifndef PADDLE_H
#define PADDLE_H
enum direction {
	UP,
	DOWN
};
class Paddle {
public:
	float x;
	float y;
	float width;
	float height;
	float velocity = 0;
	float speed = 1.2f;
	float vertices[12];
	bool ai;

	Paddle(float x, float y, float width, float height, bool ai) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->ai = ai;
		vertices[0] = - width / 2;
		vertices[1] = - height / 2;
		vertices[2] = 0.0f;
		vertices[3] = - width / 2;
		vertices[4] = height / 2;
		vertices[5] = 0.0f;
		vertices[6] = width / 2;
		vertices[7] = - height / 2;
		vertices[8] = 0.0f;
		vertices[9] = width / 2;
		vertices[10] = height / 2;
		vertices[11] = 0.0f;
	}

	void movement(direction d, float deltaTime) {
		if (d == UP && y < 1.0-height/2) {
			velocity = speed * deltaTime;
			y += velocity;
		}
		else if (d == DOWN && y > -1.0+height/2) {
			velocity = -speed * deltaTime;
			y += velocity;
		}
		else {
			velocity = 0;
		}
	}

};

#endif // !PADDLE_H

