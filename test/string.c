#include <stdlib.h>
#include <util/string.h>

#include <assert.h>

void assert_str(const char *act, const char *exp)
{
	if (!act || strcmp(act, exp) != 0) {
		fprintf(stderr, "Failed. Expected %s but got %s", exp, act);
		exit(EXIT_FAILURE);
	}
}

void test_rstr(void)
{
	char *c = NULL;
	c = rstrcpy(c, "Hello, ");
	assert_str(c, "Hello, ");

	c = rstrcat(c, "world!");
	assert_str(c, "Hello, world!");

	c = rsprintf(c, "%s", c);
	assert_str(c, "Hello, world!");

	c = rsprintf(c, "%s -- %s -- %s", c, "He cried", c);
	assert_str(c, "Hello, world! -- He cried -- Hello, world!");

	c = rstrcpy(c, "Again... ");
	assert_str(c, "Again... ");

	c = rstrcat(c, c);
	assert_str(c, "Again... Again... ");

	c = rstrcpy(c, c);
	assert_str(c, "Again... Again... ");

	free(c);
}

int main()
{
	test_rstr();
}

