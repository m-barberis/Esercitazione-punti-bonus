/*! \file CContainer.h
	\brief Declaration of the container class

	Details.
*/

#ifndef	CONTAINER_H
#define CONTAINER_H
#define _CRT_SECURE_NO_WARNINGS
///@include <iostream>
///@include "CQuadrilateral.h"
#include <iostream> 
#include "CQuadrilateral.h"

//DOXYGEN!!!!!!!
///@def NUM
///@brief a constant that defines the maximum amount of elements that a container class instance can contain
#define NUM 50

/// @class Container
/// @brief A container class made to hold Quadrilateral shapes
class Container
{
///@protected 
protected:
	/// @name member variables
	/// @{
	int nShapes;
	Quadrilateral** quadContainer;
	/// @}
///@public
public:
	/// @name Contructors/Destructors
	/// @{
	Container();
	Container(unsigned int size);
	Container(const Container& cont);
	~Container();
	/// @}
	/// @name Init/Reset functions
	/// @brief Very useful to ensure that the code is readable and modular
	/// @{
	void Init();
	void Init(const Container& cont);
	void Reset();
	/// @}
	/// @name Setters/Getters
	/// @{
	void SetSize(unsigned int size);
	unsigned int GetSize();
	/// @}
	/// @name Other functions
	/// @brief Functions for modifying and visualizing the Container instance
	/// @{
	void DrawAll();
	void AddShape(Quadrilateral* quadPointer);
	void RemoveShape(unsigned int index);
	void RemoveAllShapes();
	/// @}

};
#endif
