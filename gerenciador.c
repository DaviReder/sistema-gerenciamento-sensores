#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciador.h"
static Sensor listaSensores[10] = {
}; //Sensores estaticos ou a serem adicionados, limitados em 10.
static int qnt_Sensores; //não achei a melhor opção, mas não sei fazer outra no momento.

int cadastrar_sensor(void){
    int id;
    float fMax, fMin;
    char type[32]; //Poderia usar enum também... acho.

    printf("Entre com o ID do sensor: ");
    scanf("%i", &id);
    printf("Entre com o tipo do sensor: ");
    scanf("%31s", &type);
    printf("Entre com a faixa máxima do sensor: ");
    scanf("%f", &fMax);
    printf("Entre com a faixa mínima do sensor: ");
    scanf("%f", &fMin);
    
    if(qnt_Sensores < 10){
        Sensor s; 
        s.estado = SENSOR_OFF;
        s.faixa_max = fMax;
        s.faixa_min = fMin;
        s.id = id;
        strcpy(s.tipo, type); //Passa o array de caracteres lidos para o sensor.
        // s.tipo = type;
        listaSensores[qnt_Sensores] = s;
        // s.histLeit[] =  // não sei como implementar ainda.
        qnt_Sensores += 1;

        return 1;
    }
    return 0;
}
 
int remover_sensor(int id) {
    int i, j;

    for (i = 0; i < qnt_Sensores; i++) {
        // 1. Encontra o sensor com o ID desejado
        if (listaSensores[i].id == id) {
            
            // 2. Desloca todos os elementos à direita para a esquerda
            for (j = i; j < qnt_Sensores - 1; j++) {
                listaSensores[j] = listaSensores[j + 1];
            }

            // 3. Decrementa a quantidade global de sensores
            qnt_Sensores--; 

            return 1; // Sucesso
        }
    }
    return 0; // Se chegar aqui, o ID não foi encontrado
}

int listar_sensores(void){
    for(int i = 0; i < qnt_Sensores; i++){
        printf("\nSensor %i: \n", i);
        printf("Tipo: %s\n", listaSensores[i].tipo);
        printf("ID: %d\n", listaSensores[i].id);
        printf("Estado: %d\n", listaSensores[i].estado);
        printf("Faixa: De %f ate %f.\n", listaSensores[i].faixa_min, listaSensores[i].faixa_max);
        printf("Ultima leitura: %f\n", listaSensores[i].leitura);
    }
    return 1;
}

Sensor* buscar_sensor(int id){
    for(int i = 0; i <= qnt_Sensores; i++){
        if(listaSensores[i].id == id){
            return &listaSensores[i];
        }
        else{ 
            printf("Sensor não localizado.\n");
            return NULL; 
        }
    }
}

int ativar_sensor(Sensor *s){
    if(s->estado == SENSOR_OFF){ //prevejo adicionar função para ativar sensor.
        s->estado = SENSOR_ON; //Garantir valores entre -10 e 15.
        return 1;
    }
    else{
        printf("Sensor já estava ativado.\n");
        return 0;
    }
}

int registrar_leitura(Sensor *s){
    if(s->estado == SENSOR_ON){ //prevejo adicionar função para ativar sensor.
        s->leitura = ((rand() % 26)-10); //Garantir valores entre -10 e 15.
        printf("Leitura: %f\n", s->leitura);
        //s->histLeit[]
        return 1;
    }
    else{
        printf("Sensor está desativado, por favor ative-o.\n");
        return 0;
    }
}

/*int metricas(Sensor *s){ 
    s->histLeit[] // não sei como implementar ainda.
}*/




