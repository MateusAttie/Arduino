#define NOTE_D4 261
#define NOTE_G4 277
#define NOTE_A4 294
#define NOTE_A5 440

//array para sortear som
int tons[4] = {NOTE_A5,NOTE_A4,NOTE_G4,NOTE_D4};
//SEQUENCIA
int sequencia[100] = {};
//rodada que o jogo se encontra
int rodada_atual = 0;
//passo dentro da sequencia,enquanto a seq eh reproduzida
int passo_atual = 0;
//pino de audio,leds , e botoes
int pinoAudio = 6;
int pinosLeds[4] = {8,9,10,11};
int pinosBotoes[4] = {2,3,4,5};

int botao_pressionado = 0;

int game_over = 0;

void setup()
{
  //definindo leds como saida
  for(int i;i <= 3;i++){
  pinMode(pinosLeds[i],OUTPUT);
  }
  
  //definindo botoes comno entrada
  for(int i = 0;i<=3;i++){
  pinMode(pinosBotoes[i],INPUT);
  }
  
  //dfinindo audio como saida
  pinMode(pinoAudio,OUTPUT);
  //inicialzando o random atraves de um analogRead
  randomSeed(analogRead(0));
 }
 
 
 void loop()
 {
   //se perdeu o jogo reinicializamos todas as variaveis
   if(game_over)
   {
     int sequencia[100] = {};
     rodada_atual = 0;
     passo_atual = 0;
     game_over = false;
   }
   
   //toca som de inicio na primeira rodada
   if(rodada_atual == 0)
   {
     tocarSomDeInicio();
     delay(500);
   }
   
   //chama funcao de proxima rodada
   proximaRodada();
   
   //reproduz seuquencia atual
   reproduzirSequencia();
   
   //aguarda os botoes serem pressionados
   aguardarJogador();
   
   delay(1000);
 }
   
   //Sorteia um novo item e adiciona na sequencia
   void proximaRodada()
   {
     int numero_sorteado = random(0,4);
     sequencia[rodada_atual++]= numero_sorteado;
   } 
  
  //reproduz a sequencia para sr memorizada
    void reproduzirSequencia()
   {
     for(int i = 0;i<rodada_atual;i++){
     tone(pinoAudio,tons[sequencia[i]]);
     digitalWrite(pinosLeds[sequencia[i]],HIGH);
     delay(500);
     noTone(pinoAudio);
     digitalWrite(pinosLeds[sequencia[i]],LOW);
     delay(100);
     }
     noTone(pinoAudio);
   } 
   
   //aguarda o jogador
   void aguardarJogador()
   {
     for(int i = 0;i<rodada_atual;i++){
     aguardaJogada();
     verificarJogada();
     if(game_over){
       break;
     }
     passo_atual++;
     
     }
     passo_atual = 0;
     }
     
     void aguardaJogada()
     {
       boolean jogada_efetuada = false;
       while(!jogada_efetuada){
       for(int i = 0;i<=3;i++){
       if(digitalRead(pinosBotoes[i])==HIGH){
       
         botao_pressionado = i;
         
         tone(pinoAudio,tons[i]);
         digitalWrite(pinosLeds[i],HIGH);
         delay(400);
         digitalWrite(pinosLeds[i],LOW);
         noTone(pinoAudio);
         
         jogada_efetuada = true;
      
       }
       }
       
       delay(10);
       
       }
     
     }
     
     void verificarJogada()
     {
       if(sequencia[passo_atual]!=botao_pressionado){
       //GAME OVER
       
       for(int i = 0;i<=3;i++){
       tone(pinoAudio,tons[i]);
       digitalWrite(pinosLeds[i],HIGH);
       delay(200);
       digitalWrite(pinosLeds[i],LOW);
       noTone(pinoAudio);
       
       }
       tone(pinoAudio,tons[3]);
       for(int i = 0;i <=3;i++){
       digitalWrite(pinosLeds[0],HIGH);
       digitalWrite(pinosLeds[1],HIGH);
       digitalWrite(pinosLeds[2],HIGH);
       digitalWrite(pinosLeds[3],HIGH);
       delay(100);
       digitalWrite(pinosLeds[0],LOW);
       digitalWrite(pinosLeds[1],LOW);
       digitalWrite(pinosLeds[2],LOW);
       digitalWrite(pinosLeds[3],LOW);
       delay(100);
       }
       noTone(pinoAudio);
       
       game_over = true;
       }
       }
       
       void tocarSomDeInicio()
       {
         tone(pinoAudio,tons[0]);
            digitalWrite(pinosLeds[0],HIGH);
       digitalWrite(pinosLeds[1],HIGH);
       digitalWrite(pinosLeds[2],HIGH);
       digitalWrite(pinosLeds[3],HIGH);
       delay(500);
       digitalWrite(pinosLeds[0],LOW);
       digitalWrite(pinosLeds[1],LOW);
       digitalWrite(pinosLeds[2],LOW);
       digitalWrite(pinosLeds[3],LOW);
       delay(500);
       noTone(pinoAudio);
       }
   
   
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
