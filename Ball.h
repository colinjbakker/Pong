#pragma once
#ifndef BALL_H
#define BALL_H
#include <glm/glm.hpp>
class Ball 
{
public:
	float x;
	float y;
	float direction;
	float speed;
	float vertices[36];

	Ball() {
		x = 0.0f;
		y = 0.0f;
		direction = 15.0f;
		speed = 2.0f;
		for (int i = 0; i < 12; i++) {
			vertices[i*3] = cos(glm::radians(30.0f * i)) * 0.05 * 0.6 + x;
			vertices[i*3 + 1] = sin(glm::radians(30.0f * i)) * 0.05 * 0.8 + y;
			vertices[i*3 + 2] = 0.0f;
		}
	}

	float* getVertices() {
		return vertices;
	}

	void processFrame(float deltaTime, float playerY, float aiY, float playerV, float aiV, float height) {
		if (x > 0.93f && x < 0.96f) {
			if (y < playerY + height / 2 && y > playerY - height / 2) {
				if (playerV == 0.0f) {
					direction = 180.0f - direction;
				}
				else if (playerV > 0.0f) {
					direction = 180.0f - direction - 10.0f;
				}
				else {
					direction = 180.0f - direction + 10.0f;
				}
				x = 0.929f;
			}
		}
		if (x < -0.93f && x > -0.96f) {
			if (y < aiY + height / 2 && y > aiY - height / 2) {
				if (aiV == 0.0f) {
					direction = 180.0f - direction;
				}
				else if (aiV > 0.0f) {
					direction = 180.0f - direction;
				}
				else {
					direction = 180.0f - direction - 10.0f;
				}
				x = -0.929f;
			}
		}
		if (y > 0.95f) {
			direction = -direction;
			y = 0.949f;
		}
		else if (y < -0.95f) {
			direction = -direction;
			y = -0.949f;
		}

		x += (speed * deltaTime) * cos(glm::radians(direction));
		y += (speed * deltaTime) * sin(glm::radians(direction));

		if (x > 1.1f || x < -1.1f) {
			x = 0.0f;
			y = 0.0f;
			direction = 0.0f;
		}
	}
};
#endif // !BALL_H
