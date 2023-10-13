#include <stdio.h>
void printer(int score) {
    for (int TD = 0; TD <= score/6; TD++){
    for (int FG = 0; FG <= score/3; FG++){
    for (int safety = 0; safety <= score / 2; safety++){
    for (int TD_2 = 0; TD_2 <= (score -(TD * 6 + FG * 3 + safety * 2))/8; TD_2++){
    for (int TD_1 = 0; TD_1 <= (score -(TD * 6 + FG * 3 + safety * 2 + TD_2 * 8))/7; TD_1++){
        int remaining_score = score -(TD * 6 + FG * 3 + safety * 2 + TD_2 * 8 + TD_1 * 7);
            if (remaining_score == 0) {
                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD_2, TD_1, TD, FG, safety);
                        }
                    }
                }
            }
        }
    }
}
int main() {
    int score;
    while (1) {
        printf("\n-----Enter 0 or 1 to stop-----\n");
        printf("\nEnter the score: ");
        scanf("%d", &score);
        if (score <= 1) {
            break;
        }
        printf("\nPossible combinations:\n");
        printer(score);
    }

    return 0;
}

