#pragma once

#include <cstdlib>
#include "math.hpp"



namespace engine
{

	class Camera
	{

	public: 

		//Matrices de transformación inicializadas a la matriz de identidad
		Matrix44 rotation_x = glm::mat4(1.0f);
		Matrix44 rotation_y = glm::mat4(1.0f);
		Matrix44 rotation_z = glm::mat4(1.0f);
		Matrix44 translation = glm::mat4(1.0f);
		Matrix44 identity = glm::mat4(1.0f);


	public :

		Camera(Vector3f position, float angle)
		{					
			set_camera(position,angle);
		}

		void set_camera(Vector3f position, float angle)
		{
			translation = translate(identity, position);
			rotation_x = rotate_around_x(identity, angle);
		}



	};

}