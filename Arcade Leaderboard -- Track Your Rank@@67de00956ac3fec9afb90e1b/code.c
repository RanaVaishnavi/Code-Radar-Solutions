#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 100

typedef struct {
    char name[50];
    int score;
} Player;

// Function to sort players by score in descending order
void sortPlayers(Player players[], int n) {
    Player temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (players[j].score > players[i].score) {
                temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
}

// Function to find rank of a player
int findRank(Player players[], int n, char targetName[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(players[i].name, targetName) == 0) {
            return i + 1;  // Rank is index + 1
        }
    }
    return -1;  // Not found
}

int main() {
    Player players[MAX_PLAYERS];
    int n;
    char targetName[50];

    printf("Enter number of players: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        printf("Enter score of %s: ", players[i].name);
        scanf("%d", &players[i].score);
    }

    sortPlayers(players, n);

    printf("\n--- Leaderboard ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %d\n", i + 1, players[i].name, players[i].score);
    }

    printf("\nEnter your name to check your rank: ");
    scanf("%s", targetName);

    int rank = findRank(players, n, targetName);
    if (rank != -1) {
        printf("🎮 %s, your rank is: %d\n", targetName, rank);
    } else {
        printf("⚠️ Player not found on the leaderboard.\n");
    }

    return 0;
}