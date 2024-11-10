#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[20];
} Contact;

void addContact(Contact *contacts, int index, const char *name, const char *phone) {
    strcpy(contacts[index].name, name);
    strcpy(contacts[index].phone, phone);
}

int binarySearch(Contact *contacts, int n, const char *target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(contacts[mid].name, target);
        if (cmp == 0) return mid;
        else if (cmp < 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void displayContact(Contact contact) {
    printf("Name: %s\nPhone: %s\n", contact.name, contact.phone);
}

int compareContacts(const void *a, const void *b) {
    return strcmp(((Contact *)a)->name, ((Contact *)b)->name);
}

int main() {
    int n;
    printf("Enter the number of contacts: ");
    scanf("%d", &n);

    Contact *contacts = (Contact *)malloc(n * sizeof(Contact));
    if (contacts == NULL) return 1;

    for (int i = 0; i < n; i++) {
        char name[50], phone[20];
        printf("Enter Name and Phone for contact %d:\n", i + 1);
        scanf("%s %s", name, phone);
        addContact(contacts, i, name, phone);
    }

    qsort(contacts, n, sizeof(Contact), compareContacts);

    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    int index = binarySearch(contacts, n, searchName);
    if (index != -1) displayContact(contacts[index]);
    else pri
