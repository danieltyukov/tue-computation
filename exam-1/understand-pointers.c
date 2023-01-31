// integer x is set to 4
int x = 4;

// integer pointer pX is set to (address) of x
int * pX = &x;

// now we can access x by reference and NOT BY VALUE

// integer y is set to the thing pointed to by pX
int y = *pX;
