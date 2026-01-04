#ifndef GERENCIADOR_H
#define GERENCIADOR_H
#include "sensor.h"

int cadastrar_sensor(void);
int remover_sensor(int id);
int listar_sensores(void);
Sensor* buscar_sensor(int id);
int ativar_sensor(Sensor *s);
int registrar_leitura(Sensor *s);
int metricas(Sensor *s);

#endif