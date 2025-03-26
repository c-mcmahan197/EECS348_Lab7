#include <stdio.h>

// Function to find and print all possible scoring combinations recursively
void findCombinations(int score, int td_2pt, int td_fg, int td, int fg, int safety) {
    if (score == 0) {
        // Print the combination if the exact score is achieved
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2pt, td_fg, td, fg, safety);
        return;
    }
    //if blocks to take away points based on scoring method
    if (score >= 8) findCombinations(score - 8, td_2pt + 1, td_fg, td, fg, safety);
    if (score >= 7) findCombinations(score - 7, td_2pt, td_fg + 1, td, fg, safety);
    if (score >= 6) findCombinations(score - 6, td_2pt, td_fg, td + 1, fg, safety);
    if (score >= 3) findCombinations(score - 3, td_2pt, td_fg, td, fg + 1, safety);
    if (score >= 2) findCombinations(score - 2, td_2pt, td_fg, td, fg, safety + 1);
}

int main() {
    int score;
    
    while (1) {
        // Prompt the user for input
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        
        // Stop if input is 0 or 1
        if (score <= 1) break;
        
        // Print possible scoring combinations
        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
        findCombinations(score, 0, 0, 0, 0, 0);
    }
    
    return 0;
}
