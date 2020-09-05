#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>
using namespace sf;
using namespace std;

int randomHeight=0, part=1;
int iteration=0;
int cont=0,limit=150;
int pos=0;
struct data
{
    int height;
    int posX;
}line[151];


int main()
{
    RenderWindow window(VideoMode(1280,1024), "BUBBLE SORT", Style::Default);
    //Background
    Sprite background;
    Texture backGroundTex;
    backGroundTex.loadFromFile("Textures/background.png");
    background.setTexture(backGroundTex);
    background.setScale(1.f,1.5f);
    //Rectangles
    RectangleShape rectangle;
    rectangle.setFillColor(Color::Red);
    rectangle.setOutlineThickness(1.f);
    rectangle.setOutlineColor(Color::Black);
    rectangle.setSize(Vector2f(10.f,100.f));

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }
        }


    if(part==2)
    {
        if(line[iteration].height<line[iteration+1].height)
        {
            swap(line[iteration].height,line[iteration+1].height);
        }
    }


    if(part==1)
    {
        int i=0;
        while(i<151)
        {
            randomHeight=1*(rand()%600+80);
            line[i].posX=pos;
            line[i].height=randomHeight;
            i++;
            pos+=10;
            if(i==150)
            {
                part=2;
            }
            
        }
       
        
    }



        window.clear();
        window.draw(background);
        for(int i=0; i<=400; i++)
        {
            rectangle.setFillColor(Color::Red);
            if(i==iteration)
            {
                rectangle.setFillColor(Color::Blue);
            }
            rectangle.setPosition(line[i].posX,750);
            rectangle.setSize(Vector2f(10,line[i].height));
            rectangle.setRotation(180);
            window.draw(rectangle);
        }
        window.display();
        iteration++;
        if(iteration>=limit)
        {
            iteration=0;
            limit--;
        }
    }


    return 0;
}
