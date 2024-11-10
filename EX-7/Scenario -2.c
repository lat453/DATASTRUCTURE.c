#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char username[50];
    char email[100];
    int followers;
} User;

void addUser(User *users, int index, const char *username, const char *email, int followers) {
    strcpy(users[index].username, username);
    strcpy(users[index].email, email);
    users[index].followers = followers;
}

int binarySearch(User *users, int n, const char *target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(users[mid].username, target);
        if (cmp == 0) return mid;
        else if (cmp < 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void displayUser(User user) {
    printf("Username: %s\nEmail: %s\nFollowers: %d\n", user.username, user.email, user.followers);
}

int compareUsers(const void *a, const void *b) {
    return strcmp(((User *)a)->username, ((User *)b)->username);
}

int main() {
    int n;
    printf("Enter the number of users: ");
    scanf("%d", &n);

    User *users = (User *)malloc(n * sizeof(User));
    if (users == NULL) return 1;

    for (int i = 0; i < n; i++) {
        char username[50], email[100];
        int followers;
        printf("Enter Username, Email, Followers for user %d:\n", i + 1);
        scanf("%s %s %d", username, email, &followers);
        addUser(users, i, username, email, followers);
    }

    qsort(users, n, sizeof(User), compareUsers);

    char searchUsername[50];
    printf("Enter username to search: ");
    scanf("%s", searchUsername);

    int index = binarySearch(users, n, searchUsername);
    if (index != -1) displayUser(users[index]);
    else printf("User not found.\n");

    free(users);
    return 0;
}
