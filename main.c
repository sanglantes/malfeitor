#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// If -v/--verbose is given at start, print return codes to stderr.

static void
craft_usage(void) {
	fprintf(stderr, 
"usage: craft <-p protocol> [-e]\n"
"	-protocol: ip, udp, tcp\n"
"	-e: empty packet\n"
	);
}
static void
set_usage(void) {
	fprintf(stderr,
"usage: set <option> <value>\n"
"	-option: version, hlength, dsf, tlength, id, flag, foffset, ttl, protocol, checksum, src, dest\n"
"		 srcport, destport, seq, ack, window, upointer, options, payload, length\n"
	);
}

static void
ip_usage(void) {
	fprintf(stderr,
"Options for crafting IP packets\n"
"usage (craft ip): set <option> <value>\n"
"	-option: version, hlength, dfs, tlength, id, flag, foffset, ttl, protocol, cheksum, src, dest\n"
	);
}

static void
tcp_usage(void) {
	fprintf(stderr,
"Options for crafting TCP packets.\n"
"usage (craft tcp): set <option> <value>\n"
"	-option: srcport, destport, seq, ack, hlength, flag, window, checksum, upointer, options\n"
	);
}

static void
udp_usage(void) {
	fprintf(stderr,
"Options for crafting UDP packets\n"
"usage (craft udp): set <option> <value>\n"
"	-option: srcport, destport, length, checksum, payload\n"
	);
}

static void
valid_options(void) {
	fprintf(stderr, "usage: malfeitor [-v --verbose]\n");
}

static void
help(void) {
	fprintf(stderr, 
"Type \"help [option]\" for more information. Available options:\n"
"	craft, tcp, udp, ip, flood, set\n"
	);
}

int main(int argc, char* argv[]) {
	unsigned short int verbose = 0;
	if (argv[1] != NULL) {
		if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--verbose") == 0) {
			verbose = 1;
			printf("Launching in verbose mode...\n");
		}

		else {
			fprintf(stderr, "Not a valid option: \"%s\".\n", argv[1]);
			valid_options();
			return 255;
		}
	}

	FILE* logo = fopen("art", "r");
	char c;
	c = fgetc(logo);
	while (c != EOF) {
		printf("%c", c);
		c = fgetc(logo);	
	}
	fclose(logo);
	printf("MALFEITOR: Packet crafting tool\n\n");
	
	printf(">> ");
	char command[24];
	fgets(command, sizeof(command), stdin);

	return 0;
}
