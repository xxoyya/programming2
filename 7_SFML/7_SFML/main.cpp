/*
#include <SFML/Graphics.hpp> 
#include <iostream> 
using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(600, 480), "SFML works!");
	CircleShape shape(100.8); // -> 팔각형 안 그려주셔 ㅜ
	shape.setFillColor(Color::Green);

	RectangleShape rectangle(Vector2f(120, 50));

	// 게임 배경 스프라이트와 텍스쳐 생성 
	Texture t1;
	Sprite background;
	t1.loadFromFile("images/background.png");
	background.setTexture(t1);
	// 화면에 스프라이트를 그린다. 
	window.draw(background);

	Font font;
	Text text;
	if (!font.loadFromFile("OpenSans-Bold.ttf")) {
		cout << "폰트 파일을 오픈할 수 없음!" << endl;
	}
	text.setFont(font);                // 폰트 설정
	text.setString("Hello world");     // 출력 문자열

	text.setCharacterSize(24);         // 폰트 크기

	text.setFillColor(Color::Red); // 폰트 색상

	// text 위치 변경 -> 왜 안 돼~~??!!!
	text.setPosition(100, 100);
	text.move(50, 50);

	// 스타일 설정
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	window.draw(text);      // 텍스트 출력

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// 키보드 이벤트 처리
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
		// window.draw(rect); -> 왜 안 돼~~??!!
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

    // 이미지 리소스 로드 및 초기화
    Texture t_background, t_bird, t_pipe_top, t_pipe_bottom;
    t_bird.loadFromFile("images/bird.png");
    t_background.loadFromFile("images/background.png");
    t_pipe_top.loadFromFile("images/pipe_top.png");
    t_pipe_bottom.loadFromFile("images/pipe_bottom.png");

    Sprite background(t_background), bird(t_bird), pipe_top(t_pipe_top), pipe_bottom(t_pipe_bottom);

    // 게임 초기 설정
    bird.setPosition(10, 200);
    pipe_top.setPosition(500, 0);
    pipe_bottom.setPosition(450, 300);

    Font font; // 폰트 객체 
    Text text; // 텍스트 객체 

    if (!font.loadFromFile("OpenSans-Bold.ttf")) {
        cout << "폰트 파일을 오픈할 수 없음!" << endl;
    }
    text.setFont(font);
    text.setString("Game Over");
    text.setCharacterSize(30);
    text.setPosition(220, 200);

    bool isPlayFlag = true; // 게임 진행 상태 플래그 
    int gravity = 2; // 중력 값

    // 게임루프
    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed)
                window.close();
        }

        if (isPlayFlag) {
            // 키보드 입력 처리 
            if (Keyboard::isKeyPressed(Keyboard::Up))
                bird.move(0, -gravity * 2);
            else
                bird.move(0, gravity);

            if (pipe_top.getPosition().x < 50)
                pipe_top.setPosition(600, 0);
            else
                pipe_top.move(-2, 0);

            // 충돌체크(Bird vs Pipes, Top, Bottom)
            if (FloatRect(bird.getGlobalBounds()).intersects(pipe_top.getGlobalBounds())
                || FloatRect(bird.getGlobalBounds()).intersects(pipe_bottom.getGlobalBounds())
                || bird.getPosition().y < 0 || bird.getPosition().y > 425) {
                cout << "Game Over" << endl;
                isPlayFlag = false;
            }

            // 파이프 스크롤 이동 처리 
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
            // Game Over 상태에서 스페이스바로 재시작
            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                isPlayFlag = true;
                bird.setPosition(10, 200);
                pipe_top.setPosition(500, 0);
                pipe_bottom.setPosition(450, 300);
            }
        }

        // 화면 그리기 
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
        bird.setPosition(10, 200); // 초기 위치 설정
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
        pipe.setPosition(x, y); // 초기 위치 설정
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

        // 윈도우 생성
        window.create(VideoMode(600, 480), "FlappyBird");
        window.setFramerateLimit(60);

        // 배경 텍스처 로드
        t_background.loadFromFile("images/background.png");
        background.setTexture(t_background);

        // 폰트 및 텍스트 초기화
        if (!font.loadFromFile("OpenSans-Bold.ttf")) {
            cout << "폰트 파일을 열 수 없습니다!" << endl;
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
        // 파이프 이동
        pipe_top.move(-2);
        pipe_bottom.move(-2);

        // 파이프가 화면 왼쪽으로 나가면 재설정
        if (pipe_top.getPosition().x < -50) {
            pipe_top.setPosition(650 + rand() % 100, 0);
        }
        if (pipe_bottom.getPosition().x < -50) {
            pipe_bottom.setPosition(650 + rand() % 100, 300);
        }

        // 충돌 체크
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
                // 스페이스바로 게임 재시작
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
    Game game; // 게임 객체 생성
    game.run(); // 게임 실행
    return 0;
}

