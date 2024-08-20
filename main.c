#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <raylib.h>

#define WIDTH 1005
#define HEIGHT 1000
#define CELL_SIZE 4
#define ROW_SIZE (WIDTH / CELL_SIZE)

void caStep(int* row, int* next, char* rule);

int main(int argc, char** argv)
{
    // getting input for rule
    if (argc != 2) {
        printf("Usage: %s [rule]\n", argv[0]);
        return -1;
    }

    if (strlen(argv[1]) != 7) {
        printf("Usage: %s [rule(7-digit)]\n", argv[0]);
        return -1;
    }

    // initialize the array
    int* row = malloc(sizeof(int) * ROW_SIZE);
    int* next_row = malloc(sizeof(int) * ROW_SIZE);
    memset(row, 0, sizeof(int) * ROW_SIZE);
    row[ROW_SIZE / 2] = 2;

    InitWindow(WIDTH, HEIGHT, "2D_3Color");
    SetTargetFPS(30);

    ClearBackground(BLACK);
    int y = 0;
    while (!WindowShouldClose()) {
        BeginDrawing();

        for (int i = 0; i < ROW_SIZE && y <= HEIGHT; i++) {
            Color c;
            switch (row[i]) {
                case 0:
                    c = WHITE;
                    break;
                case 1:
                    c = BLACK;
                    break;
                case 2:
                    c = BLUE;
                    break;
            }
            DrawRectangle(i * CELL_SIZE, y, CELL_SIZE - 1, CELL_SIZE - 1, c);
        }

        y += CELL_SIZE;
        caStep(row, next_row, argv[1]);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void caStep(int* row, int* next, char* rule)
{
    next[0] = row[0];
    next[ROW_SIZE - 1] = row[ROW_SIZE - 1];
    for (int i = 1; i < ROW_SIZE - 1; i++) {
        int total = 0;
        total = row[i] + row[i - 1] + row[i + 1];
        switch (total) {
            case 0:
                next[i] = rule[0] - '0';
                break;
            case 1:
                next[i] = rule[1] - '0';
                break;
            case 2:
                next[i] = rule[2] - '0';
                break;
            case 3:
                next[i] = rule[3] - '0';
                break;
            case 4:
                next[i] = rule[4] - '0';
                break;
            case 5:
                next[i] = rule[5] - '0';
                break;
            case 6:
                next[i] = rule[6] - '0';
                break;
        }
    }
    memcpy(row, next, ROW_SIZE * sizeof(int));
}
