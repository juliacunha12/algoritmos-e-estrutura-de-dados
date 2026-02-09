# 🔄 Pilha via Fila (LIFO usando FIFO)

Uma demonstração lógica de como adaptar uma **Fila** para se comportar como uma **Pilha**.

## 🛠️ Como usar (Manual)
1. **Quantidade:** Digite o número total de operações.
2. **Comandos de Pilha:**
   - `P <valor>`: (Push) Empilha o valor. Internamente, o código insere na fila e rotaciona todos os outros elementos para trás dele.
   - `O`: (Pop) Desempilha o elemento do topo.
   - `T`: (Top) Mostra o topo sem remover.
   - `S`: Mostra o tamanho.

**Exemplo de entrada:**

3
P 10
P 20
T