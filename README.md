🚀 Simulação de Resgate Espacial em Órbita

Projeto desenvolvido como parte da disciplina de Programação Orientada a Objetos no curso de Engenharia de Computação - CEFET-MG.

🧠 Objetivo

Simular o resgate de astronautas em uma estação espacial utilizando um robô autônomo. O robô percorre a estação em busca dos astronautas e os conduz até um ponto seguro, aplicando conceitos de orientação a objetos, algoritmos de busca e estruturas de dados dinâmicas.


📥 Formato da Entrada

O arquivo Entrada.txt contém a representação da estação espacial em forma de matriz, com os seguintes símbolos:

'# → Parede'  
'. → Espaço livre'
'A → Astronauta' 
'R → Robô' 
'S → Ponto seguro'

Exemplo:

#######
#R...A#
#.#.#.#
#...#.#
#A#S#.#
#######


🧭 Lógica de Funcionamento

    O robô localiza os astronautas na matriz.

    Utiliza busca (como BFS ou DFS) para traçar o caminho até cada um.

    Após resgatar todos, os leva até o ponto seguro.

    O programa imprime os passos do robô e o estado do mapa a cada ação.

🚧 Próximos Passos

    Melhorar otimização do percurso (reduzir número de passos).

    Adicionar visualização da simulação (ex: gerar um GIF).

    Implementar tratamento de exceções e validação da entrada.

👨‍🚀 Autores

    Deivy Rossi
