#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int card_[] = {
	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	/*				?>=< ;:98 7654 3210  /.-, +*)( '&%$ #"!  */
	0x03fc0000, /*	0000 0011 1111 1100  0000 0000 0000 0000 */
	/*				_^]\ [ZYX WVUT SRQP  ONML KJIH GFED CBA@ */
	0x00100c12, /*	0000 0000 0001 0000  0000 1100 0001 0010 */
	/*				 ~}| {zyx wvut srqp  onml kjih gfed cba` */
	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */

};

int syntax_(const int table[8], int c) {
	return (table[(c >> 5)] & (1U << (c & 0x1f)));
}

size_t score_(char card, size_t* ace_count){
	switch(card){
		case 'A':
			(*ace_count)++;
			// *is_ace = *is_ace + 1;
			return 0;
		case 'T':
		case 'J':
		case 'D':
		case 'K':
			return 10;
		default:
			return card - '0';
	}
}

void ace_calculate(size_t* score, size_t ace_count){
	size_t temp = *score;
	int	flag_eleven = 0;

	for (size_t i = 0; i < ace_count; i++){
		if (temp + 11 <= 21){
			temp += 11;
			flag_eleven = 1;
		}else{
			if (flag_eleven && (temp + 1 > 21)){
					temp -= 10;
			}
			temp += 1;
			flag_eleven = 0;
		}
	}
	if (temp == 21){
		printf("Blackjack!\n");
	}else{
		printf("%ld\n", temp);
	}
}

void play_game(char* deck){
	size_t score = 0;
	size_t ace_count = 0;

	while (*deck != '\0'){
		char temp = toupper(*deck);
		if(syntax_(card_, temp)){
			score += score_(temp, &ace_count);
		}else{
			printf("Invalid card: %c\n", *deck);
			exit(1);
		}
		deck++;
	}
	if (score >= 21){
		size_t total = score + ace_count;
		if (total == 21){
			printf("Blackjack!\n");
		}else{
			printf("%ld\n", total);
		}
	}else{
		ace_calculate(&score, ace_count);
	}
}

int main(int argc, char **argv){
	if (argc == 2){
		play_game(argv[1]);
	}else{
		printf("Usage: ./blackjack <deck>\n");
	}
}
