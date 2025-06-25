/*
#include <SFML/Graphics.hpp> 
#include <iostream> 
using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(600, 480), "SFML works!");
	CircleShape shape(100.8); // -> �Ȱ��� �� �׷��ּ� ��
	shape.setFillColor(Color::Green);

	RectangleShape rectangle(Vector2f(120, 50));

	// ���� ��� ��������Ʈ�� �ؽ��� ���� 
	Texture t1;
	Sprite background;
	t1.loadFromFile("images/background.png");
	background.setTexture(t1);
	// ȭ�鿡 ��������Ʈ�� �׸���. 
	window.draw(background);

	Font font;
	Text text;
	if (!font.loadFromFile("OpenSans-Bold.ttf")) {
		cout << "��Ʈ ������ ������ �� ����!" << endl;
	}
	text.setFont(font);                // ��Ʈ ����
	text.setString("Hello world");     // ��� ���ڿ�

	text.setCharacterSize(24);         // ��Ʈ ũ��

	text.setFillColor(Color::Red); // ��Ʈ ����

	// text ��ġ ���� -> �� �� ��~~??!!!
	text.setPosition(100, 100);
	text.move(50, 50);

	// ��Ÿ�� ����
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	window.draw(text);      // �ؽ�Ʈ ���

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Ű���� �̺�Ʈ ó��
		if (Keyboard::isKeyPressed(Keyboard::Left))
			cout << "Left" << endl;
			Vector2i position = Mouse::getPosition();
			cout << position.x << ", " << position.y << endl;
		if (Keyboard::isKeyPressed(Keyboard::Right))
			cout << "Right" << endl;
			Vector2i position = Mouse::getPosition();
			cout << position.x << ", " << position.y << endl;

		window.clear();
		window.draw(background);
		window.draw(shape);
		window.draw(text);
		// window.draw(rect); -> �� �� ��~~??!!
		window.display();
	}return 0;
} */

/*
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
using namespace sf;

int main()
{
    srand(time(NULL));

    RenderWindow window(VideoMode(600, 480), "FlappyBird");
    window.setFramerateLimit(60);

    // �̹��� ���ҽ� �ε� �� �ʱ�ȭ
    Texture t_background, t_bird, t_pipe_top, t_pipe_bottom;
    t_bird.loadFromFile("images/bird.png");
    t_background.loadFromFile("images/background.png");
    t_pipe_top.loadFromFile("images/pipe_top.png");
    t_pipe_bottom.loadFromFile("images/pipe_bottom.png");

    Sprite background(t_background), bird(t_bird), pipe_top(t_pipe_top), pipe_bottom(t_pipe_bottom);

    // ���� �ʱ� ����
    bird.setPosition(10, 200);
    pipe_top.setPosition(500, 0);
    pipe_bottom.setPosition(450, 300);

    Font font; // ��Ʈ ��ü 
    Text text; // �ؽ�Ʈ ��ü 

    if (!font.loadFromFile("OpenSans-Bold.ttf")) {
        cout << "��Ʈ ������ ������ �� ����!" << endl;
    }
    text.setFont(font);
    text.setString("Game Over");
    text.setCharacterSize(30);
    text.setPosition(220, 200);

    bool isPlayFlag = true; // ���� ���� ���� �÷��� 
    int gravity = 2; // �߷� ��

    // ���ӷ���
    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed)
                window.close();
        }

        if (isPlayFlag) {
            // Ű���� �Է� ó�� 
            if (Keyboard::isKeyPressed(Keyboard::Up))
                bird.move(0, -gravity * 2);
            else
                bird.move(0, gravity);

            if (pipe_top.getPosition().x < 50)
                pipe_top.setPosition(600, 0);
            else
                pipe_top.move(-2, 0);

            // �浹üũ(Bird vs Pipes, Top, Bottom)
            if (FloatRect(bird.getGlobalBounds()).intersects(pipe_top.getGlobalBounds())
                || FloatRect(bird.getGlobalBounds()).intersects(pipe_bottom.getGlobalBounds())
                || bird.getPosition().y < 0 || bird.getPosition().y > 425) {
                cout << "Game Over" << endl;
                isPlayFlag = false;
            }

            // ������ ��ũ�� �̵� ó�� 
            pipe_top.move(-2, 0);
            pipe_bottom.move(-2, 0);
            auto pipe_top_pos = pipe_top.getPosition();
            auto pipe_bottom_pos = pipe_bottom.getPosition();
            if (pipe_top_pos.x < -50)
                pipe_top.setPosition(650 + rand() % 100, 0);
            if (pipe_bottom_pos.x < -50)
                pipe_bottom.setPosition(650 + rand() % 100, 300);
        }
        else {
            // Game Over ���¿��� �����̽��ٷ� �����
            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                isPlayFlag = true;
                bird.setPosition(10, 200);
                pipe_top.setPosition(500, 0);
                pipe_bottom.setPosition(450, 300);
            }
        }

        // ȭ�� �׸��� 
        window.clear();
        window.draw(background);
        window.draw(bird);
        window.draw(pipe_top);
        window.draw(pipe_bottom);
        if (!isPlayFlag) {
            window.draw(text);
        }
        window.display();
    }
    return 0;
}*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <ctime>

using namespace sf;
using namespace std;

class Bird {
private:
    Sprite bird;
    Texture t_bird;

public:
    Bird(const string& img_path) {
        t_bird.loadFromFile(img_path);
        bird.setTexture(t_bird);
        bird.setPosition(10, 200); // �ʱ� ��ġ ����
    }

    void moveUp(int gravity) {
        bird.move(0, -gravity * 2);
    }

    void moveDown(int gravity) {
        bird.move(0, gravity);
    }

    FloatRect getGlobalBounds() const {
        return bird.getGlobalBounds();
    }

    Vector2f getPosition() const {
        return bird.getPosition();
    }

    void setPosition(float x, float y) {
        bird.setPosition(x, y);
    }

    void draw(RenderWindow& window) const {
        window.draw(bird);
    }
};

class Pipe {
private:
    Sprite pipe;
    Texture t_pipe;

public:
    Pipe(const string& img_path, float x, float y) {
        t_pipe.loadFromFile(img_path);
        pipe.setTexture(t_pipe);
        pipe.setPosition(x, y); // �ʱ� ��ġ ����
    }

    void move(float dx) {
        pipe.move(dx, 0);
    }

    FloatRect getGlobalBounds() const {
        return pipe.getGlobalBounds();
    }

    Vector2f getPosition() const {
        return pipe.getPosition();
    }

    void setPosition(float x, float y) {
        pipe.setPosition(x, y);
    }

    void draw(RenderWindow& window) const {
        window.draw(pipe);
    }
};

class Game {
private:
    RenderWindow window;
    Sprite background;
    Texture t_background;
    Bird bird;
    Pipe pipe_top;
    Pipe pipe_bottom;
    Text gameOverText;
    Font font;
    bool isPlayFlag;
    int gravity;

public:
    Game()
        : bird("images/bird.png"),
        pipe_top("images/pipe_top.png", 500, 0),
        pipe_bottom("images/pipe_bottom.png", 450, 300),
        isPlayFlag(true),
        gravity(2) {

        // ������ ����
        window.create(VideoMode(600, 480), "FlappyBird");
        window.setFramerateLimit(60);

        // ��� �ؽ�ó �ε�
        t_background.loadFromFile("images/background.png");
        background.setTexture(t_background);

        // ��Ʈ �� �ؽ�Ʈ �ʱ�ȭ
        if (!font.loadFromFile("OpenSans-Bold.ttf")) {
            cout << "��Ʈ ������ �� �� �����ϴ�!" << endl;
        }
        gameOverText.setFont(font);
        gameOverText.setString("Game Over");
        gameOverText.setCharacterSize(30);
        gameOverText.setPosition(220, 200);
    }

    void inputProc() {
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            bird.moveUp(gravity);
        }
        else {
            bird.moveDown(gravity);
        }
    }

    void update() {
        // ������ �̵�
        pipe_top.move(-2);
        pipe_bottom.move(-2);

        // �������� ȭ�� �������� ������ �缳��
        if (pipe_top.getPosition().x < -50) {
            pipe_top.setPosition(650 + rand() % 100, 0);
        }
        if (pipe_bottom.getPosition().x < -50) {
            pipe_bottom.setPosition(650 + rand() % 100, 300);
        }

        // �浹 üũ
        if (bird.getGlobalBounds().intersects(pipe_top.getGlobalBounds()) ||
            bird.getGlobalBounds().intersects(pipe_bottom.getGlobalBounds()) ||
            bird.getPosition().y < 0 ||
            bird.getPosition().y > 425) {
            cout << "Game Over" << endl;
            isPlayFlag = false;
        }
    }

    void render() {
        window.clear();
        window.draw(background);
        bird.draw(window);
        pipe_top.draw(window);
        pipe_bottom.draw(window);

        if (!isPlayFlag) {
            window.draw(gameOverText);
        }

        window.display();
    }

    void gameLoop() {
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();
            }

            if (isPlayFlag) {
                inputProc();
                update();
            }
            else {
                // �����̽��ٷ� ���� �����
                if (Keyboard::isKeyPressed(Keyboard::Space)) {
                    isPlayFlag = true;
                    bird.setPosition(10, 200);
                    pipe_top.setPosition(500, 0);
                    pipe_bottom.setPosition(450, 300);
                }
            }

            render();
        }
    }

    void run() {
        gameLoop();
    }
};

int main() {
    Game game; // ���� ��ü ����
    game.run(); // ���� ����
    return 0;
}

