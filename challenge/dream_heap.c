#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct note {
    char *content;
    size_t size;
};

struct note *notes[8];

void get_flag() {
    system("echo 'flag{this_is_a_mock_flag}'");
    exit(0);
}

void menu() {
    puts("1. Add Note");
    puts("2. Delete Note");
    puts("3. View Note");
    puts("4. Exit");
    printf("> ");
}

void add_note() {
    int idx;
    printf("Index: ");
    scanf("%d", &idx);
    if (idx < 0 || idx >= 8) {
        puts("Invalid index.");
        return;
    }
    notes[idx] = malloc(sizeof(struct note));
    printf("Size: ");
    scanf("%lu", &notes[idx]->size);
    notes[idx]->content = malloc(notes[idx]->size);
    printf("Content: ");
    read(0, notes[idx]->content, notes[idx]->size);
    puts("Note added!");
}

void delete_note() {
    int idx;
    printf("Index: ");
    scanf("%d", &idx);
    if (idx < 0 || idx >= 8 || !notes[idx]) {
        puts("Invalid index.");
        return;
    }
    free(notes[idx]->content);
    free(notes[idx]);
    puts("Note deleted.");
}

void view_note() {
    int idx;
    printf("Index: ");
    scanf("%d", &idx);
    if (idx < 0 || idx >= 8 || !notes[idx]) {
        puts("Invalid index.");
        return;
    }
    printf("Note: %s\n", notes[idx]->content);
}

int main() {
    setbuf(stdout, NULL);
    puts("Welcome to Dream Heap!");
    while (1) {
        menu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_note(); break;
            case 2: delete_note(); break;
            case 3: view_note(); break;
            case 4: exit(0);
            default: puts("Invalid choice.");
        }
    }
}
