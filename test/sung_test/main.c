#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc == 1)
		printf("인자가 없습니다.");
	
	int i = 1;
	while (argv[i]) {
		int j = 0;
		while (argv[i][j]) {
			char c;
			int cnt = 1;
			c = argv[i][j];
			printf("%c", c);
			while (c == argv[i][j + cnt])
				cnt++;
			if (cnt != 1)
				printf("%d", cnt);
			j += cnt;
		}
		i++;
	}
	return 0;
}
