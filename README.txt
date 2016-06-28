

Polynomial : implementation choice :
	- we chose to use variadic template to be able to easily implement with different containers
	- so far we have the std::vector and the flat_map, we didn't have time to do other implementation
	- the variadic template was hard to handle, and took a lot of time to correct compilation errors


Bench :
	- we compared both implementation and we can see that flat_map is better than vector
	which is not a surprise
	
