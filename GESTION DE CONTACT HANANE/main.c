#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_contact 100

typedef struct {
    char nom[50];
    char num[50];
    char adress[50];
} contact;

contact contacts[MAX_contact];
int nbr_contacts = 0;
int i, j;

void AjouterContact() {
    if (nbr_contacts < MAX_contact) {
        printf("Entrer le nom du contact :\n");
        scanf("%s", contacts[nbr_contacts].nom);
        printf("Entrer le numéro du contact :\n");
        scanf("%s", contacts[nbr_contacts].num);
        printf("Entrer l'adresse du contact :\n");
        scanf("%s", contacts[nbr_contacts].adress);
        nbr_contacts++;
    } else {
        printf("La liste de contacts est pleine !\n");
    }
}

void modifierContact(char nom_modifier[], int nbr_contacts) {
    int contact_trouve = 0;
    for (i = 0; i < nbr_contacts; i++) {
        if (strcmp(contacts[i].nom, nom_modifier) == 0) {
            printf("Entrer le nouveau numéro :\n");
            scanf("%s", contacts[i].num);
            printf("Entrer la nouvelle adresse :\n");
            scanf("%s", contacts[i].adress);
            contact_trouve = 1;
            break;
        }
    }
    if (!contact_trouve) {
        printf("Le contact n'existe pas.\n");
    }
}

void afficher_contact() {
    if (nbr_contacts > 0) {
        for (i = 0; i < nbr_contacts; i++) {
            printf("Nom : %s\nNuméro : %s\nAdresse : %s\n", contacts[i].nom, contacts[i].num, contacts[i].adress);
        }
    } else {
        printf("Aucun contact à afficher.\n");
    }
}

void supprimer_contact(char contact_supprimer[]) {
    for (i = 0; i < nbr_contacts; i++) {
        if (strcmp(contact_supprimer, contacts[i].nom) == 0) {
            for (j = i; j < nbr_contacts - 1; j++) {
                strcpy(contacts[j].nom, contacts[j + 1].nom);
                strcpy(contacts[j].num, contacts[j + 1].num);
                strcpy(contacts[j].adress, contacts[j + 1].adress);
            }
            nbr_contacts--;
            printf("Le contact est supprimé.\n");
            return;
        }
    }
    printf("Le contact n'a pas été trouvé.\n");
}

void rechercher_cantact(char contact_rechercher[]) {
    printf("Entrez le nom du contact à rechercher : ");
    scanf("%s", contact_rechercher);
    for (i = 0; i < nbr_contacts; i++) {
        if (strcmp(contacts[i].nom, contact_rechercher) == 0) {
            printf("Voici le contact trouvé :\n");
            printf("Nom : %s\nNuméro : %s\nAdresse : %s\n", contacts[i].nom, contacts[i].num, contacts[i].adress);
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

int main() {
    int choix;
    char nom_modifier[50];
    char contact_supprimer[50];
    char contact_rechercher[50];

    do {
        printf("1. Ajouter contact\n");
        printf("2. Modifier contact\n");
        printf("3. Afficher contacts\n");
        printf("4. Supprimer contact\n");
        printf("5. Rechercher contact\n");

        scanf("%d", &choix);

        switch (choix) {
            case 1:
                AjouterContact();
                break;
            case 2:
                printf("Entrer le nom à modifier :\n");
                scanf("%s", nom_modifier);
                modifierContact(nom_modifier, nbr_contacts);
                break;
            case 3:
                afficher_contact();
                break;
            case 4:
                printf("Entrer le contact à supprimer :\n");
                scanf("%s", contact_supprimer);
                supprimer_contact(contact_supprimer);
                break;
            case 5:
                rechercher_cantact(contact_rechercher);
                break;
            default:
                printf("Choix n'existe pas.\n");
        }
    } while (choix != 0);

    return 0;
}
