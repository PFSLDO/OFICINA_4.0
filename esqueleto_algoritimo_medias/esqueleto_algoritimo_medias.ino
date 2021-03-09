// Author: Pamela Fialho
// Date: 03/05/2021
// Sensors: TMP36, current and voltage (to choose)
// Function: exports the values ​​obtained by sensing to a csv file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char NOME_ARQ[] = "export.csv"; //when it cannot find a file with that name, it creates one

int TMP36 = 7; //temperature sensor simulation
//set pinout for voltage sensor
//set pinout for current sensor

void setup() {
  //define a voltage sensor as an input
  //define a current sensor as an input
  pinMode(TMP36, INPUT); //defines the LDR as a sensor/input

  int n; //counting the number of readings
  double float voltage, current; //double float for more accurate reading value
  float temperature;
  char date[50];
  FILE  *fileptr;
  char texto[100]; //char for csv file header

  fileptr = fopen(NOME_ARQ, "w"); //allows writing to file
  
  if (fileptr == NULL) {
    printf ("Erro ao abrir o arquivo.\n");
    return 0;
  }
  
  printf("data tensao corrente temperatura\n");

  fclose(fileptr);
}

void loop() {
  fileptr = fopen(NOME_ARQ, "w"); //allows writing to file
  
  if (fileptr == NULL) {
    printf ("Erro ao abrir o arquivo.\n");
    return 0;
  }
  
  temperature = analogRead(TMP36);
  //voltage = analogRead(voltage sensor);
  //current = analogRead(current sensor);

  printf("data tensao corrente temperatura\n");
  n=fprintf(fileptr, "%[^,], %lf, %lf, %f", date[0], voltage, current, temperature);

  fclose(fileptr);
}
