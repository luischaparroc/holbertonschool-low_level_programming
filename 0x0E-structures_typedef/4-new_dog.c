#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog.
 * @name: name of the dog.
 * @age: age of the dog.
 * @owner: owner of the dog.
 *
 * Return: struct dog.
 * if fails, returns NULL.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *p_dog;

	p_dog = malloc(sizeof(*p_dog));
	if (p_dog == NULL)
		return (NULL);

	p_dog->name = name;
	p_dog->age = age;
	p_dog->owner = owner;

	return (p_dog);
}
