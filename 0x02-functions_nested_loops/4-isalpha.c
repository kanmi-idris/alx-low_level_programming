#include "main.h"

/**
 * isalpha - checks for alphabetic character
 * @c - checks for upper and lowercase character
 * Return: 1 if c is lowercase and 0 if otherwise
 */
int _isalpha(int c)
{
return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}