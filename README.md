# TrabalhoEngenhariaLinguagem
Repositório para guardar analisadores da linguagem M


Para informações de como rodar entre na pasta de analisador-sintatico e rode o comando:
  flex lex.l
Logo apos, o comando
  yacc parser.y -d -v -g
E então o comando
  gcc lex.yy.c y.tab.c -o executavel

Então terá gerado um compilador para a linguagem, com isso rode o comando:
  ./executavel < codigos/{arquivo desejado}.m
 
Para verificar se o programa está funcionando corretamente compile usando um compilador em C e execute o programa gerado
