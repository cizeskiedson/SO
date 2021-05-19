#include "cliente.h"

//fluxo principal
int main(int argc, char *argv[]){  
    char escolha[2], novo_pokemon[1000], aux[1000], novo_treinador[1000], server_response[1000];
    //falo com o servidor
    //ve a requisicao do cliente
    while(true){
        fflush(stdin);
        printf("========== BEM VINDO AO SISTEMA ==========\n");
        printf("Escolha uma das alternativas a seguir:\n");
        printf("1- Registrar um pokemon\n");
        printf("2- Utilizar um pokemon\n");
        printf("3- Registrar um treinador\n");
        printf("Digite 0 para sair\n");
        scanf("%s", escolha);
        system("clear");
        //
        fflush(stdin);
        if(!strcmp(escolha, "1")){
            fflush(stdin);
            printf("Digite o nome do Pokemon:\n");
            scanf("%s", novo_pokemon);
            fflush(stdin);
            strcat(novo_pokemon, "|");

            printf("Digite o tipo do Pokemon:\n");
            scanf("%s", aux);
            fflush(stdin);
            strcat(novo_pokemon, aux);
            strcat(novo_pokemon, "|");

            printf("Digite a forca do Pokemon:\n");
            scanf("%s", aux);
            fflush(stdin);
            strcat(novo_pokemon, aux);

            system("clear");
            printf("Novo pokemon adicionado!\n\n");
            printf("%s\n\n\n", novo_pokemon);
        }else if(!strcmp(escolha, "2")){
            char *nome, *tipo, *forca, *response, pk[2];
            int cont = 0;
            
            response = malloc(sizeof(char) * strlen(server_response));
            server_response[strlen(server_response)-1] = '\0';
            strcpy(response, server_response);
            
            nome = strtok(server_response, "|");
            while(nome){
                printf("%d - Pokemon:\n", cont++);
                printf("\tNome: %s\n", nome);
                printf("\tTipo: %s\n", strtok(NULL, "|"));
                printf("\tForça: %s\n", strtok(NULL, "|"));
                nome = strtok(NULL, "|");
                printf("\n/////////////\n");
            }

            printf("Agora, escolha o Pokemon desejado:\n");
            scanf("%s", pk);
            //dostuff

        }else if(!strcmp(escolha, "3")){
            fflush(stdin);
            printf("Digite o nome do Treinador:\n");
            scanf("%s", novo_treinador);
            fflush(stdin);
            strcat(novo_treinador, "|");

            printf("Digite a idade do Treinador:\n");
            scanf("%s", aux);
            fflush(stdin);
            strcat(novo_treinador, aux);
            strcat(novo_treinador, "|");

            printf("Digite a sexo do Pokemon:\n");
            scanf("%s", aux);
            fflush(stdin);
            strcat(novo_treinador, aux);

            system("clear");
            printf("Novo treinador cadastrado!\n\n");
            printf("%s\n\n\n", novo_treinador);

        }else{
            printf("Encerrando programa...\n");
            break;
        }
        strcpy(escolha, "");
    }

    return 0;
}