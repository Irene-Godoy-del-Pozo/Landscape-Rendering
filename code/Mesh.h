#ifndef MESH_HEADER
#define MESH_HEADER


#include <Color_Buffer.hpp>
#include <cstdlib>
#include "math.hpp"
#include "Rasterizer.hpp"
#include <vector>

namespace engine
{
    using  std::vector;
    using argb::Rgb888;
    using argb::Color_Buffer;
    class View;


    class Mesh
    {
    protected:

        typedef Rgb888                Color;
        typedef Point4f               Vertex;
        typedef vector< Vertex >      Vertex_Buffer;
        typedef vector< int    >      Index_Buffer;
        typedef vector< Color  >      Vertex_Colors;

    protected:

        //Referencia a view
        View *view;

    public:
        //Matrices de transformacion del modelo
        Matrix44 scaling = glm::mat4(1.0f);
        Matrix44 rotation_x = glm::mat4(1.0f);
        Matrix44 rotation_y = glm::mat4(1.0f);
        Matrix44 rotation_z = glm::mat4(1.0f);
        Matrix44 translation = glm::mat4(1.0f);

        //Vetices originales y transformados
        Vertex_Buffer     original_vertices;
        Vertex_Buffer     transformed_vertices;
        

        Index_Buffer      original_indices;

        //Colores originales y transformados por la iluminacion
        Vertex_Colors     original_colors;
        Vertex_Colors     transformed_colors;

        vector< Point4i > display_vertices;
        
        //Normales originales y transformados
        Vertex_Buffer     original_normals;
        Vertex_Buffer     transformed_normals;
        
    public:

        Mesh()=default;

        Mesh(View * view, char mesh_file_path[], bool increment, int r, int g, int b);

    };
}

#endif