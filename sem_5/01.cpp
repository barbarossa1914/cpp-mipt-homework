#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct book {
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void print_book(const Book* b) {
    printf("Book: %s, Pages: %i, Price: %.1f\n",
           b->title, b->pages, b->price);
}

struct book_ptr {
    char* title;
    int pages;
    float price;
};
typedef struct book_ptr BookPtr;

void print_book_ptr(const BookPtr* b) {
    printf("Book: %s, Pages: %i, Price: %.1f\n",
           b->title, b->pages, b->price);
}

struct library {
    BookPtr* books;
    int number_of_books;
};
typedef struct library Library;

void library_create(Library* lib, int n) {
    lib->books = (BookPtr*)malloc(n * sizeof(BookPtr));
    lib->number_of_books = n;
}

void library_set(Library lib, int i, const char* title, int pages, float price) {
    lib.books[i].title = (char*)malloc(strlen(title) + 1);
    strcpy(lib.books[i].title, title);
    lib.books[i].pages = pages;
    lib.books[i].price = price;
}

BookPtr* library_get(Library lib, int i) {
    return &lib.books[i];
}

void library_print(Library lib) {
    for (int i = 0; i < lib.number_of_books; ++i) {
        print_book_ptr(&lib.books[i]);
    }
}

void library_destroy(Library* lib) {
    for (int i = 0; i < lib->number_of_books; ++i) {
        free(lib->books[i].title);
    }
    free(lib->books);
    lib->books = NULL;
    lib->number_of_books = 0;
}

int main() {

    size_t* p1 = (size_t*)malloc(sizeof(size_t));
    *p1 = 123;
    printf("a) %zu\n", *p1);
    free(p1);

    char* p2 = (char*)malloc(30 * sizeof(char));
    strcpy(p2, "Elephant");
    printf("b) %s\n", p2);
    free(p2);

    char** p3 = (char**)malloc(sizeof(char*));
    *p3 = (char*)malloc(30 * sizeof(char));
    strcpy(*p3, "Cats and Dogs");
    printf("c) %s\n", *p3);
    free(*p3);
    free(p3);

    Book* p4 = (Book*)malloc(sizeof(Book));
    strcpy(p4->title, "Don Quixote");
    p4->pages = 1000;
    p4->price = 750;
    print_book(p4);
    free(p4);

    Book a = {"Don Quixote", 1000, 750};
    Book* p5 = &a;
    printf("e) ");
    print_book(p5);

    Book** p6 = (Book**)malloc(sizeof(Book*));
    *p6 = (Book*)malloc(sizeof(Book));
    strcpy((*p6)->title, "Don Quixote");
    (*p6)->pages = 1000;
    (*p6)->price = 750;
    printf("f) ");
    print_book(*p6);
    free(*p6);
    free(p6);

    Book* p7 = (Book*)malloc(3 * sizeof(Book));
    strcpy(p7[0].title, "Don Quixote"); p7[0].pages = 1000; p7[0].price = 750;
    strcpy(p7[1].title, "Oblomov");     p7[1].pages = 400;  p7[1].price = 250;
    strcpy(p7[2].title, "The Odyssey"); p7[2].pages = 500;  p7[2].price = 500;
    printf("g)\n");
    for (int i = 0; i < 3; ++i) {
        printf("   ");
        print_book(&p7[i]);
    }
    free(p7);

    BookPtr* p8 = (BookPtr*)malloc(sizeof(BookPtr));
    p8->title = (char*)malloc(50 * sizeof(char));
    strcpy(p8->title, "Don Quixote");
    p8->pages = 1000;
    p8->price = 750;
    printf("h) ");
    print_book_ptr(p8);
    free(p8->title);
    free(p8);

    Library lib;
    library_create(&lib, 3);
    library_set(lib, 0, "Don Quixote", 1000, 750);
    library_set(lib, 1, "Oblomov",     400,  250);
    library_set(lib, 2, "The Odyssey", 500,  500);

    printf("i)\n");
    library_print(lib);

    printf("   get(1): ");
    print_book_ptr(library_get(lib, 1));

    library_destroy(&lib);
}