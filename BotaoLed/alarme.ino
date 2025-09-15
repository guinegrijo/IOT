void handleAlarme(AdafruitIO_Data *data) {
  String valor = data->toString();

  Serial.print(F("Valor recebido do feed: "));
  Serial.println(valor);

  if (valor == "true") {
    alarmeAtivo = true;
    Serial.println("Alarme ARMADO pelo dash / app!");
  } else {
    Serial.println("Alarme DESARMADO pelo dash / app!");
  }
}


void ativarAlerta() {
  digitalWrite(BUZZER_PIN, HIGH);
  digitalWrite(LED_ALARME, HIGH);
}


void desativarAlerta() {
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_ALARME, LOW);
}