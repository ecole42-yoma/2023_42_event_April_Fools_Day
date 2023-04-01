#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum LF_E {
	NONE = 0,
	LF
} LF_T;

typedef struct vector_s {
	char** vector;
	size_t size;
	size_t capacity;
	size_t max_len_word;
} vector_t;

void* my_malloc(size_t size){
	void* p = malloc(size);
	if (p == NULL){
		printf("Error: malloc failed\n");
		exit(1);
	}
	return p;
}

void repeat_print_(size_t max_len, char charater, LF_T on){
	for (size_t i = 0; i < max_len;++i){
		printf("%c", charater);
	}
	if (on == LF){
		printf("\n");
	}
}

void vector_append(vector_t* vector, char* add){
	if (vector->size + 1 == vector->capacity){
		char** temp_vector = (char **)my_malloc(sizeof(char *) * (vector->capacity * 2));

		vector->capacity = vector->capacity * 2;
		for (size_t i = 0; i < vector->size; i++){
			temp_vector[i] = vector->vector[i];
		}
		free(vector->vector);
		vector->vector = temp_vector;
	}
	vector->vector[vector->size++] = add;
	vector->vector[vector->size] = NULL;
}

void vector_init(vector_t* vector, size_t capacity, size_t max_len_word){
	vector->vector = (char **)my_malloc(sizeof(char *) * (capacity));
	vector->vector[capacity - 1] = NULL;
	vector->size = 0;
	vector->capacity = capacity;
	vector->max_len_word = max_len_word;
}

void vector_clear(vector_t* vector){
	free(vector->vector);
	free(vector);
}

void main3(vector_t *vector){
	char* p;
	char* next;

	repeat_print_(vector->max_len_word + 4, '*', LF);
	for (int i = 0; i < vector->size; i++){
		printf("* %s", vector->vector[i]);
		repeat_print_(vector->max_len_word - strlen(vector->vector[i]), ' ', NONE);
		printf(" *\n");
	}
	repeat_print_(vector->max_len_word + 4, '*', LF);
	vector_clear(vector);
}

vector_t* main2(int argc, char** argv){
	char* p;
	char* next;
	size_t temp_len;
	vector_t* vector;

	vector = (vector_t *)my_malloc(sizeof(vector_t));
	vector_init(vector, 2, 0);

	for (int i = 1; i < argc; i++){
		char * p = strtok_r(argv[i], " ", &next);

		while (p != NULL){
			temp_len = strlen(p);
			if (temp_len > vector->max_len_word)
				vector->max_len_word = temp_len;
			vector_append(vector, p);
			p = strtok_r(NULL, " ", &next);
		}
	}
	return vector;
}

void leak_handler(){
	system("leaks frame");
}

int main(int argc, char **argv){
	if (argc != 1){
		#ifdef LEAK
		atexit(leak_handler);
		#endif
		main3( main2(argc, argv));
	}
}
