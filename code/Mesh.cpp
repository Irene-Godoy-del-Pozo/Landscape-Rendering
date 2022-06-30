#include "Mesh.h"

#include <cassert>
#include <cmath>
#include "math.hpp"
#include "View.hpp"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace engine
{
	
  
    Mesh::Mesh(View * v, char mesh_file_path[],bool increment,int r,int g, int b) :
       view(v)
    {
        Assimp::Importer importer;

        //Importamos el objeto
        auto scene = importer.ReadFile
        (
            mesh_file_path,
            aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType
        );

        // Si scene es un puntero nulo significa que el archivo no se pudo cargar con éxito:

        if (scene && scene->mNumMeshes > 0)
        {
            // Se coge la primera malla y se calcula el numero de vertices que tiene
            auto mesh = scene->mMeshes[0];
            size_t number_of_vertices = mesh->mNumVertices;

            // Se redimensionan los vertex buffers de vectores y normales originales
            original_vertices.resize(number_of_vertices);
            original_normals .resize(number_of_vertices);

            //Se asignan los vectores y normales de cada vertice original  
            for (size_t index = 0; index < number_of_vertices; index++)
            {
                auto& vertex = mesh->mVertices[index];             
                original_vertices[index] = Vertex(vertex.x, -vertex.y, vertex.z, 1.f);

                //Si tienen normales se asignaran
                if (mesh->HasNormals())
                {
                    auto& vertex_n = mesh->mNormals[index];
                    original_normals[index] = Vertex(vertex_n.x, -vertex_n.y, vertex_n.z, 0.f);
                }
            }

            // Se redimensionan los vertex buffers de vertices y normales
            transformed_vertices.resize(number_of_vertices);
            transformed_normals.resize(number_of_vertices);
            
            display_vertices.resize(number_of_vertices);

            // Se inicializan los datos de color 
            original_colors.resize(number_of_vertices);
            transformed_colors.resize(number_of_vertices);

            
            for (size_t index = 0; index < number_of_vertices; index++)
            {
                //Si se los colores incrementan su valor con cada index
               if(increment)
                   original_colors[index].set(r * index * 0.0039215f, g * index * 0.0039215f, b * index * 0.0039215f);
                              
               else
                   original_colors[index].set(r *0.0039215f, g * 0.0039215f, b * 0.0039215f);
            }

            // Se generan los índices de los triángulos
            size_t number_of_triangles = mesh->mNumFaces;
            original_indices.resize(number_of_triangles * 3);

            Index_Buffer::iterator indices_iterator = original_indices.begin();

            for (size_t index = 0; index < number_of_triangles; index++)
            {
                auto& face = mesh->mFaces[index];

                assert(face.mNumIndices == 3);              
                                                            
                auto indices = face.mIndices;

                *indices_iterator++ = int(indices[0]);
                *indices_iterator++ = int(indices[1]);
                *indices_iterator++ = int(indices[2]);
            }
        }
    }

}
