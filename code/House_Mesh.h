#pragma once


#include "Mesh.h"

namespace engine
{
	class Mesh;

	class House_Mesh : public Mesh
	{
	private:

		//Hay que ponerle el numero de caracteres que hay
		char file_path[37] = "../../../../shared/assets/Casita.obj";
		Matrix44 transformation;

	public:
		Matrix44 scaling      = glm::mat4(1.0f);
		Matrix44 rotation_x	  = glm::mat4(1.0f);
		Matrix44 rotation_y	  = glm::mat4(1.0f);
		Matrix44 rotation_z	  = glm::mat4(1.0f);
		Matrix44 translation  = glm::mat4(1.0f);
		Matrix44 projection	  = glm::mat4(1.0f);

	public:

		//House_Mesh(unsigned width, unsigned height) :Mesh(width, height)
		//{
		//	scene_vertices(file_path);
		//}

		//void update()
		//{
		//	// Se actualizan los parámetros de transformatión (sólo se modifica el ángulo):

		//	//static float angle = 0.f;

		//	//angle += 0.025f;

		//	//// Se crean las matrices de transformación:
		//	////////ARRAY Y SIZE T VACIOS ARRIBA Y SE ASIGNA EN UNA FUNCIION APRATE ESCRIBIENDO LA MATRICES EN EL MAIN
		//	/*Matrix44 identity(1);
		//	Matrix44 scaling	= scale(identity, 0.2f);
		//	Matrix44 rotation_y = rotate_around_y(identity, angle);
		//	Matrix44 translation = translate(identity, Vector3f{ 0.f, 0.5f, -10.f });
		//	Matrix44 projection = perspective(20, 1, 15, float(width) / height);*/

		//	Matrix44 transformation = projection * translation * scaling * rotation_x * rotation_y * rotation_z;

		//	Mesh::update(transformation);
		//	
		//}

		//void render()
		//{
		//	// Se convierten las coordenadas transformadas y proyectadas a coordenadas
	 //  // de recorte (-1 a +1) en coordenadas de pantalla con el origen centrado.
	 //  // La coordenada Z se escala a un valor suficientemente grande dentro del
	 //  // rango de int (que es lo que espera fill_convex_polygon_z_buffer).

		//	Matrix44 identity(1);
		//	Matrix44 _scaling = scale(identity, float(width / 2), float(height / 2), 100000000.f);
		//	Matrix44 _translation = translate(identity, Vector3f{ float(width / 2), float(height / 2), 0.f });
		//	
		//	Matrix44 _transformation = _translation * _scaling;
		//	
	
		//	Mesh::render(_transformation);

		//}
		///*void set_transform_update(Matrix44  begin[] , int count)
		//{
		//	transform = glm::mat4(1.0f);
		//	for (int i = 0; i < count; i++)
		//	{
		//		transform *= begin[i];
		//	}

		//}*/
		//void set_transform(Matrix44  a, Matrix44  b= glm::mat4(1.0f), Matrix44  c= glm::mat4(1.0f), Matrix44  d= glm::mat4(1.0f), Matrix44  e= glm::mat4(1.0f), Matrix44  f= glm::mat4(1.0f))
		//{
		//	transformation = a * b * c * d * e * f;
		//}

	};



}