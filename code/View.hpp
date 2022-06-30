
// Este código es de dominio público.
// angel.rodriguez@esne.edu
// 2013.12 - 2021.04

#ifndef VIEW_HEADER
#define VIEW_HEADER

    #include "Mesh.h"
    #include <Color_Buffer.hpp>
    #include <cstdlib>
    #include "math.hpp"
    #include "Rasterizer.hpp"
    #include <vector>
    #include "Camera.h"

    namespace engine
    {

        using  std::vector;
        using argb::Rgb888;
        using argb::Color_Buffer;

        class View
        {
        private:


            typedef Rgb888                Color;
            typedef Color_Buffer< Color > Color_Buffer;
            typedef Point4f               Vertex;

            //Vector encargado de la ilumnacion
            Vector4f transformed_light_vector{ -15,-20,0,0 };

            Matrix44 identity= glm::mat4(1.0f);
            Matrix44 _scaling;
            Matrix44 _translation;
            Matrix44 _transformation;

        public:
       
            //Buffer de pixeles de la ventana
            Color_Buffer               color_buffer;
            Rasterizer< Color_Buffer > rasterizer;

            //Matriz de proyeccion de la vista comun a todos los objetos
            Matrix44 projection = glm::mat4(1.0f);

            //Cámara 
            Camera* camera;

            //Ancho y alto de la ventana 
            unsigned width;
            unsigned height;

        public:

            
            View(unsigned width, unsigned height) :
                width(width),
                height(height),
                color_buffer(width, height),
                rasterizer(color_buffer) 
            {
                
                 _scaling       = scale(identity, float(width / 2), float(height / 2), 100000000.f);
                 _translation = translate(identity, Vector3f{ float(width / 2), float(height / 2), 0.f });
                 _transformation = _translation * _scaling;
            }


            void update(Mesh* objects[], int count);

            void render(Mesh* objects[], int count, bool light);

        private:
            bool  is_frontface(const Vertex* const projected_vertices, const int* const indices)
            {
                const Vertex& v0 = projected_vertices[indices[0]];
                const Vertex& v1 = projected_vertices[indices[1]];
                const Vertex& v2 = projected_vertices[indices[2]];

                // Se asumen coordenadas proyectadas y polígonos definidos en sentido horario.
                // Se comprueba a qué lado de la línea que pasa por v0 y v1 queda el punto v2:

                return ((v1[0] - v0[0]) * (v2[1] - v0[1]) - (v2[0] - v0[0]) * (v1[1] - v0[1]) < 0.f);
            }


        };

    }

#endif
