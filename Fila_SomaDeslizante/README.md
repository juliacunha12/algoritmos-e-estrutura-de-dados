# 📈 Soma em Janela Deslizante (Sliding Window)

Este programa implementa uma técnica otimizada de análise de dados utilizando uma fila dinâmica para calcular a soma de elementos dentro de uma janela que se desloca.

## 🚀 O que este código resolve?
Em vez de recalcular a soma de todos os elementos toda vez que um novo número entra, este algoritmo utiliza o conceito de **Fila**. Quando a janela atinge seu tamanho máximo:
1. O novo número entra no fim da fila e é **somado** ao total.
2. O número mais antigo sai da frente da fila e é **subtraído** do total.

Isso torna o cálculo extremamente rápido, independentemente do tamanho da janela.



## 🛠️ Como Usar (Passo a Passo)

1. **Entrada Inicial:** O programa espera **dois números inteiros** na primeira linha:
   - `N`: Quantidade total de números que você vai digitar.
   - `K`: O tamanho da janela (quantos números somar por vez).

2. **Entrada de Dados:** Em seguida, insira os `N` números.

### Exemplo Prático:
Se você digitar `5 3` (5 números totais, janela de tamanho 3) e os números `10 20 30 40 50`:

* **Passo 1:** Lê 10, 20, 30 -> Soma = **60**
* **Passo 2:** Lê 40 (Entra 40, sai 10) -> Soma = 60 + 40 - 10 = **90**
* **Passo 3:** Lê 50 (Entra 50, sai 20) -> Soma = 90 + 50 - 20 = **120**

**Entrada no terminal:**

5 3
10 20 30 40 50

