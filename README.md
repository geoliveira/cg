# Computação Gráfica

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
#### Básico:
- [X] Tipos de objetos: Esfera e Malha
- [X] Transformações: Translação, Rotação e Escala
- [X] __Mudanças de câmera (construção explícita da matriz WorldToCamera)*__
- [ ] __Fontes de luz: Ambiente e Pontual*__
- [X] Cenário com, no mínimo, seis objetos
- [X] __Projeção perspectiva*__
- [X] __Representação da Janela no plano “bloqueador” com dimensões W x H em ponto flutuante (Window em Wpix x Hpix é o tamanho da matriz da imagem)*__
- [ ] Definição da matriz de cores com elementos (R, G, B) entre 0 E 1.0 (normalização)

### Intermediário:
- [X] Tipos de objetos adicionais: Cone e Cilindro
- [ ] Transformações: Cisalhamento, Reflexão nos planos padrões
- [ ] __Fontes de luz: Spot e luz direcional no infinito*__
- [X] Cenário com mais de seis objetos
- [X] __Projeção paralela ortográfica*__

### Avançado:
- [ ] Transformações: Reflexão em plano arbitrário e rotação em trono de eixo arbitrário
- [ ] Uso de clusters para acelerar o raycasting
- [ ] __Sombra*__

__*Requisitos obrigatórios__
