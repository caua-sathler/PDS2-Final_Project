# PDS2 | UFMG - Trabalho final | Grupo 5

## **Apresentação do Problema**
O desafio consistia no desenvolvimento de um sistema capaz de rodar três jogos clássicos: **Reversi**, **Tic Tac Toe** e **Connect4 (Lig4)**. O objetivo era criar um programa funcional e bem estruturado, permitindo que os jogadores interajam por meio de comandos, registrando estatísticas e proporcionando uma experiência fluida durante as partidas.

---

## **Visão Geral da Solução**
Para atender aos requisitos do problema, o sistema foi projetado com uma arquitetura baseada em **seis classes principais**:

1. **Classe `Game`**: Serve como a classe base para os três jogos, fornecendo métodos e atributos comuns a todos.
2. **Classe `Board`**: Responsável por gerenciar o tabuleiro dos jogos, incluindo o armazenamento das posições e a manipulação do estado do tabuleiro.
3. **Classes específicas dos jogos**:
   - **`Reversi`**: Implementa as regras, jogadas e validações do jogo Reversi.
   - **`Tic Tac Toe (Jogo da Velha)`**: Representa o jogo da velha, com métodos específicos para este jogo.
   - **`Connect4 (Lig4)`**: Gerencia o funcionamento do jogo de conectar 4 peças.
4. **Classe `Player`**: Controla as informações dos jogadores, como nome, username, estatísticas de vitórias e derrotas, além de manipular as interações entre eles.

### **Relacionamentos**
- A relação entre as classes `Board` e `Game` é de **composição**, onde cada jogo possui seu próprio tabuleiro.
- A relação entre a classe `Game` e os jogos específicos (`Reversi`, `Tic Tac Toe` e `Connect4`) é de **herança**, com cada jogo implementando seus métodos e regras únicas.

---

### **Funcionamento do Programa**
- O programa é iniciado lendo um arquivo que contém os dados dos jogadores previamente registrados.
- Os dados são armazenados em uma lista para facilitar o gerenciamento durante as partidas.
- Com base nos comandos fornecidos pelos jogadores, o programa inicia as partidas, registra os resultados e atualiza as estatísticas.
- Cada jogo possui loops com critérios de parada específicos, garantindo o funcionamento correto de acordo com as regras de cada um.

---

## **Principais Dificuldades**
1. **Implementação do jogo Reversi**:
   - Este foi o maior desafio devido à sua complexidade. Reversi exige diversas validações para garantir que as jogadas sejam válidas e que as peças do oponente sejam capturadas corretamente. Isso resultou na classe mais extensa e detalhada do programa.
2. **Integração de arquivos no `main`**:
   - Durante o desenvolvimento, tivemos que lidar com conflitos de merge ao integrar todas as funcionalidades no arquivo principal (`main`). Isso exigiu atenção para garantir que todas as interações entre os componentes funcionassem corretamente.

---

## **Extras Implementados**
Como uma melhoria adicional, implementamos uma funcionalidade no jogo **Reversi**:
- O tabuleiro exibe, além das peças em jogo, **asteriscos (`*`) indicando todas as jogadas possíveis** para o jogador da vez.
- Essa funcionalidade torna a partida mais dinâmica e facilita as decisões dos jogadores, especialmente à medida que o jogo avança e o número de jogadas válidas aumenta.

## **Executando o projeto**
- O sistema conta com um *Makefile* que automatiza sua compilação e execução através do comando `make`.
- O programa foi desenvolvido utilizando **WSL**, **g++**, **C++11** e **Valgrind**. Caso vise fazer a execução sem o *Makefile*, atente-se a essas características. 
- O comando `valgrind make` faz uma checagem quanto ao gerenciamento de memória do programa.
- O comando `make clean` deleta todos os arquivos binários gerados.
- O *Makefile* também automatiza a criação dos diretórios `bin/` e `obj/` caso eles não existam.
