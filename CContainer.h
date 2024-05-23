/*! \file CQuadrilateral.h
	\brief Declaration of the general class Quadrilateral

	Details.
*/


#ifndef	CONTAINER_H
#define CONTAINER_H
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include "CQuadrilateral.h"

//DOXYGEN!!!!!!!

#define NUM 50

class Container
{
protected:
	int nShapes;
	Quadrilateral** quadContainer;
public:
	Container();
	Container(unsigned int size);
	Container(const Container& cont);
	~Container();
	void Init();
	void Init(const Container& cont);
	void Reset();
	void SetSize(unsigned int size);
	void DrawAll();
	void AddShape(Quadrilateral* quadPointer);
	void RemoveShape(unsigned int index);
	void RemoveAllShapes();

};
#endif
