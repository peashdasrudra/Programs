#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <conio.h>

using namespace std;

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 20;
const int GRAVITY = 1;

class Object
{
public:
    int x, y;
    int width, height;
public:
    Object(int x_, int y_, int width_, int height_) : x(x_), y(y_), width(width_), height(height_) {}
    virtual void draw() const = 0;
    virtual void update() = 0;
    bool collide_with(const Object &o) const
    {
        return (x < o.x + o.width && x + width > o.x && y < o.y + o.height && y + height > o.y);
    }
};

class Player : public Object
{
    int vel_y;
public:
    Player(int x_, int y_) : Object(x_, y_, 3, 3), vel_y(0) {}
    void draw() const
    {
        cout << "O\n/|\\\n/ \\\n";
    }
    void update()
    {
        vel_y += GRAVITY;
        y += vel_y;
        if (y >= SCREEN_HEIGHT - height)
        {
            y = SCREEN_HEIGHT - height;
            vel_y = 0;
        }
    }
    void jump()
    {
        vel_y = -10;
    }
};

class Cactus : public Object
{
public:
    Cactus(int x_, int y_) : Object(x_, y_, 3, 4) {}
    void draw() const
    {
        cout << "  ___\n /   \\\n/     \\\n\\     /\n \\___/\n";
    }
    void update()
    {
        x--;
    }
};

class Game
{
    vector<Object*> objects;
    Player player;
    int score;
public:
    Game() : player(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 3), score(0)
    {
        srand(time(NULL));
        for (int i = 0; i < 10; i++)
        {
            int x = SCREEN_WIDTH + i * 20;
            int y = rand() % (SCREEN_HEIGHT - 7) + 2;
            objects.push_back(new Cactus(x, y));
        }
        objects.push_back(&player);
    }
    ~Game()
    {
        for (auto obj : objects)
        {
            delete obj;
        }
    }
    void draw()
    {
        system("cls");
        for (auto obj : objects)
        {
            obj->draw();
        }
        cout << "Score: " << score << endl;
    }
    void update()
    {
        for (auto obj : objects)
        {
            obj->update();
        }
        for (auto obj : objects)
        {
            if (obj != &player && player.collide_with(*obj))
            {
                cout << "Game over! Score: " << score << endl;
                exit(0);
            }
        }
        if (objects[0]->x < -objects[0]->width)
        {
            delete objects[0];
            objects.erase(objects.begin());
            int x = objects.back()->x + 20;
            int y = rand() % (SCREEN_HEIGHT - 7);
            
        }
        
    }
    
    };
