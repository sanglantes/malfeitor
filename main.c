#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void
craft_usage(void) {
	fprintf(stderr, 
"usage: craft <-p protocol> [-e]\n"
"	-protocol: udp/tcp\n"
"	-e: empty packet\n"
	);
}


int main() {
	FILE* logo = fopen("art", "r");

	char c;
	c = fgetc(logo);
	while (c != EOF) {
		printf("%c", c);
		c = fgetc(logo);	
	}
	fclose(logo);
	printf("MALFEITOR: Packet crafting tool\n\n");

	craft_usage();
	return 0;
}
