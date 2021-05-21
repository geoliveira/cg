# Computação Gráfica
Esta é a versão final do cenário construído utilizando a técnica de Raycasting.

<img src="img/img_21-5-2021.ppm" alt="cenario versao final"/>

No Ubuntu, para executar (e compilar):
```
$ make run
```
Para limpar todos os arquivos:
```
$ make clean
```
Para excluir os arquivos .ppm na pasta img/
```
$ make rmppm
```
### Níveis das aplicações ao cenário:
#### Básico:
- [X] Tipos de objetos: Esfera e Malha
- [X] Transformações: Translação, Rotação e Escala
- [X] __Mudanças de câmera (construção explícita da matriz WorldToCamera)*__
- [X] __Fontes de luz: Ambiente e Pontual*__
- [X] Cenário com, no mínimo, seis objetos
- [X] __Projeção perspectiva*__
- [X] __Representação da Janela no plano “bloqueador” com dimensões W x H em ponto flutuante (Window em Wpix x Hpix é o tamanho da matriz da imagem)*__
- [X] Definição da matriz de cores com elementos (R, G, B) entre 0 E 1.0 (normalização)

#### Intermediário:
- [X] Tipos de objetos adicionais: Cone e Cilindro
- [X] Transformações: Cisalhamento, Reflexão nos planos padrões
- [X] __Fontes de luz: Spot e luz direcional no infinito*__
- [X] Cenário com mais de seis objetos
- [X] __Projeção paralela ortográfica*__

#### Avançado:
- [ ] Transformações: Reflexão em plano arbitrário e rotação em trono de eixo arbitrário
- [X] Uso de clusters para acelerar o raycasting
- [X] __Sombra*__

__*Requisitos obrigatórios__

### Lista de melhorias e ajustes:
- Adicionar um idenficador para os objetos. Dessa forma, podemos ignorar o Cluster ao calcular a sombra.
- Adicionar aos objetos funções específicas para aplicar rotação, translação, cisalhamento, espelhamento.
- Definir o eixo y igual a 0 para todos os objetos do cenário. Atualmente, o padrão está -10, o que torna péssimo para debugar.
- Retirar translações de objetos desnecessárias.
- É necessário investigar e aplicar ajustes: a câmera; projeção ortográfica; e possivelmente aos objetos de tipo cone e cilindro.