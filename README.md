# Software-Cifras
Software desenvolvido em C++ para cadastro e pesquisa de cifras musicais

## Motivação
Em meados de 2014, como músico em uma banda, estava me deparando com um problema. Nessa época eu organizava os ensaios, criando e tirando arranjos, definindo tonalidades, etc. As cifras e anotações eram armazenadas em pasta física (aquelas pastas com folhas de plástico). Com o passar do tempo, a quantidade de cifras foi aumentando, chegando na casa das centenas. Algumas representavam a mesma música, porém em tonalidade diferente e outras eram idênticas em tonalidade e arranjo. A grande quantidade de cifras deixava o trabalho de procurar determinada música cada vez mais difícil. Muitas vezes, imprimia mais cifras idênticas pelo simples fato da mesma passar desapercebido durante a busca. Por esse motivo resolvi desenvolver esta aplicação.

## Solução
O software não armazena a cifra propriamente dita (letra e notas). Ele armazena o nome da música, banda, tonalidade, metrônomo, observações, etc. O armazenamento é feito em documento .txt simplesmente. Cada cifra possui um código que será anotado na folha física. Esse código representará o número da página em que a cifra se encontra na pasta. O programa ainda conta com menu interativo baseado nas classes do repositório [Menu-navegavel-pelas-setas][1]. 

Abaixo estão algumas imagens representando o funcionamento da aplicação:

<p align="center">
  <figcaption> Menu Principal </figcaption>
  <img width="600" heigh="400" src="to_readme/1-MenuPrincipal.jpg">
</p>   

<p align="center">
  <figcaption> Cadastrar Cifra </figcaption>
  <img width="600" heigh="400" src="to_readme/2-CadastrarCifra.jpg">
</p>   

<p align="center">
  <figcaption> Pesquisar Cifra </figcaption>
  <img width="600" heigh="400" src="to_readme/3-PesquisarCifra.jpg">
</p>   

<p align="center">
  <figcaption> Pesquisa por Artista </figcaption>
  <img width="600" heigh="400" src="to_readme/4-PesquisaArtista.jpg">
</p>   

<p align="center">
  <figcaption> Pesquisa realizada </figcaption>
  <img width="600" heigh="400" src="to_readme/5-PesquisaRealizada.jpg">
</p>   

<p align="center">
  <figcaption> Selecionando Cifra </figcaption>
  <img width="600" heigh="400" src="to_readme/6-SelecionandoCifra.jpg">
</p>   

<p align="center">
  <figcaption> Alterar ou excluir Cifra </figcaption>
  <img width="600" heigh="400" src="to_readme/7-AlterarOuExcluirCifra.jpg">
</p>   

[1]: https://github.com/stlandre/Menu-navegavel-pelas-setas
