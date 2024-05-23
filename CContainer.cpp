/*! \file CQuadrilateral.cpp
	\brief Implementation of the general class Quadrilateral

	Details.
*/

#include "CContainer.h"

//DOXYGEN!!!!!

Container::Container()
{
	Init();
}

Container::Container(const Container& cont)
{
	Init(cont);
}

Container::~Container()
{
	Reset();
}


Container::Container(unsigned int size)
{
	SetSize(size);
	quadContainer = new Quadrilateral * [nShapes];
	for (int count = 0; count <= (nShapes - 1); count++)
	{
		quadContainer[count] = NULL;
	}
}

void Container::Init()
{
	nShapes = 0;
	quadContainer = NULL;
}

void Container::Init(const Container& cont)
{
	SetSize(cont.nShapes);
	quadContainer = new Quadrilateral* [nShapes];
	for (int count = 0; count <= (nShapes - 1); count++)
	{
		*quadContainer[count] = *cont.quadContainer[count];
	}
}

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

void Container::RemoveAllShapes()
{
	for (int count = 0; count <= (nShapes - 1); count++)
	{
		quadContainer[count] = NULL;
	}
	cout << "RemoveAllShapes: all shapes have been removed." << endl;
}