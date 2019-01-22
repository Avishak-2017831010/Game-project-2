#include<SFML\Graphics.hpp>

#include<SFML\Window.hpp>

#include<SFML\System.hpp>

#include<SFML\Audio.hpp>

#include<iostream>

#include<cmath>
#include "time.h"

using namespace sf;

using namespace std;

int main()

{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    // Define some constants

    const   float pi = 3.14159f;

    const int gameWidth = 800;

    const int gameHeight = 600;

    sf::Vector2f paddleSize(25, 100);

    float ballRadius = 10.f;
     int y=0;
     int b=0;
     int menuselect = 1;
     int bh=0;
     int gh=0;
     int cs=0;



    RenderWindow window(VideoMode(gameWidth,gameHeight),"MY GAMES",Style::Resize);

    window.setFramerateLimit(6000);

      window.setVerticalSyncEnabled(true);



    Font font;

    if(!font.loadFromFile("cambriab.ttf"))

        return 42;

   Font font1,font3;
   font1.loadFromFile("alubaba.otf");
   font3.loadFromFile("font3.ttf");

    Texture texte;
    texte.loadFromFile("download.png");
    Sprite sprite;
   sprite.setTexture(texte);
   sprite.setScale(0.8,0.8);


    Texture ai;
    ai.loadFromFile("ai.jpg");
    Sprite aisprite;
    aisprite.setTexture(ai);
    aisprite.setScale(0.3,0.3);
    aisprite.setPosition(680.0,500.0);



   Texture text1;
   text1.loadFromFile("gamemenu.png");
   Sprite sprite1;
   sprite1.setTexture(text1);
   sprite1.setScale(0.5,0.7);

   Texture text3;
   text3.loadFromFile("gameover.jpg");
   Sprite sprite2;
   sprite2.setTexture(text3);
   sprite2.setScale(0.4,0.6);


   Texture text4;
   text4.loadFromFile("help.jpg");
   Sprite sprite3;
   sprite3.setTexture(text4);
   sprite3.setScale(0.3,0.3);

   Texture win;
   win.loadFromFile("win.png");
   Sprite winsprite;
   winsprite.setTexture(win);
   winsprite.setScale(0.8f,0.9f);


   SoundBuffer buffer,over,menumusic;
   buffer.loadFromFile("tennisserve.wav");
   over.loadFromFile("overgame.wav");
   menumusic.loadFromFile("menumusic.wav");
   Sound sound,gameover_sound,intro;
   sound.setBuffer(buffer);
   gameover_sound.setBuffer(over);
   intro.setBuffer(menumusic);

    Text score;
    score.setFont(font1);
    score.setCharacterSize(40);
    score.setFillColor(Color::Red);
    score.setString("Score");
    //score.setPosition(350.0,250.0);



    Text pauseMessage;

    pauseMessage.setFont(font1);

    pauseMessage.setCharacterSize(40);

    pauseMessage.setFillColor(Color::Green);

    pauseMessage.setString("A : New Game");



    Text pauseMessage1;

    pauseMessage1.setFont(font);

    pauseMessage1.setCharacterSize(30);

    pauseMessage1.setPosition(30.0f, 550.f);

    pauseMessage1.setFillColor(Color::Red);

    Text pauseMessage2;

    pauseMessage2.setFont(font1);

    pauseMessage2.setCharacterSize(30);

    pauseMessage2.setFillColor(Color::Green);

    pauseMessage2.setString("B : Instructions");


     Text pauseMessage3;

    pauseMessage3.setFont(font1);

    pauseMessage3.setCharacterSize(30);

    pauseMessage3.setFillColor(Color::Green);

    pauseMessage3.setString("C : Exit");

    Text pau;
    pau.setFont(font3);
    pau.setCharacterSize(30);
    pau.setPosition(150.0f, 420.f);
    pau.setFillColor(Color::Red);
    pau.setString("=>. Right paddle is played by Computer.");
    Text pau1;
    pau1.setFont(font3);
    pau1.setCharacterSize(30);
    pau1.setPosition(150.0f, 470.f);
    pau1.setFillColor(Color::Red);
    pau1.setString("=>. Left Paddle  is played by you");
    Text pau2;
    pau2.setFont(font3);
    pau2.setCharacterSize(30);
    pau2.setPosition(150.0f, 520.f);
    pau2.setFillColor(Color::Red);
    pau2.setString("=>. Press up and down button to move your paddle");


   /* Text pauseMessage5;

    pauseMessage5.setFont(font);

    pauseMessage5.setCharacterSize(40);

    pauseMessage5.setFillColor(Color::Red);

    pauseMessage5.setPosition(350.0,250.0);*/



     // Create the left paddle

    sf::RectangleShape leftPaddle;

    leftPaddle.setSize(paddleSize - sf::Vector2f(3, 3));

    leftPaddle.setOutlineThickness(3);

    leftPaddle.setOutlineColor(sf::Color::White);

    leftPaddle.setFillColor(sf::Color::White);

    leftPaddle.setOrigin(paddleSize / 2.f);





    // Create the right paddle

    sf::RectangleShape rightPaddle;

    rightPaddle.setSize(paddleSize - sf::Vector2f(3, 3));

    rightPaddle.setOutlineThickness(3);

    rightPaddle.setOutlineColor(sf::Color::Black);

    rightPaddle.setFillColor((sf::Color::Black));

    rightPaddle.setOrigin(paddleSize / 2.f);



    // Create the ball

    sf::CircleShape ball;

    ball.setRadius(ballRadius - 3);

    ball.setOutlineThickness(3);

    ball.setOutlineColor(sf::Color::Black);

    ball.setFillColor(sf::Color::Red);

    ball.setOrigin(ballRadius / 2, ballRadius / 2);



   // Define the paddles properties

    sf::Clock AITimer;

    const sf::Time AITime   = sf::seconds(0.1f);

     float paddleSpeed = 400.f;

    float rightPaddleSpeed  = 0.f;

     float ballSpeed   = 400.f;

    float ballAngle         = 0.0f; // to be changed later

    Text Play,Instructions,Exit;

    bool Menu=true;







    sf::Clock clock;

    bool isPlaying = false;

   bool ch =true;
   int k=1;

    while(window.isOpen())

    {
      //  intro.play();

        Event event;

        while(window.pollEvent(event))

        {


            if(isPlaying == false)
            {
                gh=gh+1;
                if(gh == 1)
                {
                    intro.play();
                }

            }

          if ((event.type == sf::Event::Closed) ||

               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::C)))

            {

                window.close();

                break;

            }
            if ((event.type == sf::Event::Closed) ||

               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::B)))
               {

                     bh=1;
               }

              if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::A))

            {

                if (!isPlaying)

                {
                    // (re)start the game

                   // intro.play();


                    isPlaying = true;
                  //intro.stop();
                     clock.restart();



                      // Reset the position of the paddles and ball

                    leftPaddle.setPosition(10 + paddleSize.x / 2, gameHeight / 2);

                    rightPaddle.setPosition(gameWidth - 10 - paddleSize.x / 2, gameHeight / 2);

                    ball.setPosition(gameWidth / 2, gameHeight / 2);






                      do

                    {

                        // Make sure the ball initial angle is not too much vertical

                        ballAngle = (std::rand() % 360) * 2 * pi / 360;

                    }

                    while (std::abs(std::cos(ballAngle)) < 0.7f);

                }

            }

        }

        if(isPlaying)

        {
            intro.stop();
            //intro.play();



        float deltaTime = clock.restart().asSeconds();





            // Move the player's paddle

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&

               (leftPaddle.getPosition().y - paddleSize.y / 2 > 5.f))

            {

                leftPaddle.move(0.f, -paddleSpeed * deltaTime);

            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&

               (leftPaddle.getPosition().y + paddleSize.y / 2 < gameHeight - 5.f))

            {

                leftPaddle.move(0.f, paddleSpeed * deltaTime);

            }



            // Move the computer's paddle

            if (((rightPaddleSpeed < 0.f) && (rightPaddle.getPosition().y - paddleSize.y / 2 > 5.f)) ||

                ((rightPaddleSpeed > 0.f) && (rightPaddle.getPosition().y + paddleSize.y / 2 < gameHeight - 5.f)))

            {

                rightPaddle.move(0.f, rightPaddleSpeed * deltaTime);

            }



            // Update the computer's paddle direction according to the ball position

            if (AITimer.getElapsedTime() > AITime)

            {

                AITimer.restart();

                if (ball.getPosition().y + ballRadius > rightPaddle.getPosition().y + paddleSize.y / 2)

                    rightPaddleSpeed = paddleSpeed;

                else if (ball.getPosition().y - ballRadius < rightPaddle.getPosition().y - paddleSize.y / 2)

                    rightPaddleSpeed = -paddleSpeed;

                else

                    rightPaddleSpeed = 0.f;

            }



             float factor = ballSpeed * deltaTime;

            ball.move(std::cos(ballAngle) * factor, std::sin(ballAngle) * factor);



            // Check collisions between the ball and the screen

            if (ball.getPosition().x - ballRadius < 0.f)

            {


                isPlaying = false;
                gameover_sound.play();

               // pauseMessage5.setString("You lost!\nPress space to restart or\nescape to exit");
               b=1;
            }

            if (ball.getPosition().x + ballRadius > gameWidth)

            {

                isPlaying = false;

               // pauseMessage5.setString("You won!\nPress space to restart or\nescape to exit");
                   b=1;
                   gameover_sound.play();
                   cs=1;

            }

            if (ball.getPosition().y - ballRadius < 0.f)

            {

                sound.play();

               ballAngle = -ballAngle;

                ball.setPosition(ball.getPosition().x, ballRadius + 0.1f);

            }

            if (ball.getPosition().y + ballRadius > gameHeight)

            {

            sound.play();

                ballAngle = -ballAngle;

                ball.setPosition(ball.getPosition().x, gameHeight - ballRadius - 0.1f);

            }



            // Check the collisions between the ball and the paddles

            // Left Paddle

            if (ball.getPosition().x - ballRadius < leftPaddle.getPosition().x + paddleSize.x / 2 &&

                ball.getPosition().x - ballRadius > leftPaddle.getPosition().x &&

                ball.getPosition().y + ballRadius >= leftPaddle.getPosition().y - paddleSize.y / 2 &&

                ball.getPosition().y - ballRadius <= leftPaddle.getPosition().y + paddleSize.y / 2)

            {

                if (ball.getPosition().y > leftPaddle.getPosition().y)

                    ballAngle = pi - ballAngle + (std::rand() % 20) * pi / 180;

                else

                    ballAngle = pi - ballAngle - (std::rand() % 20) * pi / 180;



               sound.play();
               y++;
               char arr[100];
               sprintf(arr,"Score : %d",y);
               pauseMessage1.setString(arr);
                ball.setPosition(leftPaddle.getPosition().x + ballRadius + paddleSize.x / 2 + 0.1f, ball.getPosition().y);
                if(y == 5)
                {
                    ballSpeed = 500.0f;
                    paddleSpeed = 450.0f;
                }
                if( y == 10)
                {
                    ballSpeed = 550.0f;
                    paddleSpeed = 500;
                }
                if(y == 15)
                {
                    ballSpeed=600.0f;
                    paddleSpeed = 550.0f;
                }
                if(y == 20)
                {
                    ballSpeed=650.0f;
                    paddleSpeed = 600.0f;
                }
                if(y == 25)
                {
                    ballSpeed=700.0f;
                    paddleSpeed = 650.0f;
                }
                if(y == 30)
                {
                    ballSpeed=750.0f;
                    paddleSpeed = 700.0f;
                }
                if(y>30){
                    ballSpeed=1000.0f;
                    paddleSpeed=850.0f;
                }

            }



            // Right Paddle

            if (ball.getPosition().x + ballRadius > rightPaddle.getPosition().x - paddleSize.x / 2 &&

                ball.getPosition().x + ballRadius < rightPaddle.getPosition().x &&

                ball.getPosition().y + ballRadius >= rightPaddle.getPosition().y - paddleSize.y / 2 &&

                ball.getPosition().y - ballRadius <= rightPaddle.getPosition().y + paddleSize.y / 2)

            {

                if (ball.getPosition().y > rightPaddle.getPosition().y)

                    ballAngle = pi - ballAngle + (std::rand() % 20) * pi / 180;

                else

                    ballAngle = pi - ballAngle - (std::rand() % 20) * pi / 180;



                sound.play();

                ball.setPosition(rightPaddle.getPosition().x - ballRadius - paddleSize.x / 2 - 0.1f, ball.getPosition().y);

            }





        }




    window.clear();




        if (isPlaying)

        {

            // Draw the paddles and the ball
           window.draw(sprite);

            window.draw(leftPaddle);

            window.draw(rightPaddle);

            window.draw(ball);
            window.draw(pauseMessage1);


        }

        else

        {

            // Draw the pause message

                if(b==1)
                {
                    if(cs==1)
                    {
                        window.draw(winsprite);
                    }


                 else{ char arr[100];
               sprintf(arr,"Score : %d",y);
               score.setString(arr);
               score.setPosition(280.0f,450.0f);


                window.draw(sprite2);
                window.draw(score);
                sleep(milliseconds(20));
                 }





                }

                else if(bh == 1)
                {

                    window.draw(sprite3);
                    window.draw(pau);
                    window.draw(pau1);
                    window.draw(pau2);
                }

                else
                {

                pauseMessage.setPosition(60.0,150.0);
                pauseMessage2.setPosition(60.0,250.0);
                pauseMessage3.setPosition(60.0,350.0);
                window.clear();
                window.draw(sprite1);
                window.draw(aisprite);
                window.draw(pauseMessage);
                window.draw(pauseMessage2);
                window.draw(pauseMessage3);
                //y=0;
                }
               // y=0;

        }




        // Display things on screen

        window.display();

    }
    //y=0;
    intro.stop();
    isPlaying = true;
   // y=0;
    return EXIT_SUCCESS;


}

