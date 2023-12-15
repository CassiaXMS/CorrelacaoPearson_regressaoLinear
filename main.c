#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* O presente algoritmo tem como objetivo calcular o correlação entre
   duas variáveis x e y utilizando a correlação de Pearson. A partir
   deste algortimo, saberemos se as variáveis possuem relacionamento
   forte, médio, fraco, nulo ou perfeito. A partir do cálculo do
   coeficiente de Pearson, pode-se construir  a de reta regressão linear
   e obter o gráfico da relação entre as variáveis estudadas.O programa abaixo
   está escrito em linguagem C.
*/

   


/* 
TESTE 1
  X = 7.2, 6.3, 6.7, 7, 6.9, 6.4, 7.1, 6.7, 3.8
  Y = 291,228,252,265,270,240,288,246,81

TESTE 2
  X = 163, 159, 175, 180, 165, 81
  Y = 250, 81, 300, 225, 247,  275

TESTE 3
  X = 14, 12, 18, 25, 32, 44, 81, 28
  Y = 49, 52, 81,  46, 41, 35,  49,  44
*/

int main() {
  
  // Valores de x e y

  //TESTE 1 
  float x[9] = {7.2, 6.3, 6.7, 7, 6.9, 6.4, 7.1, 6.7, 3.8};
  int y[9] = {291,228,252,265,270,240,288,246,81};

  /*TESTE 2
  int x[6] = {163, 159, 175, 180, 165, 81};
  int y[6] = {250, 81, 300, 225, 247,  275};*/

  /*TESTE 3
  int x[8] = {14, 12, 18, 25, 32, 44, 81, 28};
  int y[8] = {49, 52, 81,  46, 41, 35,  49,  44}; */

  int  qntd_elementos = 9;
  float somatorio_x = 0.0, somatorio_y = 0.0, somatorio_media_y = 0.0;
  float sub_x[qntd_elementos], sub_y[qntd_elementos], mult_xy[qntd_elementos];
  
  float media_x, media_y, quad_x[qntd_elementos], quad_y[qntd_elementos], raiz,
        coeficiente_pearson_xy = 0.0, somatorio_media_x = 0.0,
        somatorio_multiplicacao = 0.0, coefic_explicacao=0.0; ;

  // Regressao linear
  float taxa_variacao, interseccao_y;

  printf("\n\n **********  TESTE 1 ********** \n\n\n");

  
  printf("Valores de X: ");
  for (int i = 0; i < qntd_elementos; i++) {
    printf("%.1f  ", x[i]);
  }
  printf("\n\n");
  printf("Valores de Y: ");
  for (int i = 0; i < qntd_elementos; i++) {
    printf("%d  ", y[i]);
  }
  printf("\n\n-------------------\n\n");

  // Dados os valores iremos calcular o coeficiente de pearson.
  // Este coeficiente indicará a correlação entre as variáveis x e y

  // Calculando a somatoria
  for (int i = 0; i < qntd_elementos; i++) {
    somatorio_x = somatorio_x + x[i];
  }
  for (int i = 0; i < qntd_elementos; i++) {
    somatorio_y = somatorio_y + y[i];
  }
  printf("\nSomatorio de X =  %.2f", somatorio_x);

  printf("\nSomatorio de Y =  %.2f", somatorio_y);

  // calculando a media
  media_x = somatorio_x / qntd_elementos;
  media_y = somatorio_y / qntd_elementos;

  printf("\n\nMedia X =  %.4f  \nMedia Y =  %.4f", media_x, media_y);

//----------------------------------------//
  
  // subtraindo a media dos valores de x
  printf("\n\nValores de X - media de X: \n");
  for (int i = 0; i < qntd_elementos; i++) {
    sub_x[i] = x[i] - media_x;
    printf("%.2f  ", sub_x[i]);
  }
  

  // Subtraindo a media dos valores de y
  printf("\n\nValores de Y - media de Y: \n");
  for (int i = 0; i < qntd_elementos; i++) {
    sub_y[i] = y[i] - media_y;
    printf("%.2f ", sub_y[i]);
  }

  //----------------------------------------//

  printf("\n\n-------------------\n");
  
  // Elevando os  valores de x - media ao quadrado
  printf("\nValores da subtracao de X ao quadrado (X^2): \n");
  for (int i = 0; i < qntd_elementos; i++) {
    quad_x[i] = pow(sub_x[i], 2);
    printf("%.2f  ", quad_x[i]);
  }

  // Somatório dos valores do x ao quadrado
  for (int i = 0; i < qntd_elementos; i++) {
    somatorio_media_x = somatorio_media_x + quad_x[i];
  }
  printf("\n\nSomatorio da subtracao da media de X =  %.4f", somatorio_media_x);
  printf("\n");

  
  // Elevando os  valores de y - media ao quadrado
  printf("\n\nValores da subtracao de Y ao quadrado (Y) : \n");
  for (int i = 0; i < qntd_elementos; i++) {
    quad_y[i] = pow(sub_y[i], 2);
    printf("%.2f  ", quad_y[i]);
  }

  // Somatório dos valores do y ao quadrado
  for (int i = 0; i < qntd_elementos; i++) {
    somatorio_media_y = somatorio_media_y + quad_y[i];
  }
  printf("\n\nSomatorio da subtracao da media de Y: %.4f", somatorio_media_y);
  
   printf("\n\n-------------------\n\n");
  
//----------------------------------------//


  // Multiplicando os valores de x e de y
  printf("Multipicação da subtração de X e Y: \n");
  for (int i = 0; i < qntd_elementos; i++) {
    mult_xy[i] = sub_x[i] * sub_y[i];
    printf("%.2f  ", mult_xy[i]);
  }

  for (int i = 0; i < qntd_elementos; i++) {
    somatorio_multiplicacao = somatorio_multiplicacao + mult_xy[i];
    
  }
  printf("\n\nSomatorio da multiplicacao =  %.4f", somatorio_multiplicacao);

  printf("\n\n-------------------\n\n");

//----------------------------------------//

  
  // calculando a raiz da multiplicacao dos somatorios de x - a media tal como do y ao quadrado
  raiz = (somatorio_media_x * somatorio_media_y);
  raiz = sqrt(raiz);
  
  // dividindo o somatorio da subtracao  da media do x
  coeficiente_pearson_xy = somatorio_multiplicacao / raiz;
  printf("\nCOEFICIENTE DE PEARSON: %f", coeficiente_pearson_xy);

 
  //-------------------- Interpretaçao -----------------//

  // verificando se e positivo ou negativo
  if (coeficiente_pearson_xy > 0) {
    printf("\nCorrelacao positiva e diretamente proporcional.");
  } else {
    printf("\nCorrelacao negativa e inversamente proporcional.");
    coeficiente_pearson_xy = coeficiente_pearson_xy * (-1);
  }

  // multiplicando por 100 para ter numero inteiro
  coeficiente_pearson_xy = coeficiente_pearson_xy * 100;

  if (coeficiente_pearson_xy == 0) {
    printf("Correlacao nula.");
  } else if (coeficiente_pearson_xy > 80 && coeficiente_pearson_xy <= 100) {
    printf("\nCorrelacao forte.");
  } else if (coeficiente_pearson_xy > 50 && coeficiente_pearson_xy <= 80) {
    printf("\nCorrelacao média.");
  } else if (coeficiente_pearson_xy >= -50 && coeficiente_pearson_xy <= 50) {
    printf("\nCorrelação fraca.");
  } else if (coeficiente_pearson_xy == 100) {
    printf("\nCorrelacao perfeita");
  }

  
  //--------- REGRESSAO LINEAR  ----------------------//
  printf("\n\n--- Calculando a Regressao Linear ---\n\n\n");
  taxa_variacao = somatorio_multiplicacao / somatorio_media_x;

  printf("Coeficiente de inclinação = %.5f\n", taxa_variacao);

  interseccao_y = media_y - (taxa_variacao * media_x);

  printf("Coeficiente Linear = %.5f", interseccao_y);

  // Formula final de regressão. Onde b1 é a taxa de variação
  printf("\nFormula da Regressao Linear: Y = %.4fX %.4f", taxa_variacao,interseccao_y);

  coefic_explicacao = (coeficiente_pearson_xy * coeficiente_pearson_xy)/100;
  
  printf("\nCoeficiente de explicação (R²)=  %.2f", coefic_explicacao);

  //Resposta teste 1
  printf("\n\nRESPOSTA FINAL:\n");
  printf("Portanto, temos um relacionamento forte e diretamente proporcional, onde %.2f%% do Número de matrículas na Unicamp é explicada pelo Número de casas alugadas.", coefic_explicacao);

  /*Resposta teste 2
  printf("\n\nRESPOSTA FINAL:\n");
  printf("Portanto, temos um relacionamento fraco e inversamente proporcional, onde %.2f%% do Preço de venda por unidade  é explicada pela Unidades Vendidas.", coefic_explicacao);*/

  /*Resposta teste 3
  printf("\n\nRESPOSTA FINAL:\n");
  printf("Portanto, temos um relacionamento fraco e inversamente proporcional, onde %.2f%% das  Horas de Treinamento é explicada pelo Número de Acidentes .", coefic_explicacao);*/

  return 0;
}

