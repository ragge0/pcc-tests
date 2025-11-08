/* correct - from c99 */

enum { foo = 42 }; struct { char *b; } x[] = { { (char []){ foo, 0, 0 } } };

int main(int argc, char *argv[])
{
	/* pa[2] = {1,2} */ 
	int *pa = (int []){1,2};  
	
	/* pb[2] = {*pa, 0} */ 
	int *pb = (int [2]){*pa};

	/* self-referencing declarations */
	void *list[] = {
		&list[0],
		&list[1]
	};
	if (&list[0] != list[0] || &list[1] != list[1])
		return 1;

	return 0; 
}
