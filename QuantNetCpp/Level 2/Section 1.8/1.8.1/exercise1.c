/*
C code for HW2, Section 1.8, Exercise 1
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O
#include <string.h> // Strings

// Define struct
struct Article
{
	int articleNum;
	int quantity;
	char* desc[20];
};

// Declare the print function
void Print(struct Article* article);

// Main function
int main()
{
	struct Article article; // create struct instance
	article.articleNum = 100; // define struct fields
	article.quantity = 10; // define struct fields
	strcpy_s(article.desc, "C++ article"); // define struct fields
	Print(&article); // call print function to display struct contents
}

// Implement the print function
void Print(struct Article* article)
{
	printf("Article number: %d \nQuantity:%d \nDescription:%p \n", article->articleNum, article->quantity, article->desc);
}