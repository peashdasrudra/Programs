#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include<cmath>
#include <ctime>
#include <pthread.h>

using namespace std;

// Constants for the game
const int MAX_JUMP_HEIGHT = 10;
const int OBSTACLE_FREQUENCY = 4;
const int OBSTACLE_GAP_SIZE = 5;

// Function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    static bool initialized = false;
    if (!initialized) {
        srand(time(NULL));
        initialized = true;
    }
    return rand() % (max - min + 1) + min;
}

// Class for the Dino object
class Dino {
public:
    // Constructor
    Dino() {
        height = 0;
        isJumping = false;
    }

    // Function to jump
    void jump() {
        if (!isJumping) {
            isJumping = true;
            jumpStartTime = chrono::high_resolution_clock::now();
        }
    }

    // Function to update the state of the Dino
    void update() {
        if (isJumping) {
            auto currentTime = chrono::high_resolution_clock::now();
            double jumpDuration = chrono::duration_cast<chrono::milliseconds>(currentTime - jumpStartTime).count();

            if (jumpDuration < JUMP_TIME) {
                height = MAX_JUMP_HEIGHT * (1 - pow((jumpDuration / JUMP_TIME) - 1, 2));
            }
            else {
                height = 0;
                isJumping = false;
            }
        }
    }

    // Function to get the height of the Dino
    int getHeight() const {
        return height;
    }

private:
    static const int JUMP_TIME = 500; // in milliseconds

    int height;
    bool isJumping;
    chrono::time_point<chrono::high_resolution_clock> jumpStartTime;
};

// Class for the Obstacle object
class Obstacle {
public:
    // Constructor
    Obstacle(int x) {
        position = x;
    }

    // Function to move the obstacle
    void move() {
        position--;
    }

    // Function to check if the obstacle collides with the Dino
    bool collidesWith(const Dino& dino) const {
        if (dino.getHeight() == 0 && position <= 0) {
            return true;
        }
        return false;
    }

    // Function to check if the obstacle is off the screen
    bool isOffScreen() const {
        return position <= -1;
    }

    // Function to get the position of the obstacle
    int getPosition() const {
        return position;
    }

private:
    int position;
};

// Function to clear the screen
void clearScreen() {
    cout << string(50, '\n');
}

// Function to draw the game
void draw(const Dino& dino, const vector<Obstacle>& obstacles) {
    cout << string(dino.getHeight(), '\n');

    for (int i = 0; i < obstacles.size(); i++) {
        cout << string(obstacles[i].getPosition(), ' ') << "X\n";
    }

    cout << string(10 - dino.getHeight(), '\n');
}

int main() {
    Dino dino;
    vector<Obstacle> obstacles;
    int obstacleCounter = 0;

    while (true) {
        // Update the Dino and the Obstacles
        dino.update();
        for (int i = 0; i < obstacles.size(); i++) {
    obstacles[i].move();

    if (obstacles[i].collidesWith(dino)) {
        cout << "Game Over!" << endl;
        return 0;
    }

    if (obstacles[i].isOffScreen()) {
        obstacles.erase(obstacles.begin() + i);
    }
}

             // Generate a new obstacle with a certain frequency
        if (obstacleCounter == OBSTACLE_FREQUENCY) {
            obstacles.push_back(Obstacle(50));
            obstacleCounter = 0;
        }
        obstacleCounter++;

        // Draw the game
        clearScreen();
        draw(dino, obstacles);

        // Handle input
        if (cin.get() == ' ') {
            dino.jump();
        }

        // Wait for some time before refreshing the screen
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}


