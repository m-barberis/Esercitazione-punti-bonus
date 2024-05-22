/*! \file StructTextArea.h
	\brief Declaration of the struct TextArea

	Details.
*/


# define SLEN 50

/// @struct TextArea
/// @brief includes the text to be showed and the font size 
struct TextArea {
	char string[SLEN]; // the text 
	unsigned int size; // font size
	
};