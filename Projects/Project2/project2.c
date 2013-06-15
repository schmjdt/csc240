#include<stdio.h>
#include<string.h>

typedef enum {
	G, PG, PG13, R, NC17
} rating_t;

typedef struct {
	char title[20], director[20];
	int year, rating;
} movie_t;

void escape(char * mine_p);
void myVars(void);
movie_t movie_data(movie_t movie);
void movie_display(movie_t movie);
char * rating_display(int userInput); 

int main() {
	// --- Part 1 ---
	char mine[] = "Hi\tworld,\nHave a great day!";

	printf("Before:\n%s\n\n", mine);

	printf("After:\n");
	escape(&mine);
	
	printf("\n\n");
	// --- Part 2 ---
	myVars();

	printf("\n\n");
	// --- Part 3 ---
	movie_t myMovie;
	myMovie = movie_data(myMovie);
	printf("\n\n");
	movie_display(myMovie);

	return 0;
}

void escape(char * s) {
	while (*s != 0) {
		if (*s == '\t') printf("\\t");
		else if (*s == '\n') printf("\\n");
		else printf("%c", *s);
		*s++;
	}
	printf("\n");
}

void myVars(void) {
	typedef struct {
		int myInt, myArray[4];
		char myString[9];
	} myStruct_t;

	int i;

	myStruct_t myStruct;

	myStruct.myInt = 13;
	myStruct.myArray[0] = 1;
	myStruct.myArray[1] = 1;
	myStruct.myArray[2] = 2;
	myStruct.myArray[3] = 3;
	strcpy(myStruct.myString, "My String");

	printf("My Variables:\n");
	printf("Name: myStruct\t\t\t Value: %p\t Address: %p\n", myStruct, &myStruct);
	printf("Name: myStruct.myInt\t\t Value: %d\t\t Address: %p\n", myStruct.myInt, &myStruct.myInt);
	for (i = 0; i < 4; i++) {
		printf("Name: myStruct.myArray[%d]\t Value: %d\t\t Address: %p\n", i, myStruct.myArray[i], &myStruct.myArray[i]);
	}
	//printf("Name: myStruct.myArray\t Value: {%d, %d, %d, %d}\t Address: %p\n", myStruct.myArray[0], myStruct.myArray[1], myStruct.myArray[2], myStruct.myArray[3], &myStruct.myArray);
	printf("Name: myStruct.myString\t\t Value: %s\t Address: %p\n", myStruct.myString, &myStruct.myString);
}


movie_t  movie_data(movie_t movie) {
	char temp[20];

	printf("---- Movie Data ----\n");
	printf("Movie Title: ");
	fgets(movie.title, 20, stdin);
	printf("Movie Director: ");
	fgets(movie.director, 20, stdin);
	printf("Year: ");
	scanf("%d", &movie.year);
	printf("1: G, 2: PG, 3: PG-13, 4: R, 5: NC-17\n");
	printf("Rating (1-5): ");
	scanf("%d", &movie.rating);

	return movie;
}

void movie_display(movie_t movie) {
	printf("---- Movie Record ----\n");
	printf("Title:\t\t %s", movie.title);
	printf("Director:\t %s", movie.director);
	printf("Year:\t\t %d\n", movie.year);
	printf("Rating:\t\t %s\n", rating_display(movie.rating));
}

/* Converting int to string of unknown size - return char pointer */
char * rating_display(int userInput) {
	char * rating;
	switch (userInput-1) {
		case G:
			rating = "G";
			break;
		case PG:
			rating = "PG";
			break;
		case PG13:
			rating = "PG-13";
			break;
		case R:
			rating = "R";
			break;
		case NC17:
			rating = "NC-17";
			break;
		default:
			rating = "Error";
	}
	
	return rating;
}
