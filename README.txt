Project: Polynomials
Authors: Francois BOSMA (bosma_f), Alexis YANG (yang_e)
Year: 2016

Please find below our comments on this project.

Polynomial : implementation choice :
	- we chose to use variadic template to be able to easily implement with different containers
	- we implemented an std::vector and a flat_map, we eventually lacked time to implement other implementations
	- the variadic template was difficult to handle, and it took us quite some time to correct compilation errors

Bench :
	- we compared both implementation and we can see that flat_map is better than vector
	which is not a surprise
