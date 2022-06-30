

#include "View.hpp"
#include "Mesh.h"
#include <SFML/Window.hpp>

using namespace sf;
using namespace engine;

int main()
{
    

    constexpr auto window_width = 1600u;
    constexpr auto window_height = 900u;

    
    Matrix44 identity(1);

     
    Window window(VideoMode(window_width, window_height), "Render", Style::Titlebar | Style::Close);

    //Crea la vista y la camara
    View   view(window_width, window_height);
    view.projection = perspective(20, 1, 15, float(window_width) / window_height);
    view.camera = new Camera(engine::Vector3f{ 0.f,50.f,-28.f }, (90.f * 3.14f) / 180.f);

   
    window.setVerticalSyncEnabled(true);
    
    //Array de objetos de la escena
    const int count_objects = 14;
    Mesh* objects[count_objects];

    //Bool para determinat que ruta se sigue para obtener los objetos de la escena
    bool is_exe = false;

    if (is_exe == false)
    {
        #pragma region Ruta Objetos Proyecto


        //Floor
        objects[13] = new Mesh(&view, "../../binaries/assets/model.obj", false, 0, 121, 0);

        //Tents
        objects[0] = new Mesh(&view, "../../binaries/assets/Casita.obj", true, 0, 0, 250);
        objects[1] = new Mesh(&view, "../../binaries/assets/Casita.obj", true, 0, 0, 250);
        objects[2] = new Mesh(&view, "../../binaries/assets/Casita.obj", true, 0, 0, 250);
        objects[3] = new Mesh(&view, "../../binaries/assets/Casita.obj", true, 0, 0, 250);

        // Trees
        objects[4] = new Mesh(&view, "../../binaries/assets/Arbolito.obj", false, 0, 200, 0);
        objects[5] = new Mesh(&view, "../../binaries/assets/Arbolito.obj", false, 0, 200, 0);
        objects[6] = new Mesh(&view, "../../binaries/assets/Arbolito.obj", false, 0, 200, 0);
        objects[7] = new Mesh(&view, "../../binaries/assets/Arbolito.obj", false, 0, 200, 0);
        objects[8] = new Mesh(&view, "../../binaries/assets/Arbolito.obj", false, 0, 200, 0);
        objects[9] = new Mesh(&view, "../../binaries/assets/Arbolito.obj", false, 0, 200, 0);
        objects[10] = new Mesh(&view, "../../binaries/assets/Arbolito.obj", false, 0, 200, 0);

        //Rabbit
        objects[11] = new Mesh(&view, "../../binaries/assets/stanford-bunny.obj", false, 138, 92, 6);

        //Campfire
        objects[12] = new Mesh(&view, "../../binaries/assets/Campfire_clean.obj", false, 100, 0, 0);


#pragma endregion
    }
    else
    {
        #pragma region Ruta Objetos EXE
        //Floor
        objects[13] = new Mesh(&view, "assets/model.obj", false, 0, 121, 0);

        //Tents
        objects[0] = new Mesh(&view, "assets/Casita.obj", true, 0, 0, 250);
        objects[1] = new Mesh(&view, "assets/Casita.obj", true, 0, 0, 250);
        objects[2] = new Mesh(&view, "assets/Casita.obj", true, 0, 0, 250);
        objects[3] = new Mesh(&view, "assets/Casita.obj", true, 0, 0, 250);

        // Trees
        objects[4] = new Mesh(&view, "assets/Arbolito.obj", false, 0, 200, 0);
        objects[5] = new Mesh(&view, "assets/Arbolito.obj", false, 0, 200, 0);
        objects[6] = new Mesh(&view, "assets/Arbolito.obj", false, 0, 200, 0);
        objects[7] = new Mesh(&view, "assets/Arbolito.obj", false, 0, 200, 0);
        objects[8] = new Mesh(&view, "assets/Arbolito.obj", false, 0, 200, 0);
        objects[9] = new Mesh(&view, "assets/Arbolito.obj", false, 0, 200, 0);
        objects[10] = new Mesh(&view, "assets/Arbolito.obj", false, 0, 200, 0);

        //Rabbit
        objects[11] = new Mesh(&view, "assets/stanford-bunny.obj", false, 138, 92, 6);

        //Campfire
        objects[12] = new Mesh(&view, "assets/Campfire_clean.obj", false, 100, 0, 0);
#pragma endregion
    }
   
#pragma region Transformaciones de mallas

    //Floor
    objects[13]->translation = translate(identity, engine::Vector3f{ 3.f, 3.f, -27.f });
    objects[13]->scaling = scale(identity, 28.55f);

    //Tents
    objects[0]->translation = translate(identity, engine::Vector3f{ -10.f, 0.f, -22.f });
    objects[0]->scaling = scale(identity, 0.2f);
    objects[0]->rotation_y = rotate_around_y(identity, 45);

    objects[1]->translation = translate(identity, engine::Vector3f{ 10.f, 0.f, -20.f });
    objects[1]->scaling = scale(identity, 0.2f);
    objects[1]->rotation_y = rotate_around_y(identity, 90);

    objects[2]->translation = translate(identity, engine::Vector3f{ -7.f, 0.f, -38.f });
    objects[2]->scaling = scale(identity, 0.2f);
    objects[2]->rotation_y = rotate_around_y(identity, 90);

    objects[3]->translation = translate(identity, engine::Vector3f{ 14.f, 0.f, -35.f });
    objects[3]->scaling = scale(identity, 0.2f);
    objects[3]->rotation_y = rotate_around_y(identity, 85);

    // Trees
    objects[4]->translation = translate(identity, engine::Vector3f{ 18.f, 0.f, -23.f });
    objects[4]->scaling = scale(identity, 0.8f);
    objects[4]->rotation_y = rotate_around_y(identity, 85);

    objects[5]->translation = translate(identity, engine::Vector3f{ 14.f, 0.f, -40.f });
    objects[5]->scaling = scale(identity, 0.2f);
    objects[5]->rotation_y = rotate_around_y(identity, 85);

    objects[6]->translation = translate(identity, engine::Vector3f{ -2.f, 0.f, -18.f });
    objects[6]->scaling = scale(identity, 0.9f);
    objects[6]->rotation_y = rotate_around_y(identity, 85);

    objects[7]->translation = translate(identity, engine::Vector3f{ -18.f, 0.f, -28.f });
    objects[7]->scaling = scale(identity, 0.6f);
    objects[7]->rotation_y = rotate_around_y(identity, 85);

    objects[8]->translation = translate(identity, engine::Vector3f{ -18.f, 0.f, -32.f });
    objects[8]->scaling = scale(identity, 0.3f);
    objects[8]->rotation_y = rotate_around_y(identity, 85);

    objects[9]->translation = translate(identity, engine::Vector3f{ -19.f, 0.f, -12.f });
    objects[9]->scaling = scale(identity, 0.5f);
    objects[9]->rotation_y = rotate_around_y(identity, 85);

    objects[10]->translation = translate(identity, engine::Vector3f{ 14.f, 0.f, -10.f });
    objects[10]->scaling = scale(identity, 0.4f);
    objects[10]->rotation_y = rotate_around_y(identity, 85);

    //Rabbit
    objects[11]->translation = translate(identity, engine::Vector3f{ 0.f, 0.f, -10.f });
    objects[11]->scaling = scale(identity, 0.8f);
    objects[11]->rotation_y = rotate_around_y(identity, 85);

    //Campfire
    objects[12]->translation = translate(identity, engine::Vector3f{ 0.f, 0.f, -27.f });
    objects[12]->scaling = scale(identity, 0.03f);
    objects[12]->rotation_y = rotate_around_y(identity, 85);

#pragma endregion 


    bool perspective = false;

    bool light = false;

    bool exit = false;

    float camera_angle = 0;

    float camera_displacement = 0;

    float bunny_angle = 0;


    // Run the main loop:
    do
    {
        Event event;

        while (window.pollEvent (event))
        {
            switch (event.type)
            {
                case Event::Closed: 
                {
                    exit = true;
                    break;
                }
                case Event::KeyPressed:
                {
                    switch (event.key.code)
                    {

                        case Keyboard::Num1: //Camara 90 grados desde arriba
                        {
                            perspective = false;
                            view.camera->set_camera(engine::Vector3f{ 0,50,-28 }, (90.f * 3.14f) / 180.f);

                            break;
                        }
                        case Keyboard::Num2: // Camara con perspectiva
                        {
                            view.camera->set_camera(engine::Vector3f{ 3,30,-0 }, (130.f * 3.14f) / 180.f);
                            view.camera->rotation_z = rotate_around_z(identity, (0 * 3.14) / 180.f);
                            perspective = true;
                            break;
                        }

                        case Keyboard::D: //Girar derecha
                        {
                          
                            if (!perspective && camera_angle> -10)
                            {
                                view.camera->rotation_z = rotate_around_z(identity, (camera_angle * 3.14f) / 180.f);
                                camera_angle -= 1;
                            }

                            break;
                        }
                        case Keyboard::A: // Girar Izquierda
                        {
                            
                            if (!perspective && camera_angle < 10)
                            {
                                view.camera->rotation_z = rotate_around_z(identity, (camera_angle * 3.14f) / 180.f);
                                camera_angle += 1;
                            }

                            break;
                        }
                        case Keyboard::W: //Hacia delante
                        {
                            if (!perspective)
                                view.camera->translation = translate(identity, engine::Vector3f{ 0,50 + camera_displacement,-28 });                               
                            else
                                view.camera->translation = translate(identity, engine::Vector3f{ 3,30 + camera_displacement,0 + camera_displacement });
                            
                            camera_displacement -= 0.5;
                            break;
                        }
                        case Keyboard::S: // Hacia atras
                        {
                            if (!perspective)
                                view.camera->translation = translate(identity, engine::Vector3f{ 0,50 + camera_displacement,-28 });
                            else
                                view.camera->translation = translate(identity, engine::Vector3f{ 3,30 + camera_displacement,0 + camera_displacement });

                            camera_displacement += 0.5;
                            break;
                        }
                        case Keyboard::Q: //Poner o no iluminacion
                        {
                           
                            light = !light;

                            break;
                        }
                    }
                }
            }                        
        }

        //------------------------------------------------UPDATE-------------------------
        

        //Movimiento Conejo
        objects[11]->translation = translate(objects[11]->translation, engine::Vector3f{cosf((bunny_angle * 3.14f) / 180.f),0,sinf((bunny_angle * 3.14f) / 180.f)});

        view.update(objects, count_objects);

        bunny_angle-= 3.f;

        //------------------------------------------------RENDER-------------------------

        view.render(objects, count_objects, light);
     

        window.display ();
    }
    while (not exit);

    return 0;
}
