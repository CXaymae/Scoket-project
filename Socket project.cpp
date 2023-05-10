#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 1234

int main(int argc, char *argv[]){
	int clientSocket;
	struct sockaddr_in serverAddr;
	char buffer[1024];
	
	// créer un socket coté client
	if((clientSocket = socket(AF_INET, SOK_STREAM, 0)) < 0){
		perror("Impossible de créer le spcket client !");
		return EXIT_FAILURE;
	}
	
	// initialiser la structure d'addresse de serveur
	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.0");
	
	// recevoir la réponce du server
	memset(buffer, '\0', sizeof(buffer));
	recv(clientSocket, buffer, 1024, 0);
	
	// traiter la réponce du server
	if (strcmp(buffer, "LOGIN échoué") == 0) {
        printf("Le nom d'utilisateur ou le mot de passe est incorrect.\n");
        int tries = 1;
        while (tries < 3) {
            printf("Entrez votre nom d'utilisateur : ");
            scanf("%s", username);
            printf("Entrez votre mot de passe : ");
            scanf("%s", password);
            sprintf(buffer, "%s,%s", username, password);
            send(clientSocket, buffer, strlen(buffer), 0);
            memset(buffer, '\0', sizeof(buffer));
            recv(clientSocket, buffer, 1024, 0);
            if (strcmp(buffer, "LOGIN échoué") == 0) {
                printf("Le nom d'utilisateur ou le mot de passe est incorrect.\n");
                tries++;
            } else {
                printf("Vous êtes connecté en tant que %s.\n", buffer);
                break;
            }
        }
        if (tries == 3) {
            printf("Vous avez dépassé le nombre maximum de tentatives de connexion.\n");
            close(clientSocket);
            return EXIT_FAILURE;
        }
    } else {
        printf("Vous êtes connecté en tant que %s.\n", buffer);
    }

    // Fermer de la connexion
    close(clientSocket);

    return EXIT_SUCCESS;
}
    // Connexion au serveur
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Erreur de connexion au serveur");
        return EXIT_FAILURE;
    }

    // Saisir lu nom d'utilisateur et du mot de passe
    char username[100];
    char password[100];
    
    printf("Entrez votre nom d'utilisateur : ");
    scanf("%s", username);
    printf("Entrez votre mot de passe : ");
    scanf("%s", password);

    // Envoi du nom d'utilisateur et du mot de passe au serveur
    sprintf(buffer, "%s,%s", username, password);
    send(clientSocket, buffer, strlen(buffer), 0);
    
    // Fonction pour lire le fichier texte des utilisateurs et renvoyer le profil de l'utilisateur
char* get_user_profile(char* login) {
    FILE* fp;
    char buffer[256];
    char* profile = NULL;

    // Ouverture du fichier texte des utilisateurs
    fp = fopen("users.txt", "r");
    if (fp == NULL) {
        perror("impossible d'ouveture de fichier'");
        exit(1);
    }

    // Lecture du fichier texte ligne par ligne
    while (fgets(buffer, 255, f) != NULL) {
    	
        // Supprimer du caractère de fin de ligne
        buffer[strcspn(buffer, "\n")] = 0;

        // Rechercher du login dans la ligne lue
        char* token = strtok(buffer, ",");
        
        if (strcmp(token, login) == 0) {
            // Le login a été trouvé, récupération du profil de l'utilisateur
            token = strtok(NULL, ",");
            profile = strdup(token);
            break;
        }
    }

    // Fermeture du fichier texte des utilisateurs
    fclose(f);

    return profile;
    
     Vérification du mot de passe
     
if (strcmp(buffer, "OK") == 0) {
    // Le mot de passe est correct, récupération du profil de l'utilisateur
    char* profile = get_user_profile(login);
    if (profile != NULL) {
    	
        // Envoi du profil de l'utilisateur au client
        n = write(sockfd, profile, strlen(profile));
        if (n < 0) {
            perror("Impossible d'écrir le socket§'");
            exit(1);
        }
    } else {
        // Le profil de l'utilisateur n'a pas été trouvé
        printf("utilisateur inconnu\n");
    }
    break;
} else {
    // Le mot de passe est incorrect
    printf("mot de pase invalide\n");
    attempts++;
}
}
}
