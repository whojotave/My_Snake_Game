# 🐍 Snake Game

Um clássico jogo da cobra desenvolvido em C++ com a biblioteca **SFML** (Simple and Fast Multimedia Library).

## 📋 Descrição

Este projeto implementa o jogo Snake tradicional, onde você controla uma cobra que se move pela tela, come comida e cresce. O objetivo é comer o máximo de comida possível sem bater em si mesma.

## 🎮 Como Jogar

- **W** - Mover para cima
- **A** - Mover para esquerda
- **S** - Mover para baixo
- **D** - Mover para direita
- Feche a janela para sair

### Regras
- A cobra come a comida e cresce
- Se a cobra bater nas bordas da tela, ela aparece do outro lado
- Se a cobra colidir consigo mesma, o jogo termina
- O placar exibe seu progresso

## 🏗️ Estrutura do Projeto

```
snake-game/
├── main.cpp           # Arquivo principal com o loop do jogo
├── snake.h / snake.cpp        # Classe da cobra
├── corpo.h / corpo.cpp        # Classe de segmento da cobra
├── food.h / food.cpp          # Classe da comida
├── interface/
│   ├── fundo.h / fundo.cpp    # Gerenciamento do fundo
│   ├── placar.h / placar.cpp  # Gerenciamento do placar
│   └── fontes/                # Arquivos de fontes para texto
└── README.md          # Este arquivo
```

## 🛠️ Requisitos

- C++11 ou superior
- SFML 2.5+ (Simple and Fast Multimedia Library)
- Compilador g++ ou clang

## 📦 Instalação

### Linux (Ubuntu/Debian)
```bash
sudo apt-get install libsfml-dev
```

### macOS
```bash
brew install sfml
```

### Windows
Baixe os arquivos pré-compilados de [SFML](https://www.sfml-dev.org/download.php)

## 🚀 Compilação e Execução

### Compilar
```bash
g++ -std=c++11 main.cpp snake.cpp corpo.cpp food.cpp interface/fundo.cpp interface/placar.cpp -o snake_game -lsfml-graphics -lsfml-window -lsfml-system
```

### Executar
```bash
./snake_game
```

## 📚 Componentes Principais

### Snake
A classe principal que gerencia a cobra:
- Movimento em 4 direções
- Colisão com as bordas (wrap-around)
- Detecção de auto-colisão
- Crescimento ao comer comida

### Food
Representa a comida no jogo:
- Posicionamento aleatório
- Detecção de colisão com a cobra

### Corpo
Representa cada segmento da cobra:
- Renderização de cada parte do corpo
- Posicionamento preciso

### Interface
Componentes de visualização:
- **Fundo**: Renderização do fundo do jogo
- **Placar**: Exibição da pontuação

## 🎨 Características

✅ Controle fluido da cobra  
✅ Velocidade controlada  
✅ Sistema de colisão  
✅ Tela com bordas que envolvem  
✅ Placar em tempo real  
✅ Interface gráfica com SFML  

## 🤝 Contribuições

Sinta-se livre para fazer fork, melhorias e pull requests!

## 📄 Licença

Este projeto é de uso livre. Modifique e distribua conforme necessário.

## 📞 Autor

Desenvolvido com ❤️

---

**Divirta-se jogando!** 🎮
