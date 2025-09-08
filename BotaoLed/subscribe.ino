// // Função chamada automaticamente quando o feed receber atualizações
// void handleBotaoLed(AdafruitIO_Data * data){
//   bool botao = data -> toBool();
  
//   Serial.print("Status: ");
//   Serial.println(botao);

//   // Lógica para acender ou não o LED
//   if(!botao){
//     digitalWrite(pinLed, HIGH);
//   }
//   else{
//     digitalWrite(pinLed, LOW);
//   }
// }