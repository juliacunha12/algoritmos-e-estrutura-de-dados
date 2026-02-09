# ⚔️ Problema de Josephus (Simulação Circular)

Este algoritmo utiliza uma fila para resolver o Problema de Josephus, simulando um círculo de pessoas onde cada $K$-ésima pessoa é eliminada.

## 🛠️ Como usar (Manual)
1. **Entrada Única:** O programa espera **dois números** na mesma linha:
   - `N`: O número total de pessoas (ex: 5).
   - `K`: O passo da eliminação (ex: 2).
2. **Processo:** Ele rotaciona a fila e remove a pessoa no passo indicado até que reste apenas uma.

**Exemplo de entrada:**
`5 2`

**Saída esperada:**
`2 4 1 5` (Ordem de eliminação)
`3` (Sobrevivente final)