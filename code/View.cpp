

#include <cassert>
#include <cmath>
#include "math.hpp"
#include "View.hpp"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace engine
{

   

	void View::update(Mesh* objects[], int count)
    {
        //Calculamos la matriz de treanformacion de la camara y su inversa 
        Matrix44 trans_cam = camera->translation * camera->rotation_x * camera->rotation_y * camera->rotation_z;
        Matrix44 trans_cam_inv = inverse(trans_cam);

        //Recorremos los objetos de las escenas
        for (int j = 0; j < count; j++)
        {
            //Hallamos la matriz de tranformacion del objeto y la multiplicamos por la projeccion y la inversa de la camara
            Matrix44 transformation = projection * trans_cam_inv * objects[j]->translation * objects[j]->scaling * objects[j]->rotation_x * objects[j]->rotation_y * objects[j]->rotation_z;
            
            // Se transforman todos los vértices usando la matriz de transformación resultante:
            for (size_t index = 0, number_of_vertices = objects[j]->original_vertices.size(); index < number_of_vertices; index++)
            {
                // Se multiplican todos los vértices y normales originales con la matriz de transformación y se guarda el resultado en otro vertex buffer:
                Vertex& vertex = objects[j]->transformed_vertices[index] = transformation * objects[j]->original_vertices[index];
                Vertex& vertex_n = objects[j]->transformed_normals[index] = objects[j]->translation * objects[j]->scaling * objects[j]->rotation_x * objects[j]->rotation_y * objects[j]->rotation_z * objects[j]->original_normals[index];
                              
                // La matriz de proyección en perspectiva hace que el último componente del vector transformado no tenga valor 1.0, por lo que hay que normalizarlo dividiendo:
                float divisor = 1.f / vertex.w;

                vertex.x *= divisor;
                vertex.y *= divisor;
                vertex.z *= divisor;
                vertex.w = 1.f;

                //Calculamos la intensidad
                float intensity = vertex_n.x * transformed_light_vector.x + vertex_n.y * transformed_light_vector.y + vertex_n.z * transformed_light_vector.z + vertex_n.w * transformed_light_vector.w;
                //Clampeamos la intensidad
                if (intensity < 0.f) intensity = 0.f; if (intensity > 1.f) intensity = 1.f;

                //Multiplicamos la intensidad por los colores RGB
                objects[j]->transformed_colors[index].set_red(objects[j]->original_colors[index].red() * intensity);
                objects[j]->transformed_colors[index].set_green(objects[j]->original_colors[index].green() * intensity);
                objects[j]->transformed_colors[index].set_blue(objects[j]->original_colors[index].blue() * intensity);


            }
        }
    }


    void View::render(Mesh* objects[], int count, bool light)
    {

        //Se averiguan los vertices de la pantalla de cada modelo
        for (int j = 0; j < count; j++)
        {
            for (size_t index = 0, number_of_vertices = objects[j]->transformed_vertices.size(); index < number_of_vertices; index++)
            {
                objects[j]->display_vertices[index] = Point4i(_transformation * objects[j]->transformed_vertices[index]);
            }
        }

        // Se borra el buffer y se dibujan los triángulos:
        rasterizer.clear();

        //Se establece los colores de cada pixel
        for (int j = 0; j < count; j++)
        {
            for (int* indices = objects[j]->original_indices.data(), *end = indices + objects[j]->original_indices.size(); indices < end; indices += 3)
            {
                if (is_frontface(objects[j]->transformed_vertices.data(), indices))
                {
                    //Si esta la iluinación activada se transforma con los colores transformados
                    if (light)
                        rasterizer.set_color(objects[j]->transformed_colors[*indices]);
                    else
                        rasterizer.set_color(objects[j]->original_colors[*indices]);

                    // Se rellena el polígono:
                    rasterizer.fill_convex_polygon_z_buffer(objects[j]->display_vertices.data(), indices, indices + 3);
                }
            }
        }

        // Se copia el framebúffer oculto en el framebúffer de la ventana:
        color_buffer.blit_to_window();
    }

}
