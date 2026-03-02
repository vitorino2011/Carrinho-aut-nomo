# Robô Autônomo com Desvio de Obstáculos e Leitura de Cores

## Visão Geral

Este projeto consiste em um robô autônomo capaz de:

-   Seguir linha preta
-   Identificar cores específicas na pista
-   Desviar automaticamente de obstáculos
-   Realizar ré real utilizando ponte H
-   Tomar decisões aleatórias ao desviar

O sistema foi desenvolvido com foco em simplicidade, organização e
funcionamento confiável.

------------------------------------------------------------------------

## Componentes Utilizados

-   Arduino
-   Sensor Ultrassônico (HC-SR04)
-   Ponte H (L298N ou similar)
-   2 Motores DC
-   Sensor de Cor
-   Buzzer
-   Chassi com rodas

------------------------------------------------------------------------

## Funcionamento Geral

O robô executa decisões com base em prioridade:

1.  Vermelho → Para completamente
2.  Verde → Vira à direita
3.  Azul → Vira à esquerda
4.  Obstáculo detectado → Dá ré e escolhe direção aleatória
5.  Preto → Segue em frente
6.  Branco ou indefinido → Mantém movimento padrão

------------------------------------------------------------------------

## Sistema de Desvio

Quando o sensor ultrassônico detecta um obstáculo a menos de 15 cm:

1.  O robô para
2.  Dá ré utilizando inversão real de polaridade via ponte H
3.  Escolhe aleatoriamente virar para esquerda ou direita
4.  Retoma o movimento

------------------------------------------------------------------------

## Sistema de Cores

As cores têm significados específicos:

-   Preto: Caminho principal
-   Branco: Fundo
-   Verde: Indicação de curva
-   Vermelho: Parada obrigatória
-   Azul: Área especial ou direção alternativa

------------------------------------------------------------------------

## Controle dos Motores

A ponte H permite:

-   Movimento para frente
-   Movimento para trás (inversão de polaridade)
-   Curvas
-   Parada total

A velocidade é controlada por PWM.

------------------------------------------------------------------------

## Objetivo do Projeto

Criar um robô simples, funcional e modular que possa ser usado em:

-   Competições escolares
-   OBR
-   Projetos educacionais
-   Introdução à robótica autônoma

------------------------------------------------------------------------

## Possíveis Melhorias Futuras

-   Implementação de PID para linha
-   Remoção de delays (modo não bloqueante)
-   Calibração real do sensor de cor
-   Máquina de estados
-   Mapeamento de ambiente

------------------------------------------------------------------------

Projeto desenvolvido com foco em clareza, funcionamento e expansão
futura.
