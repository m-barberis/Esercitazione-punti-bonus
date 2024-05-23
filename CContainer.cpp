/*! \file CContainer.cpp
	\brief Implementation of the container class

	Details.
*/
///@include Header file with all declarations
#include "CContainer.h"


///@brief Default contructor
Container::Container()
{
	Init();
}

/// @brief Makes an exact replica of another container
/// @param cont Container to be copied, passed by reference
Container::Container(const Container& cont)
{
	Init(cont);
}

/// @brief eliminates the instance from memory
Container::~Container()
{
	Reset();
}

/// @brief already sets the size variable
/// @param size the maximum amount of quadrilateral shapes that can be contained
Container::Container(unsigned int size)
{
	Init();
	
	SetSize(size);
	quadContainer = new Quadrilateral * [nShapes];
	for (int count = 0; count <= (nShapes - 1); count++)
	{
		quadContainer[count] = NULL;
	}
}

/// @brief very useful for the management of multiple constructors
void Container::Init()
{
	nShapes = 0;
	quadContainer = NULL;
}

/// @brief overloaded version used for the copy constructor
/// @param cont container to be copied
void Container::Init(const Container& cont)
{
	SetSize(cont.nShapes);
	quadContainer = new Quadrilateral* [nShapes];
	for (int count = 0; count <= (nShapes - 1); count++)
	{
		*quadContainer[count] = *cont.quadContainer[count];
	}
}

/// @brief useful mostly to wipe all shapes from the container
void Container::Reset()
{
	delete quadContainer;
	quadContainer = NULL;
	/*
	for (int count = 0; count <= (nShapes - 1); count++)
	{
		if (quadContainer[count] != NULL)
		{
			delete quadContainer[count];
			quadContainer[count] = NULL;
		}
		
	}
	*/
}

/// @brief Draws every shape VERY realistically. should be considered art
void Container::DrawAll()
{
	cout << endl;
	if (quadContainer != NULL)
	{
		cout << "*** DRAWING EVERY SHAPE *** " << endl;
		for (int count = 0; count <= (nShapes - 1); count++)
		{
			if (quadContainer[count] != NULL)
			{
				cout << "Shape number: " << count + 1 << endl;
				quadContainer[count]->Drawing();
			}
		}
		cout << "*** DrawAll ended *** " << endl;
	}
	else
		cout << "DrawAll: quadContainer is NULL" << endl;
	cout << endl;
}

/// @brief sets the size of the container
/// @param size new maximum amount of quadrilaterals it can contain
void Container::SetSize(unsigned int size)
{
	if (size <= NUM)
	{
		nShapes = size;
	}
	else
	{
		cout << "The maximum amount of shapes is: " << NUM << endl;
	}
}

/// @brief
/// @return value of the size member variable
unsigned int Container::GetSize()
{
	return nShapes;
}

/// @brief Adds a shape to the container. Does not create a copy, but just adds its pointer to quadList
/// @param quadPointer pointer to the shape that needs to be added
void Container::AddShape(Quadrilateral* quadPointer)
{
	if (quadPointer != NULL)
	{
		for (int count = 0; count <= (nShapes - 1); count++)
		{
			if (quadContainer[count] == NULL)
			{
				quadContainer[count] = quadPointer;
				cout << "AddShape: added shape " << count + 1 << "/" << nShapes << endl;
				break;
			}
			else
				continue;
		}
	}
	else
	{
		cout << "AddShape: NULL pointer (no shape to add)." << endl;
	}
}

/// @brief Removes a shape
/// @param shapeNumber index of the shape in the list
void Container::RemoveShape(unsigned int shapeNumber)
{
	if (quadContainer[shapeNumber - 1] != NULL)
	{
		quadContainer[shapeNumber - 1] = NULL;
		cout << "RemoveShape: shape number " << shapeNumber << " has been removed." << endl;
	}
	else
	{
		cout << "RemoveShape: NULL pointer (no shape to remove)." << endl;
	}
}

/// @brief removes every shape from the container, goes back to square one
void Container::RemoveAllShapes()
{
	for (int count = 0; count <= (nShapes - 1); count++)
	{
		quadContainer[count] = NULL;
	}
	cout << "RemoveAllShapes: all shapes have been removed." << endl;
}