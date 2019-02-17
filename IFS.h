#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <map>
#include <string>
#include <glad/glad.h>
class Fractal
{
	std::vector<GLfloat[3]> input_vertices;
	std::vector<GLfloat*>  lower_left;
	std::vector<GLfloat*> upper_left;
	std::vector<GLfloat*>  upper_right;
	std::map<std::string, GLfloat*> translate_x_mat = { {"Lower-Left", {0}}, {"Upper-Left", {0}}, {"Upper-Right" , {0}} };
	std::map<std::string, GLfloat*> translate_y_mat = { {"Lower-Left", {0}}, {"Upper-Left", {0}}, {"Upper-Right" , {0}} };
	std::map<std::string, GLfloat*> shear_x_mat = { {"Lower-Left", {0}}, {"Upper-Left", {0}}, {"Upper-Right" , {0}} };
	std::map<std::string, GLfloat*> shear_y_mat = { {"Lower-Left", {0}}, {"Upper-Left", {0}}, {"Upper-Right" , {0}} };
	std::map<std::string, GLfloat*> scale_hor_mat = { {"Lower-Left", {0}}, {"Upper-Left", {0}}, {"Upper-Right" , {0}} };
	std::map<std::string, GLfloat*> scale_vert_mat = { {"Lower-Left", {0}}, {"Upper-Left", {0}}, {"Upper-Right" , {0}} };
	std::map<std::string, GLfloat*> rotate_x_mat = { {"Lower-Left", {0}}, {"Upper-Left", {0}}, {"Upper-Right" , {0}} };
	std::map<std::string, GLfloat*> rotate_y_mat = { {"Lower-Left", {0}}, {"Upper-Left", {0}}, {"Upper-Right" , {0}} }; 
	

	Fractal() = default;
	Fractal(std::vector<GLfloat[3]> input)
	{

		input_vertices = input;
		

	
	}

	void Set_Transform(std::string quadrant, std::vector<GLfloat> translate, std::vector<GLfloat> shear,
		std::vector<GLfloat> scale, std::vector<GLfloat> rotation)
	{
		translate_x_mat[quadrant][0] = 1.0; translate_x_mat[quadrant][1] = 0.0; translate_x_mat[quadrant][2] = translate[0];
		translate_x_mat[quadrant][3] = 0.0; translate_x_mat[quadrant][4] = 1.0; translate_x_mat[quadrant][5] = 0.0;
		translate_x_mat[quadrant][6] = 0.0; translate_x_mat[quadrant][7] = 0.0; translate_x_mat[quadrant][8] = 1.0;

		translate_y_mat[quadrant][0] = 1.0; translate_y_mat[quadrant][1] = 0.0; translate_y_mat[quadrant][2] = 0.0;
		translate_y_mat[quadrant][3] = 0.0; translate_y_mat[quadrant][4] = 1.0; translate_x_mat[quadrant][5];
		translate_y_mat[quadrant][6] = 0.0; translate_y_mat[quadrant][7] = 0.0; translate_x_mat[quadrant][8] = 1.0;

		shear_x_mat[quadrant][0] = 1.0; shear_x_mat[quadrant][1] = 0.0; shear_x_mat[quadrant][2] = glm::tan(shear[0]);
		shear_x_mat[quadrant][3] = 0.0; shear_x_mat[quadrant][4] = 1.0; shear_x_mat[quadrant][5] = 0.0;
		shear_x_mat[quadrant][6] = 0.0; shear_x_mat[quadrant][7] = 0.0; shear_x_mat[quadrant][8] = 1.0;

		shear_y_mat[quadrant][1] = 1.0; shear_y_mat[quadrant][2] = 0.0; shear_y_mat[quadrant][3] = 0.0;
		shear_y_mat[quadrant][4] = 0.0; shear_y_mat[quadrant][5] = 1.0; shear_y_mat[quadrant][5] = glm::tan(shear[1]);
		shear_y_mat[quadrant][0] = 0.0; shear_y_mat[quadrant][0] = 0.0; shear_y_mat[quadrant][8] = 1.0;

		scale_hor_mat[quadrant][0] = 1.0; scale_hor_mat[quadrant][1] = 0.0; scale_hor_mat[quadrant][2] = scale[0];
		scale_hor_mat[quadrant][3] = 0.0; scale_hor_mat[quadrant][4] = 1.0; scale_hor_mat[quadrant][5] = 0.0;
		scale_hor_mat[quadrant][6] = 0.0; scale_hor_mat[quadrant][7] = 0.0; scale_hor_mat[quadrant][8] = 1.0;

		scale_vert_mat[quadrant][0] = 1.0; scale_vert_mat[quadrant][1] = 0.0; scale_vert_mat[quadrant][2] = 0.0;
		scale_vert_mat[quadrant][3] = 0.0; scale_vert_mat[quadrant][4] = 1.0; scale_vert_mat[quadrant][5] = scale[1];
		scale_vert_mat[quadrant][6] = 0.0; scale_vert_mat[quadrant][7] = 0.0; scale_vert_mat[quadrant][8] = 1.0;

		GLfloat x_rad = glm::radians(rotation[0);
		GLfloat y_rad = glm::radians(rotation[1]);

		rotate_x_mat[quadrant][0] = 1.0; rotate_x_mat[quadrant][1] = 0.0; rotate_x_mat[quadrant][2] = 0.0;
		rotate_x_mat[quadrant][3] = 0.0; rotate_x_mat[quadrant][4] = glm::cos(x_rad); rotate_x_mat[quadrant][5] = -glm::sin(x_rad);
		rotate_x_mat[quadrant][6] = 0.0; rotate_x_mat[quadrant][7] = glm::sin(x_rad); rotate_x_mat[quadrant][8] = glm::cos(x_rad);

		rotate_y_mat[quadrant][0] = glm::cos(y_rad); rotate_y_mat[quadrant][1] = 0.0; rotate_y_mat[quadrant][2] = glm::sin(y_rad);
		rotate_y_mat[quadrant][3] = 0.0; rotate_y_mat[quadrant][4] = 1.0; rotate_y_mat[quadrant][5] = 0.0;
		rotate_y_mat[quadrant][6] = -glm::sin(y_rad); rotate_y_mat[quadrant][7] = 0.0; rotate_y_mat[quadrant][8] = glm::cos(y_rad);

	}

	GLfloat* Mat_Multiply(GLfloat big_mat[9], GLfloat small_mat[3])
	{
		GLfloat result[3] = { 0 };

		result[0] = big_mat[0] * small_mat[0] + big_mat[1] * small_mat[1] + big_mat[2] * small_mat[2];
		result[1] = big_mat[3] * small_mat[0] + big_mat[4] * small_mat[1] + big_mat[5] * small_mat[2];
		result[2] = big_mat[6] * small_mat[0] + big_mat[7] * small_mat[1] + big_mat[8] * small_mat[2];
	
		return result;
	}


	std::vector<GLfloat*> IFS_Perform(GLfloat input_big[9],
		std::vector<GLfloat*> input_small)
	{
		std::vector<GLfloat*> result;
		
		for (int i = 0; i < input_small.size(); i++)
		{
			GLfloat *new_mat = Mat_Multiply(input_big, input_small[i]);

			result.push_back(new_mat);
		}

		return result;
	}

	std::vector<GLfloat*> Copy_Vector(std::vector<GLfloat[3]> main)
	{
		std::vector<GLfloat*> result;

		for (int i = 0; i < main.size(); i++)
		{
			result.push_back(main[i]);
		}

		return result;
	}

	void Do_Lower_Left(std::vector<GLfloat> translate, std::vector<GLfloat> shear,
		std::vector<GLfloat> scale, std::vector<GLfloat> rotation)
	{
		Set_Transform("Lower-Left", translate, shear, scale, rotation);
		
		lower_left = Copy_Vector(input_vertices);

		lower_left = IFS_Perform(translate_x_mat["Lower-Left"], lower_left);
		lower_left = IFS_Perform(translate_y_mat["Lower-Left"], lower_left);
		lower_left = IFS_Perform(shear_x_mat["Lower-Left"], lower_left);
		lower_left = IFS_Perform(shear_y_mat["Lower-Left"], lower_left);
		lower_left = IFS_Perform(scale_hor_mat["Lower-Left"], lower_left);
		lower_left = IFS_Perform(scale_vert_mat["Lower-Left"], lower_left);
		lower_left = IFS_Perform(rotate_x_mat["Lower-Left"], lower_left);
		lower_left = IFS_Perform(rotate_y_mat["Lower-Left"], lower_left);

	}

	void Do_Upper_Left(std::vector<GLfloat> translate, std::vector<GLfloat> shear,
		std::vector<GLfloat> scale, std::vector<GLfloat> rotation)
	{
		Set_Transform("Upper-Left", translate, shear, scale, rotation);

		upper_left = Copy_Vector(input_vertices);

		upper_left = IFS_Perform(translate_x_mat["Upper-Left"], upper_left);
		upper_left = IFS_Perform(translate_y_mat["Upper-Left"], upper_left);
		upper_left = IFS_Perform(shear_x_mat["Upper-Left"], upper_left);
		upper_left = IFS_Perform(shear_y_mat["Upper-Left"], upper_left);
		upper_left = IFS_Perform(scale_hor_mat["Upper-Left"], upper_left);
		upper_left = IFS_Perform(scale_vert_mat["Upper-Left"], upper_left);
		upper_left = IFS_Perform(rotate_x_mat["Upper-Left"], upper_left);
		upper_left = IFS_Perform(rotate_y_mat["Upper-Left"], upper_left);


	}

	void Do_Upper_Right(std::vector<GLfloat> translate, std::vector<GLfloat> shear,
		std::vector<GLfloat> scale, std::vector<GLfloat> rotation)
	{
		Set_Transform("Upper-Right", translate, shear, scale, rotation);

		upper_right = Copy_Vector(input_vertices);

		upper_right = IFS_Perform(translate_x_mat["Upper-Right"], upper_right);
		upper_right = IFS_Perform(translate_y_mat["Upper-Right"], upper_right);
		upper_right = IFS_Perform(shear_x_mat["Upper-Right"], upper_right);
		upper_right = IFS_Perform(shear_y_mat["Upper-Right"], upper_right);
		upper_right = IFS_Perform(scale_hor_mat["Upper-Right"], upper_right);
		upper_right = IFS_Perform(scale_vert_mat["Upper-Right"], upper_right);
		upper_right = IFS_Perform(rotate_x_mat["Upper-Right"], upper_right);
		upper_right = IFS_Perform(rotate_y_mat["Upper-Right"], upper_right);


	}

	std::vector<GLfloat[3]> Return_Fractal()
	{
		std::vector<GLfloat*> result_premilinary;
		std::vector<GLfloat[3]> result_final;

		for (int i = 0; i < input_vertices.size(); i++)
		{
			result_premilinary.push_back(input_vertices[i]);
		}
		for (int i = 0; i < lower_left.size(); i++)
		{
			result_premilinary.push_back(lower_left[i]);
		}
		for (int i = 0; i < upper_left.size(); i++)
		{
			result_premilinary.push_back(upper_left[i]);
		}
		for (int i = 0; i < upper_right.size(); i++)
		{
			result_premilinary.push_back(lower_left[i]);
		}
		
		for (int i = 0; i < result_premilinary.size(); i++)
		{
			result_final[i][0] = result_premilinary[i][0];
			result_final[i][1] = result_premilinary[i][1];
			result_final[i][2] = result_premilinary[i][2];
		}

		return result_final;
	}


};
