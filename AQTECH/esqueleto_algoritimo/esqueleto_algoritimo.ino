// Author: Pamela Fialho
// Date: 03/03/2021
// Sensors: TMP36, current and voltage (to choose)
// Function: exports the values ​​obtained by sensing to a csv file and calculates the averages of these values, and exports it to another csv file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char NOME_ARQ[] = "export.csv"; //when it cannot find a file with that name, it creates one
const char NOME_ARQ2[] = "export_averages.csv"; //when it cannot find a file with that name, it creates one

int TMP36 = 7; //temperature sensor simulation
//set pinout for voltage sensor
//set pinout for current sensor

void setup() {
  //define a voltage sensor as an input
  //define a current sensor as an input
  pinMode(TMP36, INPUT); //defines the LDR as a sensor/input

  int n=0, i=0; //counting the number of readings
  double float voltage, current, average_voltage, average_current; //double float for more accurate reading value
  float temperature, average_temperatura;
  char date[50];
  
  FILE  *fileptr; //pointer to sensoring file
  char texto[100]; //char for csv file header
  
  FILE  *filept; //pointer to averages file
  char texto2[100]; //char for csv file header

  fileptr = fopen(NOME_ARQ, "w"); //allows writing to file
  filept = fopen(NOME_ARQ2, "w"); //allows writing to file
  
  if (fileptr == NULL) {
    printf ("Erro ao abrir o arquivo de sensoriamento.\n");
    return 0;
  }
  if (filept == NULL) {
    printf ("Erro ao abrir o arquivo de médias.\n");
    return 0;
  }
  
  fprintf(fileptr, "data, tensão, corrente, temperatura\n");
  fprintf(filept, "range, média tensão, média corrente, média temperatura\n");

  fclose(fileptr);
  fclose(filept);
}

void loop() {
  fileptr = fopen(NOME_ARQ, "w"); //allows writing to file
  filept = fopen(NOME_ARQ2, "w"); //allows writing to file
  
  if (fileptr == NULL) {
    printf ("Erro ao abrir o arquivo de sensoriamento.\n");
    return 0;
  }
  if (filept == NULL) {
    printf ("Erro ao abrir o arquivo de médias.\n");
    return 0;
  }
  
  temperature = analogRead(TMP36);
  //voltage = analogRead(voltage sensor);
  //current = analogRead(current sensor);

  n=fprintf(fileptr, "%[^,], %lf, %lf, %f", date[0], voltage, current, temperature);
  i++;
  
  if (i<10) {
    average_voltage = average_voltage + voltage;
    average_current = average_current + current;
    average_temperature = average_temperature + temperature;
  }
  else if (i==10) {
    average_voltage = average_voltage/10;
    average_current = average_current/10;
    average_temperature = average_temperature/10;
    fprintf(filept, "%d-%d, %lf, %lf, %f", n-10, n, average_voltage, average_current, average_temperature); //export the averages
    
    //reset the variables for the new average
    i = 0;
    average_voltage = 0;
    average_current = 0;
    average_temperature = 0;
  }
  
  fclose(fileptr);
  fclose(filept);
}
