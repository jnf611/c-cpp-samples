#include <stdlib.h>
#include <stdio.h>

int function(int parameter)
{
	printf("%s: parameter:%d\n", __func__, parameter);
	if (parameter > 0)
		return parameter;
	else
		return 0;

	// the following lines are not reported as not executed:
	// maybe there optimized out by the compiler
	int untested_line = 2;
	return untested_line;
}

int main()
{
	function(6);
	int a = 9;
	if (a)
		function(a);
	else
		printf("%s: unexecuted line", __func__);

	return 0;
}
