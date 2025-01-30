#include "WiFi.h"
void setup() {
  // Iniciando a comunicação serial:
  Serial.begin(115200); // Velocidade -> Comunicação Serial
  Serial.println("Iniciando Wifi..."); // comunicação serial (println mostra na tela e pula uma linha por causa do ln)
  WiFi.mode(WIFI_STA); // Modo de conexão, neste caso iremos procurar roteadores
  Serial.println("Configuração concluída!");
}

void loop() {
  Serial.println("Procurando...");
  
  int QuantidadeDeRedes = WiFi.scanNetworks(); // Wifi.scanNetworks é uma função que escaneia e conta a quantidade de roteadores 
  Serial.println("Verificação concluída");

  if (QuantidadeDeRedes == 0){
    Serial.println("Nenhuma rede encontrada.");
    }
    else{
      Serial.print("Total de rede(s) encontrada(s): ");
      Serial.println(QuantidadeDeRedes);
      //For: Estrutura de repetição que vamos usar para mostrar todas as redes encontradas
      for (int i = 0; i < QuantidadeDeRedes; i++){
        Serial.print(i+1); //Sequencia numérica 
        Serial.print(": ");

        Serial.print(WiFi.SSID(i)); //Nome da rede encontrada
        Serial.print(" - Sinal (");

        Serial.print(WiFi.RSSI(i)); //Intensidade do sinal
        Serial.print(") - Possui senha? ");
        
        //WIFI_AUTH_OPEN verifica se a rede possui senha
        Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "Não" : "Sim");
        delay(10);
      }
      //Tempo para a próxima verificação
      delay(5000);

    }
  }

