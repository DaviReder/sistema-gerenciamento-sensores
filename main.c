#include <stdio.h>
#include "sensor.h"
#include "gerenciador.h"

int main()
{
    int escolha=1, ids, res; //res = resultado da função

    while(escolha!=0){
        printf("Sistema de Gerenciamento de Sensores Industriais\n");
        printf("1 - Cadastrar sensor.\n");
        printf("2 - Remover sensor.\n");
        printf("3 - Listar sensores.\n");
        printf("4 - Registrar leitura.\n");
        printf("5 - Ativar sensor.\n");
        //printf("6 - Mostrar estátisticas.\n");
        printf("0 - Sair.\n");
        scanf("%d", &escolha);

        if(escolha == 0){
            return 0;
        }
        else if(escolha == 1){
            cadastrar_sensor();
        }
        else if(escolha == 2){
            printf("Remover sensor.\n");
            printf("Digite o ID do sensor: ");
            scanf("%d", &ids);
            res = remover_sensor(ids);

            if(res == 1){
                printf("Sensor removido com sucesso!\n");
            }
            else{
                printf("Houve um problema, sensor não foi removido.\n");
            }
        }
        else if(escolha == 3){
            printf("Listando sensores...\n");
            listar_sensores();
        }
        else if(escolha == 4){
            printf("Registrando leitura.. \n");
            printf("Entre com o ID do sensor: ");
            scanf("%i", &ids);
            Sensor *sensorbuscado = buscar_sensor(ids);
            res = registrar_leitura(sensorbuscado);
        }
        else if(escolha == 5){
            printf("Ativar sensor.. \n");
            printf("Entre com o ID do sensor: ");
            scanf("%i", &ids);
            Sensor *sensorbuscado = buscar_sensor(ids);
            res = ativar_sensor(sensorbuscado);
        }
        else{
            printf("Digitou uma opção inválida.");
        }
    }
    
    return 0;
}