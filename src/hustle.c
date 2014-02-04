#include "hustle.h"

static void
hustle_milli(command_t *cmd)
{
	long long int some_milliseconds = string_to_seconds(cmd->arg);
	char *milliseconds_string = milliseconds_to_long_string(some_milliseconds * 1000);
	printf("%s\n", milliseconds_string);
	free(milliseconds_string);
}

int
main(int argc, char **argv)
{
	command_t cmd;
	command_init(&cmd, argv[0], "0.0.58");
	command_option(&cmd, "-m", "--milliseconds <arg>", "milliseconds to text", hustle_milli);
	command_parse(&cmd, argc, argv);
	command_free(&cmd);

	return 0;
}
