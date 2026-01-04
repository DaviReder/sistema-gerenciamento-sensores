#ifndef SENSOR_H 
#define SENSOR_H

typedef enum {
    SENSOR_OFF = 0,
    SENSOR_ON = 1
} estadoSensor;

typedef struct
{
    int id, total_leituras;
    float leitura;
    estadoSensor estado; //1 on 0 off
    // float histLeit[10]; //Histórico das Leituras do sensor, implementar depois
    char tipo[32];
    float faixa_min;
    float faixa_max;
} Sensor;

#endif