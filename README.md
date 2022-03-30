# Tetris_CPP

**Objetivo:**

Criação do jogo clássico Tetris, com todas suas funcionalidade, em c++ usando, a princípio, a API OpenGL.
Estas funcionalidades seriam: 
- Sistema de pontuação - baseado nas linhas concluídas.
- Ranking - ranking dos jogos realizados na máquina.
- Linhas concluídas - exclusão das linhas preenchidas completamente e realocamento das peças acima.
- Amostra de peças futuras - randomizar a próxima peça e mostrar.
- Colisão entre as peças.
- Dificuldade progressiva - aumento de velocidade ao decorrer da jogatina.

**Recursos utilizados:**
- Para o sistema de pontuação e ranqueamento, acreditamos que apenas alguns simples cálculos (ainda a definir) e manipulação de documentos .txt para armazenamento de pontuações serão necessários.
- As linhas concluídas serão notadas quando todos os espaços da grid no eixo X estiverem preenchidos e haverá a remoção e reposicionamento em Y das peças acima.
- No Tetris existem 7 peças. Cada peça encaixada revelará a próxima em uma aleatoriedade de 1 pra 7 atribuindo um número para cada peça e usando a função rand().
- Cada peça terá uma área calculada pelos eixos X e Y que ficará impenetrável quando encaixada. Quando outra peça for atingir o mesmo valor de X ou Y de outra peça, ela não se moverá, devido a colisão.
- O aumento da velocidade será feito com o aumento da velocidade da peça em Y, para que ela mova-se mais rápido para baixo. 
