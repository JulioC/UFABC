#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define ALPHABET_COUNT 26

/* Just commenting for test
 * hehe
 */

struct CharSet_t {
	char data;
	struct CharSet_t *next;
};

typedef struct CharSet_t CharSet;

CharSet* BuildCharSet(char *chars);

char GetElement(int index, CharSet *charSet);

CharSet* BringToFront(char c, CharSet *charSet);

void DeleteCharSet(CharSet *charSet);

void PrintCharSet(CharSet *list);

int main(int argc, char *argv[]) {
	int n, num, letter;
	char alphabet[ALPHABET_COUNT+1], buffer[256];
	char *output;
	CharSet *charSet = NULL;
	
	for(n = 0; n < ALPHABET_COUNT; n++) {
		alphabet[n] = 'A' + n;
	}
	alphabet[ALPHABET_COUNT] = '\0';	
	
	charSet = BuildCharSet(alphabet);
	
	scanf("%d", &num);
	output = malloc(sizeof(char) * (num+1));
	
	for(n = 0; n < num; n++) {
		scanf("%d", &letter);
		buffer[n] = GetElement(letter-1, charSet);
		charSet = BringToFront(buffer[n], charSet);
		PrintCharSet(charSet);
	}
	buffer[n] = '\0';
	
	printf("%s", buffer);
		
	DeleteCharSet(charSet);
	
	free(output);

	return 0;
}

CharSet* BuildCharSet(char *chars) {
	if(strlen(chars) == 1) return NULL;
	
	int n;
	int num = strlen(chars) - 1;
	CharSet *charSet = NULL;
	CharSet *last = NULL;
		
	for(n = 0; n <= num; n++) {		
		CharSet *temp = NULL;
		temp = malloc(sizeof(CharSet));
		if(temp != NULL) {
			temp->data = chars[n];
			temp->next = NULL;
			
			if(charSet == NULL) {
				charSet = temp;
			} else {
				last->next = temp;
			}
			
			last = temp;
		}
	}
	
	return charSet;
}

char GetElement(int index, CharSet *charSet) {
	int n = 0;
	CharSet *curr = NULL;
	curr = charSet;
	while(curr != NULL) {
		if(n == index) {
			return curr->data;
		} else if(n > index) {
			return '\0';
		}
		
		curr = curr->next;
		
		n++;
	}
	
	return '\0';
}

CharSet* BringToFront(char c, CharSet *charSet) {
	CharSet *temp = NULL;
	CharSet *last = NULL;
	temp = charSet;
	
	while(temp->data != c && temp != NULL) {
		last = temp;
		temp = temp->next;
	}
	
	if(temp != NULL && last != NULL) {
		last->next = temp->next;
		temp->next = charSet;
		return temp;
	}
	
	return charSet;
}

void DeleteCharSet(CharSet *charSet) {
	CharSet *temp = NULL;
	temp = charSet;
	
	while(charSet != NULL) {
		temp = charSet;
		charSet = charSet->next;
		
		free(temp);
	}
}

void PrintCharSet(CharSet *charSet) {
	CharSet *curr;
	curr = charSet;
	
	while(curr != NULL) {
		printf("%c ", curr->data);
		curr = curr->next;
	}
	
	printf("\n");
}