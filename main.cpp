#include "Rectangle.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;
/*

- Debe haber un rectángulo en pantalla en todo momento.
- Cuando se de click en la pantalla, el cuadrado se deberá mover a una velocidad razonable hacía donde se dio click.
- Usa la base de código que se proporciona y responde todos los comentarios multilínea que haya (1 en main.cpp y 4 en Rectangle.cpp)


## Navegar en la terminal

1. Dentro de la terminal usa el comando `ls` para listar los archivos y carpetas que hay dentro de la carpeta en la que estás trabajando.
2. Una vez identificando la carpeta a la que quieres entrar utiliza el comando `cd nombre-de-la-carpeta` para entrar a la carpeta. Recuerda que después de escribir parte del nombre de la carpeta puedes presionar la tecla Tab para que se autocomplete el nombre.
3. Una vez dentro de la carpeta de tu proyecto usa el siguiente comando para abrirla en VSCode:
Para abrirlo en una ventana nueva
```
code .
```
Para abrirlo en la misma ventana en la que estás trabajando
```
code . -r
*/
int main()
{
    // setup
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);
    Rectangle rect(Vector2f(30,30));

    // loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed) 
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    rect.setObjective(Mouse::getPosition());
                    rect.update();
                }
            }
            /** (5pts)
                Cuando se de click izquierdo, se deberá actualizar el objetivo del cuadrado a la posición del mouse.
            */

        }

        window.clear();
        rect.update();
        rect.drawTo(window);
        window.display();
    }

    return 0;
}
